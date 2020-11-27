#include <stdio.h>
#define SIZE 5

int lista[SIZE];

void adicionar(int l[], int posicao, int valor, int tamanho){
	//programação defensiva
	if ((posicao < 0) || (posicao > tamanho - 1)){
		printf("Posicao inexistente.");
		return;
	}
	l[posicao] = valor;
}

void listar(int l[], int tamanho){
	int i;
	
	printf("\n\nMostrando dados da Lista\n\n");
	
	for (i = 0; i < tamanho; i++){
		if (l[i] != 0){
			printf("[%d] -> %d\n",i,l[i]);
		}
	}
}

int buscar(int l[], int tamanho, int chave){
	int i;
	for (i = 0; i < tamanho; i++){
		if (l[i] == chave){
			return i;
		}	
	}
	
	return -1;
}

void remover(int l[], int posicao, int tamanho){
	//programação defensiva
	if ((posicao < 0) || (posicao > tamanho - 1)){
		printf("Posicao inexistente.");
		return;
	}
	l[posicao] = 0;
}


int main(int argc, char **argv)
{
	int leitura,posicao;
	int key;
	while (1) {
		printf("Informe o valor da lista: ");
		scanf("%d %d",&posicao,&leitura);
		if (leitura == 0){
			break;
		}	
		adicionar(lista, posicao, leitura, SIZE);
	}
	//lista os valores da lista
	listar(lista,SIZE);
	//obtem o valor da chave
	printf("\n\nInforme a chave da busca: ");
	scanf("%d",&key);
	posicao = buscar(lista,SIZE, key);
	if (posicao == -1)
		printf("Chave nao encontrada na Fila\n\n");
	else
		printf("Chave encontrada na posicao: %d\n\n",posicao);	
	//remove o primeiro elemento.
	printf("Informe a posicao que deseja remover: ");	
	scanf("%d",&posicao);
	printf("\n\nRemovendo 1 elemento\n\n");
	remover(lista, posicao, SIZE);

	//apresenta novamente os dados do lista	
	listar(lista,SIZE);
	return 0;
}

