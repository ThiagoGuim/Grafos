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
    VerticeSolucao* removeVertice();
    VerticeSolucao* getPrimeiro();
    bool vazia();
    void imprime();
    int getTamanho();
    VerticeSolucao* buscaVerticeSolucao(int id);

};

#endif // LISTAVERTICESOLUCAO_H_INCLUDED
