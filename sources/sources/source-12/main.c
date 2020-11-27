#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"



void adicionar(int informacao){
	TLista * novo = new();
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

TLista * buscar(int chave){
	ultimo = primeiro;
	while (ultimo != NULL){
		if (ultimo->dado == chave)
			return ultimo;
		ultimo = ultimo->next;
	}

	return NULL;
}

void removerPrimeiro(){
	//guarda o endereço do primeiro dado na variavel destroyer para posterior liberação/destruição
	TLista *destroyer = primeiro;
	//guarda na sentinela o endereço do segundo elemento, que após a destruição do primeiro, será o primeiro elemento
	primeiro = primeiro->next;
	//libera/destroi o primeiro elemento
	free(destroyer);
}

void remover(int posicao){        
	if ((posicao == 1) && (primeiro != NULL)){
		removerPrimeiro();
		return;
	}

	TLista * anterior = primeiro;
	TLista * destroyer;
	int contador = 2;
                     
	while (contador < posicao){
		anterior = anterior->next;
		contador++;
	}

	destroyer = anterior->next;
	anterior->next = destroyer->next; 
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

		adicionar(leitura);
	}

	listar();

	int chave;
	printf("Informe a chave que deseja buscar na lista encadeada: ");
	scanf("%d",&chave);

	TLista *posicao = buscar(chave) ;
	
	if (posicao == NULL)
		printf("Chave não encontrada");
	else
		printf("Chave encontrada na posição %p", posicao);


	int posicaoRemover;
	printf("Informe a posicao que deseja excluir: ");
	scanf("%d",&posicaoRemover);
	remover(posicaoRemover);
	listar();
	

	return 0;
}

