#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define ELEMENTO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11
#define TODAS_ESTRUTURAS_AUXILIARES_INEXISTENTES -12
#define TAM 10

typedef struct d{
    int *lista;
    int tamanho;
    int qtdInseridos;
} Nodo;

typedef struct reg {
    int valor;
    struct reg *prox;
} No;

int criarEstruturaAuxiliar(int tamanho, int posicao); 
int inserirNumeroEmEstrutura(int valor, int posicao); 
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No** inicio);

int buscarNumeroNaEstruturaAuxiliar(int valor, int posicao);
int existeEstruturaAuxiliar(int posicao); 
int getTamanhoVetorAuxiliar(int posicao); 
int numeroDeElementosTodasAuxiliares();
int insereNaListaEncadeada(No *inicio, int valor);
int todasEstruturasAuxiliaresVazias();
int todasEstruturasAuxiliaresNaoExistem();

void inicializar();
void finalizar();
