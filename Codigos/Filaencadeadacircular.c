#include <stdio.h>
#include <stdlib.h>

typedef struct SFila{
    int dado;
    struct SFila *next;
} TFila;

int opc,aux;
TFila *primeiro;
TFila *novo;
TFila *ultimo;

TFila *inicial(){
    novo = (TFila *)malloc(sizeof(TFila));
    novo->next = novo;
    primeiro = novo;
    return novo;
}

TFila *proximos(){
    novo = (TFila *)malloc(sizeof(TFila));
    novo->next = primeiro;
    ultimo = primeiro;
    while (ultimo->next != primeiro){
        ultimo = ultimo->next;
    }
    ultimo->next = novo;
    return novo;
}


TFila *neww()
{
    if (primeiro == NULL)
        return inicial();
    else
        return proximos();
}

void enqueue(int valor)
{
    TFila *novo = neww();
    novo->dado = valor;
}

void denqueue(){
    TFila *aux = primeiro;

    ultimo = primeiro;

    while (ultimo->next != primeiro){
        ultimo = ultimo->next;
    }

    primeiro = primeiro->next;

    ultimo->next = primeiro;

    free(aux);
};
void listar(){
    printf("\n\n listando");
    ultimo = primeiro;
	do{
        printf("\n %d ", ultimo->dado);
        ultimo = ultimo->next;
    } while (ultimo != primeiro);
}
TFila *buscar(int chave){
    ultimo = primeiro;

    do{
        if (ultimo->dado == chave)
        {
            return ultimo;
        }
        ultimo = ultimo->next;
    } while (ultimo != primeiro);
    return NULL;
}
int menu(){
    printf("\n\n lista Circular");
    printf("\n [1]- Adicionar Valor");
    printf("\n [2]- Mostrar Valores");
    printf("\n [3]- Buscar Valor");
    printf("\n [4]- Excluir");
    printf("\n [5]- Sair do Programa");
    printf("\n Escolha uma opcao: ");
    scanf("%d",&opc);
    
    return opc;
}

void casos(int opc){
	int value, key;
	switch (opc){
        case 1:
        
            while (1){
                printf("\n Adicione um numero:[0]sair: ");
                scanf("%d", &value);
                if (value == 0)
                    break;
                enqueue(value);
            }
            break;
        
        case 2:
            listar();
            system("pause");
            break;
        
        case 3:
        
            printf("\n qual valor quer buscar");
            scanf("%d", &key);
            TFila *aux = buscar(key);

            if (aux == NULL)
            {
                printf("chave nao encontrada");
            }
            else
            {
                printf("chave encontrada %p\n", aux);
                system("pause");
            }
            break;
            
        case 4:
        	denqueue();
            break;
        
        case 5:
        	return 0;
            break;
        
        }
}

int main(int argc, char **argv){
    primeiro = NULL;

    int stop,aux;

    while (opc != 5){
        system("cls");
        aux = menu();
        casos(aux); 
    }
    return 0;
}
