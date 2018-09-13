#include "Aresta.h"
#include <iostream>

using namespace std;

Aresta::Aresta(){}

Aresta::~Aresta(){}

int Aresta::getInfo(){
    return info;
}

void Aresta::setInfo(int info){
    this->info = info;
}

Aresta* Aresta::getProx(){
    return prox;
}


void Aresta::setProx(Aresta* p){
    prox = p;
}

int Aresta::getPeso(){

    return this->peso;
}

void Aresta::setPeso(int peso){

    this->peso = peso;
}

