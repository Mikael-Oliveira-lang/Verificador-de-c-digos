#include <stdio.h>
#include <stdlib.h>

char buffer[256];
char nome_arquivo[100];

void abrir_arquivo(char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    for(; fgets (buffer, sizeof(buffer), arquivo) != NULL ;){
        printf("%s\n\n", buffer);
    }
    fclose(arquivo);
}

void contar_parenteses(char *nome_arquivo){
    for(int = 0; buffer[i] != '\0'; i++){
        
    }
}

int main() {
    
    int contador = 0;

    printf("Digite o nome do arquivo: ");
scanf("%s", nome_arquivo);

abrir_arquivo(nome_arquivo);

for(int i = 0; buffer[i] != '\0'; i++){
    if(buffer[i] == '('){
        contador++;
    }else if(buffer[i] == ')'){
        contador--;
    }
    if(contador == 0){
        printf("Sintaxe de parenteses correta.\n");
    }else if(contador != 0){
        printf("Sintaxe de parenteses incorretas.\n" "Números de parenteses incorretos %i", contador);
    }
}
}