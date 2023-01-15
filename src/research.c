#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lib/utils.c"

#define SONG_AMOUNT 30
#define MAX_LENGTH 50

int pickSongs(int* vet) {
	FILE* songs = fopen("../config/songs.txt", "r");
	
	if (!songs) {
		perror("Erro ao abrir o arquivo songs.txt"); // Caso o arquivo esteja inacessível uma mensagem indicando o tipo de erro aparecerá
		exit(EXIT_FAILURE); // E então terminamos o programa com código de erro
	}
	
	int choice = 0;
	char line[MAX_LENGTH]; // Tipo string para armazenar cada linha do arquivo uma por vez

	for (int i = 1; i <= SONG_AMOUNT; i++) {
		fgets(line, MAX_LENGTH - 1, songs); //MAX_LENGTH - 1 pois a última posição será o \0
		printf("%d) %s", i, line); // N° para escolher a música e o texto que foi pego por fgets
	} // Como no arquivo já tem o \n, não precisamos dele aqui para uma nova linha

	// Faz a mesma coisa que o de cima, só que para Linux
	// size_t len = 0;
	// int lineCount = 1;
	// char read;
	// char* line = NULL;
   
	// while ((read = getline(&line, &len, songs)) != -1) { 
	//     printf("%d - %s", lineCount, line);
	//     lineCount++;
	// }

	printf("\n"); // Agora sinm]m precisamos de uma nova linha para apresentar o menu

	int picks = 1;

	while(picks <= 5) {
        printf("Escolha a %d° música: ", picks);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 30) {
            printf("Opção inválida, escolha outra!\n");
            continue;
        }

        if (isDuplicate(vet, choice)) {
            printf("Opção já escolhida, escolha outra!\n");
            continue;
        }

        vet[picks - 1] = choice;
        picks++;
    }
	
	fclose(songs);
	system("clear || cls");
	return 0;
}

int getPersonData() {
	char nome[30];

	printf("Digite seu nome e sobrenome: ");
	gets(nome);
	char sex = getSex();

	int age = getAge();
	int choices[5] = {0};
	pickSongs(choices);
	
	FILE* pesq = fopen("../config/pesq.txt","a");

	if (!pesq) {
		perror("Erro ao abrir o arquivo pesq.txt"); // Caso o arquivo esteja inacessível uma mensagem indicando o tipo de erro aparecerá
		exit(EXIT_FAILURE); // E então terminamos o programa com código de erro
	}

	// Escreve os dados que o usuário informou no arquivo, separados por tab
	fputc(sex, pesq);
	fprintf(pesq, "\t%d\t", age);
	fputs(nome, pesq);
	
	for (int i = 0; i < 5; i++) fprintf(pesq, "\t%d", choices[i]);

	fputc('\n', pesq);
	fclose(pesq);

	return 0;
}

int main() {
	SetConsoleOutputCP(65001); // Serve para exibir caracteres fora da tabela ASCII
	return getPersonData();
}