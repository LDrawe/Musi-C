#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct person {
    char sex;
    unsigned short int age;
    char name[30];
    int choices[5];
} person;

int countLines(FILE* arq) {
    int c;    
    int count = 0;

     while ((c = getc(arq)) != EOF)
        if (c == '\n')
            count++;
    return count + 1;
}

void printPerson(person p) {
    printf("%c\n", p.sex);
    printf("%d\n", p.age);
    printf("%s\n", p.name);

    for (int j = 0; j < 5; j++) {
        printf("%d\n", p.choices[j]);
    }
}

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(65001);
    FILE* songs = fopen("../config/songs.txt", "r");
    
    if (!songs) {
        perror("Erro ao abrir o arquivo songs.txt");
        exit(EXIT_FAILURE);
    }
    
    FILE* research = fopen("../config/pesq.txt", "r");

    if (!research) {
        perror("Erro ao abrir o arquivo research.txt");
        exit(EXIT_FAILURE);
    }

    unsigned int lineCount = countLines(fopen("../config/pesq.txt", "r"));
    person pessoas[lineCount];
    char line[50];

    if (!fgets(line, 70, research)) {
        printf("Deu NULL a linha\n");
    }

    for (int i = 0; i < lineCount; i++) {
        strtok(line, "\t");
        pessoas[i].sex = line[0];
        pessoas[i].age = atoi(strtok(NULL, "\t"));
        strcpy(pessoas[i].name, strtok(NULL, "\t"));
        for (int j = 0; j < 5; j++) {
            pessoas[i].choices[j] = atoi(strtok(NULL, "\t"));
        }
    }
    
    fclose(songs);
    fclose(research);
    system("pause");
    return 0;
}