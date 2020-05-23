#include "avl.h"


void liberar_memoria_impl ( TNo * no_ptr )
{
	if ( no_ptr == NULL )
		return;

	liberar_memoria_impl ( no_ptr->esq );
	liberar_memoria_impl ( no_ptr->dir );

	free ( no_ptr );
}


void liberar_memoria ( AVL * avl_ptr )
{
	liberar_memoria_impl ( avl_ptr->raiz );
}


AVL * init_avl ( )
{
	AVL * avl = NULL;

	if ( ( avl = malloc ( sizeof ( avl ) ) ) == NULL )
	{
		return NULL;
	}

	avl->raiz = NULL;

	return avl;
}

TNo * init_no ( int valor )
{
	TNo * no_ptr;

	no_ptr = malloc ( sizeof ( TNo ) );
	if ( no_ptr == NULL )
	{
		puts ( "o programa ficou sem memória\n" );
		system ( "pause" );
	}

	no_ptr->esq = NULL;
	no_ptr->dir = NULL;
	no_ptr->valor = valor;

	return no_ptr;
}

int altura ( TNo * no_ptr )
{
	int altura_esq = 0;
	int altura_dir = 0;

	if ( no_ptr->esq )
		altura_esq = altura ( no_ptr->esq );

	if ( no_ptr->dir )
		altura_dir = altura ( no_ptr->dir );

	return fmax( altura_dir, altura_esq ) + 1;
}


int fator_bal (TNo *no_ptr )
{
	int fator = 0;

	if ( no_ptr->esq )
		fator += altura ( no_ptr->esq );

	if ( no_ptr->dir )
		fator -= altura ( no_ptr->dir );

	return fator;
}


TNo * rotacionar_esq_esq (TNo * no_ptr)
{
	TNo * temp_ptr = no_ptr;
	TNo * esq_ptr = temp_ptr->esq;

	temp_ptr->esq = esq_ptr->dir;
	esq_ptr->dir = temp_ptr;

	return esq_ptr;
}

TNo * rotationar_esq_dir (TNo * no_ptr )
{
	TNo * const temp_ptr = no_ptr;
	TNo * esq_ptr = temp_ptr->esq;
	TNo * dir_ptr = esq_ptr->dir;

	temp_ptr->esq = dir_ptr->dir;
	esq_ptr->dir = dir_ptr->esq;
	dir_ptr->esq = esq_ptr;
	dir_ptr->dir = temp_ptr;

	return dir_ptr;
}

TNo * rotacionar_dir_esq (TNo * no_ptr )
{
	TNo * temp_ptr = no_ptr;
	TNo * dir_ptr = temp_ptr->dir;
	TNo * esq_ptr = dir_ptr->esq;

	temp_ptr->dir = esq_ptr->esq;
	dir_ptr->esq = esq_ptr->dir;
	esq_ptr->dir = dir_ptr;
	esq_ptr->esq = temp_ptr;

	return esq_ptr;
}


TNo * rotacionar_dir_dir (TNo *no_ptr )
{
	TNo * temp_ptr = no_ptr;
	TNo * dir_ptr = temp_ptr->dir;

	temp_ptr->dir = dir_ptr->esq;
	dir_ptr->esq = temp_ptr;

	return dir_ptr;
}

TNo * balancear_no ( TNo *no_ptr )
{
	TNo * no_balanceado = NULL;

	if ( no_ptr->esq )
		no_ptr->esq = balancear_no ( no_ptr->esq );

	if ( no_ptr->dir )
		no_ptr->dir = balancear_no ( no_ptr->dir );

	int fator = fator_bal ( no_ptr );

	if ( fator >= 2 )
	{
		/* pesando pra esquerda */

		if ( fator_bal ( no_ptr->esq ) <= -1 )
			no_balanceado = rotationar_esq_dir ( no_ptr );
		else
			no_balanceado = rotacionar_esq_esq ( no_ptr );

	}
	else if ( fator <= -2 )
	{
		/* pesando pra direita */

		if ( fator_bal ( no_ptr->dir ) >= 1 )
			no_balanceado = rotacionar_dir_esq ( no_ptr );
		else
			no_balanceado = rotacionar_dir_dir ( no_ptr );

	}
	else
	{
		no_balanceado = no_ptr;
	}

	return no_balanceado;
}


void balancear_avl ( AVL *avl_ptr )
{
	TNo * nova_raiz = NULL;

	nova_raiz = balancear_no ( avl_ptr->raiz );

	if ( nova_raiz != avl_ptr->raiz )
	{
		avl_ptr->raiz = nova_raiz;
	}
}

void inserir ( AVL * avl_ptr, int valor )
{
	TNo * novo_no_ptr = NULL;
	TNo * next_ptr = NULL;
	TNo * last_ptr = NULL;

	if ( avl_ptr->raiz == NULL )
	{
		novo_no_ptr = init_no ( valor );
		avl_ptr->raiz = novo_no_ptr;
	}
	else
	{
		next_ptr = avl_ptr->raiz;

		while ( next_ptr != NULL )
		{
			last_ptr = next_ptr;

			if ( valor < next_ptr->valor )
			{
				next_ptr = next_ptr->esq;

			}
			else if ( valor > next_ptr->valor )
			{
				next_ptr = next_ptr->dir;
			}
			else if ( valor == next_ptr->valor )
			{
				return;
			}
		}

		novo_no_ptr = init_no ( valor );

		if ( valor < last_ptr->valor )
			last_ptr->esq = novo_no_ptr;

		if ( valor > last_ptr->valor )
			last_ptr->dir = novo_no_ptr;

	}

	balancear_avl ( avl_ptr );
}

//retorna NULL se não encontrar. Essa é função para que a árvore é construída: para se buscar valores nela.
TNo * buscar (const AVL * const avl, int valor )
{
	TNo * atual = avl->raiz;

	while ( atual && atual->valor != valor )
	{
		if ( valor > atual->valor )
			atual = atual->dir;
		else
			atual = atual->esq;
	}

	return atual;
}

void listar ( TNo * no_ptr )
{
	if ( no_ptr != NULL )
	{
		printf ( "No = %d, altura = %d, FATBAL = %d\n", no_ptr->valor, altura ( no_ptr ), fator_bal ( no_ptr ) );
		listar ( no_ptr->esq );
		listar ( no_ptr->dir );
	}
}
void pause (float delay1) {

   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.

   float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;

   return;

}
