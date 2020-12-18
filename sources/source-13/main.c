#include <stdio.h>
#include <stdlib.h>
#include "filaEncadeadaCircular.h"

//F.I.F.O => First In First Out

void enqueue(struct SAluno informacao){
	TFila * novo = new();
	novo->dado = informacao;
}

void listar(){
	printf("\n\nListando valores\n");
	ultimo = primeiro;
	do{
		printf("Matricula %d, Nome: %s \n",ultimo->dado.matricula, ultimo->dado.nome);
		ultimo = ultimo->next;
	} while (ultimo != primeiro);
}

TFila * buscar(int chave){
	ultimo = primeiro;
	do{
		if (ultimo->dado.matricula == chave)
			return ultimo;
		ultimo = ultimo->next;
	} while (ultimo != primeiro);

		return NULL;
}

void dequeue(){        
	//guarda o endereço do primeiro dado na variavel destroyer para posterior liberação/destruição
	TFila * destroyer = primeiro;
	//encontrar o ultimo
	ultimo = primeiro;
	while (ultimo->next != primeiro)
		ultimo = ultimo->next;
	//guarda na sentinela o endereço do segundo elemento, que após a destruição do primeiro, será o primeiro elemento
	primeiro = primeiro->next;
	//atualizar o endereco do primeiro no ultimo
	ultimo->next = primeiro;
	//libera/destroi o primeiro elemento
	free(destroyer);
}

int main(int argc, char **argv)
{
	primeiro = NULL;
	
	struct SAluno aluno;

	while(1){
		printf("Informe o matrícula: ");
		scanf("%d",&aluno.matricula);
		if (aluno.matricula == 0)
			break;

		printf("Informe o nome: ");
		scanf("%s", &aluno.nome);

		enqueue(aluno);
	}

	listar();

	int chave;
	printf("Informe a chave que deseja buscar na fila encadeada: ");
	scanf("%d",&chave);

	TFila *posicao = buscar(chave) ;
	
	if (posicao == NULL)
		printf("Chave não encontrada");
	else
		printf("Chave encontrada na posição %p", posicao);

	dequeue();
	listar();
	dequeue();
	listar();
	dequeue();
	listar();

	return 0;
}

