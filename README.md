# Sistema de agendamento de consulta
Implementação de uma árvore avl em um sistema de agendamento de consultas como parte da disciplina de Algoritmos e Estrutura de Dados

## Enunciado
 Deve-se construir um programa que faça a marcação de sessões terapêuticas, usando para registrar essas marcações árvores AVL. 

Para gerar os pedidos, deve-se perguntar inicialmente o número de pedidos, e com esse número gerar aleatoriamente o dia e hora de todos os pedidos. Lembre-se que pode haver pedidos que não poderão ser atendidos por falta de disponibilidade de consultório.

Levar em consideração os seguintes aspectos:

A) Considere que a clínica possui 4 consultórios, com disponibilidade para atendimento, de 2a. a 6a. feira, em três turnos:

 * Turno matutino: das 9h às 12h, sendo o último horário de marcação às 11h. Portanto 3h de atendimento.

 * Turno vespertino: das 13h às 18h, sendo o último horário de marcação às 17h. Portanto 5h de atendimento.

* Turno noturno: das 19h às 22h, sendo o último horário de marcação às 21h. Portanto 3h de atendimento.

 Assim, cada consultório possui a disponibilidade máxima de 10h de atendimento por dia.

B) Considere ainda que não há limites de terapeutas. Apenas que cada terapeuta possa atender no máximo 3h por dia, e 10h por semana.

C) Considere que o paciente pode realizar o pedido de atendimento por horário (dia e hora).

D)  Ao ser confirmado o horário (dia e hora) do atendimento, aquele horário, naquele consultório passa a ficar bloqueado para outros atendimentos por um tempo que o terapeuta julgar necessário.

E) Ao ocorrer o atendimento no horário e consultório previsto, o terapeuta ira registrar o atendimento, e confirmar o próximo atendimento do referido paciente atendido, normalmente para a semana subsequente, no mesmo horário e consultório.

F) O sistema deverá apresentar relatórios de marcação de atendimentos para o paciente, para o terapeuta e para o administrativo. Podendo estes serem diários, semanais e mensais.

## Implementação

* O programa foi construído para a marcação de consultas afim de facilitar a administração semanal dos 4 consultórios da clínica.
* Este pode apresentar relatórios mostrando as consultas agendadas no dia escolhido, fazer marcação de novas consultas e buscar informações a respeito de uma consulta já agendada.
* Há ainda uma função de testes, que gera aleatoriamente uma série de consultas.
* Todo o programa é baseado no uso de códigos de consultas, que são gerados na hora da marcação, ou aleatoriamente pelo Gerador de Testes. Usei como inspiração o conceito de Hashing.  


O código gerado é um número de 5 dígitos.
Sendo esta a composição:
* 1º Dígito - Dia da Consulta (2 - Segunda-Feira, 3 - Terça-Feira, 4 - Quarta-Feira, 5 - Quinta-Feira, 6 - Sexta-Feira).
* 2º e 3º Dígitos - Horário da Consulta.
* 4º e 5º Dígitos - Número do Consultório.  

**Exemplo**: 51403.  

Para o código acima, o algoritmo entende que esta consulta está marcada para: _Quinta-Feira, às 14h no Consultório 03_  

Supondo que o usuário não saiba o significado, basta fazer uma busca no programa utilizando o código de sua consulta que será informado as informações da mesma.
