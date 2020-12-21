#include <stdio.h>
#include <stdlib.h>


int opt, valor, buscador;
typedef struct Slista{
    int dado;
    struct SFila *next;
}Tlista;

typedef struct SDescritor{
    Tlista *first;
    int quantidade;
    Tlista *last;
}TDescritor;

TDescritor descritor;

Tlista *novo;
Tlista *last;

Tlista *initial(){
    novo = (Tlista *)malloc(sizeof(Tlista));
    novo->next = NULL;
    descritor.first = novo;
    descritor.last = novo;
    descritor.quantidade = 1;
    return novo;
}

Tlista *proximo(){
    novo = (Tlista *)malloc(sizeof(Tlista));
    novo->next = NULL;
    descritor.last->next = novo;
    descritor.last = novo;
    descritor.quantidade++;
    return novo;
}

Tlista *newItem(){
    if(descritor.first == NULL){
        return initial();
    }else{
        return proximo();
    }
}

void enqueue(int infor){
    Tlista * novo = newItem();
    novo->dado = infor;
}

void dequeue(){
    Tlista *destroyer = descritor.first;
    descritor.first = descritor.first->next;
    descritor.quantidade--;
    free(destroyer);
}

void listar(){
    printf("\n\nlistando valores \n");
    last = descritor.first;
    while(last !=NULL){
        printf("[%d] \n",last->dado);
        last = last->next;
    }
}

Tlista *buscar(int key){
    last = descritor.first;

    while(last != NULL){
        if(last->dado == key ){
            return last;
        };
        last = last->next;
    };

    return NULL;
}

int menu (){
	
	printf("\n --------------------");
	printf("\n Escolha uma opcao: ");
	printf("\n[1]-> PUSH: ");
	printf("\n[2]-> POP: ");
	printf("\n[3]-> Exibir: ");
	printf("\n[4]-> Buscar: ");
	printf("\n[5]-> Sair: ");
	printf("\n");
	scanf("%d",&opt);
	
	return opt;
}

void casos(int opt){
	switch (opt){
		case 1:
			while(1){
				printf("\n Adicione um numero:[0]sair: ");
				scanf("%d",&valor);
				if(valor == 0)
					break;
				else
				enqueue(valor);
			}
			system("cls");
		case 2:
			dequeue();
            break;
        case 3:
        	listar();
            break;
        case 4:
        	printf("\n informe o valor a ser buscado: ");
        	scanf("%i",&buscador);
        	buscar(buscador);
            Tlista *position = buscar(buscador);
            if (position == NULL)
		        printf("Chave não encontrada");
	        else
		        printf("Chave encontrada na posicao %p", position);
            break;
        case 5:
        	return 0;
        	break;
        default:
        	printf("\n opcao invalida !!");
	}
}
int main(){
	descritor.first = NULL;
	descritor.last = NULL;
    while(opt != 5){
    	opt = menu();
    	casos(opt);
	}
    return 0;
}
