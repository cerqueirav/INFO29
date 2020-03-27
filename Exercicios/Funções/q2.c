#include <stdio.h>
#define TAM 3

void getDados(float *v1, float *v2, float *v3);
void printResultado(float resultado);
float subtrair(float v1, float v2, float v3);


int main(){
    float v1, v2, v3;
    
    getDados(&v1, &v2, &v3);
    
    printResultado(subtrair(v1, v2, v3));
    
    return 0;
}

float subtrair(float v1, float v2, float v3){
    return (v1-v2-v3);
}

void getDados(float *v1, float *v2, float *v3){
    printf("Informe o primeiro valor : ");
    scanf("%f", v1);
    
    printf("Informe o segundo valor : ");  
    scanf("%f", v2);
    
    printf("Informe o terceiro valor : ");
    scanf("%f", v3);
}

void printResultado(float resultado){
    printf("Resultado da subtracao -> %.2f", resultado);
}
