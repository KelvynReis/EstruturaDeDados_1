#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct FilaI{
    int Numero[SIZE];
    int inicio;
    int fim;
}FilaP;
FilaP fila;

void Adicionar (int valor, int tamanho){
    if((fila.fim != -1) && ((fila.fim + 1) % tamanho  == fila.inicio)){
        printf("Fila cheia");
        return;
    }
    //incrementação
    fila.fim = (fila.fim + 1) % tamanho;
    fila.Numero[fila.fim] = valor;
}
 void Exibir(int tamanho){
        int i = fila.inicio;
        do{
            printf("\n [%d] ---> %d\n", i, fila.Numero[i]);
            i = (i + 1) % tamanho;
        }while(i != (fila.fim + 1) % tamanho);
    }

int Buscar (int key, int tamanho){

    int i = fila.inicio;

    do
    {

        if(fila.Numero[i] == key){
            return i;
        }
        i = (i + 1) % tamanho;

    } while (i != (fila.fim + 1) % tamanho);

    return -1;
}

void localKey( int x){
    if(x == -1){
        printf("\n Valor nao encontrado");
    }else
    {
        printf("\n Valor encontrado na posicao: %d\n",x);
    }
    
}

void Limpar (int tamanho){

    if(fila.fim == -1){
        printf("\n Fila esta vazia");
        return;
    }

    fila.inicio = (fila.inicio + 1) % tamanho;
    printf("\n Retirando um elemento");
}

int main(){
    fila.inicio = 0;
    fila.fim = -1;

    int key,local,controle,valor1 = 0;

    while(controle != 5){

        printf("\n __________________________\n");
        printf("\n [1] - Adicionar: \n");
        printf("\n [2] - Exbir: \n");
        printf("\n [3] - Buscar: \n");
        printf("\n [4] - Excluir: \n");
        printf("\n [5] - Sair: \n");
        scanf("%d",&controle);

        switch(controle){
            case 1:
                while(1) {
		
		            printf("Informe o valor da fila: ");
		            scanf("%d",&valor1);
		                if (valor1 == 0){
			                break;
		                }	
	            }
                Adicionar(valor1,SIZE);
                break;
            case 2:
                Exibir(SIZE);
                break;
            case 3:
                printf("\n\n");
                printf("\n Entre com o valor desejado: ");
                scanf("%d",&key);
                
                local = Buscar(key, SIZE);
                localKey(local);
                break;
            case 4:
                Limpar(SIZE);
                break;
            case 5:
                printf("\nSaindo \n");
                system("cls");
                return 0;
            default:
                printf("\n opcao nao  existe\n");
                return 0;
        }
    }
    return 0;
}

