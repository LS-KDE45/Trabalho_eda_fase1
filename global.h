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

maqtime* Criar_MT(int M, int T);
//op* Criar_op(int cod, int M, int T);
job* CriaJob(int cod);
job* Procura_job(job* j, int cod);
op* Procura_op(int cod, op* o);
op* Adicionar_operacao(job* j, int cod_j, int cod_o);
op* Inserir_op(op* o, job* j);
int existe_job(job* j, int codigo);
int existe_op(op* o, int codigo);
int existe_maq(maqtime* maq, int maquina);
op* Remover_op(job* j, int cod_j, int cod_o);
op* Alteracao_op(job* j, int cod_j, int cod_o, int M, int T);
int Determinacao_min_temp(job* j, int cod_j);
int Det_min_temp_mt(maqtime* mt, int min);
int Det_min_temp_o(op* o, int somado);
void Listar_operacoes_de_job(job* j);
int Determinacao_max_temp(job* j, int cod_j);
int Det_max_temp_mt(maqtime* mt, int max);
int Det_max_temp_o(op* o, int somado);
float Det_media_temp(op* o);
int Guardar_dados_ficheiro(char* nomefile, job* j);
job* Ler_dados_ficheiro(char* nomefile);
#endif