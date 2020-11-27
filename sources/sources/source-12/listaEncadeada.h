
typedef struct SLista
{
    int dado;
    struct SLista *next;
} TLista;


//DECLARAÇÃO DA SENTINELA
TLista *primeiro;

//DECLARAÇÃO DA VARIAVEL QUE ADICIONA OS ELEMENTOS
TLista *novo;

//Declaração da variavel que irá a coleção encadeada
TLista *ultimo;

TLista *inicial()
{
    //1.alocar memória
    novo = malloc(sizeof(TLista));
    //2.definir o campo next como null
    novo->next = NULL;
    //guardar o endereço na sentinela primeiro
    primeiro = novo;
    return novo;
}

TLista *proximos()
{
    //1.alocar memória
    novo = malloc(sizeof(TLista));

    //2.definir o campo next como null
    novo->next = NULL;
    //3.encadear
    ultimo = primeiro;
    while (ultimo->next != NULL)
    {
        ultimo = ultimo->next;
    }
    ultimo->next = novo;
    return novo;
}

//melhoria na inteligência do código
TLista *new ()
{
    if (primeiro == NULL)
       return inicial();
    else
        return proximos();
}