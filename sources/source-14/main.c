#include <stdio.h>
#include <stdlib.h>
#include "filaDuplamenteEncadeada.h"

//F.I.F.O => First In First Out

void enqueue(int informacao){
	TFila * novo = new();
	novo->dado = informacao;
}

void listar(){
	printf("\n\nListando valores\n");
	ultimo = primeiro;
	while (ultimo != NULL){
		printf("%p \n", ultimo->prev);
		printf("%p %d \n",ultimo,ultimo->dado);
		printf("%p \n\n", ultimo->next);
		ultimo = ultimo->next;
	}
}

TFila * buscar(int chave){
	ultimo = primeiro;
	while (ultimo != NULL){
		if (ultimo->dado == chave)
			return ultimo;
		ultimo = ultimo->next;
	}

	return NULL;
}

void dequeue(){        
	//guarda o endereço do primeiro dado na variavel destroyer para posterior liberação/destruição
	TFila * destroyer = primeiro;
	//guarda na sentinela o endereço do segundo elemento, que após a destruição do primeiro, será o primeiro elemento
	primeiro = primeiro->next; 
	//remover a referência ao antigo primeiro elemento.
	primeiro->prev = NULL;
	//libera/destroi o primeiro elemento
	free(destroyer); 
}

int main(int argc, char **argv)
{
	primeiro = NULL;
	
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


/*inserindo 200 mil elementos
	int i = 0;
	while(++i <= 200000){
		enqueue(i);
	}
*/
	return 0;
}

