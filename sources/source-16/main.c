#include <stdio.h>
#include <stdlib.h>
//Estrutura de dados Árvore binária e também para uma ABB (Árvore Binária de busca)
typedef struct SNo{
	int dado;
	struct SNo * esq;
	struct SNo * dir;
} TNo;

TNo * raiz;

 void criarRaiz(int informacao){
	 raiz = malloc(sizeof(TNo)); 
	 raiz->dado = informacao;
	 raiz->esq = raiz->dir = NULL;
 }

void preencherABB(TNo *noPai, int informacao){
	TNo * novo;                      
	if (noPai == NULL)                    
		return;                      
	// se for menor que o valor do noPai	           
	if (informacao < noPai->dado){
		if (noPai->esq == NULL){
			novo = malloc(sizeof(TNo));
			novo->dado = informacao;
			novo->esq = novo->dir = NULL;
			noPai->esq = novo;
		}else{
			//recursividade
			preencherABB(noPai->esq, informacao);
		}  
		//se maior que o valor do noPai                 
	}else if (informacao > noPai->dado){
		if (noPai->dir == NULL){
			novo = malloc(sizeof(TNo));
			novo->dado = informacao;
			novo->esq = novo->dir = NULL;
			noPai->dir = novo;
		}else{
			//recursividade
			preencherABB(noPai->dir,informacao);
		}
	//se for igual ao valor do noPai
	}else{
		printf("\nO Valor já existe no árvore.\n\n");
	}
}

void preFixado(TNo *no){
	if (no == NULL)
		return;
	printf("%d ", no->dado);
	preFixado(no->esq);
	preFixado(no->dir);
}

void central(TNo * no){
	if (no == NULL)
		return;

	central(no->esq);
	printf("%d ",no->dado);
	central(no->dir);
}

void posFixado(TNo *no){
	if (no == NULL)
		return;

	posFixado(no->esq);
	posFixado(no->dir);
	printf("%d ", no->dado);
}

TNo * buscaBinaria(TNo * no, int key){
	if (no == NULL)
		return NULL;

	if (no->dado == key)
		return no;
	else
		if (key < no->dado)
			return buscaBinaria(no->esq, key);
		else
			return buscaBinaria(no->dir,key);
}



// int i;

// void recursividade(){
// 	i++;
// 	if (i == 1000)
// 		return;
// 	printf("%d\n",i);
// 	recursividade();
// }


int main(int argc, char **argv)
{
	int leitura;

	printf("Informe o valor da raiz: ");
	scanf("%d",&leitura);
	criarRaiz(leitura);

	while (1) {
		
		printf("Informe o valor do nó: ");
		scanf("%d",&leitura);
		
		if (leitura == 0){
			break;
		}	
		
		preencherABB(raiz,leitura);
	}
	preFixado(raiz);
	printf("\n");
	central(raiz);
	printf("\n");
	posFixado(raiz);
	
	

	//obtem o valor da chave 
    printf("\n\nInforme a chave da busca: ");
	int key;
	scanf("%d",&key);
	
	TNo * posicao = buscaBinaria(raiz,key);
	 if (posicao == NULL)
	 	printf("Chave nao encontrada na Árvore\n\n");
	else
		printf("Chave encontrada na posicao: %p\n\n",posicao);

	return 0;
}
