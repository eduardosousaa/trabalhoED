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

    //Vetor com os códigos dos cursos
    int codigos[] = {10, 80, 50, 200, 20, 70, 140, 160, 40, 60, 120, 100, 90, 110, 130, 30, 150, 170, 190, 180};
    int num_cursos = sizeof(codigos) / sizeof(codigos[0]);

    // Embaralha os códigos dos cursos
    embaralhar(codigos, num_cursos);

    //Criação das árvores com as inserções embaralhadas
    for (int i = 0; i < num_cursos; i++) {
        int qtd_blocos = sortearNumero();
        int num_semanas = sortearNumero();
        // char nome_curso[50];
        // sprintf(nome_curso, "Curso %d", i + 1);
        inserirCurso(&arvoreCursos, criarNoCurso(codigos[i], "A", qtd_blocos, num_semanas));
    }

    // Obtém o tempo final
    QueryPerformanceCounter(&fim);

    // Calcula o tempo total em milissegundos
    tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

    // Exibe o tempo total de preenchimento da árvore
    printf("Tempo total: %.9f milissegundos\n", tempo_total);
    

    // imprimirCursos(arvoreCursos);

    /*
    aux = buscarCursoPorCodigo(arvoreCursos, 20);
    printf("%s\n", aux->nome_curso);
    // aux = buscarCursoPorCodigo(arvoreCursos, 20);
    // printf("%s\n", aux->nome_curso);
    // aux2 = buscarCursoPorCodigo(arvoreCursos, 30);

    inserirDisciplina(&aux->arvoreDisciplina, criarNoDisciplina(1, "ED1", 6, 60));
    inserirDisciplina(&aux->arvoreDisciplina, criarNoDisciplina(2, "ED2", 6, 60));
    inserirDisciplina(&aux->arvoreDisciplina, criarNoDisciplina(3, "PAA", 4, 50));
    inserirDisciplina(&aux->arvoreDisciplina, criarNoDisciplina(4, "TCC1", 4, 50));

    aux2 = buscarCursoPorCodigo(arvoreCursos, 10);
    inserirDisciplina(&aux2->arvoreDisciplina, criarNoDisciplina(12, "Anatomia", 6, 60));
    inserirDisciplina(&aux2->arvoreDisciplina, criarNoDisciplina(14, "Fisiologia", 6, 60));
    inserirDisciplina(&aux2->arvoreDisciplina, criarNoDisciplina(13, "Farmacologia", 4, 60));
    inserirDisciplina(&aux2->arvoreDisciplina, criarNoDisciplina(5, "Farmacologia", 4, 60));
    inserirDisciplina(&aux2->arvoreDisciplina, criarNoDisciplina(10, "Farmacologia", 4, 60));
    inserirDisciplina(&aux2->arvoreDisciplina, criarNoDisciplina(7, "Farmacologia", 4, 60));

    aux3 = buscarCursoPorCodigo(arvoreCursos, 30);
    inserirDisciplina(&aux3->arvoreDisciplina, criarNoDisciplina(15, "Patologia", 6, 60));
    inserirDisciplina(&aux3->arvoreDisciplina, criarNoDisciplina(16, "Neurologia", 6, 60));
    inserirDisciplina(&aux3->arvoreDisciplina, criarNoDisciplina(17, "Cirurgia", 4, 50));
    
    aux4 = buscarCursoPorCodigo(arvoreCursos, 40);
    inserirDisciplina(&aux4->arvoreDisciplina, criarNoDisciplina(5, "Economia", 6, 60));
    inserirDisciplina(&aux4->arvoreDisciplina, criarNoDisciplina(6, "Gestao de Pessoas", 4, 50));
    inserirDisciplina(&aux4->arvoreDisciplina, criarNoDisciplina(7, "Marketing", 4, 50));

    aux5 = buscarCursoPorCodigo(arvoreCursos, 50);
    inserirDisciplina(&aux5->arvoreDisciplina, criarNoDisciplina(8, "Direito Civil", 6, 60));
    inserirDisciplina(&aux5->arvoreDisciplina, criarNoDisciplina(9, "Direito Penal", 6, 60));

    aux6 = buscarCursoPorCodigo(arvoreCursos, 60);
    inserirDisciplina(&aux6->arvoreDisciplina, criarNoDisciplina(10, "Psicologia do Desenvolvimento", 4, 50));
    inserirDisciplina(&aux6->arvoreDisciplina, criarNoDisciplina(11, "Psicologia Clínica", 4, 50));


    */
    return 0;
}