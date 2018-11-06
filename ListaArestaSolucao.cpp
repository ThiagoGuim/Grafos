#include "ArestaSolucao.h"
#include "ListaArestaSolucao.h"
#include <iostream>

using namespace std;

ListaArestaSolucao::ListaArestaSolucao()
{
    primeiro = NULL;
}

ListaArestaSolucao::~ListaArestaSolucao(){

    ArestaSolucao *p = primeiro;

    while(p != NULL){
        ArestaSolucao *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaArestaSolucao::insereAresta(ArestaSolucao* a){

    ArestaSolucao* p = primeiro;

    if(primeiro == NULL){
        primeiro = a;
        a->setProx(NULL);
    }else{
        primeiro = a;
        a->setProx(p);
    }
}

void ListaArestaSolucao::removeAresta(int id, int id2){

    ArestaSolucao* p = primeiro;
    ArestaSolucao* aux = NULL;

    while(p != NULL){
        if((p->getVertice1() == id && p->getVertice2() == id2) || (p->getVertice2() == id && p->getVertice1() == id2))
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
}

bool ListaArestaSolucao::vazia(){

    if(primeiro == NULL)
        return true;
        else
            return false;
}

void ListaArestaSolucao::imprime(){

    ArestaSolucao *p = primeiro;
    cout << "SOLUCAO KRUSKAL : " << endl;
    while(p != NULL){
        cout << p->getVertice1() << "-" << p->getVertice2() << "//" << p->getPeso() << endl;
        p = p->getProx();
    }
}
