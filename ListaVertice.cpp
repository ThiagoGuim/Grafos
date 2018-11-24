#include "ListaVertice.h"
#include <iostream>

using namespace std;

ListaVertice::ListaVertice()
{
    primeiro = NULL;
    tamanho = 0;
}

ListaVertice::~ListaVertice(){

    Vertice *p = primeiro;

    while(p != NULL){
        Vertice *t = p->getProx();
        delete p;
        p = t;
    }

    free(p);
}

void ListaVertice::insereVertice(Vertice* t, float rankk){

    Vertice* p = primeiro;
    Vertice* a = t;

    if(primeiro == NULL){
        primeiro = a;
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setProx(p);
    }

    tamanho++;
}


Vertice* ListaVertice::removeVertice(){

    Vertice* p = primeiro;

    if(p != NULL){
        primeiro = p->getProx();
        delete p;
        tamanho--;
    }

}

Vertice* ListaVertice::buscaVerticeSolucao(int id){

    Vertice* p = primeiro;

    while(p != NULL){
        if(p->getId() == id)
            return p;
        p = p->getProx();
    }

    return p;
}


bool ListaVertice::vazia(){

    if(primeiro == NULL)
        return true;
        else
            return false;
}

void ListaVertice::imprime(){

    Vertice *p = primeiro;

    cout << "LISTA DE CANDIDATOS : " << endl;

    while(p != NULL){
        cout << p->getId() << "//" << p->getRankk() << endl;
        p = p->getProx();
    }
}

Vertice* ListaVertice::getPrimeiro(){

    return primeiro;
}

int ListaVertice::getTamanho(){

    return tamanho;
}

Vertice* ListaVertice::removeVerticeDaPosicao(int posicao){

    Vertice* p = primeiro;
    Vertice* aux = NULL;
    int cont = 0;

    while(p != NULL){
        if(cont == posicao)
            break;
        aux = p;
        p = p->getProx();
        cont++;
    }

    if(aux == NULL){
        primeiro = p->getProx();
        delete p;
        tamanho--;
    }else{
        aux->setProx(p->getProx());
        delete p;
        tamanho--;
    }

}

Vertice* ListaVertice::getPosicaoEscolhida(int posicao){

    Vertice* p = primeiro;
    int cont = 0;

    while(p != NULL){
        if(cont == posicao)
            break;
        p = p->getProx();
        cont++;
    }

    return p;
}

void ListaVertice::removeTudo(){

    Vertice* p = primeiro;
    Vertice* aux = NULL;

    while (p != NULL){
        aux = p;
        p = p->getProx();
        delete aux;
    }
    primeiro = NULL;
    tamanho = 0;
}
