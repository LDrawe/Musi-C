#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void shellsortChoices(person* pessoas, int ARRAY_SIZE) {
	for (int n = 0; n < ARRAY_SIZE; n++) {
		for (int interval = 5 / 2; interval > 0; interval /= 2) {
			for (int i = interval; i < 5; i++) {
				int temp = pessoas[n].choices[i];
				int j;
				for (j = i; j >= interval && pessoas[n].choices[j - interval] > temp; j -= interval) {
					pessoas[n].choices[j] = pessoas[n].choices[j - interval];
				}
				pessoas[n].choices[j] = temp;
			}
		}
	}
}

void sortSex(person* pessoas, int ARRAY_SIZE) {
	 for (int i = 1; i < ARRAY_SIZE; i++) {
		
		person currentValue = pessoas[i];
		int backwards = i - 1;

		while (backwards >= 0 && pessoas[backwards].sex > currentValue.sex) {
			pessoas[backwards + 1] = pessoas[backwards];
			backwards--;
		}

		pessoas[backwards + 1] = currentValue;
	}
	shellsortChoices(pessoas, ARRAY_SIZE);
}

void shellsortPerson(person* pessoas, int ARRAY_SIZE) {
	for (int interval = ARRAY_SIZE / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < ARRAY_SIZE; i++) {
			person temp = pessoas[i];
			int j;
			for (j = i; j >= interval && pessoas[j - interval].age > temp.age; j -= interval) {
				pessoas[j] = pessoas[j - interval];
			}
			pessoas[j] = temp;
		}
	}
	sortSex(pessoas, ARRAY_SIZE); //Como as idades de caada pessoa já está organizada, basta juntar quem for do mesmo sexo em cada parte
}

void shellsortPopSongs(songData* songs, int ARRAY_SIZE) {
	for (int interval = ARRAY_SIZE / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < ARRAY_SIZE; i++) {
			songData temp = songs[i];
			int j;
			for (j = i; j >= interval && songs[j - interval].votes < temp.votes; j -= interval) {
				songs[j] = songs[j - interval];
			}
			songs[j] = temp;
		}
	}
}