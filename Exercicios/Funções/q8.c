#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SEXO_INVALIDO -2
#define ERRO_OVERFLOW -1
#define SUCESS 1

typedef struct client{
    char nome[100];
    char data_nasc[12];
    int cpf;
    char sexo;
}Cliente;

typedef struct no{
    Cliente cliente;
    struct no *prox;
}No;

int cadastrarCliente(No **inicio);
void listaCliente(No *li);

int main(){
    No *inicio = NULL;
    
    cadastrarCliente(&inicio);
    
    listaCliente(inicio);
    
    return 0;
}

int cadastrarCliente(No **inicio){
    No *novo;
    novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL)
        return ERRO_OVERFLOW;
    
    // Nome
    printf("-> Informe o Nome : ");
    fgets(novo->cliente.nome, 100, stdin);
    size_t ln = strlen(novo->cliente.nome) - 1; //size_t = unsigned integer type
    if (novo->cliente.nome[ln] == '\n')
        novo->cliente.nome[ln] = '\0';
    
    // Data de Nascimento
    printf("-> Informe a Data de Nascimento : ");
    fgets(novo->cliente.data_nasc, 12, stdin);
    if (novo->cliente.data_nasc[ln] == '\n')
        novo->cliente.data_nasc[ln] = '\0';
    
    // Cpf
    printf("-> Informe o CPF : ");
    scanf("%d", novo->cliente.cpf);
    
    // Sexo
    printf("-> Informe o Sexo (M - Masculino ou F - Feminino) : ");
    scanf("%c", &novo->cliente.sexo);
    
    // Validacao de Sexo
    if ((novo->cliente.sexo != 'M') && (novo->cliente.sexo != 'F'))
        return SEXO_INVALIDO;
    
    if (*inicio==NULL){
        *inicio = novo;
        novo->prox = NULL;
    }
    else{
        novo->prox = *inicio;
        *inicio = novo;
    }
    return SUCESS;
}

void listaCliente(No *li){
    No *aux;
    
    aux = li;
    
    while (aux != NULL){
        printf("Nome: %s", aux->cliente.nome);
        printf("Data de nascimento: %s", aux->cliente.data_nasc);
        printf("CPF: %d", aux->cliente.cpf);
        printf("Sexo: %c", aux->cliente.sexo);
        aux = aux->prox;
    }
}
