#include <stdio.h>
#include <string.h>
#include <windows.h> //SetConsoleOutputCP
#include "lib/shell.c"
#include "lib/utils.c"

#define SONG_AMOUNT 30
#define MAX_LENGTH 50

char* getNthFileLine(FILE* arq, int lineIndex) {
	char line[MAX_LENGTH];
	for (int i = 1; i < lineIndex; i++) {
		fgets(line, MAX_LENGTH - 1, arq); //MAX_LENGTH - 1 pois a última posição será o \0
	}
	return fgets(line, MAX_LENGTH - 1, arq);
}

void mostPopularSongs(person* pessoas, songData* popSongs, int ARRAY_SIZE) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int j = 0; j < 5; j++) { // Para cada escolha, podemos simplesmente acessar seu index correspondente no array de músicas
			popSongs[pessoas[i].choices[j] - 1].votes++; // e aumentar sua quantidade de votos em 1 
		}
	}
	shellsortPopSongs(popSongs, SONG_AMOUNT); // Como os votos foram contabilizados, agora basta ordenar o array
}

void printMostPopSongs(songData* musics) {
	int place = 1;
	for (int i = 0; i < 30; i++) {
		char line[MAX_LENGTH];
		if (musics[i].votes == 0)
			continue;
		strcpy(line, getNthFileLine(fopen("../config/songs.txt", "r"), musics[i].index + 1));
		printf("%d° lugar - %d votos: %s", place, musics[i].votes, line);
		place++;
	}
}

int main(int argc, char *argv[]) {
	SetConsoleOutputCP(65001); // Serve para exibir caracteres fora da tabela ASCII
	
	FILE* research = fopen("../config/pesq.txt", "r");

	if (!research) {
		perror("Erro ao abrir o arquivo research.txt");
		exit(EXIT_FAILURE);
	}

	unsigned int peopleCount = countLines(fopen("../config/pesq.txt", "r"));
	person pessoas[peopleCount];
	char line[MAX_LENGTH];

	for (int i = 0; i < peopleCount; i++) {
		if (!fgets(line, MAX_LENGTH - 1, research)) { //MAX_LENGTH - 1 pois a última posição será o \0
			continue; //Se a linha não tiver texto não têm porque escanea-la
		}

		strtok(line, "\t"); //Separa  string em várias substrings divididas pelo caractere delimitador
		pessoas[i].sex = line[0];
		pessoas[i].age = atoi(strtok(NULL, "\t")); // Temos de passar NULL para a referência da string não mudar, e usamos atoi para converter em um número
		strcpy(pessoas[i].name, strtok(NULL, "\t"));

		for (int j = 0; j < 5; j++) {
			pessoas[i].choices[j] = atoi(strtok(NULL, "\t"));
		}
	}
	shellsortPerson(pessoas, peopleCount);
	fclose(research);
	FILE* songs = fopen("../config/songs.txt", "r");
	
	if (!songs) {
		perror("Erro ao abrir o arquivo songs.txt"); // Caso o arquivo esteja inacessível uma mensagem indicando o tipo de erro aparecerá
		exit(EXIT_FAILURE); // E então terminamos o programa com código de erro
	}

	songData voteCount[SONG_AMOUNT]; // Array que vai armazenar a quantidade de votos de cada música
	
	for (int i = 0; i < SONG_AMOUNT; i++) {
		voteCount[i].index = i;
		voteCount[i].votes = 0;
	}
	
	mostPopularSongs(pessoas, voteCount, peopleCount);
	printMostPopSongs(voteCount);
	
	fclose(songs);
	system("pause"); // Caso o programa seja executado fora de um terminal, a janela iria fechar automaticamente, impedindo de ver os dados
	
	return 0;
}