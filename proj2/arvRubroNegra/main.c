#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "rubro_negra.h"

int main() {
    srand(time(NULL));

    ArvRubroNegra *arvore = NULL;
    const char *arquivo = "texto.txt";

    int op = -1, construiu = 0;;

    while(op!=0){
        printf("\n");
        printf("0 - Encerrar\n"
        "1 - Construir arvore a partir de um arquivo texto\n"
        "2 - Imprimir arvore em ordem\n"
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
            default:
                printf("Essa opcao nao existe\n");
                break;
        }
    }

    return 0;
}