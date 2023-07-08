#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "rubro_negra.h"

#define RED 1
#define BLACK 0

int cor(ArvRubroNegra *raiz){
    /**
     * Retorna a cor de um nó em uma árvore rubro-negra.
     *
     * @param raiz O nó da árvore rubro-negra.
     *
     * @return A cor do nó:
     *         - 0: Preto (BLACK)
     *         - 1: Vermelho (RED)
     */

    int cor;
    if(raiz == NULL) {
        cor = BLACK;
    } else {
        cor = raiz->cor;
    }
    return cor;
}

int inserirLinha(Lista **no, int num_linha){
    /**
     * Insere um número de linha em uma lista encadeada.
     *
     * @param no Um ponteiro para o ponteiro da lista encadeada.
     * @param num_linha O número da linha a ser inserido na lista.
     *
     * @return Um valor indicando se o número de linha foi inserido:
     *         - 0: O número de linha não foi inserido na lista.
     *         - 1: O número de linha foi inserido na lista.
     */

    int inseriu = 0;
    if (*no == NULL){
        *no = (Lista*) malloc (sizeof(Lista));

        if (*no != NULL){
            (*no)->num_linha = num_linha;
            (*no)->prox = NULL;
            // inseriu indica que inseriu o numero na lista ou não, 1 para sim 0 para não
            inseriu = 1;
        }
        
    } else {
        inseriu = inserirLinha(&((*no)->prox), num_linha, inseriu);
    }

    return inseriu;
}

int criaNo(ArvRubroNegra **raiz, char *palavra, int num_linha) {
    /**
     * Cria um novo nó para ser inserido em uma árvore rubro-negra.
     *
     * @param raiz Um ponteiro para o ponteiro da raiz da árvore rubro-negra.
     * @param palavra A palavra a ser inserida no novo nó.
     * @param num_linha O número da linha a ser associado à palavra.
     *
     * @return Um valor indicando se o nó foi criado:
     *         - 0: Não foi criado um novo nó.
     *         - 1: Foi criado um novo nó.
     */

    int criou = 0;

    if (*raiz == NULL) {
        *raiz = (ArvRubroNegra *)malloc(sizeof(ArvRubroNegra));
        if (*raiz != NULL) {
            (*raiz)->info = (Info *)malloc(sizeof(Info));
            (*raiz)->info->palavra = (char *)malloc((strlen(palavra) + 1) * sizeof(char));

            strcpy((*raiz)->info->palavra, palavra);
            inserirLinha(&((*raiz)->info->num_lista), num_linha);

            (*raiz)->cor = RED;
            (*raiz)->dir = NULL;
            (*raiz)->esq = NULL;
            criou = 1; // criou
        }
    } else {
        // Caso em que o nó já existe
        inserirLinha(&((*raiz)->info->num_lista), num_linha);
    }

    return criou;
}


int inserirPalavra(ArvRubroNegra  **raiz, char *palavra, int num_linha){
    /**
     * Insere uma palavra em uma árvore rubro-negra e associa um número de linha a ela.
     *
     * @param raiz Um ponteiro para o ponteiro da raiz da árvore rubro-negra.
     * @param palavra A palavra a ser inserida na árvore.
     * @param num_linha O número da linha em que a palavra está presente.
     *
     * @return O valor de criouNo, indicando o resultado da inserção:
     *         - 0: Não foi criado um novo nó na árvore.
     *         - 1: Foi criado um novo nó na árvore.
     *         - 2: A palavra já existe na árvore e apenas o número da linha foi atualizada.
     */
    
    int criouNo = 0;
    if (*raiz == NULL){
        criouNo = criaNo(raiz, palavra, num_linha);
    }
    //É verificado se o valor está na arvore, se estiver colocar o numero da linha na lista de numeros.
    else if (strcmp((*raiz)->info->palavra, palavra) == 0){
        criouNo = 2; //Já existe
        inserirLinha(&((*raiz)->info->num_lista), num_linha);
    } else if (strcmp((*raiz)->info->palavra, palavra) > 0){
        criouNo = inserirPalavra(&((*raiz)->dir), palavra, num_linha);
    } else if(strcmp((*raiz)->info->palavra, palavra) < 0) {
        criouNo = inserirPalavra(&((*raiz)->esq), palavra, num_linha); 
    }

    if(cor((*raiz)->dir) == RED && cor((*raiz)->esq) == BLACK)
        rotacaoEsquerda(raiz);
    if(cor((*raiz)->esq) == RED && cor((*raiz)->esq->esq) == RED)
        rotacaoDireita(raiz);
    if(cor((*raiz)->esq) == RED && cor((*raiz)->dir) == RED)
        trocaCor(*raiz);

    return criouNo;
}

int inserirRubro(ArvRubroNegra  **raiz, char *palavra, int num_linha){
    /**
     * Insere uma palavra em uma árvore rubro-negra e associa um número de linha a ela.
     *
     * @param raiz Um ponteiro para o ponteiro da raiz da árvore rubro-negra.
     * @param palavra A palavra a ser inserida na árvore.
     * @param num_linha O número da linha em que a palavra está presente.
     *
     * @return O valor de inseriu, indicando o resultado da inserção:
     *         - 0: A palavra não foi inserida na árvore.
     *         - 1: A palavra foi inserida na árvore.
     *         - 2: A palavra já existe na árvore e apenas o número da linha foi atualizada.
     */

    int inseriu = inserirPalavra(raiz, palavra, num_linha);
    if (*raiz != NULL){
        (*raiz)->cor = BLACK;
    }
    return inseriu;
}

void trocaCor(ArvRubroNegra  *raiz){
    if(raiz != NULL){
        raiz->cor = !raiz->cor; 
        if(raiz->dir) {
            raiz->dir->cor = !raiz->dir->cor;
        } else if(raiz->esq)
            raiz->esq->cor = !raiz->esq->cor; 
    }
}

void rotacaoEsquerda(ArvRubroNegra **raiz){
    ArvRubroNegra *aux;

    aux = (*raiz)->dir; 
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    *raiz = aux;

    (*raiz)->cor = (*raiz)->esq->cor;
    (*raiz)->esq->cor = RED;
}

void rotacaoDireita(ArvRubroNegra **raiz){
    ArvRubroNegra *aux;

    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    *raiz = aux;

    (*raiz)->cor = (*raiz)->dir->cor;
    (*raiz)->dir->cor = RED;
}





