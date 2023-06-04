#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "exer1.h"

int main() {
    srand(time(NULL));

    Curso  *arvoreCursos;
    arvoreCursos = NULL;

    Curso *aux, *aux2, *aux3, *aux4, *aux5, *aux6;
    aux = NULL;
    

    // Exemplo de inserção de cursos e disciplinas
    inserirCurso(&arvoreCursos, criarNoCurso(10, "Engenharia", 15, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(20, "Sistemas de Informacao", 15, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(30, "Medicina", 20, 20));
    inserirCurso(&arvoreCursos, criarNoCurso(40, "Administracao", 18, 25));
    inserirCurso(&arvoreCursos, criarNoCurso(50, "Direito", 20, 30));
    inserirCurso(&arvoreCursos, criarNoCurso(60, "Psicologia", 15, 22));
    
    

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



    int cod_curso, qtd_blocos, cod_disc, bloco_curso, carga_horaria;
    int opcao = -1;
    while(opcao != 0){
        printf("\n");
        printf("0 - Encerrar\n"
        "1 - Inserir curso\n"
        "2 - Inserir disciplina\n"
        "3 - Imprimir arvore de cursos\n"
        "4 - Imprimir dados de um curso\n"
        "5 - Imprimir cursos com a mesma quantidade de blocos\n"
        "6 - Imprimir arvore de disciplinas pelo codigo\n"
        "7 - Imprimir dados de um disciplina\n"
        "8 - Imprimir as disciplinas de um determinado bloco\n"
        "9 -Imprimir disciplinas com a mesma carga horária\n"
        "10 - Excluir uma disciplina\n"
        "11 - Excluir um curso\n"
        "Digite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao){
        case 0:
            break;

        case 1:
            
            break;
            
        case 2:
            
            break;

        case 3:
            // (1) Imprimir a árvore de cursos em ordem crescente pelo código do curso;
            imprimirCursos(arvoreCursos);
            
            break;
        
        case 4:
            // (2)Imprimir os dados de um curso dado o código do mesmo;
            printf("Digite o codigo do curso que deseja imprimir: \n");
            scanf("%d", &cod_curso);
            imprimirCursoPeloCodigo(arvoreCursos, cod_curso);
            break;

        case 5:
            // (3)Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos;
            printf("Digite a quantidade de blocos: \n");
            scanf("%d", &qtd_blocos);
            imprimirCursosPorBlocosIguais(arvoreCursos, qtd_blocos); 
            
            break;

        case 6:
             //(4)Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
            printf("Digite o codigo do curso: \n");
            scanf("%d", &cod_curso);
            imprimirDisciplinasPorCodigoCurso(arvoreCursos, cod_curso); 
             
            break;

        case 7:
            // (5)Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
            printf("Digite o codigo da disciplina: \n");
            scanf("%d", &cod_disc);
            printf("Digite o codigo do curso: \n");
            scanf("%d", &cod_curso);
            imprimirDadosDisciplinasDadoCodigoCurso(arvoreCursos, cod_curso, cod_disc);
            break;

        case 8:
            // 6)Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso;
            printf("Digite o bloco do curso: \n");
            scanf("%d", &bloco_curso);
            printf("Digite o codigo do curso: \n");
            scanf("%d", &cod_curso);
            imprimirDisciplinasBloco(arvoreCursos, bloco_curso, cod_curso); 
            break;

        case 9:
            // (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário;
            printf("Digite o codigo do curso: \n");
            scanf("%d", &cod_curso);
            printf("Digite a carga horaria: \n");
            scanf("%d", &carga_horaria);
            imprimirDisCargaHoraria(arvoreCursos, cod_curso, carga_horaria); 
            break;

        case 10:
            // (8) Excluir uma disciplina dado o código da disciplina e o código do curso;
            printf("Digite o codigo da disciplina: \n");
            scanf("%d", &cod_disc);
            printf("Digite o codigo do curso: \n");
            scanf("%d", &cod_curso);
            buscarCursoParaRemover(&arvoreCursos, cod_disc, cod_curso);
            break;

        case 11:
            // (9)Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
            printf("Digite o codigo do curso: \n");
            scanf("%d", &cod_curso);
            removerCurso(&arvoreCursos, cod_curso);
            break;

        default:
        printf("Essa opcao nao existe\n");
            break;
        }
    }

    return 0;
}