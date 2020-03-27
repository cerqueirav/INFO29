#include <stdio.h>
#define TAM 3

char insereLetras(char *vetorLetras);
void printLetras(char vetorLetras[]);
char writeUserInfo(int atualPos);

int main(){
    char vetLet[TAM];

    insereLetras(vetLet);
    
    printLetras(vetLet);
    
    return 0;
}

char insereLetras(char *vetorLetras){
    int indice=0;
    
    while (indice != TAM){
        vetorLetras[indice++] = writeUserInfo(indice);
    }
}

void printLetras(char vetorLetras[]){
    int indice=0;
    
    while (indice != TAM){
        printf("%c", vetorLetras[indice++]);
    }
}

char writeUserInfo(int atualPos){
    char letra;
    printf("Informe a %d letra : ", atualPos);
    scanf("%c", &letra);
    getchar();
    return letra;
}
