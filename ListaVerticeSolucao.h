#ifndef LISTAVERTICESOLUCAO_H_INCLUDED
#define LISTAVERTICESOLUCAO_H_INCLUDED
#include "VerticeSolucao.h"

class ListaVerticeSolucao{

private:

    VerticeSolucao* primeiro;
    int tamanho;

public:

    ListaVerticeSolucao();
    ~ListaVerticeSolucao();

    void insereVertice(VerticeSolucao* a);
    void insereVertice(int id);
    void removeTudo();
    VerticeSolucao* removeVertice();
    VerticeSolucao* removeVerticeDaPosicao(int posicao);
    VerticeSolucao* getPrimeiro();
    VerticeSolucao* getPosicaoEscolhida(int posicao);
    bool vazia();
    void imprime();
    int getTamanho();
    VerticeSolucao* buscaVerticeSolucao(int id);

};

#endif // LISTAVERTICESOLUCAO_H_INCLUDED
