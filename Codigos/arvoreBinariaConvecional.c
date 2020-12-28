void preFixado(TNo *no){
    if (no == NULL)
        return;
    printf("%d ", no->dado);
    preFixado(no->esq);
    preFixado(no->dir);
}

void central(TNo * no){
    if (no == NULL)
        return;

    central(no->esq);
    printf("%d ",no->dado);
    central(no->dir);
}

void posFixado(TNo *no){
    if (no == NULL)
        return;

    posFixado(no->esq);
    posFixado(no->dir);
    printf("%d ", no->dado);
}
