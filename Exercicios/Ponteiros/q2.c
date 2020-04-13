#include <stdio.h>

void trocaNumeros(float *a, float *b);
void recebeDoisNumeros(float *num1, float *num2);
void imprimiNumeros(float a, float b);

int main(){
    float n1=2, n2=5;
    
    // Insere valores nas variaveis
    recebeDoisNumeros(&n1, &n2);
    
    // Troca valores 
    trocaNumeros(&n1, &n2);
    
    // Imprimi valores 
    imprimiNumeros(n1, n2);
    
    return 0;
}

void recebeDoisNumeros(float *num1, float *num2){
    printf("-> Informe o primeiro numero : ");
    scanf("%f", num1);
    
    printf("-> Informe o segundo numero : ");
    scanf("%f", num2);
}

void trocaNumeros(float *a, float *b){
    float c;
    c = *a;
    *a = *b;
    *b = c;
}

void imprimiNumeros(float a, float b){
    printf("\n** Valores **\n");
    printf("-> Primeiro: %.2f\n-> Segundo: %.2f", a, b);
}
