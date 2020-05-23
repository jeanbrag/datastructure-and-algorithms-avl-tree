#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "avl.h"

int listarSeg ( TNo * no_ptr);
int listarTerc ( TNo * no_ptr );
int listarQuart ( TNo * no_ptr );
int listarQuint ( TNo * no_ptr );
int listarSext ( TNo * no_ptr );
void buscarConsulta(AVL *avl, int cod);
void diaConsulta();
void visualizaDia();
void horaConsulta();
int agendaConsulta(AVL *avl, int cod);
int agendaConsultaM(AVL *avl, int cod);
void agendaManual(AVL *avl);
int geraConsulta();
void n_consultas(AVL *avl,int x);
void menu();