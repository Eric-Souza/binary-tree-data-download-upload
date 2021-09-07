#include "tipo_item_lista.h"
#include <stdio.h>

TipoItemLista::TipoItemLista()
{
    chave = -1; 
}
TipoItemLista::TipoItemLista(TipoChaveLista c)
{
    chave = c;
}

void TipoItemLista::SetChave(TipoChaveLista c)
{
    chave = c;
}

TipoChaveLista TipoItemLista::GetChave()
{
    return chave;
}

void TipoItemLista::Imprime()
{
    printf("%d ", chave);
}
