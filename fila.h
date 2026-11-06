typedef struct fila Fila;

Fila * criar_fila();
void destruir_fila(Fila **fila);
int enfileirar(Fila *fila, int vlr);
int *primeiro(Fila *fila);
int desenfileirar(Fila *fila);
void mostrar_fila(Fila *fila);

