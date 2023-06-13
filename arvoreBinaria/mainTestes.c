#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "exer1.h"

int main() {
    // srand(time(NULL));

    Curso  *arvoreCursos;
    arvoreCursos = NULL;

    Curso *aux, *aux2, *aux3, *aux4, *aux5, *aux6;
    aux = NULL;
    
    LARGE_INTEGER inicio, fim, frequencia;
    double tempo_total;

     // Obtém a frequência do contador de performance
    QueryPerformanceFrequency(&frequencia); 

    // Obtém o tempo inicial
    QueryPerformanceCounter(&inicio);

    //Vetor com os códigos dos cursos
    int codigos[10000];

    for (int i = 0; i < 10000; i++) {
        codigos[i] = 10 + (i * 10);
    }

    int num_cursos = sizeof(codigos) / sizeof(codigos[0]);

    // Embaralha os códigos dos cursos
    embaralhar(codigos, num_cursos);


    //Criação das árvores com as inserções embaralhadas
    for (int i = 0; i < num_cursos; i++) {
        int qtd_blocos = sortearNumero();
        int num_semanas = sortearNumero();
        char nome_curso[50];
        sprintf(nome_curso, "Curso %d", i + 1);
        inserirCurso(&arvoreCursos, criarNoCurso(codigos[i], nome_curso, qtd_blocos, num_semanas));
    }
    
    // Obtém o tempo final
    QueryPerformanceCounter(&fim);

    // Calcula o tempo total em milissegundos
    tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

    // Exibe o tempo total de preenchimento da árvore
    printf("Tempo total: %.5f milissegundos\n", tempo_total);
    
    // aux = buscarCursoPorCodigo(arvoreCursos, 20);


    // Exemplo de inserção de cursos e disciplinas
    // inserirCurso(&arvoreCursos, criarNoCurso(10, "Engenharia", 15, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(80, "Ciência da Computação", 20, 25));
    // inserirCurso(&arvoreCursos, criarNoCurso(50, "Direito", 20, 30));
    // inserirCurso(&arvoreCursos, criarNoCurso(200, "Artes", 20, 30));
    // inserirCurso(&arvoreCursos, criarNoCurso(20, "Sistemas de Informacao", 15, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(70, "Engenharia Civil", 16, 22));
    // inserirCurso(&arvoreCursos, criarNoCurso(140, "Química", 18, 22));
    // inserirCurso(&arvoreCursos, criarNoCurso(160, "História", 16, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(40, "Administracao", 18, 25));
    // inserirCurso(&arvoreCursos, criarNoCurso(60, "Psicologia", 15, 22));
    // inserirCurso(&arvoreCursos, criarNoCurso(120, "Letras", 12, 18));
    // inserirCurso(&arvoreCursos, criarNoCurso(100, "Biologia", 16, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(90, "Arquitetura", 18, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(110, "Economia", 15, 24));
    // inserirCurso(&arvoreCursos, criarNoCurso(130, "Física", 15, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(30, "Medicina", 20, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(150, "Matemática", 20, 25));
    // inserirCurso(&arvoreCursos, criarNoCurso(170, "Geografia", 15, 20));
    // inserirCurso(&arvoreCursos, criarNoCurso(190, "Sociologia", 16, 22));
    // inserirCurso(&arvoreCursos, criarNoCurso(180, "Filosofia", 12, 18));
    
    return 0;
}