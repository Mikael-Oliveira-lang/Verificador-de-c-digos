#include <stdio.h>
#include <stdlib.h>

char buffer[256];
char nome_arquivo[50];

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
    if(contador != 0){
            printf("Sintaxe de parenteses incorreta.\n Quantidade de parenteses incorretos: %i", contador);
    }else
        printf("Sintaxe de parenteses correta.\n");
    fclose(arquivo);
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
    if(contador != 0){
        printf("Sintaxe de chaves incorreta.\n Numero de chaves incorretas %i", contador);
    }else
        printf("Sintaxe de chaves correta.\n");
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
    if(contador != 0){
        printf("Sintaxe de conchetes incorreta.\n Numero de conchetes incorretos: %i", contador);
    }else
    printf("Sintaxe de conchetes correta.\n");
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
    
    int opc;
    while(opc = menu()){
        switch(opc){
            case 0:
            return 0;
            
            case 1:
                printf("Escreva o nome do arquivo a ser verificado: ");
                scanf("%49s", nome_arquivo);
            contar_parenteses(nome_arquivo);
            break;
            
            case 2:
                printf("Escreva o nome do arquivo a ser verificado: ");
                scanf("%49s", nome_arquivo);
            contar_conchetes(nome_arquivo);
            break;
            
            case 3:
                printf("Escreva o nome do arquivo a ser verificado: ");
                scanf("%49s", nome_arquivo);
            contar_chaves(nome_arquivo);
            break;
            
            default:
                printf("Opção inválida.\n");
        }
        getchar();
        getchar();
    }
}