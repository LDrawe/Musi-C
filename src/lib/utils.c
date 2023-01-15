#include <stdio.h>
#include <ctype.h>
#include "types.h"

int isDuplicate(int* vet, int choice) {
	for (int i = 0; i < 5; i++)
		if (vet[i] == choice)
			return 1;
	
	return 0;
}

int countLines(FILE* arq) {
	char line[50];
	int count = 0;

	 while (fgets(line, 49, arq))
		if (strcmp(line, "") || strcmp(line, "\n"))
			count++;
	return count;
}

int getAge() {
	unsigned short int age = 0;
	while (age < 13) {
		printf("Digite sua idade (Apenas maiores de 13): ");
		scanf("%hd", &age);
	}
	return age;
}

char getSex() {
	char sex = 'H';
	do {
		printf("Digite seu sexo (H ou M): ");
		sex = toupper(getchar());
	} while (sex != 'H' && sex != 'M');

	return sex;
}

void printPersons(person* pessoas, int ARRAY_SIZE) {
	for(int i = 0; i < ARRAY_SIZE; i++) {
		printf("%c %d %s", pessoas[i].sex, pessoas[i].age, pessoas[i].name);
		for (int j = 0; j < 5; j++) {
			printf(" %d", pessoas[i].choices[j]);
		}
		printf("\n");
	}
}