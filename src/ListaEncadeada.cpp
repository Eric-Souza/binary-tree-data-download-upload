#include <math.h>
#include <iostream>
#include "ListaEncadeada.h"

using namespace std;


No::No()
{
    item.SetChave(-1);
    prox = NULL;
}

ListaEncadeada::ListaEncadeada()
{
    primeiro = new No();
    ultimo = primeiro;
    tamanho = 0;
}

// O(n)
ListaEncadeada::~ListaEncadeada()
{
    Limpa();
    delete primeiro;
}

// O(n)
No* ListaEncadeada::posiciona(int pos, bool antes = false)
{
    if ((pos > tamanho) || (pos <= 0))
    {
        cerr << "Erro: Posição inváliada";
        exit(-1);
    }

    No *p;
    p = primeiro;
    for (int i = 1; i < pos; i++)
    {
        p = p->prox;
    }

    if (!antes)
    {
        p = p->prox;
    }

    return p;
}

TipoItemLista ListaEncadeada::get_item(int pos)
{
    return posiciona(pos)->item;
}

void ListaEncadeada::set_item(TipoItemLista item, int pos)
{
    posiciona(pos)->item = item;
}

void ListaEncadeada::insereInicio(TipoItemLista item)
{
    No *nova = new No();
    nova->item = item;

    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

    if (nova->prox == NULL)
    {
        ultimo = nova;
    }
}

void ListaEncadeada::insereFinal(TipoItemLista item)
{
    No *nova = new No();
    nova->item = item;

    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
}

void ListaEncadeada::inserePosicao(TipoItemLista item, int pos)
{
    if ((pos > tamanho) || (pos <= 0))
    {
        cerr << "Erro: Posição inváliada";
        exit(-1);
    }

    No *nova = new No();
    nova->item = item;

    No *aux = posiciona(pos, true);
    nova->prox = aux->prox;
    aux->prox = nova;
    tamanho++;

    if (nova->prox == NULL)
    {
        ultimo = nova;
    }
}

TipoItemLista ListaEncadeada::removeInicio()
{
    TipoItemLista aux;
    No *p;

    if (tamanho == 0)
    {
        cerr << "Erro: Lista vazia";
        exit(-1);
    }

    p = primeiro->prox; 

    primeiro->prox = p->prox;
    tamanho--;

    if (primeiro->prox == NULL)
        ultimo = primeiro;

    aux = p->item;
    delete p; 

    return aux;
}

TipoItemLista ListaEncadeada::removeFinal()
{
    TipoItemLista aux;
    No *p;

    if (tamanho == 0)
    {
        cerr << "Erro: Lista vazia";
        exit(-1);
    }

    p = posiciona(tamanho, true);

    aux = ultimo->item;
    p->prox = NULL;
    tamanho--;
    delete ultimo;
    ultimo = p;

    return aux;
}

TipoItemLista ListaEncadeada::removePosicao(int pos)
{
    if (tamanho == 0)
    {
        cerr << "Erro: Lista vazia";
        exit(-1);
    }

    TipoItemLista aux;
    No *p, *q;

    p = posiciona(pos, true);
    q = p->prox;
    aux = q->item;

    p->prox = q->prox;
    tamanho--;

    delete q;

    if (p->prox == NULL)
    {
        ultimo = p;
    }

    return aux;
}

TipoItemLista ListaEncadeada::Pesquisa(TipoChaveLista c)
{
    TipoItemLista aux(-1);
    No *p;

    if (tamanho == 0)
    {
        cerr << "Erro: Lista vazia";
        exit(-1);
    }

    p = primeiro->prox;
    while (p != NULL)
    {
        if (p->item.GetChave() == c)
        {
            aux = p->item;
            break;
        }
        p = p->prox;
    }

    return aux;
}

void ListaEncadeada::Imprime()
{
    No *p;

    p = primeiro->prox;
    while (p != NULL)
    {
        p->item.Imprime();
        p = p->prox;
    }

    cout << endl;
}

void ListaEncadeada::Limpa()
{
    No *p;

    p = primeiro->prox;
    while (p != NULL)
    {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }

    ultimo = primeiro;
    tamanho = 0;
}


int converteParaDecimal(int n)
{
    int decimal = 0;
    int bit;
    int i = 0;
    while (n != 0)
    {
        bit = n % 10;
        n = n / 10;
        decimal += bit * pow(2, i);
        i++;
    }
    return decimal;
}

int ListaEncadeada::somatorio()
{
    No *p;
    p = primeiro->prox;

    int soma = 0;
    int decimal;
    while (p != NULL)
    {
        decimal = converteParaDecimal(p->item.GetChave());
        soma += decimal;
        p = p->prox;
    }

    return soma;
}