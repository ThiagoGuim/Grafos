#ifndef LISTAVERTICE_H_INCLUDED
#define LISTAVERTICE_H_INCLUDED
#include "Vertice.h"

class ListaVertice{

private:

    Vertice* primeiro;
    int tamanho;

public:

    ListaVertice();
    ~ListaVertice();

    void insereVertice(Vertice* t, float rankk);
    void removeTudo();
    Vertice* removeVertice();
    Vertice* removeVerticeDaPosicao(int posicao);
    Vertice* getPrimeiro();
    Vertice* getPosicaoEscolhida(int posicao);
    bool vazia();
    void imprime();
    int getTamanho();
    Vertice* buscaVerticeSolucao(int id);

};

#endif // LISTAVERTICE_H_INCLUDED
