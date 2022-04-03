#pragma warning(disable: 4996)
#include<stdio.h>
#include"gobal.h"

int main() {
	job* j;
	j = NULL;
	j = CriaJob(12);
	op* o1;
	o1 = NULL;
	o1 = Adicionar_operacao(1);
	j->op = Inserir_op(j->op, o1);
	maqtime* o_1_1, *o_1_2, *o_1_3;
	o_1_1 = NULL;
	o_1_1 = Criar_MT(1, 6);
	o1->mt = Inserir_Maquina(o1->mt, o_1_1);
	o_1_2 = NULL;
	o_1_2 = Criar_MT(2, 2);
	o1->mt = Inserir_Maquina(o1->mt, o_1_2); 
	o_1_3 = NULL;
	o_1_3 = Criar_MT(3, 4);
	o1->mt = Inserir_Maquina(o1->mt, o_1_3);


	op* o2;
	o2 = NULL;
	o2 = Adicionar_operacao(2);
	j->op = Inserir_op(j->op, o2);
	maqtime* o_2_1, * o_2_2, * o_2_3;
	o_2_1 = NULL;
	o_2_1 = Criar_MT(1, 5);
	o2->mt = Inserir_Maquina(o2->mt, o_2_1);
	o_2_2 = NULL;
	o_2_2 = Criar_MT(2, 2);
	o2->mt = Inserir_Maquina(o2->mt, o_2_2);
	o_2_3 = NULL;
	o_2_3 = Criar_MT(3, 7);
	o2->mt = Inserir_Maquina(o2->mt, o_2_3);
	


	op* o3;
	o3 = NULL;
	o3 = Adicionar_operacao(3);
	j->op = Inserir_op(j->op, o3);
	maqtime* o_3_1, * o_3_2, * o_3_3;
	o_3_1 = NULL;
	o_3_1 = Criar_MT(1, 5);
	o2->mt = Inserir_Maquina(o3->mt, o_3_1);
	o_3_2 = NULL;
	o_3_2 = Criar_MT(2, 2);
	o3->mt = Inserir_Maquina(o3->mt, o_3_2);
	o_3_3 = NULL;
	o_3_3 = Criar_MT(3, 7);
	o3->mt = Inserir_Maquina(o3->mt, o_3_3);
	
	int x;
	x = Guardar_dados_ficheiro("file.txt", j);
	printf("%d", x);

	j = Ler_dados_ficheiro("file.txt");
	printf("%d", j->op->mt->M);
	
}