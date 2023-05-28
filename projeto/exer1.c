#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct disciplina {
    int codigo_disciplina;
    char nome_disciplina[50];
    int bloco;
    int carga_horaria;
    struct disciplina *esq, *dir;
} Disciplina;

typedef struct curso {
    int codigo_curso;
    char nome_curso[50];
    int quantidade_blocos;
    int num_semanas;
    struct disciplina *arvoreDisciplina;
    struct curso *esq, *dir;
} Curso;

Disciplina *criarNoDisciplina(int codigo, char nome[], int bloco, int carga) {
    Disciplina *new = (Disciplina*) malloc (sizeof(Disciplina));
    new->codigo_disciplina = codigo;
    strcpy(new->nome_disciplina, nome);
    new->bloco = bloco;
    new->carga_horaria = carga;
    new->esq = NULL;
    new->dir = NULL;
    return new;
}

// void *inserirDisciplina(Disciplina *raiz, Disciplina disciplina) {
//     if (raiz == NULL){
//         return criarNoDisciplina(disciplina.codigo_disciplina, disciplina.nome_disciplina, disciplina.bloco, disciplina.carga_horaria);
//     } else {
//         if (disciplina.codigo_disciplina < raiz->disciplina.codigo_disciplina){
//             raiz->esq = inserirDisciplina(raiz->esq, disciplina);
//         } else {
//             raiz->dir = inserirDisciplina(raiz->dir, disciplina);
//         }
//         return raiz;
//     }   
// }

void imprimirDisciplinas(Disciplina *raiz) {
    if (raiz != NULL){
        imprimirDisciplinas(raiz->esq);
        printf("\nDados da disciplina:\nCodigo: %d\nNome: %s\nBloco: %d\nCarga horaria: %d\n\n", raiz->codigo_disciplina, raiz->nome_disciplina, raiz->bloco, raiz->carga_horaria);
        imprimirDisciplinas(raiz->dir);
    }
}

// void imprimirDisciplinasPorCodigoCurso(DisciplinaArvore *raiz, int codigo_curso) {
//     if (raiz != NULL) {
//         imprimirDisciplinasPorCodigoCurso(raiz->esq, codigo_curso);
        
//         if (raiz->disciplina.codigo_curso == codigo_curso) {
//             printf("\nDados da disciplina:\nCodigo: %d\nNome: %s\nBloco: %d\nCarga horaria: %d\n\n", raiz->disciplina.codigo_disciplina, raiz->disciplina.nome_disciplina, raiz->disciplina.bloco, raiz->disciplina.carga_horaria);
//         }
        
//         imprimirDisciplinasPorCodigoCurso(raiz->dir, codigo_curso);
//     }
// }

void imprimirDisciplinasPorCodigoCurso(Curso *raiz, int codigo_curso) {
    if (raiz != NULL) {
        imprimirDisciplinasPorCodigoCurso(raiz->esq, codigo_curso);

        if (raiz->codigo_curso == codigo_curso) {
            imprimirDisciplinas(raiz->arvoreDisciplina);
        } 

        imprimirDisciplinasPorCodigoCurso(raiz->dir, codigo_curso);
    }
}

void procuraDisciplina(Disciplina *disciplina, int codigo_disciplina) {
    //raiz->arvoreDisciplina->codigo_disciplina == codigo_disciplina
    if (disciplina != NULL){
        if (disciplina->codigo_disciplina == codigo_disciplina){
            printf("\nDados da disciplina:\nCodigo: %d\nNome: %s\nBloco: %d\nCarga horaria: %d\n\n", disciplina->codigo_disciplina, disciplina->nome_disciplina, disciplina->bloco, disciplina->carga_horaria);
        } else {
            if (codigo_disciplina < disciplina->codigo_disciplina){
                procuraDisciplina(disciplina->esq, codigo_disciplina);
            } else {
                procuraDisciplina(disciplina->dir, codigo_disciplina);
            }
        }
    }
}

// Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
void imprimirDadosDisciplinasDadoCodigoCurso(Curso *raiz, int codigo_curso, int codigo_disciplina){
    if (raiz != NULL){
        if (raiz->codigo_curso == codigo_curso){
            procuraDisciplina(raiz->arvoreDisciplina, codigo_disciplina);
            // imprimirDisciplinas(raiz->arvoreDisciplina);
        } else {
            if (codigo_curso < raiz->codigo_curso){
                imprimirDadosDisciplinasDadoCodigoCurso(raiz->esq, codigo_curso, codigo_disciplina);
            } else {
                imprimirDadosDisciplinasDadoCodigoCurso(raiz->dir, codigo_curso, codigo_disciplina);
            }
        }
    }
}

void procuraDisciplina2(Disciplina *disciplina, int bloco, int codigo_disciplina) {
    if (disciplina != NULL){
        if (disciplina->bloco == bloco){
            procuraDisciplina2(disciplina->esq, bloco, codigo_disciplina);
            printf("\nDados da disciplina:\nCodigo: %d\nNome: %s\nBloco: %d\nCarga horaria: %d\n\n", disciplina->codigo_disciplina, disciplina->nome_disciplina, disciplina->bloco, disciplina->bloco);
            procuraDisciplina2(disciplina->dir, bloco, codigo_disciplina);
        } 
    }
}


// Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso;
void imprimirDisciplinasBloco(Curso *raiz, int bloco, int codigo_curso) {
    if (raiz != NULL){
        if (raiz->codigo_curso == codigo_curso){
            procuraDisciplina2(raiz->arvoreDisciplina, bloco, raiz->arvoreDisciplina->codigo_disciplina);
        } else {
            if (codigo_curso < raiz->codigo_curso){
                imprimirDisciplinasBloco(raiz->esq, bloco, codigo_curso);
            } else {
                imprimirDisciplinasBloco(raiz->dir, bloco, codigo_curso);
            }
        }
    }
}

void procuraDisciplina3(Disciplina *disciplina, int carga_horaria, int codigo_disciplina) {
    if (disciplina != NULL){
        if (disciplina->carga_horaria == carga_horaria){
            procuraDisciplina3(disciplina->esq, carga_horaria, codigo_disciplina);
            printf("\nDados da disciplina:\nCodigo: %d\nNome: %s\nBloco: %d\nCarga horaria: %d\n\n", disciplina->codigo_disciplina, disciplina->nome_disciplina, disciplina->bloco, disciplina->carga_horaria);
            procuraDisciplina3(disciplina->dir, carga_horaria, codigo_disciplina);
        } 
    }
}

// Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário;
void imprimirDisCargaHoraria(Curso *raiz, int codigo_curso, int carga_horaria) {
    if (raiz != NULL){
        if (raiz->codigo_curso == codigo_curso){
            procuraDisciplina3(raiz->arvoreDisciplina, carga_horaria, raiz->arvoreDisciplina->codigo_disciplina);
        } else {
            if (codigo_curso < raiz->codigo_curso){
                imprimirDisCargaHoraria(raiz->esq, codigo_curso, carga_horaria);
            } else {
                imprimirDisCargaHoraria(raiz->dir, codigo_curso, carga_horaria);
            }
        }
    }
}


Curso *criarNoCurso(int codigo, char nome_curso[], int quantidade_blocos, int num_semanas) {
    Curso *new = (Curso*) malloc (sizeof(Curso));
    new->codigo_curso = codigo;
    strcpy(new->nome_curso, nome_curso);
    new->quantidade_blocos = quantidade_blocos;
    new->num_semanas = num_semanas;
    new->arvoreDisciplina = NULL;
    new->esq = NULL;
    new->dir = NULL;
    return new;
}

void inserirCurso(Curso **raiz, Curso *curso) {
    if (*raiz == NULL)
        *raiz = curso;
    else if (curso->codigo_curso < (*raiz)->codigo_curso){
        inserirCurso(&((*raiz)->esq), curso);
    } else {
        inserirCurso(&((*raiz)->dir), curso);
    }
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
    if (raiz != NULL){
        imprimirCursos(raiz->esq);
        printf("\nDados do curso:\nCodigo: %d\nNome: %s\nQuantidade de blocos: %d\nNumero de semanas: %d\n\n", raiz->codigo_curso, raiz->nome_curso, raiz->quantidade_blocos, raiz->num_semanas);
        if(raiz->arvoreDisciplina)
            imprimirDisciplinas(raiz->arvoreDisciplina);
        imprimirCursos(raiz->dir);
    }
}

