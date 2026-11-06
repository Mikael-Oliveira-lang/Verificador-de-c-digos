#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int menu(){
      int opc;
      system("clear");
      printf("[0] - Sair.\n");
      printf("[1] - Criar a fila.\n");
      printf("[2] - Enfileirar.\n");
      printf("[3] - Desenfileirar.\n");
      printf("[4] - Consultar o primeiro.\n");
      printf("[5] - Mostrar os elementos na fila.\n");
      printf("[6] - Destruir a fila.\n");
      
      printf("\nEscolha uma opção: ");
      scanf("%i", &opc);
      return opc;
}

int main(){
      Fila *a=NULL;
      int opc, vlr, *aux;
      while(opc = menu()){
            switch(opc){
                  case 1:
                          if (a != NULL){
                                printf("A fila já existe.\n");
                          }else{
                                a = criar_fila();
                                printf("A fila foi criada com sucesso.\n");
                          }
                  break;
                  case 2:
                          printf("valor: ");
                          scanf("%i", &vlr);
                          if (enfileirar(a, vlr)){
                                printf("%i enfileirado.\n", vlr);
                          }else{
                                printf("Falha ao efileirar %i.\n", vlr);
                          }
                  break;
                  case 3:
                          if (desenfileirar(a)){
                                printf("elemento desenfileirado.\n");
                          }else{
                                printf("Falha ao desenfileirar.\n");
                          }
                  break;
                  case 4:
                        aux = primeiro(a);
                        if (aux == NULL){
                              printf("Fila vazia.\n");
                        }else{
                              printf("Primeiro: %i\n", *aux);
                        }
                  break;
                  case 5:
                        mostrar_fila(a);
                  break;
                  case 6:
                        destruir_fila(&a);
                        printf("O espaço da fila foi removido.\n");
                  break;
                  default:
                        printf("opção inválida.\n");
            }
            getchar();
            getchar();
      }      
}

