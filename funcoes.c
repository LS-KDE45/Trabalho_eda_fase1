#pragma warning(disable: 4996)
#include<stdio.h>
#include"global.h"


/**
* Autor: Luís Queirós
* Email: luisqueiros21@gmail.com
* Date 20-03-2022
* Desc: Módulo de funções 
*/

							//////  perguntar ao stor sobre as maquinas e tempo serem listas ou não


							////// perguntar sobre as operação quando se retira, retira se tudo ou não





							// falta adicionar funções ao .h


/**
* Função para criar maqtime
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
* Função para criar operação
*/

//op* Criar_op(int cod, int M, int T) {
//	op* x;
//	maqtime* mt;
//	mt = (maqtime*)malloc(sizeof(maqtime));
//	mt=Criar_MT(M, T);
//	x = (op*)malloc(sizeof(op));
//	while (x != NULL) {
//		x = x->next;
//	}
//	x->cod = cod;		
//	x->mt = mt;
//	x->next = NULL;
//	return x;
//}

/**
* Função para criar tipo
*/

//tipo* Criartipo(char nome[4], int M, int T,int cod) {
//	op* y = Criar_op(M, T, cod);
//	tipo* x;
//	x = (tipo*)malloc(sizeof(tipo));
//	strcpy(x->tipo, nome);
//	x->op = y;
//	x->next = NULL;
//	return x;
//}




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
* Função de procurar jobs
*/

job* Procura_job(job* j, int cod) {
	if (j == NULL) return NULL; //ve se existe o head
	else {
		while (j->cod != cod && j != NULL) {
			j = j->next;
		}
		if (j == NULL)return NULL; //caso não exista esse job
		return j;
	}
}



/**
* Função de procurar operações
*/

op* Procura_op(int cod, op* o ) {
	if (o == NULL) return NULL; //ve se existe o head
	else {
		while (o->cod != cod && o != NULL) {
			o = o->next;
		}
		if (o == NULL)return NULL; //caso não exista essa op
		return o;
	}
}

/**
* Função de procurar maquina e tempo
*/

maqtime* Procura_mt(maqtime* mt, int M) {
	if (mt == NULL) return NULL; //se o header existe
	else {
		while (mt->M != M && mt != NULL) {
			mt = mt->next;
		}
		if (mt == NULL)return NULL; //caso não exista esse job
		return mt;
	}
}

/**
* Função de adicionar operações
*/


op* Adicionar_operacao(job* j,int cod_j, int cod_o) {
	job* jb;
	op* o;
	o = (op*)malloc(sizeof(op));
	if (j == NULL) return NULL; //  ver se tem espaço espaço disponível
	jb = Procura_job(j, cod_j);
	o = jb->op;
	/*maqtime* mt;
	mt = (maqtime*)malloc(sizeof(maqtime));						// ver se fica direito
	mt = Criar_MT(M, T);*/
	o->cod = cod_o;
	o->mt = NULL;
	o->next = NULL;
	return o;
}


/**
* Função de ordenar operações
*/

op* Inserir_op(op* o, job* j) {
	if (j == NULL)return NULL; //caso não exista o header de jobs
	if (o == NULL)return NULL; //caso não exista o header de operações
	op* aux = o;
	if (j->op == NULL)		//caso o lista de operações não exista na lista de jobs
	{
		j->op = o;
	}
	else {
		if (existe_op(j->op, o->cod) == 1)return j; //caso essa operação já exista nesse job 
		else
		{
			while (o != NULL) {
				o = o->next;
			}
			o = aux;// insere no fim uma nova operacao
		}
	}

}
/**
* Função para ver se existe job
*/

