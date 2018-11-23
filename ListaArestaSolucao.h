#ifndef LISTAARESTASOLUCAO_H_INCLUDED
#define LISTAARESTASOLUCAO_H_INCLUDED
#include "ArestaSolucao.h"


class ListaArestaSolucao{

private:

    ArestaSolucao* primeiro;
    int tamanho;

public:

    ListaArestaSolucao();
    ~ListaArestaSolucao();

    ArestaSolucao* getPrimeiro();
    void insereAresta(int id, int id2, int peso);
    ArestaSolucao* removeAresta(int id, int id2);
    ArestaSolucao* removeArestaComRetorno();
    void removeAresta();
    void removeTudo();
    int getTamanho();
    bool vazia();
    void imprime();

};

#endif // LISTAARESTASOLUCAO_H_INCLUDED
