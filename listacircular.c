#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
        int dado;
        struct no *prox;
}No;

int inserir_no_fim_LC(No **c, int vlr){
      No *novo;
      novo = (No *) malloc(sizeof(No));
      if (novo == NULL)
            return 0;
      novo->dado = vlr;
      novo->prox = NULL;
      
      if (*c == NULL){
              *c = novo;
              novo->prox = novo;
      }else{
              No *p;
              for (p = *c; p->prox != *c; p=p->prox);
              p->prox = novo;
              novo->prox = *c;
      }
      return 1;
}

void mostrar_lista(No *c){
      if (c == NULL){
            printf("Lista vazia.\n");
      }else{      
            No *p;
            printf("%i\n", c->dado);
            for (p=c->prox; p != c; p=p->prox){
                  printf("%i\n", p->dado);
            }            
      }      
}

int remover_no_fim_LC(No **c){
      if (*c == NULL)
              return 0;
      No *p, *q;
      q=NULL;
      for (p=*c; p->prox!=*c; p=p->prox){
            q = p;
      }
      if (q == NULL){ // A lista tem apenas 1 elemento
              free(p);
              *c = NULL;
      }else{
            free(p);
            q->prox = *c;
      }
      return 1;
}

int main(){
      No *cabeca=NULL;
      
      inserir_no_fim_LC(&cabeca, 10);
      inserir_no_fim_LC(&cabeca, 20);
      inserir_no_fim_LC(&cabeca, 30);
      
      mostrar_lista(cabeca);
      
      remover_no_fim_LC(&cabeca);
      printf("após a remoção.\n");
      mostrar_lista(cabeca);

      remover_no_fim_LC(&cabeca);
      printf("após a remoção.\n");
      mostrar_lista(cabeca);

      remover_no_fim_LC(&cabeca);
      printf("após a remoção.\n");
      mostrar_lista(cabeca);


}
