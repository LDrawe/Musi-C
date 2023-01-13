#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "lib/shell.c"
#include "lib/utils.c"

#define SONG_AMOUNT 30

char* getNthFileLine(FILE* arq, int ARRAY_SIZE) {
	char line[70];
	for (int i = 1; i < ARRAY_SIZE; i++) {
		fgets(line, 70, arq);
	}
	return fgets(line, 70, arq);
}

void mostPopularSongs(person* vetor, int* popSongs, int ARRAY_SIZE) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int j = 0; j < 5; j++) {
			popSongs[vetor[i].choices[j] - 1]++;
		}
	}
	shellsort(popSongs, SONG_AMOUNT);
}

void printMostPopSongs(int* musics) {
	int place = 1;
	for (int i = 0; i < 30; i++) {
		char line[70];
		if (musics[i] == 0)
			continue;
		strcpy(line, getNthFileLine(fopen("../config/songs.txt", "r"), i + 1));
		printf("%d° lugar - %d votos: %s", place, musics[i], line);
		place++;
	}
}

int main(int argc, char *argv[]) {
	SetConsoleOutputCP(65001);
	
	FILE* research = fopen("../config/pesq.txt", "r");

	if (!research) {
		perror("Erro ao abrir o arquivo research.txt");
		exit(EXIT_FAILURE);
	}

	unsigned int peopleCount = countLines(fopen("../config/pesq.txt", "r"));
	person pessoas[peopleCount];
	char line[50];

	for (int i = 0; i < peopleCount; i++) {
		if (!fgets(line, 70, research)) {
			continue;
		}

		strtok(line, "\t");
		pessoas[i].sex = line[0];
		pessoas[i].age = atoi(strtok(NULL, "\t"));
		strcpy(pessoas[i].name, strtok(NULL, "\t"));
		for (int j = 0; j < 5; j++) {
			pessoas[i].choices[j] = atoi(strtok(NULL, "\t"));
		}
	}
	shellsortPerson(pessoas, peopleCount);
	fclose(research);
	FILE* songs = fopen("../config/songs.txt", "r");
	
	if (!songs) {
		perror("Erro ao abrir o arquivo songs.txt");
		exit(EXIT_FAILURE);
	}

	int popSongs[SONG_AMOUNT] = {0};
	mostPopularSongs(pessoas, popSongs, peopleCount);
	printMostPopSongs(popSongs);
	fclose(songs);
	system("pause");
	return 0;
}