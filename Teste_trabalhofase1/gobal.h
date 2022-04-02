#include<stdio.h>
/**
* Autor: Luís Queirós
* Email: luisqueiros21@gmail.com
* Date 20-03-2022
* Desc: Módulo de conteúdos globais
*/


#ifndef DADOSGLOBAIS
#define DADOSGLOBAIS

typedef struct maqtime {
	int M;
	int T;
	struct maqtime* next;
}maqtime;




typedef struct op {
	int cod;
	struct maqtime* mt;
	struct op* next;
}op;

typedef struct job {
	int cod;
	struct op* op;
	struct job* next;
}job;

job* CriaJob(int cod);
op* Adicionar_operacao(int cod_o);
op* Inserir_op(op* h, op* o);
int existe_op(op* o, int codigo);
int existe_maq(maqtime* mt, int M);
maqtime* Inserir_Maquina(maqtime* h, maqtime* mt);
maqtime* Criar_MT(int M, int T);
maqtime* Det_min(op* o);
int Det_min_o(job* j);
maqtime* Det_max(op* o);
int Det_max_o(job* j);
float Det_media_temp(op* o);
op* Remover_op(op* h, int cod_o);
maqtime* Alterar_MT(maqtime* h, int M, int n_M, int n_T);
maqtime* Apagar_MT(maqtime* h, int M);
op* Alteracao_op(op* h, int cod, int cod_novo);
int Guardar_dados_ficheiro(char* nomefile, job* j);
job* Ler_dados_ficheiro(char* nomefile);
#endif