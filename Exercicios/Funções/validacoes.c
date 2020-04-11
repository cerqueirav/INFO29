#include <stdio.h>
#include <stdlib.h>
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

int validacaoFinalCpf(int cpfInt[], int n){
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

int validacaoComplementarCpf(char cpfStr[], int size){
    int contPonto=0, contHifen=0;
    // Cpf com caracteres especiais
    if (size==14){
        int indAux=0;
        while (indAux < size){
            if (ehCaracterDeCpf(cpfStr[indAux])){
                if (cpfStr[indAux]=='.')
                    contPonto++;
                
                if (cpfStr[indAux]=='-')
                    contHifen++;
                
                indAux++;
            }
            else
                return ERRO_CPF_INVALIDO;
        }
    
        // Validacao complementar
        if ((contPonto != 2) || (contHifen != 1))
            return ERRO_CPF_INVALIDO;
    }
    // Cpf sem caracteres especiais
    else if (size==11){
        int indAux=0;
        while (indAux < size){
            if (isdigit(cpfStr[indAux]))
                indAux++;
            else
                return ERRO_CPF_INVALIDO;
        }
    }
    return SUCESSO_CADASTRO;
}

int validarCpf(char cpfStr[]){
    int cpfInt[12], indice=0, pos=0;
    int size = strlen(cpfStr);
    
    // Verifica se o CPF está incompleto ou com numeros em excesso
    if ((size != 11) && (size != 14))
        return ERRO_CPF_INVALIDO;
    
    // Validacao parcial (caracteres invalidos)
    int retorno = validacaoComplementarCpf(cpfStr, size);
    if (retorno==ERRO_CPF_INVALIDO)
        return ERRO_CPF_INVALIDO;
    
    // Cpf inserido no seguinte padrao -> 123.456.789-01
    if (size==14){
        // Convert nine cpf's digits to new char's vector
        while (cpfStr[indice] != '-'){
            if (cpfStr[indice] != '.')
                cpfInt[pos++] = cpfStr[indice++] - 48;
            else
                indice++;
        }
        
        // Encontra ambos digitos verificadores do CPF
        indice++;
        while(indice < size){
            if (indice < size-1)
                cpfInt[pos++] = cpfStr[indice++] - 48;
            else
                cpfInt[pos++] = cpfStr[indice++] - 48;
        }
    }
        
    // Cpf inserido sem caracteres especiais
    indice = 0;
    if (size==11){
        while (indice != 11){
            cpfInt[indice] = cpfStr[indice] - 48;
            indice++;
        }
    }
        
    //  Validacao final
    int codVerificador[2]; pos=0;
    
    // Primeira etapa (Find DVs - Digitos Verificadores)
    while (pos < 2){
        codVerificador[pos++] = validacaoFinalCpf(cpfInt, pos+10);
    }
    
    // Ultima etapa (Compara ambos DVs com o do CPF informado)
    if ((codVerificador[0]==cpfInt[9]) && (codVerificador[1]==cpfInt[10]))
        return SUCESSO_CADASTRO;
    else
        return ERRO_CPF_INVALIDO;
}

int validarDataEtapas(int dia, int mes, int ano){
    if ((dia < 0) || (mes < 0) || (ano < 0))
        return ERRO_DATA_INVALIDA;
    
    if ((dia > 31) || (mes > 12))
        return ERRO_DATA_INVALIDA;
    
    if ((ano < 10) || ((ano > 99) && (ano < 1000)))
        return ERRO_DATA_INVALIDA;
    
    return SUCESSO_CADASTRO;
}

int validarData(char data[]){
    char sDia[3], sMes[3], sAno[5];
    
    // Validacao previa da data
    int indice=0;
    for(; indice < strlen(data); indice++){
        if ((!isdigit(data[indice])) && (data[indice] != '/'))
            return ERRO_DATA_INVALIDA;
    }
    
    // Recort string to date (Day)
    indice=0;
    for (; data[indice] != '/'; indice++){
        if (indice < 2)
            sDia[indice] = data[indice];
        else
            return ERRO_DATA_INVALIDA;
    }
    sDia[indice++] = '\0';
    
    // Recort string to date (Month)
    int indAux=0;
    for (; data[indice] != '/'; indice++, indAux++){
        if (indAux < 2){
            sMes[indAux] = data[indice];
        }
        else{
            return ERRO_DATA_INVALIDA;
        }
    }
    sMes[indAux] = '\0';
    indice++;
    
    // Recort string to date (Year)
    indAux=0;
    
    for (; indice<strlen(data); indice++, indAux++){
        if (indAux < 4){
            sAno[indAux] = data[indice];
        }
    }
    sAno[indAux] = '\0';
    
    // Change date char to int
    int iDia = atoi(sDia);
    int iMes = atoi(sMes);
    int iAno = atoi(sAno);
    
    int retorno = validarDataEtapas(iDia, iMes, iAno);
    if (retorno==ERRO_DATA_INVALIDA)
        return ERRO_DATA_INVALIDA;
    
    return SUCESSO_CADASTRO;
}

int ehBissexto(int mes, int ano){
    
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
