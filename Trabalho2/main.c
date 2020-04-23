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
    printf("4 - Montar Lista Encadeada\n");
    printf("5 - Numero total de elementos\n");
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
                
                if (validarPosicao(posicao)){
                    ret = inserirNumeroEmEstrutura(valor, posicao);
                    if (ret == SUCESSO){
                        printf("\n** Inserido com sucesso\n");
                    }else if (ret == SEM_ESPACO){
                        printf("\n* Sem espaco\n");
                    }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                        int tam;
                        printf("\n* Sem estrutura Auxiliar!\n-> Informe o tamanho: ");
                        scanf("%d", &tam);
                        // Cria nova estrutura auxiliar
                        criarEstruturaAuxiliar(tam, posicao);
                        
                        // Insere elemento
                        ret = inserirNumeroEmEstrutura(valor, posicao);
                        if (ret==SUCESSO)
                            printf("\n** Inserido com sucesso\n");
                        else
                            printf("\n* Sem espaco\n");
                        
                    }
                }
                else
                    printf("\n* Posicao invalida\n");
                
                break;
            }

            case 2:{ //excluir
                int posicao, valor, retorno=0;
                printf("\n-> Informe a posicao : ");
                scanf("%d", &posicao);
                
                printf("\n-> Informe o valor a ser excluido : ");
                scanf("%d", &valor);
                
                retorno = excluirNumeroEspecificoDeEstrutura(valor, posicao);
                if (retorno==SUCESSO)
                    printf("** Elemento excluido com sucesso!\n");
                else{
                    retorno = excluirNumeroDoFinaldaEstrutura(posicao);
                    if (retorno==SUCESSO)
                        printf("** Elemento excluido com sucesso!\n");
                    else{
                        // Erros
                        switch(retorno){
                            // Erros 
                            case POSICAO_INVALIDA:{
                                printf("Posicao invalida\n"); break;
                            }
                            
                            case ESTRUTURA_AUXILIAR_VAZIA:{
                                printf("Estrutura vazia\n"); break;
                            }
                            
                            case SEM_ESTRUTURA_AUXILIAR:{
                                printf("Sem estrutura auxiliar\n"); break;
                            }
                        }
                    }
                }
                break;
            }

            case 3:{ //recuperar dados estrutura auxiliar
                int posicao, retorno;
                printf("Qual a estrutura a ser listada (1..10)?");
                scanf("%d", &posicao);
                
                int qtd =  getQuantidadeElementosEstruturaAuxiliar(posicao);
                
                if (qtd < 1){
                    switch(qtd){
                        // Erros 
                        case POSICAO_INVALIDA:{
                            printf("Posicao invalida\n"); break;
                        }
                        
                        case ESTRUTURA_AUXILIAR_VAZIA:{
                            printf("Estrutura vazia\n"); break;
                        }
                        
                        case SEM_ESTRUTURA_AUXILIAR:{
                            printf("Sem estrutura auxiliar\n"); break;
                        }
                    }
                }
                else{ // existe elemento
                    int vetorAux[qtd], size;
                    
                    size = getTamanhoVetorAuxiliar(posicao);
                    
                    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
                    
                    if (retorno == SUCESSO){
                        //imprimir para os dados para o usuário
                        int i = 0;
                        for (; i < qtd; i++){
                            // Formatacao da impressao
                            if (qtd==1)
                                printf ("\n-> Elementos da estrutura : {%d}\n", vetorAux[i]);
                            else{
                                if (i==0)
                                    printf ("\n-> Elementos da estrutura : {%d", vetorAux[i]);
                                else if (i!=qtd-1)
                                    printf(", %d", vetorAux[i]);
                                else
                                    printf(", %d}\n", vetorAux[i]);
                            }
                        }
                        printf("\n-> Numero de elementos: [%d/%d]\n", qtd, size);
                    }                        
                }
                break;
            }
            
            case 4:{
                int qtd = numeroDeElementosTodasAuxiliares();
                No *head = montarListaEncadeadaComCabecote();
                
                if ((qtd > 0) && (head!=NULL)){
                    int vetorAux[qtd], indiceAux=0;
    
                    getDadosListaEncadeadaComCabecote(head, vetorAux);
                    printf("\nSucesso! Lista montada!\n");
                }
                else{
                    printf("\nErro! Nao eh possivel montar!\n");
                }
                
                break;
            }
            
            case 5:{
                int retorno=0;
                
                retorno = numeroDeElementosTodasAuxiliares();
                if (ret>0)
                    printf("\n** Elementos cadastrados: %d\n", ret);
                else
                    printf("\n* Todas estruturas auxiliares estao vazias/nao existem\n");
                    
                break;
            }
            
            default:{
                printf("\n* Opcao invalida\n");
            }

            
        }
        
        
    }
    return 0;
    
}
