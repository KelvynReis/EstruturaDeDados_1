#include <stdio.h>
#include <stdlib.h>

typedef struct SDado {
	int dado;
	struct SDado * next;
} TDado;

//DECLARAÇÃO DA REFERÊNCIA
TDado * primeiro;
TDado * segundo;
TDado * aux;

int main(int argc, char **argv)
{
	//1. Alocar memória para o tipo desejado. 
	primeiro = malloc(sizeof(TDado));

	//2. Preencher o valor
	scanf("%d",&primeiro->dado);

	//3. Definir o campo next como vazio (NULL)
	primeiro->next = NULL;

	//4. Encadeamento -> como é o primeiro não tem em quem encadear
	
	//1. Alocar memória para o tipo desejado.
	segundo = malloc(sizeof(TDado));

	//2. Preencher o valor
	scanf("%d", &segundo->dado);

	//3. Definir o campo next como vazio (NULL)
	segundo->next = NULL;
	
	//4. Encadeamento -> como é o primeiro não tem em quem encadear
	primeiro->next = segundo;
	
	aux = primeiro;
	
	while (aux != NULL){
		printf("Dados armazenado: %d\n", aux->dado);
		aux = aux->next;
	}

	
	

	return 0;
}

