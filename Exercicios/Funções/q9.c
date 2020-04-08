#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "validacoes.h"
#define ERRO_OPCAO_INVALIDA -7
#define ERRO_LISTA_VAZIA -2
#define ERRO_OVERFLOW -1
#define SUCESSO_CADASTRO 1
#define FIM 3

typedef struct client{
    char nome[22];
    char data_nasc[12];
    char cpf[16];
    char sexo;
    int status;
}Cliente;

typedef struct no{
    Cliente cliente;
    struct no *prox;
}No;

void carregaFuncao(No **head, int opcao);
Cliente criarCliente();
int inserirClienteNoFinal(No **head);
void listarCliente(No *head);
void menuPrincipal(No **head);
int qtdClientesNaLista(No *head);

int main(){
    No *head = NULL;
    char data[12];
    
    strcpy(data, "12/02/1998");
    
    int ret = validarData(data);
    
   // menuPrincipal(&head);
    
    return 0;
}

void carregaFuncao(No **head, int opcao){
    if (opcao!=ERRO_OPCAO_INVALIDA){
        switch(opcao){
            case 1:{
                retornaFuncao(opcao, inserirClienteNoFinal(head)); break;
            }
            
            case 2:{
                listarCliente(*head); break;
            }
        }
    }
    else{
        printf("\nErro! Opcao invalida\n");
    }
}

Cliente criarCliente(){
    int retorno;
    Cliente cliente;
    printf("\n# Cadastro de Cliente #\n");
    // -> Dados do novo cliente
    
    // Nome 
    printf("\n-> Informe o Nome : ");
    fgets(cliente.nome, 22, stdin);
    limparBuffer(cliente.nome);
    
    // Validacao do Nome
    retorno = validarNome(cliente.nome);
    if (retorno!=SUCESSO_CADASTRO){
        cliente.status = retorno;
        return cliente;
    }
    
    // Data de Nascimento
    printf("-> Informe a Data de Nascimento : ");
    fgets(cliente.data_nasc, 12, stdin);
    limparBuffer(cliente.data_nasc);
    
    // Criar validacao...
    
    // CPF
    printf("-> Informe o CPF : ");
    fgets(cliente.cpf, 16, stdin);
    limparBuffer(cliente.cpf);
    
    // Validacao do CPF
    retorno = validarCpf(cliente.cpf);
    if (retorno!=SUCESSO_CADASTRO){
        cliente.status = retorno;
        return cliente;
    }    
    
    // Sexo
    char sexo[3];
    printf("-> Informe o Sexo : ");
    fgets(sexo, 3, stdin);
    limparBuffer(sexo);
    
    // Validacao do Sexo
    retorno = validarSexo(sexo);
    if (retorno!=SUCESSO_CADASTRO){
        cliente.status = retorno;
        return cliente;
    }
    else{
        cliente.sexo = sexo[0];
    }
    
    cliente.status = SUCESSO_CADASTRO; 
    
    return cliente;
}

int inserirClienteNoFinal(No **head){
    No *novo;
    
    novo = (No*) malloc(sizeof(No));
    
    if (novo==NULL){
        return ERRO_OVERFLOW;
    }
    
    // Verificar quando houver erro no retorno
    novo->cliente = criarCliente();
    
    if (novo->cliente.status==SUCESSO_CADASTRO){
        if (*head==NULL){
            *head = novo;
            novo->prox = NULL;
        }
        else{
            No *aux = *head;
            
            while (aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
            novo->prox = NULL;
        }
        return SUCESSO_CADASTRO;
    }
    else{
        int ERRO_CADASTRO = novo->cliente.status;
        free(novo);
        return ERRO_CADASTRO;
    }
}

void listarCliente(No *head){
    if (head==NULL)
        printf("A lista esta vazia\n");
    else{
        No *aux = head;
        printf("\n# Clientes cadastrados #");
        printf("\n_____\n");
        while(aux != NULL){
            printf("\n-> Nome: %s\n-> Data de nascimento: %s\n-> CPF: %s\n-> Sexo: %c\n",  
                // Dados do cliente
                aux->cliente.nome,
                aux->cliente.data_nasc,
                aux->cliente.cpf,
                aux->cliente.sexo);
            
            printf("_____\n");
            // Incremento da lista
            aux = aux->prox;
        }
    }
}

void menuPrincipal(No **head){
    int opcao;
    do{
        printf("\n## Menu Geral ##\n");
        printf("\n1 -> Cadastrar cliente\n");
        printf("2 -> Listar clientes\n");
        printf("3 -> Sair\n");
        
        // Captura e valida a opcao do usuario
        opcao = validarOpcao(writeUserOption());
        
        // Chama funcao correspodente
        carregaFuncao(head, opcao);
    
    }while(opcao != FIM);
}

int qtdClientesNaLista(No *head){
    if (head==NULL)
        return ERRO_LISTA_VAZIA;
    
    int size=0;
    No *aux = head;
    while (aux != NULL){
        aux = aux->prox;
        size++;
    }
    return size;
}

