#define PilhaD_encadeada.h

typedef struct{
    int dado;
    struct SPilha *next;
    struct SPilha *prev;
} TPilha;

TPilha *primeiro, *novo, *ultimo;

TPilha *inicial(){
    novo = malloc(sizeof(TPilha));
    novo->next = NULL;
    novo->prev = NULL;
    primeiro = novo;
    return novo;
}

TPilha *proximos(){
    novo = malloc(sizeof(TPilha));
    novo->prev = NULL;
    novo->next = (struct SPilha *)primeiro;
    primeiro->prev = (struct SPilha *)novo;
    primeiro = novo;
    return novo;
}

TPilha *new (){
    if (primeiro == NULL)
        return inicial();
    else
        return proximos();
}
