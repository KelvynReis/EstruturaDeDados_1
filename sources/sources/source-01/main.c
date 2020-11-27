#include <stdio.h>
#define SIZE 5

int fila[SIZE];

void enqueue(int f[], int valor, int tamanho){
	int i;
	
	for (i = 0; i < tamanho; i++){
		if (f[i] == 0){
			f[i] = valor;
			return;
		}
	}
	printf("\n\nFila cheia\n\n");
}

void listar(int f[], int tamanho){
	int i;
	
	printf("\n\nMostrando dados da Fila\n\n");
	
	for (i = 0; i < tamanho; i++){
		if (f[i] != 0){
			printf("[%d] -> %d\n",i,f[i]);
		}
	}
}

int buscar(int f[], int tamanho, int chave){
	int i;
	for (i = 0; i < tamanho; i++){
		if (f[i] == chave){
			return i;
		}	
	}
	
	return -1;
}

void dequeue(int f[], int tamanho){
	int i;
	for (i = 0; i < tamanho - 1 ; i++){
		f[i] = f[i + 1];
	}
	    
	f[tamanho - 1] = 0;
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
		
		enqueue(fila,leitura, SIZE);
	}
	
	listar(fila,SIZE);
	int key;
	printf("\n\nInforme a chave da busca: ");
	scanf("%d",&key);
	
	int posicao = buscar(fila,SIZE, key);
	if (posicao == -1)
		printf("Chave nao encontrada na Fila\n\n");
	else
		printf("Chave encontrada na posicao: %d\n\n",posicao);
		
	printf("\n\nRemovendo 1 elemento\n\n");
	dequeue(fila, SIZE);
		
	listar(fila,SIZE);

	return 0;
}

