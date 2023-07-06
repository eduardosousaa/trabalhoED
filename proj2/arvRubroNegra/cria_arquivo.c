#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* arquivo;

    arquivo = fopen("arquivo_texto.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    char *palavras[] = {
        "gato",
        "luffy",
        "zoro",
        "neymar",
        "cachorro",
        "onepiece",
        "altos",
        "lobo",
        "santos",
        "spider"
    };

    int numPalavras = sizeof(palavras) / sizeof(palavras[0]);

    for (int i = 0; i < numPalavras; i++) {
        fprintf(arquivo, "%s\n", palavras[i]); // Escrever cada palavra no arquivo
    }

    fclose(arquivo); // Fechar o arquivo

    printf("Arquivo criado com sucesso.\n");
}