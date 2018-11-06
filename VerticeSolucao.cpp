#include <iostream>
#include "VerticeSolucao.h"

VerticeSolucao::VerticeSolucao(){

}

VerticeSolucao::~VerticeSolucao()
{

}

int VerticeSolucao::getId()
{
    return id;
}

float VerticeSolucao::getRankk()
{
    return rankk;
}

void VerticeSolucao::setRankk(float valor){

    rankk = valor;
}

void VerticeSolucao::setId(int id){

    this->id = id;
}

VerticeSolucao* VerticeSolucao::getProx()
{
    return prox;
}

void VerticeSolucao::setProx(VerticeSolucao* p)
{
    prox = p;
}
