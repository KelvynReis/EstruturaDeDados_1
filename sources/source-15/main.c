#include <stdio.h>
#include <stdlib.h>
#include "filaEncadeadaComDescritor.h"

//F.I.F.O => First In First Out

void enqueue(int informacao){
	TFila * novo = new();
	novo->dado = informacao;
}

void listar(){
	printf("\n\nListando valores\n");
	ultimo = descritor.primeiro;
	while (ultimo != NULL){
		printf("%d ",ultimo->dado);
		ultimo = ultimo->next;
	}
}

TFila * buscar(int chave){
	ultimo = descritor.primeiro;
	while (ultimo != NULL){
		if (ultimo->dado == chave)
			return ultimo;
		ultimo = ultimo->next;
	}

	return NULL;
}

void dequeue(){        
	//guarda o endereço do primeiro dado na variavel destroyer para posterior liberação/destruição
	TFila * destroyer = descritor.primeiro;
	//guarda na sentinela o endereço do segundo elemento, que após a destruição do primeiro, será o primeiro elemento
	descritor.primeiro = descritor.primeiro->next;
	//libera/destroi o primeiro elemento
	free(destroyer);
}

int main(int argc, char **argv)
{
	/*
	descritor.primeiro = NULL;
	descritor.ultimo = NULL;

	int leitura;

	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;

		enqueue(leitura);
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
	*/
	int i = 0;
	while (++i < 200000000){
		enqueue(i);
	}	
	return 0;
}

