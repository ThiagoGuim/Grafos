
#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#include "Aresta.h"

class Vertice{

private:
    int info;
    Aresta* primeiro; //cabeça da lista de arestas
    Vertice* prox;
    int degree;
    int inDegree;
    int outDegree;

public:
    Vertice();
    ~Vertice();
    int getDegree();
    int getInDegree();
    int getOutDegree();
    void increaseDegree();
    void increaseInDegree();
    void increaseOutDegree();
    void decreaseDegree();
    void decreaseInDegree();
    void decreaseOutDegree();
    int getInfo();
    void setInfo(int info);
    Vertice* getProx();
    void setProx(Vertice *p);
    Aresta* getArestas(); //retorna a cabeça da lista
    void setArestas(Aresta* arestas); //define a cabeça da lista
    void insereAresta(int vert2, Aresta* a);
    void insereAresta(int vert, Aresta* a, int peso);
    void insereArco(int vert2, Aresta* a);
    void insereArco(int vert, Aresta* a, int peso);
    void retiraAresta(int vert2);
    void retiraArco(int vert2);
    void imprime();

};

#endif // VERTICE_H_INCLUDED


