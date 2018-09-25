#include "Vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(){

    int degree = 0;
    int inDegree = 0;
    int outDegree = 0;
    primeiro = NULL;

}

Vertice::~Vertice(){

    Aresta *p = primeiro;

    while(p != NULL){
        Aresta *t = p->getProx();
        delete p;
        p = t;
    }
}

int Vertice::getInfo(){
    return info;
}

void Vertice::setInfo(int info){
    this->info = info;
}

Vertice* Vertice::getProx(){
    return prox;
}

void Vertice::setProx(Vertice* p){
    prox = p;
}

Aresta* Vertice::getArestas(){
    return primeiro;
}

void Vertice::setArestas(Aresta* arestas){
    this->primeiro = arestas;
}

void Vertice::insereAresta(int vert, Aresta* a){

    Aresta* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setInfo(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setInfo(vert);
        a->setProx(p);
    }

    increaseDegree();
}

void Vertice::insereArco(int vert, Aresta* a){

    Aresta* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setInfo(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setInfo(vert);
        a->setProx(p);
    }

    increaseOutDegree();
}

void Vertice::insereAresta(int vert, Aresta* a, int peso){

    Aresta* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setPeso(peso);
        a->setInfo(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setPeso(peso);
        a->setInfo(vert);
        a->setProx(p);
    }

    increaseDegree();
}

void Vertice::insereArco(int vert, Aresta* a, int peso){

    Aresta* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setPeso(peso);
        a->setInfo(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setPeso(peso);
        a->setInfo(vert);
        a->setProx(p);
    }

    increaseOutDegree();
}

void Vertice::retiraAresta(int vert2)
{
    Aresta* p = primeiro;
    Aresta* aux = NULL;

    if(p == NULL){
        cout << "Aresta inexistente ! vertice " << info << "nao possui nenhuma aresta !" ;
    }


    while(p != NULL){
        if(p->getInfo() == vert2)
            break;
        aux = p;
        p = p->getProx();
    }

    if(aux == NULL){
        primeiro = primeiro->getProx();
        delete p;
    }else{
        aux->setProx(p->getProx());
        delete p;
    }

    decreaseDegree();
}

void Vertice::retiraArco(int vert2)
{
    Aresta* p = primeiro;
    Aresta* aux = NULL;

    if(p == NULL){
        cout << "Aresta inexistente ! vertice " << info << "nao possui nenhuma aresta !" ;
    }

    while(p != NULL){
        if(p->getInfo() == vert2)
            break;
        aux = p;
        p = p->getProx();
    }

    if(aux == NULL){
        primeiro = primeiro->getProx();
        delete p;
    }else{
        aux->setProx(p->getProx());
        delete p;
    }

    decreaseOutDegree();
}

void Vertice::imprime(){

    Aresta *p = primeiro;

    while(p != NULL){
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
}

int Vertice::getDegree(){

    /*Aresta *p = primeiro;
    int grau = 0;

    if(p == NULL)
        return grau;
        else{
            while(p != NULL){
                grau++;
                p = p->getProx();
            }
            return grau;
        }
    */
    return degree;
}

int Vertice::getInDegree()
{
    return inDegree;
}

int Vertice::getOutDegree()
{
    return outDegree;
}

void Vertice::increaseDegree()
{
    degree++;
}

void Vertice::increaseInDegree()
{
    inDegree++;
}

void Vertice::increaseOutDegree()
{
    outDegree++;
}

void Vertice::decreaseDegree()
{
    degree--;
}

void Vertice::decreaseInDegree()
{
    inDegree--;
}

void Vertice::decreaseOutDegree()
{
    outDegree--;
}

