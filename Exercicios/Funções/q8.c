#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERRO_OPCAO_INVALIDA -3
#define SEXO_INVALIDO -2
#define ERRO_OVERFLOW -1
#define SUCESS 1
#define FIM 3

typedef struct client{
    char nome[100];
    char data_nasc[12];
    char cpf[20];
    char sexo;
}Cliente;

typedef struct no{
    Cliente cliente;
    struct no *prox;
}No;

void carregaFuncao(No **head, int opcao);
Cliente criarCliente();
int inserirClienteNoFinal(No **head);
void listarCliente(No **head);
void menuPrincipal(No **head);
int validaOpcao(int opcao);
int writeUserOption();

int main(){
    No *head = NULL;
    
    menuPrincipal(&head);
    
    return 0;
}

Cliente criarCliente(){
    Cliente cliente;
    printf("\n# Cadastro de Cliente #\n");
    
    // Nome
    printf("\n-> Informe o Nome : ");
    fgets(cliente.nome, 100, stdin);
    size_t ln = strlen(cliente.nome) - 1; //size_t = unsigned integer type
    if (cliente.nome[ln] == '\n')
        cliente.nome[ln] = '\0';
    
    // Data de Nascimento
    printf("-> Informe a Data de Nascimento : ");
    fgets(cliente.data_nasc, 12, stdin);
    ln = strlen(cliente.data_nasc) - 1;
    if (cliente.data_nasc[ln] == '\n')
        cliente.data_nasc[ln] = '\0';
    
    // CPF
    printf("-> Informe o CPF : ");
    fgets(cliente.cpf, 20, stdin);
    ln = strlen(cliente.cpf) - 1;
    if (cliente.cpf[ln] == '\n')
        cliente.cpf[ln] = '\0';
        
    // Sexo
    printf("-> Informe o Sexo : ");
    scanf("%c", &cliente.sexo);
    getchar();
    
    // Validacao de Sexo
    
    // if ((cliente.sexo != 'M') && (cliente.sexo != 'F'))
    
    return cliente;
}

int inserirClienteNoFinal(No **head){
    No *novo;
    
    novo = (No*) malloc(sizeof(No));
    
    if (novo==NULL)
        return ERRO_OVERFLOW;
    
    // Verificar quando houver erro no retorno
    novo->cliente = criarCliente();
    
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
    }
    return SUCESS;
}

void listarCliente(No **head){
    if (*head==NULL)
        printf("\nLista vazia!\n");
    else{
        No *aux = *head;
        printf("\n# Clientes cadastrados #");
        printf("\n_____________________________________\n");
        while(aux != NULL){
            printf("\n-> Nome: %s\n-> Data de nascimento: %s\n-> CPF: %s\n-> Sexo: %c\n",  
                // Dados do cliente
                aux->cliente.nome,
                aux->cliente.data_nasc,
                aux->cliente.cpf,
                aux->cliente.sexo);
            
            printf("_____________________________________\n");
            // Incremento da lista
            aux = aux->prox;
        }
    }
}

void menuPrincipal(No **head){
    int opcao;
    do{
        printf("\n1 -> Cadastrar cliente\n");
        printf("2 -> Listar clientes\n");
        printf("3 -> Sair\n");
        
        // Captura e valida a opcao do usuario
        opcao = validaOpcao(writeUserOption());
        
        // Chama funcao correspodente
        carregaFuncao(head, opcao);
    
    }while(opcao != FIM);
}

int writeUserOption(){
    int op;
    printf("Informe a opcao: ");
    scanf("%d", &op);
    getchar();
    return op;
}

void carregaFuncao(No **head, int opcao){
    if (opcao!=ERRO_OPCAO_INVALIDA)
        switch(opcao){
            case 1:{
                inserirClienteNoFinal(head); break;
            }
            
            case 2:{
                listarCliente(head); break;
            }
        }
    else
        printf("Erro! Opcao invalida\n");
}

int validaOpcao(int opcao){
    if ((opcao > 0) && (opcao <= FIM))
        return opcao;
    else
        return ERRO_OPCAO_INVALIDA;
}



