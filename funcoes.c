#pragma warning(disable: 4996)
#include<stdio.h>
#include"global.h"


/**
* Autor: Lu�s Queir�s
* Email: luisqueiros21@gmail.com
* Date 20-03-2022
* Desc: M�dulo de fun��es 
*/

							//////  perguntar ao stor sobre as maquinas e tempo serem listas ou n�o


							////// perguntar sobre as opera��o quando se retira, retira se tudo ou n�o





							// falta adicionar fun��es ao .h


/**
* Fun��o para criar maqtime
*/

maqtime* Criar_MT(int M, int T) {
	maqtime* mt;
	mt = (maqtime*)malloc(sizeof(maqtime));
	if (mt == NULL) return NULL; //  ver se tem espa�o espa�o dispon�vel
	mt->M = M;
	mt->T = T;
	mt->next = NULL;
	return mt;
}


/**
* Fun��o para criar opera��o
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
* Fun��o para criar tipo
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
* Fun��o para criar job
*/


job* CriaJob(int cod) {
	job* x = (job*)malloc(sizeof(job));
	if (x == NULL) return NULL;	//  ver se tem espa�o espa�o dispon�vel
	x->cod = cod;
	x->op = NULL;
	x->next = NULL;
	return x;
}



/**
* Fun��o de procurar jobs
*/

job* Procura_job(job* j, int cod) {
	if (j == NULL) return NULL; //ve se existe o head
	else {
		while (j->cod != cod && j != NULL) {
			j = j->next;
		}
		if (j == NULL)return NULL; //caso n�o exista esse job
		return j;
	}
}



/**
* Fun��o de procurar opera��es
*/

op* Procura_op(int cod, op* o ) {
	if (o == NULL) return NULL; //ve se existe o head
	else {
		while (o->cod != cod && o != NULL) {
			o = o->next;
		}
		if (o == NULL)return NULL; //caso n�o exista essa op
		return o;
	}
}

/**
* Fun��o de procurar maquina e tempo
*/

maqtime* Procura_mt(maqtime* mt, int M) {
	if (mt == NULL) return NULL; //se o header existe
	else {
		while (mt->M != M && mt != NULL) {
			mt = mt->next;
		}
		if (mt == NULL)return NULL; //caso n�o exista esse job
		return mt;
	}
}

/**
* Fun��o de adicionar opera��es
*/


