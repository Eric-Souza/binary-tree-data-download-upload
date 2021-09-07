#include <iostream>
#include <fstream>
#include <string>
#include "ArvoreBinaria.h"

using namespace std;

int main(int argc, char const *argv[])
{

    string arq = argv[1];
    fstream file;

    file.open(arq);

    if (!file.is_open())
    {
        cerr << "O arquivo nao abriu!\n";
        return -1;
    }

    ArvoreBinaria Arvore;

    int n_dados, bin;
    string nome_user;

    file >> n_dados;
    for (int i = 0; i < n_dados; i++)
    {
        file >> nome_user;
        file >> bin;

        TipoItem novo;
        // O(1)
        novo.SetChave(nome_user);

        // O(log n)
        Arvore.insere(novo, bin);
    }
    
    // O(n)
    Arvore.caminha(2);
    printf("\n");

    TipoNo *No;
    while (file >> nome_user)
    {
        // O(log n) caso médio | O(1) melhor caso | O(n) pior caso (arvore degenerada)
        No = Arvore.pesquisa(nome_user);
        printf("%s %d\n", nome_user.c_str(), No->lista_bin.somatorio()); //somatorio() => O(n) 

        // O(log n) caso médio | O(n) pior caso
        Arvore.remove(nome_user);
    }

    // O(n)
    Arvore.caminha(2);

    file.close();

    return 0;
}
