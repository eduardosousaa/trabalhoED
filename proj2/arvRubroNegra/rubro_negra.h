// Definição da lista encadeada de números de linha
typedef struct lista{
    int num_linha;
    struct lista *prox;
}Lista;

// Info vai conter a palavra e a lista de números das linha
typedef struct info{
    char *palavra;
    Lista *num_lista;
}Info;

typedef struct arvRubroNegra{
    Info *info;
    int cor;
    struct arvRubroNegra *esq, *dir;
}ArvRubroNegra;

//Faltando...
void lerArquivo(char *nomeArquivo, ArvRubroNegra **raiz, int inseriu[]);
void buscar(ArvRubroNegra *raiz, char palavra[], int *achou);
void excluirPalavra();
void imprimirLinhas(Lista *no);
void imprimirAvr(ArvRubroNegra  *raiz);

//Encaminhadas
void inserirLinha(Lista **no, int linha, int inseriu[]);
ArvRubroNegra  *criaNo(char *palavra, int num_linha, int inseriu[]);
void inserirPalavra(ArvRubroNegra  **raiz, char *palavra, int num_linha, int inseriu[]);
void inserirRubro(ArvRubroNegra  **raiz, char *palavra, int num_linha, int inseriu[]);
void trocaCor(ArvRubroNegra *raiz);
int cor(ArvRubroNegra *raiz);
void rotacaoEsquerda(ArvRubroNegra **raiz);
void rotacaoDireita(ArvRubroNegra **raiz);