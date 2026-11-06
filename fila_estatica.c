#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define TAM 3

struct fila{
      int vet[TAM];
      int ini, fim;
};

void verificar_fila_nula(Fila *fila){
      if (fila == NULL){
            printf("A fila não foi criada.\n");
            exit(1);
      }
}

Fila * criar_fila() { 
      Fila *fila;
      fila = (Fila *)malloc(sizeof(Fila));
      if (fila == NULL){
            printf("Erro ao alocar o espaço para a fila.\n");
            exit(1);
      }
      fila->ini = 0; // Inicialização da fila
      fila->fim = 0; // Inicialização da fila
      return fila;
}

void destruir_fila(Fila **fila) { 
      verificar_fila_nula(*fila);
      if (*fila == NULL){
            printf("A fila não existe.\n");
      }else{
            free(*fila);
            *fila = NULL;
      }
}

int enfileirar(Fila *fila, int vlr){ 
      verificar_fila_nula(fila);
      if ( fila->ini == (fila->fim+1)%TAM ) {// Fila cheia
            return 0;
      }
      fila->vet[fila->fim] = vlr;
      fila->fim = (fila->fim+1)%TAM;
      return 1;
}

int *primeiro(Fila *fila){ 
      verificar_fila_nula(fila);
      if (fila->ini == fila->fim) { // fila vazia.
            return NULL;
      }
      return &fila->vet[ fila->ini];
}

int desenfileirar(Fila *fila){ 
      verificar_fila_nula(fila);
      if (fila->ini == fila->fim) { // fila vazia.
            return 0;
      }
      fila->ini = (fila->ini+1)%TAM;
      return 1;
}

void mostrar_fila(Fila *fila){ 
      verificar_fila_nula(fila);
      if (fila->ini == fila->fim) { // Fila vazia
            printf("Fila vazia.\n");
      }else{
          for(int i=fila->ini; i != fila->fim ; i=(i+1)%TAM){
                printf("%i\n", fila->vet[i]);
          }
      }
}

