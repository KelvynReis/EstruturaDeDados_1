#include <stdio.h>
#include <stdlib.h>


typedef struct elemento Elemento;
struct elemento {
	int valor;
	Elemento *proximo;
	Elemento *anterior;
};

Elemento *inicio;
Elemento *fim;
int tamanho;


void criaLista();
Elemento *aloca(int valor);
void insereInicio(int valor);


void removeInicio();

void imprimeLista();



void criaLista() {
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

Elemento *aloca(int valor) {
	Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
	novo->valor = valor;
	novo->anterior = NULL;
	novo->proximo = NULL;
	return novo;
}
void removeInicio() {
	Elemento *atual = inicio;
	inicio = atual->proximo;
	inicio->anterior = NULL;
	tamanho--;
}

void insereInicio(int valor) {
	Elemento *novo = aloca(valor);
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	}else{
		Elemento *atual;
		atual = inicio;
		novo->proximo = atual;
		atual->anterior = novo;
		inicio = novo;
	}
	tamanho++;
}



void imprimeLista() {
	Elemento *atual;
	atual = inicio;
	while(atual){
		printf("%d\n",atual->valor);
		atual=atual->proximo;
	}
}


void menu(){
	printf("\n---selecione uma opcao----");
	printf("\n [1]-> Push: ");
	printf("\n [2]-> POP: ");
	printf("\n [3]-> Exibir: ");
	printf("\n [4] -> Sair: ");
	printf("\n");
}
int main() {
    int option,valor,pos;
	while(1){
		system("cls");
          menu();
          scanf("%i",&option);
		switch(option) {
			case 1:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &valor);
				insereInicio(valor);
				break;
			case 2:
				removeInicio();
				system ("pause");
				break;
			case 3:
				imprimeLista();
				system ("pause");
				
				break;
			case 4:
				exit(1);
				break;
			default:
				option = 4;
				break;
		}
	}
	system ("pause");
}