void imprimirCursoPeloCodigo(Curso *raiz, int codigo_curso) {
    if (raiz != NULL){
        if (raiz->codigo_curso == codigo_curso){
             printf("\nDados do curso:\nCodigo: %d\nNome: %s\nQuantidade de blocos: %d\nNumero de semanas: %d\n\n", raiz->codigo_curso, raiz->nome_curso, raiz->quantidade_blocos, raiz->num_semanas);
        } else {
            if (codigo_curso < raiz->codigo_curso){
                imprimirCursoPeloCodigo(raiz->esq, codigo_curso);
            } else {
                imprimirCursoPeloCodigo(raiz->dir, codigo_curso);
            }
        }
    }
}


void imprimirCursosPorBlocosIguais(Curso *raiz, int quant_blocos) {
    if (raiz != NULL){
        if (raiz->quantidade_blocos == quant_blocos){
            printf("\nDados do curso:\nCodigo: %d\nNome: %s\nQuantidade de blocos: %d\nNumero de semanas: %d\n\n", raiz->codigo_curso, raiz->nome_curso, raiz->quantidade_blocos, raiz->num_semanas);
            imprimirCursosPorBlocosIguais(raiz->esq, quant_blocos);
            imprimirCursosPorBlocosIguais(raiz->dir, quant_blocos);
        } 
    }
}

void inserirDisciplina(Disciplina **raiz, Disciplina *noDis){
    if (raiz) {
        if (!(*raiz)) {
            *raiz = noDis;
        } else if ((*noDis).codigo_disciplina < (**raiz).codigo_disciplina){
            inserirDisciplina(&((*raiz)->esq), noDis);
        } else {
            inserirDisciplina(&((*raiz)->dir), noDis);
        }
    }
}

int main() {
    srand(time(NULL));

    Curso  *arvoreCursos;
    arvoreCursos = NULL;
    

    // Exemplo de inserção de cursos e disciplinas
    inserirCurso(&arvoreCursos, criarNoCurso(10, "Engenharia", 15, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(20, "Sistemas de Informacao", 15, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(30, "Medicina", 20, 20));
    
    Curso *aux, *aux2;

    aux = buscarCursoPorCodigo(arvoreCursos, 20);
    // printf("%s\n", aux->nome_curso);
    aux = buscarCursoPorCodigo(arvoreCursos, 20);
    // printf("%s\n", aux->nome_curso);
    aux2 = buscarCursoPorCodigo(arvoreCursos, 30);

    inserirDisciplina(&aux->arvoreDisciplina, criarNoDisciplina(1, "ED1", 6, 60));
    inserirDisciplina(&aux->arvoreDisciplina, criarNoDisciplina(2, "ED2", 6, 60));
    inserirDisciplina(&aux->arvoreDisciplina, criarNoDisciplina(3, "PAA", 4, 50));

    // printf("%s\n", aux->nome_curso);
    
    // printf("%s\n", aux2->arvoreDisciplina->nome_disciplina);

    //Imprimindo todos os cursos da árvore
    // imprimirCursos(arvoreCursos);
    printf("\n");
    // imprimirDisciplinas(aux->arvoreDisciplina);

    //Imprimindo dados de um curso especifico de acordo com o seu código
    // imprimirCursoPeloCodigo(arvoreCursos, 20);

    //Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos
    // imprimirCursosPorBlocosIguais(arvoreCursos, 15);

    //Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
    // imprimirDisciplinasPorCodigoCurso(arvoreCursos, 20);

    // imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
    // imprimirDadosDisciplinasDadoCodigoCurso(arvoreCursos, 20, 1);

    // Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso;
    imprimirDisciplinasBloco(arvoreCursos, 6, 20);

    // Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário;
    // imprimirDisCargaHoraria(arvoreCursos, 20, 60);

    return 0;
}
