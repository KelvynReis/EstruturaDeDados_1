#include <stdio.h>
#include <stdlib.h>
#include "PilhaD_encadeada.h"

int opt, valor, buscado;
void add(int valor){
    TPilha *novo = new ();
    novo->dado = valor;
}

void list(){
    printf("Lista atual: \n");
    if (primeiro == NULL){
        printf("Pilha vazia!!!\n");
    	}

    ultimo = primeiro;
    while (ultimo != NULL)
    {
        printf("Valor: %d \n", ultimo->dado);
        ultimo = (TPilha *)ultimo->next;
    }
    
}

TPilha *search(int key){
    ultimo = primeiro;
    while (ultimo != NULL)
    {
        if (ultimo->dado == key)
            return ultimo;
        ultimo = (TPilha *)ultimo->next;
    }
    return NULL;
}

void delete(){
    TPilha *del = primeiro;
    primeiro = (TPilha *)primeiro->next;
    printf("Valor deletado: %d\n", del->dado);
    free(del);
}

int menu(){
	 printf("\n --- selecione uma opcao----");
	 printf("\n [1]-> Push: ");
	 printf("\n [2]-> POP: ");
	 printf("\n [3]-> Exibir: ");
	 printf("\n [4]-> Buscar: ");
	 printf("\n [5] -> Sair: ");
	 printf("\n");
	 scanf("%d", &opt);
	 
	 system("cls");
	 
	 return opt;
}

void casos ( int opt){
	
	switch (opt){
        case 1:
            while (1)
            {
                printf("\nInforme o valor,[0] para sair: \n");
                scanf("%d", &valor);
                if (valor == 0)
                    break;
                else
                    add(valor);
            }
            system("cls");
            break;
        case 2:
        	delete ();
            
            break;
        case 3:
        	list();
            
            break;
        case 4:
        	printf("Informe o valor a ser buscado: \n");
            scanf("%d", &buscado);
            search(buscado);
            TPilha *posicao = search(buscado);
            if (posicao == NULL)
                printf("Nao encontrado\n");
            else
                printf("Chave encontrada no endereco: %p\n", posicao);
            break;
        case 5:
            exit(0);
            break;
        }
}

int main(){
    
    primeiro = NULL;

    while( opt != 5){
    	
    	opt = menu();
    	
    	casos(opt);
	}
        
    return 0;
}
