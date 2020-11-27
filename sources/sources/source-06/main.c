#include <stdio.h>
#define SIZE 5
//as funcoes listas, buscar e dequeue não foram adaptadas
typedef struct SFila{
	int dados[SIZE];
	int inicio;
	int fim; 
} TFila;

TFila fila;

void enqueue(int valor, int tamanho){
	if ((fila.fim != -1) && ((fila.fim + 1) % tamanho == fila.inicio)){
		printf("\n\nFila cheia\n\n");
		return;
	}
		        //incrementação     
	fila.fim = (fila.fim + 1) % tamanho;
	fila.dados[fila.fim] = valor;
}

void listar(int tamanho){
	int i = fila.inicio;
	printf("\n\nMostrando dados da Fila\n\n");

	do{
		printf("[%d] -> %d\n", i, fila.dados[i]);
		i = (i + 1) % tamanho;
	}while (i != (fila.fim + 1) % tamanho);

}

int buscar(int tamanho, int chave){
	int i = fila.inicio;
	do{
		if (fila.dados[i] == chave)
			return i;
		i = (i + 1) % tamanho;
	} while (i != (fila.fim + 1) % tamanho);

	return -1;
}
 
void dequeue(int tamanho){
	if (fila.fim == -1){
		printf("A fila esta vazia");
		return;
	}

	fila.inicio = (fila.inicio + 1) % tamanho;
}


int main(int argc, char **argv)
{
	fila.inicio = 0;
	fila.fim = -1;
	int leitura;
	int key;

	while (1) {
		
		printf("Informe o valor da fila: ");
		scanf("%d",&leitura);
		
		if (leitura == 0){
			break;
		}	
	
		enqueue(leitura, SIZE);
	}
	
	//lista os valores da fila
	listar(SIZE);

	//obtem o valor da chave
	printf("\n\nInforme a chave da busca: ");
	scanf("%d",&key);
	
	int posicao = buscar(SIZE, key);
	if (posicao == -1)
		printf("Chave nao encontrada na Fila\n\n");
	else
		printf("Chave encontrada na posicao: %d\n\n",posicao);
	
	//remove o primeiro elemento.	
	printf("\n\nRemovendo 1 elemento\n\n");
	dequeue(SIZE);

	//apresenta novamente os dados do fila	
	listar(SIZE); 
	return 0;
}

