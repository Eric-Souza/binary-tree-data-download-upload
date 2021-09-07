#ifndef TIPO_ITEM_LISTA
#define TIPO_ITEM_LISTA

using namespace std;

typedef int TipoChaveLista; 

class TipoItemLista
{
public:
    TipoItemLista();
    TipoItemLista(TipoChaveLista c);

    void SetChave(TipoChaveLista c);
    TipoChaveLista GetChave();
    void Imprime();

private:
    TipoChaveLista chave;
};

#endif