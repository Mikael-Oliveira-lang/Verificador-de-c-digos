#include <stdio.h>
#include <stdlib.h>

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