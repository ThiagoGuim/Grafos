#include "VerticeSolucao.h"
#include "ListaVerticeSolucao.h"
#include <iostream>

using namespace std;

ListaVerticeSolucao::ListaVerticeSolucao()
{
    primeiro = NULL;
    tamanho = 0;
}

ListaVerticeSolucao::~ListaVerticeSolucao(){

    VerticeSolucao *p = primeiro;

    while(p != NULL){
        VerticeSolucao *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaVerticeSolucao::insereVertice(VerticeSolucao* a){

    VerticeSolucao* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setProx(p);
    }

    tamanho++;
}

void ListaVerticeSolucao::insereVertice(int id){

    VerticeSolucao* p = primeiro;
    VerticeSolucao* a = new VerticeSolucao();
    a->setId(id);
    a->setRankk(0);

    if(primeiro == NULL){
        primeiro = a;
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setProx(p);
    }

    tamanho++;
}


VerticeSolucao* ListaVerticeSolucao::removeVertice(){

    VerticeSolucao* p = primeiro;
    VerticeSolucao* aux = NULL;

    if(p != NULL){
        primeiro = p->getProx();
        aux = p;
        delete p;
        tamanho--;
    }

    return aux;

}

VerticeSolucao* ListaVerticeSolucao::buscaVerticeSolucao(int id){

    VerticeSolucao* p = primeiro;

    while(p != NULL){
        if( p->getId() == id)
            return p;
        p = p->getProx();
    }

    return p;

}


bool ListaVerticeSolucao::vazia(){

    if(primeiro == NULL)
        return true;
        else
            return false;
}

void ListaVerticeSolucao::imprime(){

    VerticeSolucao *p = primeiro;

    cout << "LISTA DE CANDIDATOS : " << endl;

    while(p != NULL){
        cout << p->getId() << "//" << p->getRankk() << endl;
        p = p->getProx();
    }
}

VerticeSolucao* ListaVerticeSolucao::getPrimeiro(){

    return primeiro;
}

int ListaVerticeSolucao::getTamanho(){

    return tamanho;
}
