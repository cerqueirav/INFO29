#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limparBuffer(char string[]){
    size_t ln = strlen(string) - 1; //size_t = unsigned integer type
    if (string[ln] == '\n')
        string[ln] = '\0';
}

int ehLetra(char letra){
    // Alfabeto de A-Z
    letra = toupper(letra); // Upcase
    if ((letra > 64) && (letra < 91) || (letra==32))
        return 1;
    
    return 0;
}

int writeUserOption(){
    int op;
    printf("Informe a opcao: ");
    scanf("%d", &op);
    getchar();
    return op;
}

char writeUserInfoChar(){
    char info;
    scanf("%c", &info);
    return info;
}
