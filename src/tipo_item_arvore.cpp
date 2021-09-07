#include "tipo_item_arvore.h"
#include <iostream>

TipoItem::TipoItem()
{
    chave = "";
}
TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}

void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}

TipoChave TipoItem::GetChave()
{
    return chave;
}

void TipoItem::Imprime()
{
    std::cout << chave << " ";
}
