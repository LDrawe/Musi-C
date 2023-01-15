#ifndef TYPES_H
#define TYPES_H

typedef struct person {
	char sex;
	unsigned short int age;
	char name[30];
	int choices[5];
} person;

typedef struct songData {
	int index;
	int votes;
} songData;

#endif