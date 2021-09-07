#include "ArvoreBinaria.h"
#include <iostream>

TipoNo::TipoNo()
{
    esq = NULL;
    dir = NULL;
}

ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
    limpa();
}

void ArvoreBinaria::insere(TipoItem item, int _bin)
{
    insere_recursivo(raiz, item, _bin);
}


void ArvoreBinaria::insere_recursivo(TipoNo *&p, TipoItem item, int _bin)
{
    TipoItemLista numero_binario;
    numero_binario.SetChave(_bin);

    if (p == NULL)
    {
        p = new TipoNo();
        p->item = item;

        p->lista_bin.insereFinal(numero_binario);
    }
    else
    {

        if (item.GetChave() > p->item.GetChave())
        {
            insere_recursivo(p->dir, item, _bin);
        }
        else if (item.GetChave() < p->item.GetChave())
        {
            insere_recursivo(p->esq, item, _bin);
        }
        else
        {
            p->lista_bin.insereFinal(numero_binario);
        }
    }
}

void ArvoreBinaria::pre_ordem(TipoNo *p)
{
    if (p == NULL)
    {
        p->item.Imprime();
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}

void ArvoreBinaria::in_ordem(TipoNo *p)
{
    if (p != NULL)
    {
        in_ordem(p->esq);
        p->item.Imprime();
        in_ordem(p->dir);
    }
}

void ArvoreBinaria::pos_ordem(TipoNo *p)
{
    if (p != NULL)
    {
        pos_ordem(p->esq);
        pos_ordem(p->dir);
        p->item.Imprime();
    }
}

void ArvoreBinaria::por_nivel()
{
}

void ArvoreBinaria::limpa()
{
    apaga_recursivo(raiz);
    raiz = NULL;
}

void ArvoreBinaria::apaga_recursivo(TipoNo *p)
{
    if (p != NULL)
    {
        apaga_recursivo(p->esq);
        apaga_recursivo(p->dir);
        delete p;
    }
}

TipoNo* ArvoreBinaria::pesquisa(TipoChave chave)
{
    return pesquisa_recursiva(raiz, chave);
}

TipoNo* ArvoreBinaria::pesquisa_recursiva(TipoNo *p, TipoChave chave)
{
    TipoItem aux;

    if (p == NULL)
    {
        return new TipoNo();
    }

    if (chave > p->item.GetChave())
    {
        return pesquisa_recursiva(p->dir, chave);
    }
    else if (chave < p->item.GetChave())
    {
        return pesquisa_recursiva(p->esq, chave);
    }
    else
    {
        return p; //retorna o item com a chave
    }
}

void ArvoreBinaria::remove(TipoChave chave)
{
    return remove_recursivo(raiz, chave);
}

void ArvoreBinaria::remove_recursivo(TipoNo *&no, TipoChave chave)
{
    TipoNo *aux;

    if (no == NULL)
    {
        std::cerr << "Item não está presente";
        exit(-1);
    }

    if (chave < no->item.GetChave())
    {
        return remove_recursivo(no->esq, chave);
    }
    else if (chave > no->item.GetChave())
    {
        return remove_recursivo(no->dir, chave);
    }
    else
    {
        if (no->dir == NULL)
        {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if (no->esq == NULL)
        {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
        {
            antecessor(no, no->esq);
        }
    }
}

void ArvoreBinaria::antecessor(TipoNo *q, TipoNo *&r)
{
    if (r->dir != NULL)
    {
        antecessor(q, r->dir);
        return;
    }

    q->item = r->item;
    q->lista_bin = r->lista_bin;
    q = r;
    r = r->esq;
    free(q);
}

void ArvoreBinaria::caminha(int tipo)
{

    if (tipo == 1)
    {
        pre_ordem(raiz);
    }

    else if (tipo == 2)
    {
        in_ordem(raiz);
    }

    else if (tipo == 3)
    {
        pos_ordem(raiz);
    }

    else
    {
        std::cerr << "Tipo não é válido";
    }
}