
typedef struct SFila{
    int dado;
    struct SFila *next;
} TFila;


//DECLARAÇÃO DA SENTINELA
TFila *primeiro;

//DECLARAÇÃO DA VARIAVEL QUE ADICIONA OS ELEMENTOS
TFila *novo;

//Declaração da variavel que irá a coleção encadeada
TFila *ultimo;

TFila *inicial()
{
    //1.alocar memória
    novo = malloc(sizeof(TFila));
    //2.definir o campo next como null
    novo->next = novo;
    //guardar o endereço na sentinela primeiro
    primeiro = novo;
    return novo;
}

TFila *proximos()
{
    //1.alocar memória
    novo = malloc(sizeof(TFila));

    //2.definir o campo next como null
    novo->next = primeiro;
    //3.encadear
    ultimo = primeiro;
    while (ultimo->next != primeiro)
    {
        ultimo = ultimo->next;
    }
    ultimo->next = novo;
    return novo;
}

//melhoria na inteligência do código
TFila *new ()
{
    if (primeiro == NULL)
       return inicial();
    else
        return proximos();
}