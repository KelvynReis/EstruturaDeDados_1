#include <stdlib.h>
#include <stdio.h>

int opt;
typedef struct TipoFila{
	int dado;
	struct TipoFila *prox;
}TipoFila;

typedef struct Fila{
	TipoFila *inicio;
	TipoFila *fim;
}Fila;

Fila *Incia_Fila(){
	Fila *p = (Fila*)malloc(sizeof(Fila));
	
	if(!p){
		exit(1);
	}else{
		p->inicio = NULL;
		p->fim = NULL;
	}
	return p;
}

int Fila_Vazia (Fila *p){
	if(p == NULL) return 1;
	if(p->inicio==NULL){
		return 1;
	}else{
		return 0;
	}
}

int Ler_Valor(){
	int valor;
	printf("\n insira o valor: ");
	scanf("%d",&valor);
	
	return valor;
}

TipoFila *alocar(int valor){
	TipoFila *aux = (TipoFila*)malloc(sizeof(TipoFila));
	
	if(!aux){
		exit(1);
	}else{
		aux->dado =valor;
		aux->prox = NULL;
		return aux;
	}
}
 
void enfileirar(Fila *p){
	TipoFila *aux = alocar(Ler_Valor());
	
	if(!aux) exit(1);
	
	if(p->fim == NULL){
		p->inicio = aux;
	}else{
		p->fim->prox =aux;
	}
	
	p->fim = aux;
}

int desenfileirar (Fila *p){
	if(Fila_Vazia(p)) return 0;
	
	TipoFila *aux = p->inicio;
	p->inicio = p->inicio->prox;
	
	if(p->inicio != NULL){
		p->fim;
	}
	free(aux);
	return 1;
}

void exibir(Fila *p){
	if(Fila_Vazia(p)){
		printf("\n Fila Vazia ");
		return;
	}
	
	TipoFila *ex = 	p->inicio;
	printf("\n exibindo Fila: ");
	
	while( ex != NULL){
		printf("[%d] ", ex->dado);
		ex = ex->prox;
	}
	printf("\n");
}

void Casos( int opt, Fila *p){
	switch(opt){
		case 1:
			enfileirar(p);
			exibir(p);
			break;
		case 2:
			desenfileirar(p);
			system("cls");
			break;
		case 3:
			exibir(p);
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("\n opcao invalida!!!");
			
	}
}

int menu(){
	printf("\n -----SELECIONE UMA OPCAO ------");
	printf("\n [1]-> Enfileirar: ");
	printf("\n [2]-> Desenfileirar: ");
	printf("\n [3]-> Exibir: ");
	printf("\n [4]-> Sair: ");
	scanf("%i",&opt);
	
	return opt;
}

int main(void){
	Fila *p = Incia_Fila();
	
	do{
		opt = menu();
		
		Casos(opt, p);
	}while(opt);
	
	return 0;
	
}








