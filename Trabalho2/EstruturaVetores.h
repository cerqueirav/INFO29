#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11
#define TAM 10

typedef struct d{
    int *lista;
    int tamanho;
    int qtdInseridos;
} Nodo;

typedef struct reg {
    Nodo info;
    struct reg *prox;
} No;

int criarEstruturaAuxiliar(int tamanho, int posicao); // OK
int inserirNumeroEmEstrutura(int valor, int posicao); // OK
int excluirNumeroDoFinaldaEstrutura(int posicao); // OK
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); // OK
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao); // OK
No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No** inicio);

int ehPosicaoValida(int posicao); // OK
int ehTamanhoValido(int tamanho); // OK
int getTamanhoVetorAuxiliar(int posicao); // OK
int ehEstruturaAuxiliarVazia(int posicao); // OK

void inicializar();
void finalizar();
