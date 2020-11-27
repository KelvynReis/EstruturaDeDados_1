
typedef struct SPilha{
    int dado;
    struct SPilha *next;
} TPilha;


//DECLARAÇÃO DA SENTINELA
TPilha * primeiro;

//DECLARAÇÃO DA VARIAVEL QUE ADICIONA OS ELEMENTOS
TPilha * novo;

//Declaração da variavel que irá a coleção encadeada
TPilha * ultimo;

TPilha * inicial()
{
    //1.alocar memória
    novo = malloc(sizeof(TPilha));
    //2.definir o campo next como null
    novo->next = NULL;
    //guardar o endereço na sentinela primeiro
    primeiro = novo;
    return novo;
}

TPilha * proximos()
{   
    //1.alocar memória
    novo = malloc(sizeof(TPilha));
   
    //2.encadear
    novo->next = primeiro;

    //guardar o endereço na sentinela primeiro
    primeiro = novo;
    return novo;
}

//melhoria na inteligência do código
TPilha * new (){
    if (primeiro == NULL)
       return inicial();
    else
        return proximos();
}