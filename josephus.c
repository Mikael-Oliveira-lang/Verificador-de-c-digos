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

        for(soldado *aux = inicio->prox; aux != inicio; aux = aux->prox);
    }
}