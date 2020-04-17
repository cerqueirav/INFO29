#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "EstruturaVetores.h"

int writeUserInfoInt(){
    int info;
    printf("Informe um valor : ");
    scanf("%i", &info);
    return info;
}

int writeUserInfoPosicao(){
    int pos;
    printf("Informe a posicao : ");
    scanf("%i", &pos);
    return pos;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    
    if ((posicao < 1) || (posicao > 10))
        retorno = POSICAO_INVALIDA;
    else 
        retorno = SUCESSO;

    return retorno;
}

int ehTamanhoValido(int tamanho){
    int retorno;
    if (tamanho < 1) 
        retorno = TAMANHO_INVALIDO; 
    else retorno = SUCESSO;
    
    return retorno;
}

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void ajustarIndice(int *indice){
    *indice--;
}
