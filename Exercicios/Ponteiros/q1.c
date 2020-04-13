#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

void limparBuffer(char string[]);
void inserirValorParametro(int numero, char letra, char palavra[], float real, double realPlus);
void inserirValorReferencia(int *numero, char *letra, char palavra[], float *real, double *realPlus);
void printValor(int numero, char letra, char palavra[], float real, double realPlus);

int main(){
    // Variaveis primitivas
    int inteiro;
    char word; 
    char string[TAM];
    float real;
    double realPlus;
    
    // Ponteiros para variaveis
    int *pInt = &inteiro;
    char *pChar = &word;
    char *pString = string;
    float *pReal = &real;
    double *pRealPlus = &realPlus;
        
    // Inserção de valores por parametro (variaveis primitivas)
    inserirValorParametro(inteiro, word, string, real, realPlus);
    
    // Inserção por parametro (ponteiros para variaveis)
    inserirValorParametro(*pInt, *pChar, pString, *pReal, *pRealPlus);
    
    // *Inserção por referencia (variaveis primitivas)
    inserirValorReferencia(&inteiro, &word, string, &real, &realPlus);
    
    // *Inserção por referencia (ponteiros para variaveis)
    inserirValorReferencia(pInt, pChar, pString, pReal, pRealPlus);
    
    return 0;
}

void inserirValorParametro(int numero, char letra, char palavra[], float real, double realPlus){
    // Captura dos dados c/ variaveis primitivas
    printf("\n** Leitura dos dados **\n");
    printf("\n-> Informe um inteiro : ");
    scanf("%i", &numero);
    getchar();
    
    printf("-> Informe um caracter : ");
    scanf("%c", &letra);
    getchar();
    
    printf("-> Informe uma string : ");
    fgets(palavra, TAM, stdin);
    limparBuffer(palavra);
    
    printf("-> Informe um float : ");
    scanf("%f", &real);
    getchar();
    
    printf("-> Informe um float grande : ");
    scanf("%d", &realPlus);
    getchar();
    
    // Realiza a impressao dos dados
    printValor(numero, letra, palavra, real, realPlus);
}

void inserirValorReferencia(int *numero, char *letra, char palavra[], float *real, double *realPlus){
    // Captura dos dados c/ variaveis primitivas
    printf("\n** Leitura dos dados **\n");
    printf("\n-> Informe um inteiro : ");
    scanf("%i", numero);
    getchar();
    
    printf("-> Informe um caracter : ");
    scanf("%c", letra);
    getchar();
    
    printf("-> Informe uma string : ");
    fgets(palavra, TAM, stdin);
    limparBuffer(palavra);
    
    printf("-> Informe um float : ");
    scanf("%f", real);
    getchar();
    
    printf("-> Informe um float grande : ");
    scanf("%d", realPlus);
    getchar();
    
    // Realiza a impressao dos dados
    printValor(*numero, *letra, palavra, *real, *realPlus);
}

void printValor(int numero, char letra, char palavra[], float real, double realPlus){
    // Imprimir os dados com dados primitivos
    printf("\n** Impressao dos dados ** \n");
    printf("-> Inteiro: %i\n", numero);
    printf("-> Caracter: %c\n", letra);
    printf("-> String: %s\n", palavra);
    printf("-> Float: %.2f\n", real);
    printf("-> Double: %d\n", realPlus);
}

void limparBuffer(char string[]){
    size_t ln = strlen(string) - 1; //size_t = unsigned integer type
    if (string[ln] == '\n')
        string[ln] = '\0';
}
