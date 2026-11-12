#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50

typedef struct No{
    int id;
    struct No *prox;
}soldado;

void mostrar_soldado(soldado *ini) {
    soldado *aux;
    if(ini == NULL){
        printf("A lista está vazia.\n");
        return;
    }
    aux = ini;
    do {
        printf("Soldado: %d\n", aux->id);
        aux = aux->prox;
    } while(aux != ini);
}
void inserir_soldado(soldado **ini){
        soldado *novo = (soldado*) malloc(sizeof(soldado));
        soldado *aux;
    if(novo == NULL){
        return;
    }
    scanf("%d", &novo->id);

    if(*ini == NULL){
        *ini = novo;
        novo->prox = *ini;
    }else {
    aux = *ini;
        
        while(aux->prox != *ini){
        aux = aux->prox;
        }
    }
    aux->prox = novo;
    novo->prox = *ini;   
}

soldado *sortear_soldado(soldado *ini){
    int total = 0;
    int qtd = 0;
    soldado *aux;
    
    if(ini == NULL){
        printf("Falha ao sortear soldado.\n");
        return NULL;
    }
    aux = ini;
    do {
        total++;
        aux = aux->prox;
    } while(aux != ini);
    qtd = rand() % total;
    for(int i = 0; i < qtd; i++){
        aux = aux->prox;
    }
    return aux;
}

void remover_soldado(soldado **ini, soldado *sorteado){
    if(*ini == NULL || sorteado == NULL){
        printf("Falha ao remover soldado.\n");
        return;
    }
    
    soldado *aux = *ini;
    int total = 0, n;
    do{
        aux = aux->prox;
    }while(aux != *ini);
    
    n = (rand() % total) + 1;
    printf("Número N sorteado: %d\n", n);
    
    soldado *atual = sorteado;
    soldado *anterior = NULL;
    while(atual->prox != atual){
        for(int i = 1 ; i < n ; i++ ){
            anterior = atual;
            atual = atual->prox;
        }
    }
}