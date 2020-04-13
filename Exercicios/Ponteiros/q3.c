#include <stdio.h>
#include <stdlib.h>
#include "utils.c"
#define ERRO_SEM_ESPACO -1
#define SUCESSO 1
#define FIM 0
#define MAX 5

int inserirNoVetor(int vector[], int *atualPosicao);
void listarVetor(int vector[], int atualPosicao);
void menuPrincipal(int vet[], int *atualPosicao);
void ordenarVetorComBubble(int vector[], int atualPosicao);

int main(){
    int *vetor, qtdInseridos=0;
    
    vetor = (int*) malloc(sizeof(int));
    
    menuPrincipal(vetor, &qtdInseridos);
    
    return 0;
}

void menuPrincipal(int vet[], int *atualPosicao){
    int op;
    do{
        printf("\n0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Ordenar\n");
        printf("3 - Listar\n");
        
        op = writeUserOption();
        switch(op){
            // Funcao para "inserir"
            case 1:{
                int ret = inserirNoVetor(vet, atualPosicao);
                if (ret!=ERRO_SEM_ESPACO)
                   printf("\nInserido com sucesso!\n");
                else
                    printf("\nSem espaco disponivel\n");
                break;
            }
            
            // Funcao para "ordenar"
            case 2:{
                ordenarVetorComBubble(vet, *atualPosicao); break;
            }
            
            // Funcao para "listar"
            case 3:{
                listarVetor(vet, *atualPosicao); break;
            }
        }
    }while (op != FIM);
}


int inserirNoVetor(int vector[], int *atualPosicao){
    if (*atualPosicao < MAX){
        int valor, indice=0, var;
        
        valor = writeUserInfoInt();
    
        vector[*atualPosicao] = valor;
        *atualPosicao += 1;
        return SUCESSO;
    
    }
    return ERRO_SEM_ESPACO;
}

void listarVetor(int vector[], int atualPosicao){
    int indice=0;
    while (indice < atualPosicao){
        if (indice==0)
            printf("\nElement's list : %d", vector[indice++]);
        else if (indice != atualPosicao-1)
            printf(", %d", vector[indice++]);
        else
            printf(", %d\n", vector[indice++]);
    }
}

void ordenarVetorComBubble(int vector[], int atualPosicao){
    int i, j, aux;
    
    for (i=1; i<atualPosicao; i++)
        for (j=0; j<atualPosicao-1; j++)
            if (vector[j] > vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
}
