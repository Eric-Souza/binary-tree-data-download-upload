#ifndef TIPO_ITEM
#define TIPO_ITEM

#include <string>

using namespace std;

typedef string TipoChave; // TipoChave é um inteiro

class TipoItem
{
public:
    TipoItem();
    TipoItem(TipoChave c);

    void SetChave(TipoChave c);
    TipoChave GetChave();
    void Imprime();

private:
    TipoChave chave;
};

#endif