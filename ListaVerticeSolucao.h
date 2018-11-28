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

    void insereVertice(int id, float rankk);
    void removeTudo();
    void removeVertice();
    void removeVerticeDaPosicao(int posicao);
    VerticeSolucao* getPrimeiro();
    VerticeSolucao* getPosicaoEscolhida(int posicao);
    bool vazia();
    void imprime();
    int getTamanho();
    VerticeSolucao* buscaVerticeSolucao(int id);

};

#endif // LISTAVERTICESOLUCAO_H_INCLUDED
