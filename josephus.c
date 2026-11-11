#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct No{
    int id;
    struct No *prox;
}soldado;

void mostrar_soldado(soldado *inicio) {
    soldado *aux;
    if(inicio == NULL){
        printf("A lista está vazia.\n");
        return;
    }
    aux = inicio;
    do {
        printf("Soldado: %d\n", aux->id);
        aux = aux->prox;
    } while(aux != inicio);
}

void inserir_soldado(soldado **inicio){
    soldado *novo = (soldado*) malloc(sizeof(soldado));
    if(inicio == NULL){
        printf("Falha ao inserir o soldado.\n");
        return;
    }
    novo = novo->id;

    if(*inicio == NULL){
        inicio = novo;
        novo->prox = inicio;
    } else {

    }
}