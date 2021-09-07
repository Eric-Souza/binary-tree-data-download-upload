#ifndef LISTA_ENCADEADA_
#define LISTA_ENCADEADA_

#include "tipo_item_lista.h"

class No
{
public:
    No();

private:
    TipoItemLista item;
    No *prox;

    friend class ListaEncadeada;
};

class ListaEncadeada
{
public:
    
    ListaEncadeada();
    ~ListaEncadeada();

    TipoItemLista get_item(int pos);

    void set_item(TipoItemLista item, int pos);
    void insereInicio(TipoItemLista item);
    void insereFinal(TipoItemLista item);
    void inserePosicao(TipoItemLista item, int pos);

    TipoItemLista Pesquisa(TipoChaveLista c);
    TipoItemLista removeInicio();
    TipoItemLista removeFinal();
    TipoItemLista removePosicao(int pos);

    void Limpa();
    int somatorio();
    void Imprime();

private:
    No *primeiro;
    No *ultimo;
    No *posiciona(int pos, bool antes);
    int tamanho;
};

#endif