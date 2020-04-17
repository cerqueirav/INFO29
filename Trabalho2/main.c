#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"
#include "utils.h"
#define TAM 10

int menu();

int menu(){
    int op;
    printf("\nDigite as opcao desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar uma estrutura\n");
    scanf("%d", &op);
    return op;
}

int main(){
    No listaAuxiliar[TAM];
    
    //inicializar();
    int op;
    int sair = 0;
    int ret;
    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                sair=1;
                finalizar();
                break;
            }
            case 1:{ //inserir
                // OK
                int valor = writeUserInfoInt();
                int posicao = writeUserInfoPosicao();
                
                ret = inserirNumeroEmEstrutura(valor, posicao);
                if (ret == SUCESSO){
                    printf("\nInserido com sucesso\n");
                }else if (ret == SEM_ESPACO){
                    printf("\nSem Espaco\n");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                    int tam;
                    printf("\nSem estrutura Auxiliar, informe o tamanho da estrutura : ");
                    scanf("%d", &tam);
                    // Cria nova estrutura auxiliar
                    criarEstruturaAuxiliar(tam, posicao);
                    
                    // Insere elemento
                    ret = inserirNumeroEmEstrutura(valor, posicao);
                    if (ret==SUCESSO)
                        printf("Inserido com sucesso\n");
                    else
                        printf("Sem espaco\n");
                    
                }
                break;
            }

            case 2:{ //excluir
                //TODO
                // int ret = excluirNumeroEspecificoDeEstrutura(writeUserInfoInt(), writeUserInfoPosicao());

                break;
            }

            case 3:{ //recuperar dados estrutura auxiliar
                int posicao, retorno;
                printf("Qual a estrutura a ser listada (1..10)?");
                scanf("%d", &posicao);
                
                int qtd =  getQuantidadeElementosEstruturaAuxiliar(posicao);
                
                if (qtd == POSICAO_INVALIDA){
                    printf ("Posicao invalida\n");
                }else{ // existe elemento
                    int vetorAux[qtd], size;
                    
                    size = getTamanhoVetorAuxiliar(posicao);
                    
                    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
                    
                    if (retorno == SUCESSO){
                        printf("-> Tamanho: [%d] | Elementos existentes: [%d]\n", size, qtd);
                        //imprimir para os dados para o usuário
                        int i = 0;
                        for (; i < qtd; i++)
                            printf ("%d ", vetorAux[i]);
                    }                        
                }
                break;
            }
            
            default:{
                printf("opcao invalida\n");
            }

            
        }
        
        
    }
    return 0;
    
}