int existe_job(job* j, int codigo)
{
	if (j == NULL) return 0; //caso não exista jobs
	job* aux = j;
	while (aux != NULL)	//procurar o codigo
	{
		if (aux->cod == codigo)
			return 1;
		else
		{
			aux = aux->next;
		}
	}
	return 0;
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
* Função para ver se existe maquina tempo
*/

int existe_maq(maqtime* maq, int maquina)
{
	maqtime* aux = maq;

	if (maq == NULL) return 0;//caso não exista operações

	while (aux != NULL)
	{
		if (aux->M = maquina)//procurar o codigo
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
* Função de Remoção de operações
*/													

op* Remover_op(job* j, int cod_j, int cod_o) {
	if (j == NULL) return NULL;		//se a lista for vazia
	job* jb;
	op* o;
	op* aux;
	jb = Procura_job(j, cod_j);
	o = jb->op;
	if (o->cod == cod_o) {// se for na primeira posição
		aux = o;
		o = o->next;
		free(aux);
	}
	else {
		aux = o;
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
	return o;
}



/**
* Funções de alteração de operações
*/


/**
* Função para alterar op adicionar maqtime
*/

op* Alteracao_op(job* j, int cod_j, int cod_o, int M, int T) {
	if (j == NULL) return NULL;// caso não exista jobs
	job* jb;
	op* o;
	maqtime* mt;
	jb = Procura_job(j, cod_j); 
	o = jb->op;
	o = Procura_op(cod_o, o);
	o->cod = cod_o;
	mt = o->mt;
	while (mt != NULL) { //vai ao fim da maquinas
		mt = mt->next;
	}
	mt = Criar_MT(M, T);
	return o;
}

/**
* Função para retirar maqtime
*/

maqtime* Apagar_MT(maqtime* mt, int M){
	if (mt == NULL) return NULL;// caso não exista maquina tempo
	maqtime* maqt = mt;
	maqtime* aux;
	if (maqt->M == M) {// se for na primeira posição
		aux = maqt;
		maqt = maqt->next;
		free(aux);
	}
	else {
		aux = maqt;
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
	return maqt;
}

/**
* Função para alterar maqtime
*/

maqtime* Alterar_MT(maqtime* mt, int M, int n_M, int n_T) {
	if (mt == NULL) return NULL;
	maqtime* maqt;
	maqt = Procura_mt(mt, M);
	maqt->M = n_M;
	maqt->T = n_T;
	return maqt;
}

/**
* Funções de determinação de quantidade mínima de unidades de tempo
*/


int Determinacao_min_temp(job* j, int cod_j) {
	int soma = 0;
	if (j == NULL) return NULL;//caso não existam jobs
	job* jb;
	op* o;
	maqtime* mt;
	jb = Procura_job(j, cod_j);
	o = jb->op;
	if (o == NULL)return NULL; //caso não existam operações
	mt = o->mt;
	if (mt == NULL) return NULL;//caso não existam maqtime
	Listar_operacoes_de_job(jb);
	return (Det_min_temp_o(o, soma));
}


/**
* Função de determinação de quantidade mínima de unidades de tempo em cada operação na lista maqtime
*/


int Det_min_temp_mt(maqtime* mt, int min) {
	if (mt == NULL) return min; //caso mt já não exista devolve o minimo
	int minimo;
	if (min > mt->T) {
		minimo = mt->T;
	}
	else {
		minimo = min;
	}
	minimo = Det_min_temp_mt(mt->next, minimo); // pela função recorrente vai descobrir qual o minimo de todas as maquinas tempo
	return minimo;
}


/**
* Função de determinação de quantidade mínima de unidades de tempo em todas operações
*/

int Det_min_temp_o(op* o, int somado) {
	if (o == NULL) return somado; //caso a operação já não exista devolve o minimo
	int min = o->mt->T;
	int soma;
	soma = Det_min_temp_mt(o->mt, min) + somado; // iguala o minimo da operação à soma
	soma = Det_min_temp_o(o->next, soma);// pela função recorrente vai descobrir qual o minimo de todas as operações
	return soma;
}


/**
* Função de listagem de operações de um job
*/

void Listar_operacoes_de_job(job* j) {
	op* o;
	o = j->op;
	while (o != NULL) {
		printf("%d", o->cod);
		o = o->next;
	}
}


/**
* Funções de determinação de quantidade máxima de unidades de tempo
*/


int Determinacao_max_temp(job* j, int cod_j) {
	int soma = 0;
	if (j == NULL) return NULL;;//caso não existam jobs
	job* jb;
	op* o;
	maqtime* mt;
	jb = Procura_job(j, cod_j);
	o = jb->op;
	if (o == NULL)return NULL;;//caso não existam operações
	mt = o->mt;
	if (mt == NULL) return NULL;;//caso não existam maquina tempos
	Listar_operacoes_de_job(jb);
	return (Det_max_temp_o(o, soma));
}



/**
* Função de determinação de quantidade máxima de unidades de tempo em cada operação na lista maqtime
*/


int Det_max_temp_mt(maqtime* mt, int max) {
	if (mt == NULL) return max;//caso mt já não exista devolve o maximo
	int maximo;
	if (max < mt->T) {
		maximo = max;
	}
	else {
		maximo = max;
	}
	maximo = Det_max_temp_mt(mt->next, maximo);// pela função recorrente vai descobrir qual o máximo de todas as maquinas tempo
	return maximo;
}



/**
* Função de determinação de quantidade máxima de unidades de tempo em todas operações
*/


int Det_max_temp_o(op* o, int somado) {
	if (o == NULL) return somado;//caso a operação já não exista devolve o máximo
	int max = o->mt->T;
	int soma;
	soma = Det_max_temp_mt(o->mt, max) + somado;// iguala o minimo da operação à soma
	soma = Det_max_temp_o(o->next, soma);// pela função recorrente vai descobrir qual o minimo de todas as operações
	return soma;
}

/**
* Função de determinação de quantidade média de unidades de tempo
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
* Função para guardar dados em ficheiros txt
*/


int Guardar_dados_ficheiro(char* nomefile, job* j) {						//Perguntar porque que char é pointer
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
	fclose(fp);
	return 0;
}

/**
* Função para ler dados em ficheiros txt
*/


job* Ler_dados_ficheiro(char* nomefile) {
	char sitio;
	int temp_m, temp_t, temp_codj, temp_codo;
	FILE* fp;
	if ((fp = fopen(nomefile, "r")) == NULL) return -1;//caso não exista o file
	job* j;
	j = (job*)malloc(sizeof(job));
	if (j == NULL)return NULL; //  ver se tem espaço espaço disponível
	op* o;
	o = (op*)malloc(sizeof(op));
	if (o == NULL)return NULL; //  ver se tem espaço espaço disponível
	maqtime* mt;	
	mt = (maqtime*)malloc(sizeof(maqtime));
	if (mt == NULL)return NULL; //  ver se tem espaço espaço disponível
	while (fp != feof) {
		fscanf(fp, "%c", &sitio);
		if (sitio == 'm') {//caso a letra seja m escreve no maquina tempo
			fscanf(fp, "%d;%d", &temp_m, &temp_t);
			o->mt = Criar_MT(temp_m, temp_t);
		}
		else {
			if (sitio == 'o') {//caso a letra seja o escreve nas operações
				fscanf(fp, "%d", &temp_codo);
				o = Adicionar_operacao(j, j->cod, temp_codo);
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