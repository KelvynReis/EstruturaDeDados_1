
typedef struct SFila{
    int dado;
    struct SFila *next;
} TFila;

typedef struct SDescritor{
    TFila * primeiro; //sentinela
    int quantidade;
    TFila * ultimo;
} TDescritor;

//Descritor
TDescritor descritor;



//DECLARAÇÃO DA VARIAVEL QUE ADICIONA OS ELEMENTOS
TFila * novo;

//Declaração da variavel que irá a coleção encadeada
TFila *ultimo;

TFila *inicial(){
    //1.alocar memória
    novo = malloc(sizeof(TFila));
    //2.definir o campo next como null
    novo->next = NULL;
    //guardar o endereço do primeiro e do ultimo no descritor e a quantidade de elementos
    descritor.primeiro = novo;
    descritor.ultimo = novo;
    descritor.quantidade = 1;
    return novo;
}

TFila *proximos(){
    //1.alocar memória
    novo = malloc(sizeof(TFila));
    //2.definir o campo next como null
    novo->next = NULL;
    //3.encadear
    descritor.ultimo->next = novo;
    //atualizar a referencia do ultimo e a quantidade no descritor
    descritor.ultimo = novo;
    descritor.quantidade++;
    return novo;
}

//melhoria na inteligência do código
TFila *new ()
{
    if (descritor.primeiro == NULL)
       return inicial();
    else
        return proximos();
}