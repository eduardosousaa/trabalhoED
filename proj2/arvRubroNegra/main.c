#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "rubro_negra.h"

int main() {
    srand(time(NULL));

    ArvRubroNegra *arvore = NULL, *No = NULL;
    const char *arquivo = "texto.txt";

    int op = -1, construiu = 0, achou = 0;
    char palavra[20];

    while(op!=0){
        printf("\n");
        printf("0 - Encerrar\n"
        "1 - Construir arvore a partir de um arquivo texto\n"
        "2 - Imprimir arvore em ordem\n"
        "3 - Buscar palavra\n"
        "Digite a opcao: ");
        scanf("%d", &op);
        switch (op){
            case 0:
                printf("Programa encerrado!\n");
                break;
            case 1: 
                construiu = lerArquivoTexto(&arvore, arquivo);
                if(construiu == 1){
                    printf("Arvore a partir do arquivo %s criada com sucesso!\n", arquivo);
                }else{
                    printf("Falha ao criar arvore a partir do arquivo %s!\n", arquivo);
                }
                break;
            case 2:
                imprmrInOrdem(arvore, 0);
                break;
            case 3:
                printf("Digite a palavra que deseja buscar: ");
                scanf("%s", palavra);
                achou = buscrPalvr(arvore, palavra, &No);
                if(achou == 1){
                    printf("A palavra '%s' esta presente nas seguintes linhas: ");
                    imprmrLinhs(No->info->num_lista, 0);
                    printf("\n");
                }else if(achou == 0){
                    printf("A palavra '%s' nao foi encontrada!\n");
                }
                break;
            default:
                printf("Essa opcao nao existe\n");
                break;
        }
    }

    return 0;
}