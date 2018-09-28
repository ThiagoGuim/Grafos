#include "Vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(){

    degree = 0;
    inDegree = 0;
    outDegree = 0;
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

int Vertice::getId(){

    return id;
}

void Vertice::setId(int id){
    this->id = id;
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
        a->setId(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setId(vert);
        a->setProx(p);
    }

    increaseDegree();
}

void Vertice::insereArco(int vert, Aresta* a){

    Aresta* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setId(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setId(vert);
        a->setProx(p);
    }
}

void Vertice::insereAresta(int vert, Aresta* a, int peso){

    Aresta* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setPeso(peso);
        a->setId(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setPeso(peso);
        a->setId(vert);
        a->setProx(p);
    }
}

void Vertice::insereArco(int vert, Aresta* a, int peso){

    Aresta* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setPeso(peso);
        a->setId(vert);
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setPeso(peso);
        a->setId(vert);
        a->setProx(p);
    }

    increaseOutDegree();
}

void Vertice::retiraAresta(int vert2)
{
    Aresta* p = primeiro;
    Aresta* aux = NULL;

    if(p == NULL){
        cout << "Aresta inexistente ! vertice " << id << "nao possui nenhuma aresta !" ;
    }


    while(p != NULL){
        if(p->getId() == vert2)
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
        cout << "Arco inexistente ! vertice " << id << "nao possui nenhum arco !" ;
    }

    while(p != NULL){
        if(p->getId() == vert2)
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
        cout << p->getId() << " ";
        p = p->getProx();
    }
}

int Vertice::getDegree(){

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

