#include <stdio.h>
#include <ctype.h>

int isDuplicate(int* vet, int choice) {
    for (int i = 0; i < 5; i++)
        if (vet[i] == choice)
            return 1;
    
    return 0;
}

int getAge() {
    unsigned short int age = 0;
    while (age < 13) {
        printf("Digite sua idade (Apenas maiores de 13): ");
        scanf("%d", &age);
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