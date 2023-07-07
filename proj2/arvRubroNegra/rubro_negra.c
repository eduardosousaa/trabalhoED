#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "rubro_negra.h"

#define RED 1
#define BLACK 0

int cor(ArvRubroNegra *raiz){
    int cor;
    if(raiz == NULL) {
        cor = BLACK;
    } else {
        cor = raiz->cor;
    }
    return cor;
}

void inserirLinha(Lista **no, int num_linha, int inseriu[]){
    if (*no == NULL){
        *no = (Lista*) malloc (sizeof(Lista));

        if (*no != NULL){
            (*no)->num_linha = num_linha;
            (*no)->prox = NULL;
            // inseriu[1] indica que inseriu o numero na lista ou não, 1 para sim 0 para não
            inseriu[1] = 1;
        } else {
            inseriu[1] = 0;
        }
        
    } else {
        inserirLinha(&((*no)->prox), num_linha, inseriu);
    }
    
}

ArvRubroNegra  *criaNo(char *palavra, int num_linha, int inseriu[]){
    ArvRubroNegra *new;
    new = (ArvRubroNegra*) malloc (sizeof(ArvRubroNegra));
    if (new != NULL){
        new->info = (Info*) malloc (sizeof(Info));
        // Aloca memória para a palavra
        new->info->palavra = (char*) malloc((strlen(palavra) + 1) * sizeof(char)); 

        strcpy(new->info->palavra, palavra);
        inserirLinha(&(new->info->num_lista), num_linha, inseriu);

        new->cor = RED;
        new->dir = NULL;
        new->esq = NULL;
        inseriu[0] = 1; //Inseriu 
    } else {
        inseriu[0] = 0; //Inseriu 
    }
    return new;

}

void inserirPalavra(ArvRubroNegra  **raiz, char *palavra, int num_linha, int inseriu[]){
    if (*raiz == NULL){
        *raiz = criaNo(palavra, num_linha, inseriu);
    }
    //É verificado se o valor está na arvore, se estiver colocar o numero da linha na lista de numeros.
    else if (strcmp((*raiz)->info->palavra, palavra) == 0){
        inseriu[0] = 2; //Já existe
        inserirLinha(&((*raiz)->info->num_lista), num_linha, inseriu);

    } else if (strcmp((*raiz)->info->palavra, palavra) > 0){
        inserirPalavra(&((*raiz)->dir), palavra, num_linha, inseriu);

    } else if(strcmp((*raiz)->info->palavra, palavra) < 0) {
        inserirPalavra(&((*raiz)->esq), palavra, num_linha, inseriu); 
    
    }

    if(cor((*raiz)->dir) == RED && cor((*raiz)->esq) == BLACK)
        rotacaoEsquerda(raiz);

    if(cor((*raiz)->esq) == RED && cor((*raiz)->esq->esq) == RED){
        rotacaoDireita(raiz);
    }
        

    if(cor((*raiz)->esq) == RED && cor((*raiz)->dir) == RED)
        trocaCor(*raiz);
    
}

void inserirRubro(ArvRubroNegra  **raiz, char *palavra, int num_linha, int inseriu[]){
    inserirPalavra(raiz, palavra, num_linha, inseriu);
    if (*raiz != NULL){
        (*raiz)->cor = BLACK;
    }
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





