#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "exer2.h"

int main() {
    Curso  *arvoreCursos;
    arvoreCursos = NULL;

    Curso *aux;
    aux = NULL;

    LARGE_INTEGER inicio, fim, frequencia;
    double tempo_total;

    // Obtém a frequência do contador de performance
    QueryPerformanceFrequency(&frequencia); 

    // Obtém o tempo inicial
    QueryPerformanceCounter(&inicio);

    // printf("Entrou");

    // Exemplo de inserção de cursos e disciplinas
    insrrCurs(&arvoreCursos, criarNoCurso(80, "Ciencia da Computacao", 20, 25));
    insrrCurs(&arvoreCursos, criarNoCurso(10, "Engenharia", 15, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(50, "Direito", 20, 30));
    insrrCurs(&arvoreCursos, criarNoCurso(200, "Artes", 20, 30));
    insrrCurs(&arvoreCursos, criarNoCurso(20, "Sistemas de Informacao", 15, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(70, "Engenharia Civil", 16, 22));
    insrrCurs(&arvoreCursos, criarNoCurso(140, "Quimica", 18, 22));
    insrrCurs(&arvoreCursos, criarNoCurso(160, "Historia", 16, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(40, "Administracao", 18, 25));
    insrrCurs(&arvoreCursos, criarNoCurso(60, "Psicologia", 15, 22));
    insrrCurs(&arvoreCursos, criarNoCurso(120, "Letras", 12, 18));
    insrrCurs(&arvoreCursos, criarNoCurso(100, "Biologia", 16, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(90, "Arquitetura", 18, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(110, "Economia", 15, 24));
    insrrCurs(&arvoreCursos, criarNoCurso(130, "Fisica", 15, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(30, "Medicina", 20, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(150, "Matematica", 20, 25));
    insrrCurs(&arvoreCursos, criarNoCurso(170, "Geografia", 15, 20));
    insrrCurs(&arvoreCursos, criarNoCurso(190, "Sociologia", 16, 22));
    insrrCurs(&arvoreCursos, criarNoCurso(180, "Filosofia", 12, 18));

    // printf("Saiu");

    // Obtém o tempo final
    QueryPerformanceCounter(&fim);

    // Calcula o tempo total em milissegundos
    tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

    // Exibe o tempo total de preenchimento da árvore
    printf("Tempo total: %.9f milissegundos\n", tempo_total);

    // imprimirCursos(arvoreCursos);

    // removerCurso(&arvoreCursos, 200);

    // imprimirCursos(arvoreCursos);

    aux = buscarCursoPorCodigo(arvoreCursos, 20);

    if (aux != NULL){
        printf("Entrou \n");
        inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(1, "ED1", 6, 60));
        inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(2, "ED2", 6, 60));
        inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(3, "PAA", 4, 50));
        inserirDis(&aux->arvoreDisciplina, criarNoDisciplina(4, "TCC1", 4, 50));
        printf("Saiu \n");
    }
    
    
    imprimirDisciplinas(arvoreCursos->arvoreDisciplina);

    buscarCursoParaRemover(&arvoreCursos, 2, 20);

    imprimirDisciplinas(arvoreCursos->arvoreDisciplina);


    return 0;
}

