#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int main() {
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fclose(arquivo);
}