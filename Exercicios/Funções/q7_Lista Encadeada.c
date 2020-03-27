#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIM 4
#define MAX 3
#define SUCESS 1
#define ERRO_OVERFLOW -1
#define LISTA_VAZIA -2

typedef struct li{
    char* palavra;
    struct li *prox;
}No;

int printLista(No *inicio);
void inicializaFuncao(No **inicio, int opcao);
int inserePalavraNaListaNoInicio(No **inicio);
int inserePalavraNaListaNoFinal(No ** inicio);
void menuPrincipal(No **inicio);
int retornaFuncao(int opcao, int retorno);
int sizeList(No *li);
int writeUserOption();
char* writeUserInfo(char *n);

int main(){
    No *lista = NULL;
    
    menuPrincipal(&lista);
    
    return 0;
}

int inserePalavraNaListaNoInicio(No **inicio){
    if (sizeList(*inicio) < MAX){
        No *elem;
        
        elem = (No*) malloc(sizeof(No));
        
        elem->palavra = (char*) malloc(sizeof(char));
        
        if ((elem==NULL) || (elem->palavra==NULL))
            return ERRO_OVERFLOW;
        
        printf("Informe a nova palavra : ");
        scanf("%s", elem->palavra);
        
        if (*inicio == NULL){
            *inicio = elem;
            elem->prox = NULL;
            return SUCESS;
        }
        else{
            elem->prox = *inicio;
            *inicio = elem;
            return SUCESS;
        }
    }
    return ERRO_OVERFLOW;
}

int inserePalavraNaListaNoFinal(No ** inicio){
    if (sizeList(*inicio) < MAX){
        No *novo;
        
        novo = (No*) malloc(sizeof(No));
        
        novo->palavra = (char*) malloc(sizeof(char));
        
        if ((novo==NULL) || (novo->palavra==NULL)){
            return ERRO_OVERFLOW;
        }
        
        printf("Informe a palavra : ");
        scanf("%s", novo->palavra);
        
        novo->prox = NULL;
        
        if (*inicio==NULL)
            *inicio = novo;
        else{
            No *aux = *inicio;
            
            while (aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        return SUCESS;
    }
    else{
        return ERRO_OVERFLOW;
    }
    
}

int printLista(No *inicio){
    No *aux = inicio;
    if (inicio == NULL)
        return LISTA_VAZIA;
    while (aux != NULL){
        if (aux==inicio){
            printf("Lista de palavras -> %s", aux->palavra);
            aux = aux->prox;
        }else{
            printf(", %s", aux->palavra);
            aux = aux->prox;
        }
    }
}

void menuPrincipal(No **inicio){
    int opcao;
    do{
        printf("\n1 - Inserir nova palavra\n");
        printf("2 - Listar todas palavras\n");
        printf("3 - Tamanho da lista\n");
        printf("4 - Sair\n");
        
        // Recebe a opcao do usuario
        opcao = writeUserOption();
        
        inicializaFuncao(inicio, opcao);
            
    }while(opcao != FIM); 
}

void inicializaFuncao(No **inicio, int opcao){
     switch(opcao){
            // Chamada da funcao "Inserir"
            case 1:{
                //retornaFuncao(opcao, inserePalavraNaListaNoInicio(inicio)); // Insercao no inicio
                retornaFuncao(opcao, inserePalavraNaListaNoFinal(inicio)); // Insercao no final
                break;
            }
            
            // Chamada da funcao "Listar"
            case 2:{
                retornaFuncao(opcao, printLista(*inicio));
                break;
            }
            
            // Chamada da funcao "Tamanho"
            case 3:{
                retornaFuncao(opcao, sizeList(*inicio));
            }
    }
}

int retornaFuncao(int opcao, int retorno){
    switch(opcao){
        case 1:{
            // Retorno da funcao "Inserir"
            switch(retorno){
                case SUCESS:{
                    printf("Palavra cadastrada com sucesso !\n"); break;
                }
                
                case ERRO_OVERFLOW:{
                    printf("Nao eh possivel cadastrar, sem espaco!\n"); break;
                }
            }
            break;
        }
        
        //Retorno da funcao "Listar"
        case 2:{
            switch(retorno){
                case LISTA_VAZIA:{
                    printf("Nao eh possivel imprimir, a lista esta vazia!\n"); break;
                }
            }
            break;
        }
        
        //Retorno da funcao "Tamanho"
        case 3:{
            switch(retorno){
                case LISTA_VAZIA:{
                    printf("Nao eh possivel imprimir, a lista esta vazia!\n"); break;   
                }
                
                default:{
                    printf("Tamanho da lista -> %d\n", retorno); break;
                }
            }
        }
    }
}

int writeUserOption(){
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

char* writeUserInfo(char *n){
    scanf("%s", &n);
    return n;
}

int sizeList(No *li){
    int cont=0;
    No *aux = li;
    
    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}
    
