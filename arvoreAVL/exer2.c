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

// Função para calcular a altura de um nó Disciplina
int calclrAltrDis(Disciplina *no) {
    int i = -1;
    if (no != NULL){
        i = no->altura;
    }
    return i;
}

// Função para atualizar a altura de um nó
void atlzrAltrDis(Disciplina *no) {
    int altura_esq = calclrAltrDis(no->esq);
    int altura_dir = calclrAltrDis(no->dir);
    no->altura = (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

// Função para calcular o fator de balanceamento de um nó Disciplina
int calclrFatrBalncmntDis(Disciplina *no) {
    int i = 0;
    if (no != NULL){
        int altura_esq = calclrAltrDis(no->esq);
        int altura_dir = calclrAltrDis(no->dir);
        i = ((altura_esq) - (altura_dir));
    }
    return i;
}

void rotDirtDis(Disciplina **raiz){
    Disciplina *aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);

    // atualizar altura
    atlzrAltrDis(*raiz);
    atlzrAltrDis(aux);

    (*raiz) = aux;
}

void rotEsqrdDis(Disciplina **raiz){
    Disciplina *aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);

    // atualizar altura
    atlzrAltrDis(*raiz);
    atlzrAltrDis(aux);

    (*raiz) = aux;
}

void inserirDis(Disciplina **raiz, Disciplina *no) {
    int fb;

    if (*raiz == NULL){
        *raiz = no;
    }

    else if (no->codigo_disciplina < (*raiz)->codigo_disciplina){
        inserirDis(&((*raiz)->esq), no);
    } else {
        inserirDis(&((*raiz)->dir), no);
    }
    
    fb = calclrFatrBalncmntDis(*raiz);

    if (fb == 2){ //arvore esta desbalanceada para a esquerda; rotacao para a direita
        int fbEsq;
        fbEsq = calclrFatrBalncmntDis((*raiz)->esq);
        if (fbEsq < 0){
            // caso seja necessario rotação dupla (esquerda-direita)
            rotEsqrdDis(&((*raiz)->esq));
        }
        // rotação simples
        rotDirtDis(raiz);
    } else if (fb == -2){ //arvore esta desbalanceada para a direita; rotacao para a esquerda
        int fbDir;
        fbDir = calclrFatrBalncmntDis((*raiz)->dir);
        if (fbDir > 0){
             // caso seja necessario rotação dupla (direita-esquerda)
            rotDirtDis(&((*raiz)->dir));
        }
        // rotacao simples
        rotEsqrdDis(raiz);
    }
    
    atlzrAltrDis(*raiz);
    
}

