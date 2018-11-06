#ifndef LISTAARESTASOLUCAO_H_INCLUDED
#define LISTAARESTASOLUCAO_H_INCLUDED
#include "ArestaSolucao.h"


class ListaArestaSolucao{

private:

    ArestaSolucao* primeiro;


public:

    ListaArestaSolucao();
    ~ListaArestaSolucao();

    void insereAresta(ArestaSolucao* a);
    void removeAresta(int id, int id2);
    bool vazia();
    void imprime();

};

#endif // LISTAARESTASOLUCAO_H_INCLUDED
