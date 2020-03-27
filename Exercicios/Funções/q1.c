#include <stdio.h>

float getDados();
void printResultado(float resultado);
float soma(float a, float b);

int main(){
    printResultado(soma(getDados(), getDados()));
    return 0;
}

float soma(float a, float b){
    return a+b;
}

float getDados(){
    float number;
    scanf("%f", &number);
    return number;
}

void printResultado(float resultado){
    printf("Resultado da soma -> %.2f", resultado);
}
