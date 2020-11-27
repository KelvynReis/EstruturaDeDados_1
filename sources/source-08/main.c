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


void inicial(int informacao){
	//1.alocar memória
	novo = malloc(sizeof(TDado));
	//2.inserir o dado
	novo->dado = informacao;
	//3.definir o campo next como null
	novo->next = NULL;
	//guardar o endereço na sentinela primeiro
	primeiro = novo;
}

void proximos (int informacao){
	//1.alocar memória
	novo = malloc(sizeof(TDado));
	//2.inserir o dado
	novo->dado = informacao;
	//3.definir o campo next como null
	novo->next = NULL;
	//4.encadear
	ultimo = primeiro;
	while(ultimo->next != NULL){
		ultimo = ultimo->next;
	}
	ultimo->next = novo;
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
	primeiro = NULL;
	int leitura;

	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
		if (primeiro == NULL)
			inicial(leitura);
		else
			proximos(leitura);

	}

    // int i = 0;
	// while (++i <= 100000){
	// 	if (primeiro == NULL)
	// 	 		inicial(i);
	// 	 	else
	// 	 		proximos(i);
	// }

	listar();

	return 0;
}

