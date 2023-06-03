#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "exerc1.h"

int main() {
    srand(time(NULL));

    Curso  *arvoreCursos;
    arvoreCursos = NULL;

    Curso *aux, *aux2, *aux3, *aux4, *aux5, *aux6;
    

    // Exemplo de inserção de cursos e disciplinas
    inserirCurso(&arvoreCursos, criarNoCurso(10, "Engenharia", 15, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(20, "Sistemas de Informacao", 15, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(30, "Medicina", 20, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(40, "Administracao", 18, 25));
    inserirCurso(&arvoreCursos, criarNoCurso(50, "Direito", 20, 30));
    inserirCurso(&arvoreCursos, criarNoCurso(60, "Psicologia", 15, 22));
    
    

    aux = buscarCursoPorCodigo(arvoreCursos, 20);
    // printf("%s\n", aux->nome_curso);
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
    
    // aux4 = buscarCursoPorCodigo(arvoreCursos, 40);
    // inserirDisciplina(&aux4->arvoreDisciplina, criarNoDisciplina(5, "Economia", 6, 60));
    // inserirDisciplina(&aux4->arvoreDisciplina, criarNoDisciplina(6, "Gestao de Pessoas", 4, 50));
    // inserirDisciplina(&aux4->arvoreDisciplina, criarNoDisciplina(7, "Marketing", 4, 50));

    aux5 = buscarCursoPorCodigo(arvoreCursos, 50);
    inserirDisciplina(&aux5->arvoreDisciplina, criarNoDisciplina(8, "Direito Civil", 6, 60));
    inserirDisciplina(&aux5->arvoreDisciplina, criarNoDisciplina(9, "Direito Penal", 6, 60));

    // aux6 = buscarCursoPorCodigo(arvoreCursos, 60);
    // inserirDisciplina(&aux6->arvoreDisciplina, criarNoDisciplina(10, "Psicologia do Desenvolvimento", 4, 50));
    // inserirDisciplina(&aux6->arvoreDisciplina, criarNoDisciplina(11, "Psicologia Clínica", 4, 50));


    // (1) Imprimir a árvore de cursos em ordem crescente pelo código do curso;
    // imprimirCursos(arvoreCursos);

    // imprimirDisciplinas(aux2->arvoreDisciplina);

    // (2)Imprimir os dados de um curso dado o código do mesmo;
    // imprimirCursoPeloCodigo(arvoreCursos, 60);

    // (3)Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos;
    // imprimirCursosPorBlocosIguais(arvoreCursos, 20); 

    //(4)Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
    // imprimirDisciplinasPorCodigoCurso(arvoreCursos, 40); 

    // (5)Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
    // imprimirDadosDisciplinasDadoCodigoCurso(arvoreCursos, 40, 7);

    // 6)Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso;
    // imprimirDisciplinasBloco(arvoreCursos, 6, 40); 

    // (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário;
    // imprimirDisCargaHoraria(arvoreCursos, 10, 60); 

    // (8) Excluir uma disciplina dado o código da disciplina e o código do curso;
    // imprimirDisciplinas(aux2->arvoreDisciplina);

    // buscarCursoParaRemover(&arvoreCursos, 12, 10);

    // imprimirDisciplinas(aux2->arvoreDisciplina);

    // (9)Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
    // imprimirCursos(arvoreCursos);

    // removerCurso(&arvoreCursos, 60);

    // imprimirCursos(arvoreCursos);

    return 0;
}