void imprimirDisciplinas(Disciplina *raiz) {
    // Essa funcao recebe a struct com o curso apontando para as disciplinas e imprime os dados das disciplinas do curso
    if (raiz != NULL){
        imprimirDisciplinas(raiz->esq);
        printf("\nDados da disciplina:\nCodigo: %d\nNome: %s\nBloco: %d\nCarga horaria: %d\n\n", raiz->codigo_disciplina, raiz->nome_disciplina, raiz->bloco, raiz->carga_horaria);
        imprimirDisciplinas(raiz->dir);
    }
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

// Função para calcular a altura de um nó  Curso
int calclrAltr(Curso *no) {
    int i = -1;
    if (no != NULL) {
        i = no->altura;
    }
    return i;
}

// Função para atualizar a altura de um nó Curso
void atlzrAltr(Curso *no) {
    int altura_esq = calclrAltr(no->esq);
    int altura_dir = calclrAltr(no->dir);
    no->altura = (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

// Função para calcular o fator de balanceamento de um nó Curso
int calclrFatrBalncmnt(Curso *no) {
    int i = 0;
    if (no != NULL) {
        int altura_esq = calclrAltr(no->esq);
        int altura_dir = calclrAltr(no->dir);
        i = ((altura_esq) - (altura_dir));
    }
    return i;
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

    if (*raiz == NULL) {
        *raiz = No;
    }

    else if (No->codigo_curso < (*raiz)->codigo_curso){
        insrrCurs(&((*raiz)->esq), No);
    } else {
        insrrCurs(&((*raiz)->dir), No);
    }

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
    } else if (fb == -2){ //arvore esta desbalanceada para a direita; rotacao para a esquerda
        int fbDir;
        fbDir = calclrFatrBalncmnt((*raiz)->dir);
        if(fbDir > 0){
            // caso seja necessario rotação dupla (direita-esquerda)
            rotDirt(&((*raiz)->dir));
        }
        // rotacao simples
        rotEsqrd(raiz);
    }

    atlzrAltr(*raiz);
}

Curso *buscarCursoPorCodigo(Curso *raiz, int codigo) {
    if (raiz == NULL || raiz->codigo_curso == codigo) {
        return raiz;
    }

    if (codigo < raiz->codigo_curso) {
        return buscarCursoPorCodigo(raiz->esq, codigo);
    } else {
        return buscarCursoPorCodigo(raiz->dir, codigo);
    }
}

void imprimirCursos(Curso *raiz) {
    if (raiz != NULL) {
        imprimirCursos(raiz->esq);
        printf("\nDados do curso:\nCodigo: %d\nNome: %s\nQuantidade de blocos: %d\nNumero de semanas: %d\n\n", raiz->codigo_curso, raiz->nome_curso, raiz->quantidade_blocos, raiz->num_semanas);
        imprimirCursos(raiz->dir);
    }
}

// (8)Excluir uma disciplina dado o código da disciplina e o código do curso;

// Usada para encontrar a folha mais à direita em uma subárvore
// Até encontrar o último nó à direita e atribuindo o novo nó folha a esse local.
void buscarfolha(Disciplina **ultimo, Disciplina *filho){
    if(*ultimo){
        buscarfolha(&((*ultimo)->dir), filho);
    }
    else {
        (*ultimo) = filho;
    }
}


void removerDisciplina(Disciplina **raiz,int codigo){
    if (*raiz != NULL){
        Disciplina *aux;
        if((*raiz)->codigo_disciplina == codigo){
            // Se o nó não tem filhos
            if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
                free(*raiz);
                (*raiz) = NULL;
            }
            // Se o nó tem apenas um filho
            else if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
                Disciplina *endFilho;
                if((*raiz)->esq != NULL){
                    aux = *raiz;
                    endFilho = (*raiz)->esq;
                    *raiz = endFilho;
                    free(aux);
                    aux = NULL;
                }
                else{
                    aux = *raiz;
                    endFilho = (*raiz)->dir;
                    *raiz = endFilho;
                    free(aux);
                    aux = NULL;
                }
            }
            else{
                Disciplina *filho;
                aux = *raiz;
                filho = (*raiz)->esq;
                // encontrar o nó folha mais à direita da subárvore esquerda, que será movido para o lugar do nó a ser removido.
                buscarfolha(&((*raiz)->esq), (*raiz)->dir);
                *raiz = filho;
                free(aux);      
                aux = NULL;          
            }
        }
        else if (codigo < (*raiz)->codigo_disciplina){
            removerDisciplina(&(*raiz)->esq,codigo);
        }
        else {
            removerDisciplina(&(*raiz)->dir,codigo);
        }
    // Se estiver desbalanceado, vai ser feito o balanceamento da árvore.
    if (*raiz != NULL){
        int valorBalan;
        valorBalan = calclrFatrBalncmntDis(*raiz);
        if (valorBalan == 2){ //arvore esta desbalanceada para a esquerda; rotacao para a direita
            if (calclrFatrBalncmntDis((*raiz)->esq) == -1){
                rotEsqrdDis(&((*raiz)->esq));
            }
            rotDirtDis((raiz));
            
        } else if (valorBalan == -2){
            if (calclrFatrBalncmntDis((*raiz)->esq) == 1){
                rotDirtDis(&((*raiz)->dir));
            }
            rotEsqrdDis((raiz));
            
        }
        // Vai atualizar a altura.
        atlzrAltrDis(*raiz);
        }
    }
    
}

