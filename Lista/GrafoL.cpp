#include "GrafoL.h"
#include <iostream>

using namespace std;

GrafoL::GrafoL(){

    numVertices = 0;
    numArestas = 0;
    ehPonderado = false;
    primeiro = NULL;
}

GrafoL::~GrafoL(){

    Vertice *p = primeiro;

    while(p != NULL){
        Vertice *t = p->getProx();
        delete p;
        p = t;
    }
}

int GrafoL::getNumVertices(){

    return numVertices;
}

void GrafoL::setNumVertices(int numVertices){

    this->numVertices = numVertices;
}

int GrafoL::getNumArestas(){

    return numArestas;
}

void GrafoL::setNumArestas(int numArestas){

    this->numArestas = numArestas;
}

Vertice* GrafoL::buscaVertice(int info){

    Vertice* p = primeiro;

    while(p != NULL){
        if( p->getInfo() == info)
            return p;
        p = p->getProx();
    }

    return p;
}

Aresta* GrafoL::buscaAresta(int vert1, int vert2){

    Vertice* p = buscaVertice(vert1);
    Aresta* aux = p->getArestas();

    if(p != NULL && aux != NULL){

        while(aux != NULL){
            if(aux->getInfo() == vert2)
                return aux;
            aux = aux->getProx();
        }
    }

    return aux;
}

void GrafoL::insereVertice(int info){

    Vertice *p = new Vertice();
    Vertice *t = primeiro;

    p->setInfo(info);

    if(!buscaVertice(info)){
        if(t == NULL){
            primeiro = p;
            p->setProx(NULL);
            }else{
                while(t->getProx() != NULL)
                    t = t->getProx();
                    t->setProx(p);
                    p->setProx(NULL);
            }

        numVertices++;

    }//else
        //cout << "Vertice ja existe !" << endl;
}

void GrafoL::insereAresta(int vert1, int vert2){

    Vertice* p = buscaVertice(vert1);
    Vertice* t = buscaVertice(vert2);
    Aresta* a = new Aresta();
    Aresta* b = new Aresta();

    if(vert1 == vert2)
        cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
        else{
            if(buscaAresta(vert1, vert2) == NULL){
                if(p != NULL && t != NULL){
                    p->insereAresta(vert2, a);
                    t->insereAresta(vert1, b);
                    numArestas++;
                }else
                    cout << "\nVertices nao encontrados !" << endl;
            }else
                cout << "Aresta ja existente entre os vertices " << vert1 << " e " << vert2 << " ! " << endl;
        }
}

void GrafoL::insereAresta(int vert1, int vert2, int peso){

    Vertice* p = buscaVertice(vert1);
    Vertice* t = buscaVertice(vert2);
    Aresta* a = new Aresta();
    Aresta* b = new Aresta();

    if(vert1 == vert2)
        cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
        else{
            if(buscaAresta(vert1, vert2) == NULL){
                if(p != NULL && t != NULL){
                    p->insereAresta(vert2, a, peso);
                    t->insereAresta(vert1, b, peso);
                    numArestas++;
                }else
                    cout << "\nVertices nao encontrados !" << endl;
            }else
                cout << "Aresta ja existente entre os vertices " << vert1 << " e " << vert2 << " ! " << endl;
        }
}

