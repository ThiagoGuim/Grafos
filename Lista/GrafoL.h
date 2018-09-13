#ifndef GRAFOL_H_INCLUDED
#define GRAFOL_H_INCLUDED
#include "Vertice.h"

class GrafoL{

private:
    int numVertices;
    int numArestas;
    bool ehPonderado;
    Vertice* primeiro;

public:

    GrafoL();
    ~GrafoL();
    int getNumVertices();
    void setNumVertices(int numVertices);
    int getNumArestas();
    void setNumArestas(int numArestas);
    Vertice* buscaVertice(int info);
    Aresta* buscaAresta(int vert1, int vert2);
    int grauVertice(int info);
    void sequenciaDeGraus();
    int ordemGrafo();
    void vizinhancaAberta(int info);
    void vizinhancaFechada(int info);
    int kRegularidade();
    bool ehCompleto();
    bool ehbipartido();
    void insereVertice(int info);
    void insereAresta(int vert1, int vert2);
    void insereAresta(int vert1, int vert2, int peso);
    void retiraVertice(int vert);
    void retiraAresta(int vert1, int vert2);
    void imprimeVertices();
    void imprimeArestas();
    void quickSort(int vetorGraus[], int inicio, int fim);
};

#endif // GRAFOL_H_INCLUDED
