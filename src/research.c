#include <stdio.h>
#include <windows.h>
#include "lib/utils.c"

int pickSongs(int* vet) {
    FILE* songs = fopen("../config/songs.txt", "r");
    
    if (!songs) {
        perror("Erro ao abrir o arquivo Songs.txt");
        exit(EXIT_FAILURE);
    }
    
    int choice = 0, lineCount = 1, n = 1;
    char line[50];

    while (fgets(line, 70, songs)) {
        printf("%d) %s", lineCount, line);
        lineCount++;
    }

    // Faz a mesma coisa que o de cima, só que para Linux
    // size_t len = 0;
    // int lineCount = 1;
    // char read;
    // char* line = NULL;
   
    // while ((read = getline(&line, &len, songs)) != -1) { 
    //     printf("%d - %s", lineCount, line);
    //     lineCount++;
    // }

    printf("\n");

    while(n <= 5) {
        printf("Escolha a %d° música: ", n);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 30) {
            printf("Opção inválida, escolha outra!\n");
            continue;
        }

        if (isDuplicate(vet, choice)) {
            printf("Opção já escolhida, escolha outra!\n");
            continue;
        }

        vet[n-1] = choice;
        n++;
    }
    fclose(songs);
    system("clear || cls");
    return 0;
}

int getPersonData() {
    char sex = getSex();
    char nome[15];
    char sobrenome[15];

    printf("Digite seu nome e sobrenome: ");
    scanf("%s %s", nome, sobrenome);

    int age = getAge();
    int choices[5] = {0};
    pickSongs(choices);
    
    FILE* pesq = fopen("../config/pesq.txt","a");

    if (!pesq) {
        perror("Erro ao abrir o arquivo pesq.txt.");
        exit(EXIT_FAILURE);
    }

    // Escreve os dados que o usuário informou no arquivo
    fputc(sex, pesq); 
    fprintf(pesq, "\t%d\t", age);
    fputs(nome, pesq);
    fputc('\t', pesq);
    fputs(sobrenome, pesq);
    
    for (int i = 0; i < 5; i++) fprintf(pesq, "\t%d", choices[i]);

    fclose(pesq);
    return 0;
}

int main() {
    SetConsoleOutputCP(65001);
    return getPersonData();
}