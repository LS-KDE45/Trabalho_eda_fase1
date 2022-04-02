#pragma warning(disable: 4996)
#include<stdio.h>
#include"gobal.h"


/**
* Autor: Luís Queirós
* Email: luisqueiros21@gmail.com
* Date 20-03-2022
* Desc: Módulo de funções
*/


/**
* Função para criar job
*/


job* CriaJob(int cod) {
	job* x = (job*)malloc(sizeof(job));
	if (x == NULL) return NULL;	//  ver se tem espaço espaço disponível
	x->cod = cod;
	x->op = NULL;
	x->next = NULL;
	return x;
}


/**
* Função de adicionar operações
*/

op* Adicionar_operacao(int cod_o) {
	op* o;
	o = (op*)malloc(sizeof(op));
	if (o == NULL) return NULL; //  ver se tem espaço espaço disponível
	o->cod = cod_o;
	o->mt = NULL;
	o->next = NULL;
	return o;
}


/**
* Função de ordenar operações
*/

op* Inserir_op(op* h, op* o) {
	if (o == NULL)return NULL; //caso não exista a operação
	if (h == NULL)		//caso a lista de operações não tenha header
	{
		h = o;
	}
	else {
		if (existe_op(h, o->cod) == 1)return h; //caso essa operação já exista nesse job 
		else
		{
			op* aux = h;
			while (aux->next != NULL) {
				aux = aux->next;
			}
			aux->next = o;// insere no fim uma nova operacao
		}
	}
	return h;
}

/**
* Função para ver se existe operação
*/

int existe_op(op* o, int codigo)
{
	op* aux = o;

	if (o == NULL) return 0; //caso não exista operações

	while (aux)
	{
		if (aux->cod == codigo)	//procurar o codigo
			return 1;
		else
		{
			aux = aux->next;
		}
	}

	return 0;
}

/**
* Função de ordenar maquina tempo
*/

maqtime* Inserir_Maquina(maqtime* h, maqtime* mt)	
{
	if (mt == NULL) return NULL;	//se o novo maqtime não existir

	if (h == NULL)			//se não existir nenhuma maquina na operaçao,insere a maquina e respetivo tempo
	{
		h = mt;
	}
	else
	{
		if (existe_maq(h, mt->M) == 1) return h; //se já existir a maquina na operçao, nao insere
		else
		{
			maqtime* aux;
			aux = h;
			while (aux->next != NULL) {
				aux = aux->next;
			}
			aux->next = mt;// insere no fim uma nova operacao
		}
	}

	return h;
}


/**
* Função para ver se existe maquina
*/

int existe_maq(maqtime* mt, int M)
{
	if (mt == NULL) return 0;//caso não exista operações
	maqtime* aux = mt;
	while (aux != NULL)
	{
		if (aux->M == M)//procurar o codigo
		{
			return 1;
		}
		else
		{
			aux = aux->next;
		}
	}

	return 0;
}

/**
* Função de criar maquina tempo
*/


maqtime* Criar_MT(int M, int T) {
	maqtime* mt;
	mt = (maqtime*)malloc(sizeof(maqtime));
	if (mt == NULL) return NULL; //  ver se tem espaço espaço disponível
	mt->M = M;
	mt->T = T;
	mt->next = NULL;
	return mt;
}


/**
* Funções de determinação de quantidade mínima de unidades de tempo
*/

/**
* Função de determinação de quantidade mínima de unidades de tempo por operação
*/

maqtime* Det_min(op* o) {
	if (o == NULL) return NULL;//caso não exista operação
	if (o->mt == NULL)return NULL;//caso não existam maquinas
	maqtime* aux = o->mt, * aux2 = aux->next;
	while (aux2 != NULL) { // procura na lista qual a maquina com menor tempo
		if (aux->T > aux2->T) {
			aux = aux2;
		}
		aux2 = aux2->next;
	}
	return aux;
}


/**
* Função de determinação de quantidade mínima de unidades de tempo por job
*/

int Det_min_o(job* j) {
	if (j == NULL)return -1;//caso não existam jobs
	if (j->op == NULL)return -1;//caso não existam operações
	op* o = j->op;
	if (o->mt == NULL)return -1;//caso não existam maquinas
	maqtime* mt;
	int soma = 0;
	while (o != NULL) {
		mt = Det_min(o);
		printf("op: %d, maq: %d, temp: %d", o->cod, mt->M, mt->T);//diz a operação, a maquina com menor tempo e o respetivo tempo
		soma += mt->T;
		o = o->next;
	}
	return soma;
}

/**
* Funções de determinação de quantidade máxima de unidades de tempo
*/

/**
* Função de determinação de quantidade máxima de unidades de tempo por operação
*/

maqtime* Det_max(op* o) {
	if (o == NULL) return NULL;//caso não exista operação
	if (o->mt == NULL)return NULL;//caso não existam maquinas
	maqtime* aux = o->mt, * aux2 = aux->next;
	while (aux2 != NULL) { // procura na lista qual a maquina com maior tempo
		if (aux->T < aux2->T) {
			aux = aux2;
		}
		aux2 = aux2->next;
	}
	return aux;
}


/**
* Função de determinação de quantidade máxima de unidades de tempo por job
*/

