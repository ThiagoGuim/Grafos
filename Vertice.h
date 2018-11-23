#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#include "Aresta.h"
#include <cstdio>
#include <cstdlib>

class Vertice{

private:
    int id;
    Aresta* primeiro; //cabeça da lista de arestas
    Vertice* prox;
    int degree;
    int inDegree;
    int outDegree;
    bool ehTerminal;
    bool marcado;

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
    int getId();
    void setId(int id);
    bool getMarcado();
    void marcar();
    Vertice* getProx();
    void setProx(Vertice *p);
    Aresta* getArestas(); //retorna a cabeça da lista
    void setArestas(Aresta* arestas); //define a cabeça da lista
    void insereAresta(int vert, Aresta* a); //insere a aresta com a outra extremidade em a->getId
    void insereAresta(int vert, int peso); //insere a aresta com o peso
    void insereArco(int vert2, Aresta* a); //insere arco que tem como cabeça a->getId
    void insereArco(int vert, Aresta* a, int peso); //insere arco com peso
    void retiraAresta(int vert);//retira aresta com o vertice vert
    void retiraArco(int vert);//retira arco que tem como cabeça vert
    void imprime(FILE* arq);
    bool veSeEhTerminal();
    void setTerminal(bool i);

};

#endif // VERTICE_H_INCLUDED


