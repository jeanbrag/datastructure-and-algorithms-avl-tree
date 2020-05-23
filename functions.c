#include "functions.h"

int listarSeg ( TNo * no_ptr)
{
	int aux,consultorio,hora,flag=0;;
	if ( no_ptr != NULL )
	{
		if(((no_ptr->valor)>20000)&&((no_ptr->valor)<22500)){
					aux = no_ptr->valor;
					consultorio = aux % 100;
					hora = (aux/100)%100;
					printf("Horario: %dh\n",hora);
					printf("Consultorio: %d\n\n",consultorio);
					flag=1;
		}

		listarSeg ( no_ptr->esq);
		listarSeg ( no_ptr->dir);
	}
	return flag;
}

int listarTerc ( TNo * no_ptr )
{
	int aux,consultorio,hora,flag=0;
	if ( no_ptr != NULL )
	{
		if(((no_ptr->valor)>30000)&&((no_ptr->valor)<32500)){
			aux = no_ptr->valor;
					consultorio = aux % 100;
					hora = (aux/100)%100;
					printf("Horario: %dh\n",hora);
					printf("Consultorio: %d\n\n",consultorio);
					flag=1;
		}

		listarTerc ( no_ptr->esq );
		listarTerc ( no_ptr->dir );
	}
	return flag;
}

int listarQuart ( TNo * no_ptr )
{
	int aux,consultorio,hora,flag=0;
	if ( no_ptr != NULL )
	{
		if(((no_ptr->valor)>40000)&&((no_ptr->valor)<42500)){
			aux = no_ptr->valor;
					consultorio = aux % 100;
					hora = (aux/100)%100;
					printf("Horario: %dh\n",hora);
					printf("Consultorio: %d\n\n",consultorio);
					flag=1;
		}

		listarQuart ( no_ptr->esq );
		listarQuart ( no_ptr->dir );
	}
	return flag;
}

int listarQuint ( TNo * no_ptr )
{
	int aux,consultorio,hora,flag=0;
	if ( no_ptr != NULL )
	{
		if(((no_ptr->valor)>50000)&&((no_ptr->valor)<52500)){
			aux = no_ptr->valor;
					consultorio = aux % 100;
					hora = (aux/100)%100;
					printf("Horario: %dh\n",hora);
					printf("Consultorio: %d\n\n",consultorio);
					flag=1;
		}

		listarQuint ( no_ptr->esq );
		listarQuint ( no_ptr->dir );
	}
	return flag;
}

int listarSext ( TNo * no_ptr )
{
	int aux,consultorio,hora,flag=0;
	if ( no_ptr != NULL )
	{
		if(((no_ptr->valor)>60000)&&((no_ptr->valor)<62500)){
			aux = no_ptr->valor;
					consultorio = aux % 100;
					hora = (aux/100)%100;
					printf("Horario: %dh\n",hora);
					printf("Consultorio: %d\n\n",consultorio);
					flag=1;
		}

		listarSext ( no_ptr->esq );
		listarSext ( no_ptr->dir );
	}
	return flag;
}





void buscarConsulta(AVL *avl, int cod){
	TNo *a = buscar(avl,cod);
	int aux;
	int dia;
	int hora;
	int consultorio;
				if(a!=NULL){
					aux = a->valor;
					consultorio = aux % 100;
					hora = (aux/100)%100;
					dia = (aux/10000);
					printf("\nConsulta marcada para ");
					switch(dia){
						case 2: printf("segunda-feira\n");
								break;
						case 3: printf("terca-feira\n");
								break;
						case 4: printf("quarta-feira\n");
								break;
						case 5: printf("quinta-feira\n");
								break;
						case 6: printf("sexta-feira\n");
								break;
					}
					printf("Horario: %dh\n",hora);
					printf("Consultorio: %d",consultorio);
				}
				else {
					printf("Consulta nao existe\n");
				}
}


