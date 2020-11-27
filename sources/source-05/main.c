#include <stdio.h>
#define SIZE 5

typedef struct SPilha{
	int dados[SIZE];
	int topo;
} TPilha;

TPilha pilha;

void push(int valor, int tamanho){
	if (pilha.topo + 1 == tamanho){
		printf("\n\n Pilha cheia \n\n");
		return;
	}	

	pilha.dados[++pilha.topo] = valor;
}

void listar(int tamanho){
	int i;	
	printf("\n\n Mostrando dados da Pilha \n\n");
	for (i = pilha.topo; i >= 0; i--){
		printf("[%d] -> %d\n",i,pilha.dados[i]);
	}
}

int buscar(int tamanho, int chave){
	int i;
	for (i = pilha.topo; i >= 0; i--){
		if (pilha.dados[i] == chave){
			return i;
		}	
	}
	
	return -1;
}

void pop(){
	if (pilha.topo == -1){
		printf("\n\nPilha vazia\n\n");
		return;
	}

	pilha.dados[pilha.topo--] = 0;
}


int main(int argc, char **argv)
{
	pilha.topo = -1;
	int leitura;
	while (1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		
		if (leitura == 0){
			break;
		}	
		push(leitura, SIZE);
	}
	
	listar(SIZE);
	int key;
	printf("\n\nInforme a chave da busca: ");
	scanf("%d",&key);
	
	int posicao = buscar(SIZE, key);
	if (posicao == -1)
		printf("Chave nao encontrada na Pilha \n\n");
	else
		printf("Chave encontrada na posicao: %d\n\n",posicao);
		
	printf("\n\nRemovendo 1 elemento\n\n");
	pop();
	listar(SIZE);
	return 0;
}

