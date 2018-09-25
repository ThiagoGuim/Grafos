#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Vertice.h"

class Fila{

private:
    Vertice* c;
    Vertice* f;

public:
    Fila();
    ~Fila();
    int getInicio();
    void enfileira(int info);
    int desenfileira();
    bool vazia();

};

#endif // FILA_H_INCLUDED