op* Adicionar_operacao(job* j,int cod_j, int cod_o) {
	job* jb;
	op* o;
	o = (op*)malloc(sizeof(op));
	if (j == NULL) return NULL; //  ver se tem espa�o espa�o dispon�vel
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
* Fun��o de ordenar opera��es
*/

op* Inserir_op(op* o, job* j) {
	if (j == NULL)return NULL; //caso n�o exista o header de jobs
	if (o == NULL)return NULL; //caso n�o exista o header de opera��es
	op* aux = o;
	if (j->op == NULL)		//caso o lista de opera��es n�o exista na lista de jobs
	{
		j->op = o;
	}
	else {
		if (existe_op(j->op, o->cod) == 1)return j; //caso essa opera��o j� exista nesse job 
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
* Fun��o para ver se existe job
*/

int existe_job(job* j, int codigo)
{
	if (j == NULL) return 0; //caso n�o exista jobs
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
* Fun��o para ver se existe opera��o
*/


int existe_op(op* o, int codigo)
{
	op* aux = o;

	if (o == NULL) return 0; //caso n�o exista opera��es

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
* Fun��o para ver se existe maquina tempo
*/

int existe_maq(maqtime* maq, int maquina)
{
	maqtime* aux = maq;

	if (maq == NULL) return 0;//caso n�o exista opera��es

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
* Fun��o de Remo��o de opera��es
*/													

op* Remover_op(job* j, int cod_j, int cod_o) {
	if (j == NULL) return NULL;		//se a lista for vazia
	job* jb;
	op* o;
	op* aux;
	jb = Procura_job(j, cod_j);
	o = jb->op;
	if (o->cod == cod_o) {// se for na primeira posi��o
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
* Fun��es de altera��o de opera��es
*/


/**
* Fun��o para alterar op adicionar maqtime
*/

op* Alteracao_op(job* j, int cod_j, int cod_o, int M, int T) {
	if (j == NULL) return NULL;// caso n�o exista jobs
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
* Fun��o para retirar maqtime
*/

maqtime* Apagar_MT(maqtime* mt, int M){
	if (mt == NULL) return NULL;// caso n�o exista maquina tempo
	maqtime* maqt = mt;
	maqtime* aux;
	if (maqt->M == M) {// se for na primeira posi��o
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
* Fun��o para alterar maqtime
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
* Fun��es de determina��o de quantidade m�nima de unidades de tempo
*/


int Determinacao_min_temp(job* j, int cod_j) {
	int soma = 0;
	if (j == NULL) return NULL;//caso n�o existam jobs
	job* jb;
	op* o;
	maqtime* mt;
	jb = Procura_job(j, cod_j);
	o = jb->op;
	if (o == NULL)return NULL; //caso n�o existam opera��es
	mt = o->mt;
	if (mt == NULL) return NULL;//caso n�o existam maqtime
	Listar_operacoes_de_job(jb);
	return (Det_min_temp_o(o, soma));
}


/**
* Fun��o de determina��o de quantidade m�nima de unidades de tempo em cada opera��o na lista maqtime
*/


int Det_min_temp_mt(maqtime* mt, int min) {
	if (mt == NULL) return min; //caso mt j� n�o exista devolve o minimo
	int minimo;
	if (min > mt->T) {
		minimo = mt->T;
	}
	else {
		minimo = min;
	}
	minimo = Det_min_temp_mt(mt->next, minimo); // pela fun��o recorrente vai descobrir qual o minimo de todas as maquinas tempo
	return minimo;
}


/**
* Fun��o de determina��o de quantidade m�nima de unidades de tempo em todas opera��es
*/

int Det_min_temp_o(op* o, int somado) {
	if (o == NULL) return somado; //caso a opera��o j� n�o exista devolve o minimo
	int min = o->mt->T;
	int soma;
	soma = Det_min_temp_mt(o->mt, min) + somado; // iguala o minimo da opera��o � soma
	soma = Det_min_temp_o(o->next, soma);// pela fun��o recorrente vai descobrir qual o minimo de todas as opera��es
	return soma;
}


/**
* Fun��o de listagem de opera��es de um job
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
* Fun��es de determina��o de quantidade m�xima de unidades de tempo
*/


int Determinacao_max_temp(job* j, int cod_j) {
	int soma = 0;
	if (j == NULL) return NULL;;//caso n�o existam jobs
	job* jb;
	op* o;
	maqtime* mt;
	jb = Procura_job(j, cod_j);
	o = jb->op;
	if (o == NULL)return NULL;;//caso n�o existam opera��es
	mt = o->mt;
	if (mt == NULL) return NULL;;//caso n�o existam maquina tempos
	Listar_operacoes_de_job(jb);
	return (Det_max_temp_o(o, soma));
}



/**
* Fun��o de determina��o de quantidade m�xima de unidades de tempo em cada opera��o na lista maqtime
*/


int Det_max_temp_mt(maqtime* mt, int max) {
	if (mt == NULL) return max;//caso mt j� n�o exista devolve o maximo
	int maximo;
	if (max < mt->T) {
		maximo = max;
	}
	else {
		maximo = max;
	}
	maximo = Det_max_temp_mt(mt->next, maximo);// pela fun��o recorrente vai descobrir qual o m�ximo de todas as maquinas tempo
	return maximo;
}



/**
* Fun��o de determina��o de quantidade m�xima de unidades de tempo em todas opera��es
*/


int Det_max_temp_o(op* o, int somado) {
	if (o == NULL) return somado;//caso a opera��o j� n�o exista devolve o m�ximo
	int max = o->mt->T;
	int soma;
	soma = Det_max_temp_mt(o->mt, max) + somado;// iguala o minimo da opera��o � soma
	soma = Det_max_temp_o(o->next, soma);// pela fun��o recorrente vai descobrir qual o minimo de todas as opera��es
	return soma;
}

/**
* Fun��o de determina��o de quantidade m�dia de unidades de tempo
*/


float Det_media_temp(op* o) {
	if (o->mt == NULL) return 0;//caso n�o existam maquinas tempo
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
* Fun��o para guardar dados em ficheiros txt
*/


int Guardar_dados_ficheiro(char* nomefile, job* j) {						//Perguntar porque que char � pointer
	FILE* fp;								

	if (j == NULL) return -1;//caso n�o existam jobs
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
* Fun��o para ler dados em ficheiros txt
*/


job* Ler_dados_ficheiro(char* nomefile) {
	char sitio;
	int temp_m, temp_t, temp_codj, temp_codo;
	FILE* fp;
	if ((fp = fopen(nomefile, "r")) == NULL) return -1;//caso n�o exista o file
	job* j;
	j = (job*)malloc(sizeof(job));
	if (j == NULL)return NULL; //  ver se tem espa�o espa�o dispon�vel
	op* o;
	o = (op*)malloc(sizeof(op));
	if (o == NULL)return NULL; //  ver se tem espa�o espa�o dispon�vel
	maqtime* mt;	
	mt = (maqtime*)malloc(sizeof(maqtime));
	if (mt == NULL)return NULL; //  ver se tem espa�o espa�o dispon�vel
	while (fp != feof) {
		fscanf(fp, "%c", &sitio);
		if (sitio == 'm') {//caso a letra seja m escreve no maquina tempo
			fscanf(fp, "%d;%d", &temp_m, &temp_t);
			o->mt = Criar_MT(temp_m, temp_t);
		}
		else {
			if (sitio == 'o') {//caso a letra seja o escreve nas opera��es
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