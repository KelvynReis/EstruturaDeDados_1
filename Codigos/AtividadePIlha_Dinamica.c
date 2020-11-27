#include <stdlib.h>
#include <stdio.h>

typedef struct TipoPilha{
    int dado;
    struct TipoPilha *prox;
}TipoPilha;

int opt, valor;

typedef struct Pilha{
	TipoPilha *topo;
}Pilha;


Pilha *Inica_Pilha(){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	
	if(!p){
		exit(1);
	}else{
		p->topo =  NULL;
	} 
	
	return p;
}


void Pilha_Push(int dado, Pilha *p){
    TipoPilha *ptr = (TipoPilha*)malloc(sizeof(TipoPilha));

    if(ptr == NULL){ 
       printf("nao foi possivel alocar memoria");
    }else{
        ptr->dado = dado;
        ptr->prox = p->topo;

        p->topo = ptr;

        printf("valor adicionado com sucesso");
    }
}

int Pilha_Pop(Pilha *p){ 
    TipoPilha* temp = p->topo;
    if(temp == NULL){
        printf("pilha vazia ^_^");
    }else{
        p->topo = temp->prox;
		
        temp->prox = NULL;
        
        int dado = temp->dado;
         
        
        free(temp);
        
        return dado;
        printf("\n\nElemento removido com sucesso\n");
    }
}


void exibir_pilha(Pilha *p) {
	TipoPilha *aux = p->topo;

	if(aux == NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}
	printf("\nExibindo Pilha:");
	
	while(aux!=NULL) {
		printf("[%d]\n",aux -> dado);
		aux = aux->prox;	
	}
	printf("\n");
}
void casos(int opt, Pilha *p){
	switch(opt){
		case 1:
			printf("\n Digite o valor a ser inserido: ");
			scanf("%d", &valor);
			Pilha_Push(valor,p);
			break;
		case 2:
			Pilha_Pop(p);
			break;
		case 3:
			exibir_pilha(p);
			system ("pause");
			
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("\n opcao invalida!!!");
			break;
	}
}
int menu(){
	 printf("\n --- selecione uma opcao----");
	 printf("\n [1]-> Push: ");
	 printf("\n [2]-> POP: ");
	 printf("\n [3]-> Exibir: ");
	 printf("\n [4] -> Sair: ");
	 printf("\n");
	 scanf("%d", &opt);
	 
	 system("cls");
	 
	 return opt;
}
int main(void){
	Pilha *p = Inica_Pilha();
	
	while(opt!= 4){
	
		opt = menu();
		
		casos(opt,p);
	}
	
	return 0;
}
