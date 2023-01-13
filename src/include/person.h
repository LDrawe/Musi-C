#ifndef PERSON_H
#define PERSON_H
typedef struct person {
	char sex;
	unsigned short int age;
	char name[30];
	int choices[5];
} person;
#endif