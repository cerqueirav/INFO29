#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "EstruturaVetores.h"
#include "utils.h"

Nodo estruturaVetores[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){
    int retorno = SUCESSO;

    // Erro de posicao invalida
    if (posicao < 1 || posicao > 10)
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
                estruturaVetores[posicao].qtdInseridos = 0;
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

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    
    if ((posicao < 1) || (posicao > 10)) 
        posicao_invalida = 1;
    
    // Correcao de indice
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
              estruturaVetores[posicao].lista[tam] = valor;
              
              // Incremento da variavel de controle (qtdInseridos)
              estruturaVetores[posicao].qtdInseridos++;
              retorno = SUCESSO;
          }else{
              retorno = SEM_ESPACO;
          }
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    int retorno=0;

    if (ehPosicaoValida(posicao)!=SUCESSO)
        retorno = POSICAO_INVALIDA;

    if (retorno != POSICAO_INVALIDA){
        // Correcao de indice
        posicao--;

        if (estruturaVetores[posicao].lista == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;

        else if (estruturaVetores[posicao].qtdInseridos == 0)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }

    if (retorno==0){
        // Processo de exclusao logico
        estruturaVetores[posicao].qtdInseridos--;
        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
    int retorno = SUCESSO;

    if (ehPosicaoValida(posicao)!=SUCESSO)
        retorno = POSICAO_INVALIDA;

    if (retorno!=POSICAO_INVALIDA){
        // Correção de indice
        posicao--;

        // Estrutura auxiliar vazia
        if (ehEstruturaAuxiliarVazia(posicao)==ESTRUTURA_AUXILIAR_VAZIA)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;

        int pos  = buscarNumeroNaEstruturaAuxiliar(valor, posicao);
        int size = estruturaVetores[posicao].qtdInseridos;
                
        if (pos > 0){
            int index=pos;
            // Shift
            for (; index<size+1; index++){
                estruturaVetores[posicao].lista[index] = estruturaVetores[posicao].lista[index+1];
            }
            
            // Impressao
            for (index=0; index<size; index++){
                printf("%d ", estruturaVetores[posicao].lista[index]);
            }
        }
                
    }

  return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    
    int retorno = 0;
    
    if ((posicao < 1) || (posicao > 10))
        retorno = POSICAO_INVALIDA;
    
    if (retorno!=POSICAO_INVALIDA){
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

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    
    int retorno = 0;

    if ((posicao < 1) || (posicao > 10))
        retorno = POSICAO_INVALIDA;
        
    if (retorno!=POSICAO_INVALIDA){
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
        
        if (retorno==SUCESSO)
            bubble_sort(vetorAux, estruturaVetores[posicao].qtdInseridos);
         
    }
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    
    int retorno=0, indice=0, estruturasVazias=0;
    
    // Verifica quantas estruturas estao vazias
    for (indice=0; indice<10; indice++){
        if (estruturaVetores[indice].lista == NULL){
            estruturasVazias++;
        }
    }
    
    if (estruturasVazias==9)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        int i=0, j=0, pos=0;
        for (j=0; i<10; i++){
            int size = estruturaVetores[i].qtdInseridos;
            for (j=0; j<size; j++){
                vetorAux[pos] = estruturaVetores[i].lista[j];
                pos++;
            }
            retorno = SUCESSO;
        }
    }
    
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno=0, indice=0, estruturasVazias=0;
    
    // Verifica quantas estruturas estao vazias
    for (indice=0; indice<10; indice++){
        if (estruturaVetores[indice].lista == NULL){
            estruturasVazias++;
        }
    }
    
    if (estruturasVazias==9)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        int i=0, j=0, pos=0;
        for (j=0; i<10; i++){
            int size = estruturaVetores[i].qtdInseridos;
            for (j=0; j<size; j++){
                vetorAux[pos] = estruturaVetores[i].lista[j];
                pos++;
            }
            retorno = SUCESSO;
        }
        
        // Realiza a ordenação
        bubble_sort(vetorAux, pos);
    }
    
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0;
    
    if ((posicao < 1) || (posicao > 10))
        retorno = POSICAO_INVALIDA;
    
    if (novoTamanho < 1)
        retorno = NOVO_TAMANHO_INVALIDO;
    
    if (retorno==0){
        // Correcao de indice
        posicao--;
        
        if (estruturaVetores[posicao].lista != NULL){
            // Define o novo tamanho 
            int tamF;
            tamF = estruturaVetores[posicao].tamanho + novoTamanho;
            
            // Realiza a realocação de memoria
            estruturaVetores[posicao].lista = (int*) realloc(estruturaVetores[posicao].lista, tamF*sizeof(int));
            
            if (estruturaVetores[posicao].lista!=NULL)
                retorno = SUCESSO;
            else
                retorno = SEM_ESPACO_DE_MEMORIA;
        }else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    
    int retorno = 0;

    if ((posicao < 1) || (posicao > 10))
        retorno = POSICAO_INVALIDA;
    
    posicao--;
    if (estruturaVetores[posicao].lista==NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    
    if (retorno==0){
        // Correcao de indice
        
        if (estruturaVetores[posicao].qtdInseridos == 0)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        else
            retorno = estruturaVetores[posicao].qtdInseridos;
    }
    
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote(){

    return NULL;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){


}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
   

}

int getTamanhoVetorAuxiliar(int posicao){
    int retorno=0;
    
    if (ehPosicaoValida(posicao)!=SUCESSO)
        retorno = POSICAO_INVALIDA;
    
    // Correcao de indice
    posicao--;
    
    if (estruturaVetores[posicao].lista == NULL)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    
    if (retorno==0)
        retorno = estruturaVetores[posicao].tamanho;
    
    return retorno;
}

int ehEstruturaAuxiliarVazia(int posicao){
    int retorno=0;
    
    retorno = ehPosicaoValida(posicao);
    
    if (retorno==SUCESSO)
        if (estruturaVetores[posicao].lista==NULL)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        else
            retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        
    return retorno;
}

int buscarNumeroNaEstruturaAuxiliar(int valor, int posicao){
    int retorno=SUCESSO;
    
    if (ehPosicaoValida(posicao)!= SUCESSO)
        retorno = POSICAO_INVALIDA;
    
    if (retorno){
        // Correção de indice
        ajustarIndice(&posicao);
    
        int tamanhoAux = estruturaVetores[posicao].qtdInseridos, indiceAux=0;
        
        if (ehEstruturaAuxiliarVazia(tamanhoAux)!=ESTRUTURA_AUXILIAR_VAZIA)
            for (; indiceAux<tamanhoAux; indiceAux++)
                if (estruturaVetores[posicao].lista[indiceAux]==valor)
                    return indiceAux;
        else
            return ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    return NUMERO_INEXISTENTE;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar(){
    
    
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    
    
}