int Det_max_o(job* j) {
	if (j == NULL)return -1;//caso não existam jobs
	if (j->op == NULL)return -1;//caso não existam operações
	op* o = j->op;
	if (o->mt == NULL)return -1;//caso não existam maquinas
	maqtime* mt;
	int soma = 0;
	while (o != NULL) {
		mt = Det_max(o);
		printf("op: %d, maq: %d, temp: %d", o->cod, mt->M, mt->T);//diz a operação, a maquina com maior tempo e o respetivo tempo
		soma += mt->T;
		o = o->next;
	}
	return soma;
}


/**
* Função de determinação de quantidade média de unidades de tempo por operação
*/

float Det_media_temp(op* o) {
	if (o->mt == NULL) return 0;//caso não existam maquinas tempo
	maqtime* mt;
	mt = o->mt;
	int soma = 0, contador = 0;
	float media;
	while (mt != NULL) {
		soma = soma + mt->T;
		mt = mt->next;
		contador++;
	}
	media = soma / contador;
	return media;

}


/**
* Função de Remoção de operações
*/

op* Remover_op(op* h, int cod_o) {
	if (h == NULL) return NULL;		//se a lista for vazia
	op* aux;
	if (h->cod == cod_o) {// se for na primeira posição
		aux = h;
		h = h->next;
		free(aux);
	}
	else {
		aux = h;
		op* Ant_aux = aux;
		while (aux && aux->cod != cod_o) {// procurar o codigo
			Ant_aux = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					//se encontrou, remove
			Ant_aux->next = aux->next;
			free(aux);
		}

	}
	return h;
}

/**
* Função para alterar maqtime
*/

maqtime* Alterar_MT(maqtime* h, int M, int n_M, int n_T) {
	if (h == NULL) return NULL;//caso õ header não exista
	maqtime* aux = h;
	while (aux->M != M && aux != NULL) {
		aux = aux->next;
	}
	if (aux == NULL)return NULL; //caso não exista essa maquina
	aux->M = n_M;
	aux->T = n_T;
	return h;
}


/**
* Função para retirar maqtime
*/

maqtime* Apagar_MT(maqtime* h, int M) {
	if (h == NULL) return NULL;// caso não exista maquina tempo
	maqtime* aux;
	if (h->M == M) {// se for na primeira posição
		aux = h;
		h = h->next;
		free(aux);
	}
	else {
		aux = h;
		maqtime* Ant_aux;
		Ant_aux = aux;
		while (aux && aux->M != M) {// procurar a maquina
			Ant_aux = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					//se encontrou, remove
			Ant_aux->next = aux->next;
			free(aux);
		}

	}
	return h;
}


/**
* Função de alteração de operações
*/

op* Alteracao_op(op* h, int cod, int cod_novo) {
	if (h == NULL) return NULL;// caso não exista header
	op* aux = h;
	while (aux != NULL && aux->cod != cod) {
		aux = aux->next;
	}
	if (aux == NULL)return NULL;//caso não exista o codigo
	aux->cod = cod_novo;
	return h;
}


/**
* Função para guardar dados em ficheiros txt
*/


int Guardar_dados_ficheiro(char* nomefile, job* j) {
	FILE* fp;

	if (j == NULL) return -1;//caso não existam jobs
	op* o;
	o = j->op;
	maqtime* mt;
	fp = fopen(nomefile, "w");
	fprintf(fp, "j\n%d\n", j->cod);//coloca-se a letra j para identificar o codigo, e escrevo o codigo do job
	while (o != NULL) {
		fprintf(fp, "o\n%d\n", o->cod);//coloca-se a letra o para identificar o codigo, e escrevo o codigo do o
		mt = o->mt;
		while (mt != NULL) {
			fprintf(fp, "m\n%d;%d\n", mt->M, mt->T);//coloca-se a letra m para identificar o codigo, e escrevo o numero da maquina e o tempo
			mt = mt->next;
		}
		o = o->next;
	}
	fprintf(fp, "e");//coloca-se a letra e para saber o fim do ficheiro
	fclose(fp);
	return 0;
}

/**
* Função para ler dados em ficheiros txt
*/


job* Ler_dados_ficheiro(char* nomefile) {
	char sitio = NULL;
	int temp_m, temp_t, temp_codj, temp_codo;
	FILE* fp;
	if ((fp = fopen(nomefile, "r")) == NULL) return -1;//caso não exista o file
	job* j;
	j = NULL;
	op* o;
	o = NULL;
	maqtime* mt;
	mt = NULL;
	while (fp != NULL && sitio != 'e') {
		fscanf(fp, "%c", &sitio);
		if (sitio == 'm') {//caso a letra seja m escreve no maquina tempo
			fscanf(fp, "%d;%d", &temp_m, &temp_t);
			mt = Criar_MT(temp_m, temp_t);
			o->mt = Inserir_Maquina(o->mt, mt);
		}
		else {
			if (sitio == 'o') {//caso a letra seja o escreve nas operações
				fscanf(fp, "%d", &temp_codo);
				o = Adicionar_operacao(temp_codo);
				j->op = Inserir_op(j->op, o);
			}
			else {
				if (sitio == 'j') {//caso a letra seja j escreve nos jobs
					fscanf(fp, "%d", &temp_codj);
					j = CriaJob(temp_codj);
				}
			}
		}


	}
	return j;
}