#include "ArestaSolucao.h"

ArestaSolucao::ArestaSolucao(int id1, int id2, int peso){

    vertice1 = id1;
    vertice2 = id2;
    this->peso = peso;
}

ArestaSolucao::ArestaSolucao(){}

ArestaSolucao::~ArestaSolucao(){}

int ArestaSolucao::getVertice1()
{
    return vertice1;
}

int ArestaSolucao::getVertice2()
{
    return vertice2;
}

int ArestaSolucao::getPeso()
{
    return peso;
}

int ArestaSolucao::getVisitado(){

    return visitado;
}

void ArestaSolucao::setVertice1(int id)
{
    vertice1 = id;
}

void ArestaSolucao::setVertice2(int id)
{
    vertice2 = id;
}

void ArestaSolucao::setPeso(int peso)
{
    this->peso = peso;
}

void ArestaSolucao::setVisitado(bool t){

    visitado = t;
}

ArestaSolucao* ArestaSolucao::getProx()
{
    return prox;
}

void ArestaSolucao::setProx(ArestaSolucao* p)
{
    prox = p;
}

