#ifndef ARV_BINARIA_
#define ARV_BINARIA_

#include "ListaEncadeada.h"
#include "tipo_item_arvore.h"

class TipoNo
{
public:
    TipoNo();
    ListaEncadeada lista_bin;
    TipoItem item;

private:
    TipoNo *esq;
    TipoNo *dir;

    friend class ArvoreBinaria;
};

class ArvoreBinaria
{

public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void insere(TipoItem item, int _bin);
    void caminha(int tipo);
    TipoNo *pesquisa(TipoChave chave); 
    void remove(TipoChave chave);      
    void limpa();

private:
    void insere_recursivo(TipoNo *&p, TipoItem item, int _bin);
    void apaga_recursivo(TipoNo *p);
    TipoNo *pesquisa_recursiva(TipoNo *p, TipoChave c); 
    void remove_recursivo(TipoNo *&p, TipoChave chave); 
    void antecessor(TipoNo *q, TipoNo *&r);             
    void por_nivel();
    void pre_ordem(TipoNo *p);
    void in_ordem(TipoNo *p);
    void pos_ordem(TipoNo *p);

    TipoNo *raiz;
};

#endif