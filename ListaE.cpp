#include "ListaE.h"
#include <iostream>

using namespace std;

ListaE::ListaE(){

    primeiro = NULL;
}

ListaE::~ListaE(){

    Aresta *p = primeiro;

    while(p != NULL){
        Aresta *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaE::insereFinal(int info){

    Aresta *p = new Aresta();
    Aresta *t = primeiro;

    p->setInfo(info);

    if(t == NULL){
        primeiro = p;
        p->setProx(NULL);
    }else{
        while(t->getProx() != NULL)
        t = t->getProx();

        t->setProx(p);
        p->setProx(NULL);
    }
}

bool ListaE::busca(int info){

    Aresta* p = primeiro;

    while(p != NULL){
        if( p->getInfo() == info)
            return true;
        p = p->getProx();
    }

    return false;
}

void ListaE::imprime(){

    Aresta *p = primeiro;

    while(p != NULL){
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
}

void ListaE::retira(int i)
{
    Aresta* p = primeiro;
    Aresta* aux = NULL;

    while(p != NULL){
        if(p->getInfo() == i)
            break;
        aux = p;
        p = p->getProx();
    }

    if(aux == NULL){
        primeiro = primeiro->getProx();
        delete p;
    }else{
        if(p == NULL){
            aux = NULL;
            delete p;
        }else{
            aux->setProx(p->getProx());
            delete p;
        }
    }
}

