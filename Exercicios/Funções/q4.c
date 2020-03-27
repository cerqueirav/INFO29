#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int* retornaVetor();
void printVetor(int vetor[]);

int main(){
    // Retorna o vetor
    printVetor(retornaVetor());
}

int* retornaVetor(){
    int *vetor, indice=0;
    
    vetor = malloc(sizeof(int)*TAM);
    
    while (indice != TAM){
        scanf("%d", &vetor[indice]);
        indice++;
    }
    
    return vetor;
}

void printVetor(int *vet){
    int indice=0;
    
    while (indice != TAM){
        printf("%d ", vet[indice]);
        indice++;
    }
}



