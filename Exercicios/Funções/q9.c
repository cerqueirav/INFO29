#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERRO_OPCAO_INVALIDA -4
#define ERRO_CPF_INVALIDO -3
#define SEXO_INVALIDO -2
#define ERRO_OVERFLOW -1
#define SUCESSO_CADASTRO 1
#define FIM 3
#define TAM 15

typedef struct client{
    char nome[25];
    char data_nasc[12];
    char cpf[20];
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
void listarCliente(No **head);
void menuPrincipal(No **head);
void limparBuffer(char string[]);
int validarCpf(char cpf[]);
int validarNome(char nome[]);
int validarOpcao(int opcao);
int validarSexo(char sexo);
int writeUserOption();
void printCpf(int cpf[]);
int validarCpf(char cpf[]);
int findDigitV(int cpf[], int dv);

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
    fgets(cliente.nome, 25, stdin);
    limparBuffer(cliente.nome);
    
    // Data de Nascimento
    printf("-> Informe a Data de Nascimento : ");
    fgets(cliente.data_nasc, 12, stdin);
    limparBuffer(client.data_nasc);
    
    // CPF
    printf("-> Informe o CPF : ");
    fgets(cliente.cpf, 20, stdin);
    limparBuffer(cliente.cpf);
        
    // Sexo
    printf("-> Informe o Sexo : ");
    scanf("%c", &cliente.sexo);
    getchar();
    
    
    cliente->status = SUCESSO_CADASTRO; 
    
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
    return SUCESSO_CADASTRO;
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
        printf("\n## Menu Geral ##\n");
        printf("\n1 -> Cadastrar cliente\n");
        printf("2 -> Listar clientes\n");
        printf("3 -> Sair\n");
        
        // Captura e valida a opcao do usuario
        opcao = validaOpcao(writeUserOption());
        
        // Chama funcao correspodente
        carregaFuncao(head, opcao);
    
    }while(opcao != FIM);
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

int validarCpf(char cpf[]){
    int iCpf[12];
    
    int indice=0;
    
    while (indice != strlen(cpf)){
        iCpf[indice] = atoi(cpf[indice++]);  
    }
    
    int indice=0;
    
    while(indice != 12){
        printf("%d | ", iCpf[indice++]);
    }
    
    return SUCESSO_CADASTRO;
}

int validarNome(char nome[]){
    int tamanho = strlen(nome);
    if ((tamanho > 20) || (tamanho <= 0))
        return ERRO_NOME_INVALIDO;
    else
        return SUCESSO_CADASTRO;
}

int validarOpcao(int opcao){
    if ((opcao > 0) && (opcao <= FIM))
        return opcao;
    else
        return ERRO_OPCAO_INVALIDA;
}

int validarSexo(char sexo){
    sexo = toupper(sexo);
    if ((sexo=='M') || (sexo=='F') || (sexo=='O'))
        return SUCESSO_CADASTRO;
    else
        return ERRO_SEXO_INVALIDO;
    
}

void limparBuffer(char string[]){
    size_t ln = strlen(string) - 1; //size_t = unsigned integer type
    if (string[ln] == '\n')
        string[ln] = '\0';
}

int writeUserOption(){
    int op;
    printf("Informe a opcao: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int validarCpf(char cpf[]){
    int iCpf[16], indice=0, dv[2];
    
    int size = strlen(cpf);
    
    if ((size < 11) || (size > 15))
        return ERRO_CPF_INVALIDO;
    
    // Transformar string com caracteres em vetor de int...
    else if (size==15)
        // construir...
        
    // Caso o CPF seja inserido sem caracteres especiais '-' ou '.'
    if (size==11)
        while (indice != 11){
            iCpf[indice] = cpf[indice] - 48;
            indice++;
        }        
    
    // Retorna ambos digitos verificadores para o vetor dv
    int digitPos = 0;
    while (digitPos < 2){
        dv[digitPos] = findDigitV(iCpf, digitPos);
        digitPos++;
    }
    
    // Imprimir CPF
    printf("\nDigitos -> %d , %d\n", dv[0], dv[1]);
    
    printCpf(iCpf);

    return SUCESSO_CADASTRO;
}

int findDigitV(int cpf[], int dv){
    int indice=0, aux, digitV=0;
    // Primeiro passo, verifica qual digito sera verificado
    if (dv==0)
        aux = 10;
    else if (dv==1)
        aux = 11;
        
    // Realiza aritmetica (somatorio e produto)
    while (indice != 9){
        digitV += cpf[indice] * aux;
        aux--;
        if (indice==8){ 
            if (dv==0)
                digitV %= 10;
            else if (dv==1)
                digitV %= 11;
        }
        indice++;
    }
    
    // Verifica digito verificador
    if ((digitV==0) || (digitV==1))
        digitV = 0;
    else
        digitV = 11-digitV;
    
    return digitV;
}

void printCpf(int cpf[]){
    int indice=0;
    
    while (indice != 9){
        printf("%d", cpf[indice]);
        indice++;
    }
}

