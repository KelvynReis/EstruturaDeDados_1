#include <stdio.h>
#include <stdlib.h>

typedef struct SDado {
	int dado;
	struct SDado * next;
} TDado;

//DECLARAÇÃO DA SENTINELA
TDado * primeiro;

//DECLARAÇÃO DA VARIAVEL QUE ADICIONA OS ELEMENTOS
TDado * novo;

//Declaração da variavel que irá a coleção encadeada
TDado * ultimo;


TDado * inicial(){
	//1.alocar memória
	novo = malloc(sizeof(TDado));
	//2.definir o campo next como null
	novo->next = NULL;
	//guardar o endereço na sentinela primeiro
	primeiro = novo;
	return novo;
}

TDado * proximos (){
	//1.alocar memória
	novo = malloc(sizeof(TDado));
	
	//2.definir o campo next como null
	novo->next = NULL;
	//3.encadear
	ultimo = primeiro;
	while(ultimo->next != NULL){
		ultimo = ultimo->next;
	}
	ultimo->next = novo;
	return novo;
}

//melhoria na inteligência do código
TDado * new(){
	if (primeiro == NULL)
		return inicial();
	else
		return proximos();
}

void listar(){
	printf("\n\nListando valores\n");
	ultimo = primeiro;
	while (ultimo != NULL){
		printf("%d ",ultimo->dado);
		ultimo = ultimo->next;
	}
}

int main(int argc, char **argv)
{

	TDado * novo;
	primeiro = NULL;
	
	int leitura;

	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;

		novo = new();
		novo->dado = leitura;
	}

	//liberar o espaço de memória 
	free(novo);

	listar();

	return 0;
}

