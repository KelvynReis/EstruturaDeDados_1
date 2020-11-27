#include <stdio.h>
#include <stdlib.h>
#include "pilhaEncadeada.h"

//L.I.F.O => Last In First Out

void push(int informacao){
	TPilha * novo = new();
	novo->dado = informacao;
}

void listar(){
	printf("\n\nListando valores\n");
	ultimo = primeiro;
	while (ultimo != NULL){
		printf("%d ",ultimo->dado);
		ultimo = ultimo->next;
	}
}

TPilha * buscar(int chave){
	ultimo = primeiro;
	while (ultimo != NULL){
		if (ultimo->dado == chave)
			return ultimo;
		ultimo = ultimo->next;
	}

	return NULL;
}

void pop(){        
	//guarda o endereço do primeiro dado na variavel destroyer para posterior liberação/destruição
	TPilha * destroyer = primeiro;
	//guarda na sentinela o endereço do segundo elemento, que após a destruição do primeiro, será o primeiro elemento
	primeiro = primeiro->next;
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

		push(leitura);
	}

	listar();

	int chave;
	printf("Informe a chave que deseja buscar na pilha encadeada: ");
	scanf("%d",&chave);

	TPilha * posicao = buscar(chave) ;
	
	if (posicao == NULL)
		printf("Chave não encontrada");
	else
		printf("Chave encontrada na posição %p", posicao);

	pop();
	listar();
	pop();
	listar();
	pop();
	listar();

	return 0;
}

