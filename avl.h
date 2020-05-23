#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <math.h>

struct node
{
	struct node * esq;
	struct node * dir;
	int valor;
};

typedef struct node TNo;

struct avl_struct
{
	TNo * raiz;
};

typedef struct avl_struct AVL;

void liberar_memoria_impl ( TNo * no_ptr );
void liberar_memoria ( AVL * avl_ptr );
AVL * init_avl ();
TNo * init_no ( int valor );
int altura ( TNo * no_ptr );
int fator_bal (TNo *no_ptr );
TNo * rotacionar_esq_esq (TNo * no_ptr);
TNo * rotationar_esq_dir (TNo * no_ptr );
TNo * rotacionar_dir_esq (TNo * no_ptr );
TNo * rotacionar_dir_dir (TNo *no_ptr );
TNo * balancear_no ( TNo *no_ptr );
void balancear_avl ( AVL *avl_ptr );
void inserir ( AVL * avl_ptr, int valor );
TNo * buscar (const AVL * const avl, int valor );
void listar ( TNo * no_ptr );
void pause (float delay1);