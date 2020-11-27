#include <stdio.h>
#define SIZE 5

int pilha[SIZE];

void push(int p[], int valor, int tamanho){
	int i;
	
	for (i = 0; i < tamanho; i++){
		if (p[i] == 0){
			p[i] = valor;
			return;
		}
	}
	printf("\n\n Pilha cheia \n\n");
}

void listar(int p[], int tamanho){
	int i;
	
	printf("\n\n Mostrando dados da Pilha \n\n");
	
	for (i = tamanho - 1; i >= 0; i--){
		if (p[i] != 0){
			printf("[%d] -> %d\n",i,p[i]);
		}
	}
}

int buscar(int p[], int tamanho, int chave){
	int i;
	for (i = tamanho - 1; i >= 0; i--){
		if (p[i] == chave){
			return i;
		}	
	}
	
	return -1;
}

void pop(int p[], int tamanho){
	int i;
	for (i = tamanho - 1; i >= 0; i--){
		if (p[i] != 0){
			p[i] = 0;
			return;
		}
	}
}


int main(int argc, char **argv)
{
	int leitura;
	
	while (1){
		
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		
		if (leitura == 0){
			break;
		}	
		
		push(pilha,leitura, SIZE);
	}
	
	listar(pilha,SIZE);
	int key;
	printf("\n\nInforme a chave da busca: ");
	scanf("%d",&key);
	
	int posicao = buscar(pilha,SIZE, key);
	if (posicao == -1)
		printf("Chave nao encontrada na Pilha \n\n");
	else
		printf("Chave encontrada na posicao: %d\n\n",posicao);
		
	printf("\n\nRemovendo 1 elemento\n\n");
	pop(pilha, SIZE);
		
	listar(pilha,SIZE);

	return 0;
}

