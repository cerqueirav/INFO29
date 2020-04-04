#include <stdio.h>
#include <string.h>
#include "utils.h"
#define ERRO_OPCAO_INVALIDA -7
#define ERRO_DATA_INVALIDA -6
#define ERRO_SEXO_INVALIDO -5
#define ERRO_CPF_INVALIDO -4
#define ERRO_NOME_INVALIDO -3
#define ERRO_LISTA_VAZIA -2
#define SUCESSO_CADASTRO 1
#define FIM 3

int validarCpf_Etapas(int cpfInt[], int n){
    int indice=0, aux=n, digitV=0;
    // Realiza aritmetica (somatorio e produto)
    while (indice != n-1){
        digitV += cpfInt[indice] * aux;
        aux--;
        indice++;
    }
    
    digitV = (digitV*10)%11;
    
    if (digitV != 10)
        return digitV;
    else
        return 0;
}

int validarCpf(char cpfStr[]){
    int size = strlen(cpfStr);
    
    // Verifica se o CPF está incompleto ou com numeros em excesso
    if ((size < 11) || (size > 15))
        return ERRO_CPF_INVALIDO;
    
    /* Transformar string com caracteres em vetor de int...
    else if (size==15)
        // construir...
    */
    
    // Caso o CPF seja inserido sem caracteres especiais '-' ou '.'
    int cpfInt[16], indice=0;
    
    if (size==11)
        while (indice != 11){
            cpfInt[indice] = cpfStr[indice] - 48;
            indice++;
        }
        
    // -> Processo de Validacao
    int codVerificador[2], pos=0;
    // Primeira etapa
    while (pos < 2){
        codVerificador[pos++] = validarCpf_Etapas(cpfInt, pos+10);
    }
    
    if ((codVerificador[0]==cpfInt[9]) && (codVerificador[1]==cpfInt[10]))
        return SUCESSO_CADASTRO;
    else
        return ERRO_CPF_INVALIDO;
}

int validarData(char data[]){
    char sDia[3], sMes[3], sAno[5];
    int iDia, iMes, iAno, indice=0;
    
    for (; data[indice] != '/'; indice++){     
        sDia[indice] = data[indice++];
    }
    
    sDia[indice] = '\0';
    
    
    return SUCESSO_CADASTRO;
}

int validarNome(char nome[]){
    int tamanho = strlen(nome);
    if ((tamanho > 20) || (tamanho <= 0))
        return ERRO_NOME_INVALIDO;
    
    int indice=0;
    while (indice != tamanho){
        if (!ehLetra(nome[indice]))
            return ERRO_NOME_INVALIDO;
        
        indice++;
    }
    return SUCESSO_CADASTRO;
}

int validarOpcao(int opcao){
    if ((opcao > 0) && (opcao <= FIM))
        return opcao;
    else
        return ERRO_OPCAO_INVALIDA;
}

int validarSexo(char sexo[]){
    sexo[0] = toupper(sexo[0]);
    int size = strlen(sexo);
    if ((size < 1) || (size > 1))
        return ERRO_SEXO_INVALIDO;
    
    if (size==1)
        if ((sexo[0]=='F') || (sexo[0]=='M') || (sexo[0]=='O'))
            return SUCESSO_CADASTRO;
    
    return ERRO_SEXO_INVALIDO;
}

int retornaFuncao(int opcao, int retorno){
    switch(opcao){
        // Retorno da funcao "Cadastrar cliente"
        case 1:{
            switch(retorno){
                case SUCESSO_CADASTRO:{
                    printf("Cadastrado com sucesso!\n"); break;
                }
                case ERRO_NOME_INVALIDO:{
                    printf("\nErro! Nome invalido!\n"); break;
                }
                case ERRO_CPF_INVALIDO:{
                    printf("\nErro! CPF invalido!\n"); break;
                }
                case ERRO_SEXO_INVALIDO:{
                    printf("\nErro! Sexo invalido!\n"); break;
                }
                case ERRO_DATA_INVALIDA:{
                    printf("\nErro! Data invalida!\n"); break;
                }
            }
            break;
        }
    }
}
