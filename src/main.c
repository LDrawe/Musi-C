#include <stdio.h>
#include <windows.h>

int countLines(FILE* arq) {
    int c;    
    int count = 0;

     while ((c = getc(arq)) != EOF) 
        if (c == '\n')
            count++;
    return count + 1;
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

    printf("Quantidade de linhas de música: %d\n", countLines(songs));
    printf("Quantidade de linhas de pesquisa: %d\n", countLines(research));

    fclose(songs);
    fclose(research);
    system("pause");
    return 0;
}