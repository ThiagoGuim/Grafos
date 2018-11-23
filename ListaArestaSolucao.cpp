#include "ArestaSolucao.h"
#include "ListaArestaSolucao.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ListaArestaSolucao::ListaArestaSolucao()
{
    primeiro = NULL;
    tamanho = 0;
}

ListaArestaSolucao::~ListaArestaSolucao(){

    ArestaSolucao *p = primeiro;

    while(p != NULL){
        ArestaSolucao *t = p->getProx();
        delete p;
        p = t;
    }

    free(p);
}

void ListaArestaSolucao::insereAresta(int id, int id2, int peso){

    ArestaSolucao* p = primeiro;
    ArestaSolucao* a = new ArestaSolucao();

    a->setVertice1(id);
    a->setVertice2(id2);
    a->setPeso(peso);

    if(primeiro == NULL){
        primeiro = a;
        a->setProx(NULL);
        tamanho++;
    }else{
        primeiro = a;
        a->setProx(p);
        tamanho++;
    }
}

ArestaSolucao* ListaArestaSolucao::removeAresta(int id, int id2){

    ArestaSolucao* p = primeiro;
    ArestaSolucao* aux = NULL;


    while(p != NULL){
        if((p->getVertice1() == id && p->getVertice2() == id2) || (p->getVertice2() == id && p->getVertice1() == id2))
            break;
        aux = p;
        p = p->getProx();
    }

    if(p != NULL){
        if(aux == NULL){
            primeiro = primeiro->getProx();

        }else{
            aux->setProx(p->getProx());

        }
        aux = p;
        //delete p;
    }
    return aux;
}

void ListaArestaSolucao::removeAresta(){

    ArestaSolucao* p = primeiro;

    if(p != NULL){
        primeiro = p->getProx();
        delete p;
        tamanho--;
    }

}

ArestaSolucao* ListaArestaSolucao::removeArestaComRetorno(){

    ArestaSolucao* p = primeiro;
    ArestaSolucao* aux = new ArestaSolucao();

    if(p != NULL){
        aux->setVertice1(p->getVertice1());
        aux->setVertice2(p->getVertice2());
        aux->setPeso(p->getPeso());
        primeiro = p->getProx();
        delete p;
    }
    tamanho--;
    return aux;
}


ArestaSolucao* ListaArestaSolucao::getPrimeiro(){
    return primeiro;
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

int ListaArestaSolucao::getTamanho(){

    return tamanho;
}


void ListaArestaSolucao::removeTudo(){

    ArestaSolucao* p = primeiro;
    ArestaSolucao* aux = NULL;

    while (p != NULL){
        aux = p;
        p = p->getProx();
        delete aux;
    }
    primeiro = NULL;
    tamanho = 0;
}
