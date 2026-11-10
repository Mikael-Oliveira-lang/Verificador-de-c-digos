#include <stdio.h>
#include <stdlib.h>

char buffer[256];
char nome_arquivo[30];

FILE* abrir_arquivo(char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return NULL;
    }
    for(; fgets (buffer, sizeof(buffer), arquivo) != NULL ;){
        printf("%s\n\n", buffer);
    }
    return arquivo;
}

void contar_parenteses(char *nome_arquivo){
    FILE *arquivo = abrir_arquivo(nome_arquivo);
    if(arquivo == NULL){
        return;
    }
    int i, contador = 0;
    for(; fgets (buffer, sizeof(buffer), arquivo) != NULL ;)
    for(i = 0; buffer[i] != '\0'; i++){
        if(buffer[i] == '('){
            contador++;
        }else if(buffer[i] == ')'){
            contador--;
        }
    }
    if(contador == 0){
            printf("Sintaxe de parenteses correta.\n");
        }else
            printf("Sintaxe de parenteses incorreta.\n Quantidade de parenteses incorretos: %i", contador);
        fclose (arquivo);
}

void contar_chaves(char *nome_arquivo){
    FILE *arquivo = abrir_arquivo(nome_arquivo);
    if(arquivo == NULL){
        return;
    }
    int i, contador = 0;
    for(; fgets(buffer, sizeof(buffer), arquivo) != NULL ;)
    for(i = 0; buffer[i] != '\0'; i++){
        if(buffer[i] == '{'){
            contador++;
        }else if(buffer[i] == '}'){
            contador--;
        }
    }
    if(contador == 0){
        printf("Sintaxe de chaves correta.\n");
    }else
        printf("Sintaxe de chaves incorreta.\n Numero de chaves incorretas %i", contador);
        fclose(arquivo);
}

void contar_conchetes(char *nome_arquivo){
    FILE *arquivo = abrir_arquivo(nome_arquivo);
    if(arquivo == NULL){
        return;
    }
    int i, contador = 0;
    for(; fgets(buffer, sizeof(buffer), arquivo) != NULL ;)
    if(buffer[i] == '['){
        contador++;
    }else if(buffer[i] == ']'){
        contador--;
    }
    if(contador == 0){
        printf("Sintaxe de conchetes correta.\n");
    }else
    printf("Sintaxe de conchetes incorreta.\n Numero de conchetes incorretos: %i", contador);
    fclose(arquivo);
}

int menu(){
    int opc;
    system("clear");
    printf("[0] - Sair.\n");
    printf("[1] - Verificar parenteses.\n");
    printf("[2] - Verificar conchetes.\n");
    printf("[3] - Verificar chaves.\n");

    printf("\nEscolha uma opção: ");
    scanf("%i", &opc);
    return opc;
}

int main() {
    
    int opc, vlr;
    while(opc = menu()){
        switch(opc){
            case 0:
            return 0;
            break;
            case 1:
            contar_parenteses(nome_arquivo);
            break;
            case 2:
            contar_conchetes(nome_arquivo);
            break;
            case 3:
            contar_chaves(nome_arquivo);
            break;
            default:
            printf("Opção inválida.\n");
        }
        getchar();
        getchar();
    }
}