void diaConsulta(){
	printf("\n2 - segunda-feira\t");
	printf("3 - terca-feira \t");
	printf("4 - quarta-feira\t");
	printf("5 - quinta-feira\t");
	printf("6 - sexta-feira\n\n");
	printf("Escolha o dia da sua consulta: ");
}

void visualizaDia(){
	printf("\n2 - segunda-feira\t");
	printf("3 - terca-feira \t");
	printf("4 - quarta-feira\t");
	printf("5 - quinta-feira\t");
	printf("6 - sexta-feira\n\n");
	printf("Escolha o dia para visualizar: ");
}
void horaConsulta(){
	printf("Digite o horario que deseja ser atendido(9h-21h):");
}

int agendaConsulta(AVL *avl, int cod){
	TNo *a = buscar(avl,cod);
					if(a==NULL){
						inserir(avl,cod);
						printf("Seu numero de consulta: %d",cod);
						printf("  Consulta Marcada\n");
						return 1;
						}
					else{
						printf("Seu numero de consulta: %d",cod);
						printf("  Horario Indisponivel\n");
						return 0;
						}
}

int agendaConsultaM(AVL *avl, int cod){
	TNo *a = buscar(avl,cod);
					if(a==NULL){
						inserir(avl,cod);
						printf("\nSeu numero de consulta: %d",cod);
						printf("  Consulta Marcada\n");
						return 1;
						}
					else
						return 0;

}


void agendaManual(AVL *avl){
		srand(time(NULL));
		int cod;
		int dia;
		int hora;
		int aux;
    	diaConsulta();
    	scanf("%d",&dia);
    	hour: horaConsulta();
    	scanf("%d",&hora);
    	if((hora<9)||(hora==12)||(hora>21)||(hora==18)){
    		printf("\nHorario invalido!\n\n");
    		goto hour;
    	}
    	int consultorio= 1;
    	cod = (((dia*100)+hora)*100)+consultorio;
    	aux = agendaConsultaM(avl,cod);
    	if(!aux){
    	do{
    		consultorio++;
    		cod = (((dia*100)+hora)*100)+consultorio;
    		aux =agendaConsultaM(avl,cod);
    		if(aux)
    			break;
    	}while(consultorio<4);
    	}
    	if(!aux)
    		printf("\nHorario Indisponivel. Tente em outro horario.\n");
	}

int geraConsulta(){
   srand(time(NULL));

   int dia = rand()%7;

    switch(dia){
    case 0: dia=2;
    		break;
    case 1: dia=2;
    		break;
   }

	int horario= rand()%22;

    while(horario<9){
        horario= rand()%22;
    }
    if(horario==12)
        horario=13;
        else if(horario==18)
            horario=19;

    int consultorio= rand()%5;

    while(consultorio==0){
        consultorio = rand()%5;
    }

    int marcacao = (dia*100)+horario;
    int consulta = (marcacao*100)+consultorio;
    return consulta;

}

void n_consultas(AVL *avl,int x){
    int i=0;
    int cod;
    int aux;
    int aux2 = 0;
    while(i<x){
        cod = geraConsulta();
        i++;
        aux = agendaConsulta(avl,cod);
        aux2=aux2+aux;
        pause(1.0);
    }

    printf("%d\n",aux2);
    printf("---------");

}

void menu(){
  printf("\n\t##########################################");
  printf("\n\t##       Estruturas de Dados II         ##");
  printf("\n\t## Arvore Binaria  - AVL                ##");
  printf("\n\t## Agendamento Semanal - Clinica        ##");
  printf("\n\t##########################################");
  printf("\n\t## OPCOES ");
  printf("\n\t## 1 - Gerador de Consultas.");
  printf("\n\t## 2 - Agendar Consultas.");
  printf("\n\t## 3 - Buscar Consulta");
  printf("\n\t## 4 - Visualizar Consultas Marcadas");
  printf("\n\t## 5 - Exibir Arvore");
  printf("\n\t## 6 - Sair");
  printf("\n\t##########################################\n");
}
