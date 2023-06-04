#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct disciplina {
    int codigo_disciplina;
    char nome_disciplina[50];
    int bloco;
    int carga_horaria;
    int altura;
    struct disciplina *esq, *dir;
} Disciplina;

typedef struct curso {
    int codigo_curso;
    char nome_curso[50];
    int quantidade_blocos;
    int num_semanas;
    int altura;
    struct disciplina *arvoreDisciplina;
    struct curso *esq, *dir;
} Curso;

Disciplina *criarNoDisciplina(int codigo, char nome[], int bloco, int carga) {
    // Essa funcao recebe os parametros: codigo:inteiro, nome:string, bloco:inteiro e carga:inteiro.
    // Ela vai alocar um espaco de memoria para a disciplina, em seguida atribuir os valores passados 
    // por parametro para cada area da struct.
    // Por fim vai retornar a struct que corresponde a nova disciplina criada.
    Disciplina *new = (Disciplina*) malloc (sizeof(Disciplina));
    new->codigo_disciplina = codigo;
    strcpy(new->nome_disciplina, nome);
    new->bloco = bloco;
    new->carga_horaria = carga;
    new->altura = 0;
    new->esq = NULL;
    new->dir = NULL;
    return new;
}


Curso *criarNoCurso(int codigo, char nome_curso[], int quantidade_blocos, int num_semanas) {
    Curso *new = (Curso*) malloc (sizeof(Curso));
    new->codigo_curso = codigo;
    strcpy(new->nome_curso, nome_curso);
    new->quantidade_blocos = quantidade_blocos;
    new->num_semanas = num_semanas;
    new->arvoreDisciplina = NULL;
    new->altura = 0;
    new->esq = NULL;
    new->dir = NULL;
    return new;
}

// Função para calcular a altura de um nó
int calclrAltr(Curso *no) {
    if (no == NULL) {
        return -1;
    }
    return no->altura;
}

// Função para atualizar a altura de um nó
void atlzrAltr(Curso *no) {
    int altura_esq = calclrAltr(no->esq);
    int altura_dir = calclrAltr(no->dir);
    no->altura = (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

// Função para calcular o fator de balanceamento de um nó
int calclrFatrBalncmnt(Curso *no) {
    if (no == NULL) {
        return 0;
    }
    int altura_esq = calclrAltr(no->esq);
    int altura_dir = calclrAltr(no->dir);
    return ((altura_esq) - (altura_dir));
}

void rotDirt(Curso **raiz){
    Curso *aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);

    // atualizar altura
    atlzrAltr(*raiz);
    atlzrAltr(aux);

    (*raiz) = aux;
}

void rotEsqrd(Curso **raiz){
    Curso *aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);

    // atualizar altura
    atlzrAltr(*raiz);
    atlzrAltr(aux);

    (*raiz) = aux;
}

void insrrCurs(Curso **raiz, Curso *No){
    int fb;
    if(*raiz != NULL){
        if(No->codigo_curso < (*raiz)->codigo_curso){
            insrrCurs(&((*raiz)->esq), No);
        }else insrrCurs(&((*raiz)->dir), No);
    }else *raiz = No;

    atlzrAltr(*raiz);

    fb = calclrFatrBalncmnt(*raiz);

    if(fb == 2){ //arvore esta desbalanceada para a esquerda; rotacao para a direita
        int fbEsq;
        fbEsq = calclrFatrBalncmnt((*raiz)->esq);
        if(fbEsq < 0){
            // caso seja necessario rotação dupla (esquerda-direita)
            rotEsqrd(&((*raiz)->esq));
        }
        // rotação simples
        rotDirt(raiz);
    }else if(fb == -2){ //arvore esta desbalanceada para a direita; rotacao para a esquerda
        int fbDir;
        fbDir = calclrFatrBalncmnt((*raiz)->dir);
        if(fbDir < 0){
            // caso seja necessario rotação dupla (direita-esquerda)
            rotDirt(&((*raiz)->dir));
        }
        // rotacao simples
        rotEsqrd(raiz);
    }
}

// (8)Excluir uma disciplina dado o código da disciplina e o código do curso;


// (9)Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
void buscarfolhaCurso(Curso **filho1, Curso *filho2){
    if(*filho1){
        buscarfolhaCurso(&((*filho1)->dir), filho2);
    }
    else {
        (*filho1) = filho2;
    }
}

Curso *enderecoFilho(Curso *raiz) {
    Curso *aux;
    if (raiz->dir) {
        aux = raiz->dir;
    } else {
        aux = raiz->esq;
    }
    return aux;
}

void removerCurso(Curso **raiz, int codigo){
    if (*raiz != NULL){
        Curso *aux;
        if((*raiz)->codigo_curso == codigo){
            //Verifica se o curso não tem discciplinas para poder remover
            if ((*raiz)->arvoreDisciplina == NULL){
                if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
                free(*raiz);
                (*raiz) = NULL;
            }
            else if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
                Curso *endFilho;
                endFilho = enderecoFilho(*raiz); //Retorna a raiz da esquerda ou da direita
                aux = *raiz;
                *raiz = endFilho;
                free(aux);
                aux = NULL;
            } else { // Dois Filhos
                Curso *filho;
                aux = *raiz;
                filho = (*raiz)->esq;
                buscarfolhaCurso(&((*raiz)->esq), (*raiz)->dir);
                *raiz = filho;
                free(aux);      
                aux = NULL;          
            }
            }
        }
        else if (codigo < (*raiz)->codigo_curso){
            removerCurso(&(*raiz)->esq,codigo);
        }
        else {
            removerCurso(&(*raiz)->dir,codigo);
        }
    calclrFatrBalncmnt(*raiz);
    atlzrAltr(*raiz);
    }
}