void GrafoL::retiraVertice(int vert){

    Vertice* p = primeiro;
    Vertice* aux = NULL;

    if(p == NULL){
        cout << "Vertice inexistente ! " << endl;
    }

    while(p != NULL && p->getInfo() != vert){
        if(buscaAresta(p->getInfo(), vert) != NULL)
            p->retiraAresta(vert);
        p = p->getProx();
    }


    while(p != NULL){
        if(p->getInfo() == vert)
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

void GrafoL::retiraAresta(int vert1, int vert2)
{
    Vertice* p = buscaVertice(vert1);
    Vertice* t = buscaVertice(vert2);

    if(p == NULL || t == NULL)
        cout << "Vertices inexistentes !" << endl;
        else{
            if(buscaAresta(vert1, vert2) != NULL){
                p->retiraAresta(vert2);
                t->retiraAresta(vert1);
                numArestas--;
            }else
                cout << "Remocao impossivel,aresta inexistente entre " << vert1 << " e " << vert2 << endl;
        }
}

int GrafoL::grauVertice(int info){

    Vertice* p = buscaVertice(info);
    int grau;

    if(p == NULL){
        cout << "Vertice inexistente !(" << info << ")" << endl;
        return -1;
    }else{
            grau = p->getGrau();
            return grau;
    }
}

void GrafoL::sequenciaDeGraus(){

    Vertice*p = primeiro;
    int* vetorGraus = new int[numVertices];
    int i = 0;

    if(p == NULL)
        cout << "<>" << endl;
        else{
            while(p != NULL){
                vetorGraus[i] = p->getGrau();
                i++;
                p = p->getProx();
            }
            i = 0;

            quickSort(vetorGraus, i, numVertices);

            cout << "<";

            while(i < numVertices){
                cout << vetorGraus[i] << ",";
                i++;
            }

            cout << ">" << endl;
        }
}

int GrafoL::ordemGrafo(){

    int aux;
    Vertice*p = primeiro;

    if(p != NULL){
        aux = p->getGrau();
        while(p != NULL){
            if(p->getGrau() >= aux)
                aux = p->getGrau();
            p = p->getProx();
        }
        return aux;
    }else
        return -1;
}

void GrafoL::vizinhancaAberta(int info){

    Vertice*p = buscaVertice(info);

    if(p != NULL){
        Aresta* aux = p->getArestas();
        cout << "Vizinhanca aberta de (" << info << ") = <";
        while(aux != NULL){
            cout << aux->getInfo() << ",";
            aux = aux->getProx();
        }
        cout << ">" << endl;
    }else
        cout << "Vertice nao existe, sem vizinhanca !" << endl;
}

void GrafoL::vizinhancaFechada(int info){

    Vertice*p = buscaVertice(info);

    if(p != NULL){
        Aresta* aux = p->getArestas();
        cout << "Vizinhanca fechada de (" << info << ") = <" << info << ",";
        while(aux != NULL){
            cout << aux->getInfo() << ",";
            aux = aux->getProx();
        }
        cout << ">" << endl;
    }else
        cout << "Vertice nao existe, sem vizinhanca !" << endl;
}

bool GrafoL::ehCompleto(){//?

    int cont = 1;
    Vertice*p = primeiro;

    if(p != NULL){
        while(p->getProx() != NULL){
            if(p->getGrau() == p->getProx()->getGrau() && p->getGrau()== (numVertices)-1)
                cont++;
            p = p->getProx();
        }
    }else
        return false;

    if(cont == numVertices)
        return true;
        else
            return false;
}

bool GrafoL::ehbipartido(){//?


}


int GrafoL::kRegularidade(){

    int cont = 1;
    Vertice* p = primeiro;

    if(ehCompleto())
        return p->getGrau();
        else{
            while(p->getProx() != NULL){
                if(p->getGrau() == p->getProx()->getGrau())
                    cont++;
                p = p->getProx();
            }
        }

    if(cont == numVertices)
        return primeiro->getGrau();
        else{
            cout << "Grafo nao Regular !" << endl;
            return -1;
        }
}

void GrafoL::imprimeVertices(){

    Vertice *p = primeiro;

    while(p != NULL){
        cout << p->getInfo() << " ";
        p = p->getProx();
    }

    cout << "\nQuantidade de Vertices : " << numVertices;

    cout << endl;
}

void GrafoL::imprimeArestas(){

    Vertice *p = primeiro;

    while(p != NULL){
        cout << "[" << p->getInfo() << "]";

        if(p->getArestas() != NULL)
            p->imprime();
            else
                cout << "---";
        cout << endl;
        p = p->getProx();
    }
}

void GrafoL::quickSort(int vetorGraus[], int inicio, int fim){

	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = vetorGraus[(inicio + fim) / 2];

	while(i <= j){

		while(vetorGraus[i] > pivo && i < fim)
			i++;

		while(vetorGraus[j] < pivo && j > inicio)
			j--;

		if(i <= j){
            aux = vetorGraus[i];
			vetorGraus[i] = vetorGraus[j];
			vetorGraus[j] = aux;
			i++;
			j--;
		}
	}

	if(j > inicio)
        quickSort(vetorGraus, inicio, j+1);

	if(i < fim)
        quickSort(vetorGraus, i, fim);
}
