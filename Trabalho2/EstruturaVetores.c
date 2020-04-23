#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "EstruturaVetores.h"
#include "utils.h"

Nodo estruturaVetores[TAM];

int criarEstruturaAuxiliar(int tamanho, int posicao){
    int retorno = SUCESSO;

    // Erro de posicao invalida
    if (!validarPosicao(posicao))
        retorno = POSICAO_INVALIDA;

    // Erro de tamanho invalido
    if (tamanho < 1)
        retorno = TAMANHO_INVALIDO;

    if (retorno==SUCESSO){
        posicao--;
        // Estrutura auxiliar inexistente
        if (estruturaVetores[posicao].lista == NULL){
            estruturaVetores[posicao].lista = (int*) malloc(tamanho*sizeof(int));
            // Verifica alocacao de espaco
            if (estruturaVetores[posicao].lista != NULL){
                estruturaVetores[posicao].tamanho = tamanho;
                retorno = SUCESSO;
            }
            else{
                // Mata o espaço alocado anteriormente
                free(estruturaVetores[posicao].lista);
                retorno = SEM_ESPACO_DE_MEMORIA;
            }
    
        }
        // Estrutura auxiliar existente
        else{
            retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

int inserirNumeroEmEstrutura(int valor, int posicao){
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    
    if (!validarPosicao(posicao)) 
        posicao_invalida = 1;
    else
        posicao--;
    
    if (estruturaVetores[posicao].lista != NULL)
        existeEstruturaAuxiliar = 1;
    
    if (estruturaVetores[posicao].qtdInseridos < estruturaVetores[posicao].tamanho)
        temEspaco = 1;
        
    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else{
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar){
          if (temEspaco){
              int tam = estruturaVetores[posicao].qtdInseridos;
              estruturaVetores[posicao].lista[tam++] = valor;
              
              // Incremento da variavel de controle (qtdInseridos)
              estruturaVetores[posicao].qtdInseridos = tam;
              retorno = SUCESSO;
          }else
              retorno = SEM_ESPACO;
        }else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao){
    int retorno=0;

    if (!validarPosicao(posicao)) 
        retorno = POSICAO_INVALIDA;

    if (!retorno){
        // Correcao de indice
        posicao--;

        if (estruturaVetores[posicao].lista != NULL){
            if (estruturaVetores[posicao].qtdInseridos == 0)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else{
                estruturaVetores[posicao].qtdInseridos--;
                retorno = SUCESSO;
            }
        }
        else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    return retorno;
}


// Construir melhor...

int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
    int retorno=0;

    if (!validarPosicao(posicao)) 
        retorno = POSICAO_INVALIDA;
    
    if (!retorno){
        posicao--;
            if (estruturaVetores[posicao].lista != NULL){
                int tam = estruturaVetores[posicao].qtdInseridos;
                int ret = buscarNumeroNaEstruturaAuxiliar(valor, posicao+1);
    
                if (ret>=0){
                        if((tam==1) || (ret==tam-1)){
                            excluirNumeroDoFinaldaEstrutura(posicao+1);
                            retorno = SUCESSO;
                        }
                        else{
                            int indice;
                            for (indice=ret; indice<tam; indice++){
                                estruturaVetores[posicao].lista[indice] = estruturaVetores[posicao].lista[indice+1]; 
                            }
                            estruturaVetores[posicao].qtdInseridos--;
                            retorno = SUCESSO;
                        }
                }else
                    retorno = ret;
                
            }else
                retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;
    
    if (!validarPosicao(posicao))
        retorno = POSICAO_INVALIDA;
    
    if (!retorno){
        // Correcao de indice
        posicao--;
        
        // Verifica se existe vetor auxiliar
        if (estruturaVetores[posicao].lista != NULL){
            int indice=0;
            while (indice < estruturaVetores[posicao].qtdInseridos){
                vetorAux[indice] = estruturaVetores[posicao].lista[indice];
                indice++;
            }
            retorno = SUCESSO;
        }
        else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    }
        
    return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;

    if (!validarPosicao(posicao))
        retorno = POSICAO_INVALIDA;
        
    if (!retorno){
        retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
        if (retorno==SUCESSO){
            ordenarVetor(vetorAux, getQuantidadeElementosEstruturaAuxiliar(posicao));
        }
    }
    
    return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno=0;
    
    if (todasEstruturasAuxiliaresVazias())
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        int i=0, j=0, pos=0;
        for (j=0; i<10; i++){
            int size = estruturaVetores[i].qtdInseridos;
            for (j=0; j<size; j++){
                vetorAux[pos++] = estruturaVetores[i].lista[j];
            }
            retorno = SUCESSO;
        }
    }
    
    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno=0;
    
    retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    
    if (retorno==SUCESSO)
        ordenarVetor(vetorAux, numeroDeElementosTodasAuxiliares());
    else
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    
    return retorno;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0;
    
    if (!validarPosicao(posicao))
        retorno = POSICAO_INVALIDA;
    
    // Correcao de indice
    posicao--;
        
    int tamF = estruturaVetores[posicao].tamanho + novoTamanho;

    if (tamF < 1)
        retorno = NOVO_TAMANHO_INVALIDO;
    
    if (retorno==0){
        if (estruturaVetores[posicao].lista != NULL){
            // Realiza a realocação de memoria
            estruturaVetores[posicao].lista = (int*) realloc(estruturaVetores[posicao].lista, tamF*sizeof(int));
            
            int qtdIns = estruturaVetores[posicao].qtdInseridos;
            
            if (estruturaVetores[posicao].lista!=NULL){
                if (tamF < qtdIns){
                    estruturaVetores[posicao].tamanho = tamF;
                    estruturaVetores[posicao].qtdInseridos = tamF;
                    retorno = SUCESSO;
                }
                else{
                    estruturaVetores[posicao].tamanho = tamF;
                    retorno = SUCESSO;
                }
            }
            else
                retorno = SEM_ESPACO_DE_MEMORIA;
        }else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    return retorno;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int retorno = 0;

    if (!validarPosicao(posicao))
        retorno = POSICAO_INVALIDA;
    
    // Correcao de Indice
    posicao--;
    
    if (!retorno){
        if (estruturaVetores[posicao].lista != NULL){
            if (estruturaVetores[posicao].qtdInseridos == 0)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else
                retorno = estruturaVetores[posicao].qtdInseridos;
        }
        else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    return retorno;
}

int todasEstruturasAuxiliaresNaoExistem(){
    int retorno=0;
    
    if (todasEstruturasAuxiliaresVazias())
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        int indice=0, contNaoExistentes=0;
        while(indice < TAM){
            if (estruturaVetores[indice++].lista==NULL)
                contNaoExistentes++;
        }
        
        if (contNaoExistentes==TAM)
            retorno = TODAS_ESTRUTURAS_AUXILIARES_INEXISTENTES;
        else
            retorno = SUCESSO;
    }
    
    return retorno;
}

int todasEstruturasAuxiliaresVazias(){
    int indice, contVazias=0, retorno=0;
    
    for (indice=0; indice<10; indice++)
        if (estruturaVetores[indice].qtdInseridos ==0)
            contVazias++;
    
    if (contVazias==TAM)
        retorno = 1;
    else
        retorno = 0;
    
    return retorno;
}

No *montarListaEncadeadaComCabecote(){
    int i, j, size;
    No *inicio = (No*)malloc(sizeof(No)); 
    
    if (inicio==NULL) 
        return NULL;
    
    inicio->prox = NULL;
    
    if (todasEstruturasAuxiliaresVazias())
        return NULL;
    
    for (i=0; i<TAM; i++){
        if (estruturaVetores[i].lista!=NULL){
            size=estruturaVetores[i].qtdInseridos;
            for (j=0; j<size; j++)
                insereNaListaEncadeada(inicio, estruturaVetores[i].lista[j]);
        }
    }
    return inicio;
}

int numeroDeElementosTodasAuxiliares(){
    int retorno=0, numeroDeElementos=0, id;
    
    if (todasEstruturasAuxiliaresVazias())
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        for (id=0; id<10; id++)
            if (estruturaVetores[id].lista != NULL)
                numeroDeElementos += estruturaVetores[id].qtdInseridos;
            
        retorno = numeroDeElementos;
    }
    return retorno;
}

void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
    No *aux = inicio->prox;
    int index=0;
    
    while (aux != NULL){
        vetorAux[index++] = aux->valor;
        aux = aux->prox;
    }
}

void destruirListaEncadeadaComCabecote(No** inicio){
    No *aux = (*inicio);
    if (*inicio != NULL){
        aux = (*inicio)->prox;
        free(*inicio);
        (*inicio) = aux;
    }
    // Retorna void para o Cabecote
    (*inicio)= NULL;
}

int getTamanhoVetorAuxiliar(int posicao){
    int retorno=0;
    
    if (!validarPosicao(posicao)) 
        retorno = POSICAO_INVALIDA;
    
    if (!retorno){
        // Correcao de indice
        posicao--;
        
        if (estruturaVetores[posicao].lista != NULL)
            retorno = estruturaVetores[posicao].tamanho;
        else
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    return retorno;
}

int existeEstruturaAuxiliar(int posicao){
    int retorno;
    
    if (!validarPosicao(posicao))
        retorno = POSICAO_INVALIDA;
    
    // Correcao de indice
    posicao--;
    
    if (estruturaVetores[posicao].lista!=NULL)
        retorno = 1;
    else
        retorno = 0;
    
    return retorno;
}

int buscarNumeroNaEstruturaAuxiliar(int valor, int posicao){
    int retorno=0, achou=0;
    
    if (!validarPosicao(posicao)) 
        retorno = POSICAO_INVALIDA;
    
    if (!retorno){
        // Correção de indice
        posicao--;
        
        if (estruturaVetores[posicao].lista!=NULL){
            int tamanhoAux = estruturaVetores[posicao].qtdInseridos, indiceAux=0;
            
            int vet[tamanhoAux];
            
            getDadosEstruturaAuxiliar(posicao+1, vet);
            
            while ((indiceAux != tamanhoAux) && (achou == 0)){
                if (vet[indiceAux]==valor){
                    achou = 1;
                    retorno = indiceAux;
                }else
                    indiceAux++;
            }
            
            if (achou==0)
                retorno = ELEMENTO_INEXISTENTE;
        }
        else
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    return retorno;
}

int insereNaListaEncadeada(No *inicio, int valor){
    int retorno;
    if (inicio==NULL)
        retorno=0;
    else{
        No *novoElemento = (No*)malloc(sizeof(No));
        if (novoElemento==NULL)
            retorno=0;
        else{   
            novoElemento->valor=valor;
            novoElemento->prox=NULL;
            if (inicio->prox==NULL){
                inicio->prox=novoElemento;
                retorno=1;
            }
            else{ 
            No *aux=inicio->prox;
            while (aux->prox!=NULL)
                aux=aux->prox;
                aux->prox=novoElemento;
            }
        }
    }        
    return retorno;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar(){
    int indice;
    
    for (indice=0; indice<TAM; indice++){
        estruturaVetores[indice].lista = NULL;
        estruturaVetores[indice].tamanho = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    // Liberando espacos
    No* head = montarListaEncadeadaComCabecote();
    destruirListaEncadeadaComCabecote(&head);
}