void buscarCursoParaRemover(Curso **raiz, int codigo_disciplina, int codigo){
    if (*raiz != NULL){
        if ((*raiz)->codigo_curso == codigo){
            removerDisciplina(&(*raiz)->arvoreDisciplina, codigo_disciplina);
        }
        else if (codigo < (*raiz)->codigo_curso){
            buscarCursoParaRemover(&(*raiz)->esq, codigo_disciplina, codigo);
        }
        else {
            buscarCursoParaRemover(&(*raiz)->dir, codigo_disciplina, codigo);
        }
    }
}


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

    // Se estiver desbalanceado, vai ser feito o balanceamento da árvore.
    if (*raiz != NULL){
        int valorBalan;
        valorBalan = calclrFatrBalncmnt(*raiz);
        if (valorBalan == 2){ //arvore esta desbalanceada para a esquerda; rotacao para a direita
            if (calclrFatrBalncmnt((*raiz)->esq) == -1){
                rotEsqrd(&((*raiz)->esq));
            }
            rotDirt((raiz));
            
        } else if (valorBalan == -2){
            if (calclrFatrBalncmnt((*raiz)->esq) == 1){
                rotDirt(&((*raiz)->dir));
            }
            rotEsqrd((raiz));
            
        }
        // Vai atualizar a altura.
        atlzrAltr(*raiz);
        }
    }
    
    
}


int main() {
    Curso  *arvoreCursos;
    arvoreCursos = NULL;

    Curso *aux;
    aux = NULL;

    // printf("Entrou");

    // Exemplo de inserção de cursos e disciplinas
    // insrrCurs(&arvoreCursos, criarNoCurso(80, "Ciencia da Computacao", 20, 25));
    // insrrCurs(&arvoreCursos, criarNoCurso(10, "Engenharia", 15, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(50, "Direito", 20, 30));
    // insrrCurs(&arvoreCursos, criarNoCurso(200, "Artes", 20, 30));
    insrrCurs(&arvoreCursos, criarNoCurso(20, "Sistemas de Informacao", 15, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(70, "Engenharia Civil", 16, 22));
    // insrrCurs(&arvoreCursos, criarNoCurso(140, "Quimica", 18, 22));
    // insrrCurs(&arvoreCursos, criarNoCurso(160, "Historia", 16, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(40, "Administracao", 18, 25));
    // insrrCurs(&arvoreCursos, criarNoCurso(60, "Psicologia", 15, 22));
    // insrrCurs(&arvoreCursos, criarNoCurso(120, "Letras", 12, 18));
    // insrrCurs(&arvoreCursos, criarNoCurso(100, "Biologia", 16, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(90, "Arquitetura", 18, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(110, "Economia", 15, 24));
    // insrrCurs(&arvoreCursos, criarNoCurso(130, "Fisica", 15, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(30, "Medicina", 20, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(150, "Matematica", 20, 25));
    // insrrCurs(&arvoreCursos, criarNoCurso(170, "Geografia", 15, 20));
    // insrrCurs(&arvoreCursos, criarNoCurso(190, "Sociologia", 16, 22));
    // insrrCurs(&arvoreCursos, criarNoCurso(180, "Filosofia", 12, 18));

    // printf("Saiu");

    imprimirCursos(arvoreCursos);

    // removerCurso(&arvoreCursos, 200);

    // imprimirCursos(arvoreCursos);

    aux = buscarCursoPorCodigo(arvoreCursos, 20);

    inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(1, "ED1", 6, 60));
    inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(2, "ED2", 6, 60));
    inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(3, "PAA", 4, 50));
    inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(4, "TCC1", 4, 50));
    

    imprimirDisciplinas(arvoreCursos->arvoreDisciplina);

    buscarCursoParaRemover(&arvoreCursos, 2, 20);

    imprimirDisciplinas(arvoreCursos->arvoreDisciplina);
}