#ifndef GRAFOL_H_INCLUDED
#define GRAFOL_H_INCLUDED
#include "Vertice.h"

class GrafoL{

private:
    int numVertices;
    int numArestas;
    int numArcos;
    bool ehDirecionado;
    bool ehPonderado;
    Vertice* primeiro;

public:

    GrafoL();
    ~GrafoL();
    int getNumVertices();
    int getNumArestas();
    int getNumArcos();
    bool ehGrafoDirecionado();
    void setDirecionado(bool x);
    bool ehGrafoPonderado();
    void setPonderado(bool x);
    Vertice* buscaVertice(int info);
    Aresta* buscaAresta(int vert1, int vert2);
    int verticeDegree(int info);
    int verticeInDegree(int info);
    int verticeOutDegree(int info);
    void sequenciaDeGraus();
    int grauDoGrafo();
    int ordemDoGrafo();
    void vizinhancaAberta(int info);
    void vizinhancaFechada(int info);
    int kRegularidade();
    bool ehCompleto();
    bool ehbipartido();
    bool auxEhBipartido(Vertice* p, int* vetorDeCores, int cor);
    void deepFirstSearch();
    void dfs(Vertice* p, int* vetorDeMarcacao);
    void breadthFirstSearch();
    void fechoTransitivoDireto(int vert);
    void fechoTransitivoIndireto(int vert);
    void auxFechoTransitivoIndireto(int chave);
    void insereVertice(int info);
    void insereAresta(int vert1, int vert2);
    void insereAresta(int vert1, int vert2, int peso);
    void insereArco(int vert1, int vert2);
    void insereArco(int vert1, int vert2, int peso);
    void retiraVertice(int vert);
    void retiraAresta(int vert1, int vert2);
    void retiraArco(int vert1, int vert2);
    void imprimeVertices();
    void imprimeArestas();
    void quickSort(int vetorGraus[], int inicio, int fim);
};

#endif // GRAFOL_H_INCLUDED
