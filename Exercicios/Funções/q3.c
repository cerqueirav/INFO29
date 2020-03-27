#include <stdio.h>
#define ERRO_NUMERO_INVALIDO -2

long int fatorial(long int n);
void printInfo(long int fat);
long int writeUserInfo();

int main(){
    
    printInfo(fatorial(writeUserInfo()));
    
    return 0;
}

long int fatorial(long int n){
    if (n < 0)
        return ERRO_NUMERO_INVALIDO;
    if ((n==1) || (n==0))
        return 1;
    else
        return n*fatorial(n-1);
}

long int writeUserInfo(){
    long int info;
    printf("Informe o numero : ");
    scanf("%ld", &info);
    return info;
}

void printInfo(long int fat){
    if (fat==ERRO_NUMERO_INVALIDO) 
        printf("Nao eh possivel calcular!\n");
    else
        printf("Resultado do fatorial -> %ld", fat);
}
