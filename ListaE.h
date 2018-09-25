#ifndef LISTAE_H_INCLUDED
#define LISTAE_H_INCLUDED
#include "Aresta.h"

class ListaE{

private:

    Aresta* primeiro;

public:

    ListaE();
    ~ListaE();
    void insereFinal(int info);
    bool busca(int info);
    void imprime();
    void retira(int info);

};

#endif // LISTAE_H_INCLUDED
