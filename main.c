#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

#include "functions.h"

int main(){

	AVL *avl1 = init_avl();
	int op;
    menu();
    dig: printf("Digite sua opcao: ");
	scanf("%d",&op);
	if((op<1)||(op>6))
        goto dig;
	int cod;
	int aux, aux2;
do{

	switch(op){
		case 1: printf("Digite o numero de consultas a ser gerado: ");
				scanf("%d",&aux);
				n_consultas(avl1,aux);
				pause(2);
				printf("\n");
				menu();
				printf("Digite sua opcao: ");
				break;
		case 2:	agendaManual(avl1);
				pause(2);
				printf("\n");
				menu();
				printf("Digite sua opcao: ");
				break;
		case 3: printf("Digite o codigo da consulta: ");
				scanf("%d",&cod);
				buscarConsulta(avl1,cod);
				pause(2);
				printf("\n");
				menu();
				printf("Digite sua opcao: ");
				break;

		case 4: visualizaDia();
				scanf("%d",&aux);
				switch(aux){
					case 2:	printf("\nConsulta marcadas para Segunda-Feira:\n\n");
							aux2=listarSeg(avl1->raiz);
							if(!aux2)
								printf("Nao ha consultas neste dia!\n\n");
							break;
					case 3: printf("\nConsulta marcadas para Terca-Feira:\n\n");
							aux2=listarTerc(avl1->raiz);
							if(!aux2)
								printf("Nao ha consultas neste dia!\n\n");
							break;
					case 4: printf("\nConsulta marcadas para Quarta-Feira:\n\n");
							aux2=listarQuart(avl1->raiz);
							if(!aux2)
								printf("Nao ha consultas neste dia!\n\n");
							break;
					case 5: printf("\nConsulta marcadas para Quinta-Feira:\n\n");
							aux2=listarQuint(avl1->raiz);
							if(!aux2)
								printf("Nao ha consultas neste dia!\n\n");
							break;
					case 6: printf("\nConsulta marcadas para Sexta-Feira:\n\n");
							aux2=listarSext(avl1->raiz);
							if(!aux2)
								printf("Nao ha consultas neste dia!\n\n");
							break;

				}

				pause(2);
				printf("\n");
				menu();
				printf("Digite sua opcao: ");
				break;
		case 5: listar(avl1->raiz);
                pause(2);
				printf("\n");
				menu();
				printf("Digite sua opcao: ");
				break;

	}

	scanf("%d",&op);
	if((op<1)||(op>6))
        goto dig;
}while(op!=6);
printf("\nFIM DO PROGRAMA!\n");
return 0;
}
