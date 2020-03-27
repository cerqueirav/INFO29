#include <stdio.h>
#define TAM 4

typedef struct ln{
    int numeros[TAM];
}num_List;

int writeUserInfo(int atualPos);
void printLista(num_List* li);
num_List* insereDados(num_List* li);

int main(){
    num_List novaLista;
    
    printLista(insereDados(&novaLista));
    
    return 0;
}

num_List* insereDados(num_List* li){
    int indice=0;
    
    while (indice != TAM){
        li->numeros[indice++] = writeUserInfo(indice);
    }
    
    return li;
}

void printLista(num_List* li){
    int indice=0;
    printf("Element's list -> ");
    while (indice != TAM){
        printf("%d ", li->numeros[indice++]);
    }
}

int writeUserInfo(int atualPos){
    int value;
    printf("Informe o %d numero : ", atualPos);
    scanf("%d", &value);
    return value;
}

