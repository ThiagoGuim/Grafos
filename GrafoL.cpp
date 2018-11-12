#include "GrafoL.h"
#include "Fila.h"
#include "limits.h"
#include "ListaArestaSolucao.h"
#include "ListaVerticeSolucao.h"
#include "ArestaSolucao.h"
#include "VerticeSolucao.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

GrafoL::GrafoL(){

    numVertices = 0;
    numArestas = 0;
    numArcos = 0;
    ehDirecionado = false;
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

int GrafoL::retornaIndice(int* vet, int tam, int id){

    int* gabarito = new int[numVertices];
    Vertice* p = primeiro;


    for(int j = 0; j < numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < numVertices; j++)
        if(gabarito[j] == id)
            return j;

    //cout<< "Indice nao encontrado!" << " Vertice : " << id <<endl;
    return -1;
}

int GrafoL::retornaIndice(int* vet, int tam, int id, GrafoL* newGrafo){

    int* gabarito = new int[newGrafo->numVertices];
    Vertice* p = newGrafo->primeiro;


    for(int j = 0; j < newGrafo->numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < newGrafo->numVertices; j++)
        if(gabarito[j] == id)
            return j;

    //cout<< "Indice nao encontrado!" << " Vertice : " << id <<endl;
    return -1;
}

int GrafoL::retornaVerticeDoVetor(int i){

    int* gabarito = new int[numVertices];
    Vertice* p = primeiro;


    for(int j = 0; j < numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < numVertices; j++)
        if(i == j)
            return gabarito[i];

    delete [] gabarito;
}

int GrafoL::retornaVerticeDoVetor(int i, GrafoL* newGrafo){

    int* gabarito = new int[newGrafo->numVertices];
    Vertice* p = newGrafo->primeiro;


    for(int j = 0; j < newGrafo->numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < newGrafo->numVertices; j++)
        if(i == j)
            return gabarito[i];

    delete [] gabarito;
}

int GrafoL::getNumVertices(){

    return numVertices;
}

int GrafoL::getNumArestas(){

    if(!ehDirecionado)
        return numArestas;
        else{
            cout << "Nao eh possivel achar um numero de arestas,a instancia eh um grafo direcionado" << endl;
            return -1;
        }
}

int GrafoL::getNumArcos(){

    if(ehDirecionado)
        return numArcos;
        else{
            cout << "Nao eh possivel achar um numero de arcos,a instancia eh um grafo nao direcionado" << endl;
            return -1;
        }
}

bool GrafoL::ehGrafoDirecionado(){

    return ehDirecionado;
}

void GrafoL::setDirecionado(bool x){

    ehDirecionado = x;
}

Vertice* GrafoL::buscaVertice(int id){

    Vertice* p = primeiro;

    while(p != NULL){
        if( p->getId() == id)
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
            if(aux->getId() == vert2)
                return aux;
            aux = aux->getProx();
        }
    }

    return aux;
}

void GrafoL::insereVertice(int id){

    Vertice *p = new Vertice();
    Vertice *t = primeiro;

    p->setId(id);
    if(!buscaVertice(id)){
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

    }
}

void GrafoL::insereAresta(int vert1, int vert2){

    if(!ehDirecionado){

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
                        p->increaseDegree();
                        t->increaseDegree();
                        numArestas++;
                    }else
                        cout << "\nVertices nao encontrados !" << endl;
                }else
                    cout << "Aresta ja existente entre os vertices " << vert1 << " e " << vert2 << " ! " << endl;
            }
    }else
            cout << "Nao eh possivel inserir uma aresta em um grafo direcionado, apenas um arco !" << endl;
}

void GrafoL::insereAresta(int vert1, int vert2, int peso){

    if(!ehDirecionado){

        Vertice* p = buscaVertice(vert1);
        Vertice* t = buscaVertice(vert2);
        Aresta* a = new Aresta();
        Aresta* b = new Aresta();

        if(vert1 == vert2){}
            //cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
            else{
                if(buscaAresta(vert1, vert2) == NULL){
                    if(p != NULL && t != NULL){
                        p->insereAresta(vert2, a, peso);
                        t->insereAresta(vert1, b, peso);
                        p->increaseDegree();
                        t->increaseDegree();
                        numArestas++;
                    }//else
                        //cout << "\nVertices nao encontrados !" << endl;
                }//else
                    //cout << "Aresta ja existente entre os vertices " << vert1 << " e " << vert2 << " ! " << endl;
            }
        }else
            cout << "Nao eh possivel inserir uma aresta em um grafo direcionado, apenas um arco !" << endl;
}

void GrafoL::insereArco(int vert1, int vert2){//(tail, head)

    if(ehDirecionado){

        Vertice* p = buscaVertice(vert1);
        Vertice* t = buscaVertice(vert2);
        Aresta* a = new Aresta();

        if(vert1 == vert2)
            cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
            else{
                if(buscaAresta(vert1, vert2) == NULL){
                    if(p != NULL && t != NULL){
                            p->insereArco(vert2, a);
                        t->increaseInDegree();
                        numArcos++;
                    }else
                        cout << "\nVertices nao encontrados !" << endl;
                }else
                    cout << "Arco ja existente entre os vertices " << vert1 << " e " << vert2 << " ! " << endl;
            }
    }else
        cout << "Nao eh possivel inserir uma arco em um grafo nao direcionado, apenas uma aresta !" << endl;
}

void GrafoL::insereArco(int vert1, int vert2, int peso){//(tail, head, peso)

    if(ehDirecionado){

        Vertice* p = buscaVertice(vert1);
        Vertice* t = buscaVertice(vert2);
        Aresta* a = new Aresta();

        if(vert1 == vert2)
            cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
            else{
                if(buscaAresta(vert1, vert2) == NULL){
                    if(p != NULL && t != NULL){
                            p->insereAresta(vert2, a, peso);
                        t->increaseInDegree();
                        numArcos++;
                    }else
                        cout << "\nVertices nao encontrados !" << endl;
                }else
                    cout << "Arco ja existente entre os vertices " << vert1 << " e " << vert2 << " ! " << endl;
            }
    }else
        cout << "Nao eh possivel inserir uma arco em um grafo nao direcionado, apenas uma aresta !" << endl;
}

void GrafoL::retiraVertice(int vert){

    Vertice* p = primeiro;
    Vertice* aux = NULL;

    if(p == NULL || buscaVertice(vert) == NULL){
        cout << "Vertice inexistente ! " << endl;
    }
        else{

            while(p != NULL){
                if(buscaAresta(p->getId(), vert) != NULL)
                    p->retiraAresta(vert);
                p = p->getProx();
            }

            p = primeiro;

            while(p != NULL){
                if(p->getId() == vert)
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
}

void GrafoL::retiraAresta(int vert1, int vert2)
{
    if(!ehDirecionado){

        Vertice* p = buscaVertice(vert1);
        Vertice* t = buscaVertice(vert2);

        if(p == NULL || t == NULL)
            cout << "Vertices inexistentes !" << endl;
            else{
                if(buscaAresta(vert1, vert2) != NULL){
                    if(ehDirecionado)
                        p->retiraAresta(vert2);
                        else{
                            p->retiraAresta(vert2);
                            t->retiraAresta(vert1);
                        }
                    numArestas--;
                }else
                    cout << "Remocao impossivel,arco inexistente entre " << vert1 << " e " << vert2 << endl;
            }
    }else
        cout << "Nao eh possivel excluir uma aresta de um grafo direcionado,somente um arco !" << endl;
}

void GrafoL::retiraArco(int vert1, int vert2)//(tail, head)
{
    if(ehDirecionado){

        Vertice* p = buscaVertice(vert1);
        Vertice* t = buscaVertice(vert2);

        if(p == NULL || t == NULL)
            cout << "Vertices inexistentes !" << endl;
            else{
                if(buscaAresta(vert1, vert2) != NULL){
                        p->retiraArco(vert2);
                    p->decreaseOutDegree();
                    t->decreaseInDegree();
                    numArcos--;
                }else
                    cout << "Remocao impossivel,arco inexistente direcionado de " << vert1 << " para " << vert2 << endl;
            }
    }else
        cout << "Nao eh possivel excluir uma arco de um grafo nao direcionado,somente um aresta !" << endl;
}

int GrafoL::getVerticeDegree(int id){

    Vertice* p = buscaVertice(id);
    int degree;

    if(p == NULL){
        cout << "Vertice inexistente !(" << id << ")" << endl;
        return -1;
    }else{
            degree = p->getDegree();
            return degree;
    }
}

int GrafoL::getVerticeInDegree(int id){

    Vertice* p = buscaVertice(id);
    int inDegree;

    if(p == NULL){
        cout << "Vertice inexistente !(" << id << ")" << endl;
        return -1;
    }else{
            inDegree = p->getInDegree();
            return inDegree;
    }
}

int GrafoL::getVerticeOutDegree(int id){

    Vertice* p = buscaVertice(id);
    int outDegree;

    if(p == NULL){
        cout << "Vertice inexistente !(" << id << ")" << endl;
        return -1;
    }else{
            outDegree = p->getOutDegree();
            return outDegree;
    }
}

void GrafoL::sequenciaDeGraus(){//Duvida no destrutor do vetor ,aonde tenho q deletar

    Vertice*p = primeiro;
    int* vetorGraus = new int[numVertices];
    int i = 0;

    if(p == NULL)
        cout << "<>" << endl;
        else{
            while(p != NULL){
                vetorGraus[i] = p->getDegree();
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
    delete [] vetorGraus;
}

int GrafoL::grauDoGrafo(){

    int aux;
    Vertice*p = primeiro;

    if(p != NULL){
        aux = p->getDegree();
        while(p != NULL){
            if(p->getDegree() >= aux)
                aux = p->getDegree();
            p = p->getProx();
        }
        return aux;
    }else
        return -1;
}

int GrafoL::ordemDoGrafo(){
    return numVertices;
}

void GrafoL::vizinhancaAberta(int id){

    Vertice*p = buscaVertice(id);

    if(p != NULL){
        Aresta* aux = p->getArestas();
        cout << "Vizinhanca aberta de (" << id << ") = <";
        while(aux != NULL){
            cout << aux->getId() << ",";
            aux = aux->getProx();
        }
        cout << ">" << endl;
    }else
        cout << "Vertice nao existe, sem vizinhanca !" << endl;
}

void GrafoL::vizinhancaFechada(int id){

    Vertice*p = buscaVertice(id);

    if(p != NULL){
        Aresta* aux = p->getArestas();
        cout << "Vizinhanca fechada de (" << id << ") = <" << id << ",";
        while(aux != NULL){
            cout << aux->getId() << ",";
            aux = aux->getProx();
        }
        cout << ">" << endl;
    }else
        cout << "Vertice nao existe, sem vizinhanca !" << endl;
}

bool GrafoL::ehCompleto(){//verifica se todos os vertices possuem grau n-1,sendo n o numero de vertices

    int cont = 1;
    Vertice*p = primeiro;

    if(p != NULL){
        while(p->getProx() != NULL){
            if(p->getDegree() == p->getProx()->getDegree() && p->getDegree()== (numVertices)-1)
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

bool GrafoL::ehbipartido(){//Duvida em relacao ao vetor

    Vertice* p = primeiro;
    int vetorDeCores[10000];

    while(p != NULL){
        vetorDeCores[p->getId()] = 0;
        p = p->getProx();
    }

    p = primeiro;

    while(p != NULL){
        if(vetorDeCores[p->getId()] == 0)
            if(auxEhBipartido(p, vetorDeCores, 0) == false)
                    return false;
        p = p->getProx();
    }

    return true;

}

bool GrafoL::auxEhBipartido(Vertice* p, int* vetorDeCores, int cor){


    if(cor == 0)
        vetorDeCores[p->getId()] = 1;

    if(cor == 1)
        vetorDeCores[p->getId()] = 2;
        else
            vetorDeCores[p->getId()] = 1;

    Aresta* a = p->getArestas();

    while(a != NULL){
        if(a != NULL && vetorDeCores[a->getId()] == 0){
            if(auxEhBipartido(buscaVertice(a->getId()), vetorDeCores, vetorDeCores[p->getId()]) == false)
                return false;
        }else
            if(vetorDeCores[a->getId()] == vetorDeCores[p->getId()])
                return false;

        a = a->getProx();
    }

    return true;
}

void GrafoL::deepFirstSearch(){//Duvida em relacao ao vetor

    Vertice* p = primeiro;
    int vetorDeMarcacao[10000];

    while(p != NULL){
        vetorDeMarcacao[p->getId()] = 0;
        p = p->getProx();
    }

    p = primeiro;

    while(p != NULL){
        if(vetorDeMarcacao[p->getId()] == 0)
            dfs(p, vetorDeMarcacao);
        p = p->getProx();
    }
}

void GrafoL::dfs(Vertice* p, int* vetorDeMarcacao){

    Aresta* a = p->getArestas();

    vetorDeMarcacao[p->getId()] = 1;
    cout << p->getId() << ",";
    while(a != NULL){
        if(a != NULL && vetorDeMarcacao[a->getId()] == 0)
            dfs(buscaVertice(a->getId()), vetorDeMarcacao);
        a = a->getProx();
    }
}

void GrafoL::breadthFirstSearch(){

    Fila fila;

    Vertice* p = primeiro;

    int vetorDeMarcacao[10000];

    while(p != NULL){
        vetorDeMarcacao[p->getId()] = 0;
        p = p->getProx();
    }

    vetorDeMarcacao[primeiro->getId()] = 1;

    fila.enfileira(primeiro->getId());

    while(!fila.vazia()){
        Vertice* v = buscaVertice(fila.desenfileira());
        Aresta* a = v->getArestas();
        cout << v->getId() << ",";
        while(a != NULL){
            if(vetorDeMarcacao[a->getId()] == 0){
                vetorDeMarcacao[a->getId()] = 1;
                fila.enfileira(a->getId());
            }

            a = a->getProx();
        }
    }
}

int GrafoL::kRegularidade(){//verifica se cada vertice tem grau igual ao do seu proximo

    int cont = 1;
    Vertice* p = primeiro;

    if(ehCompleto())
        return p->getDegree();
        else{
            while(p->getProx() != NULL){
                if(p->getDegree() == p->getProx()->getDegree())
                    cont++;
                p = p->getProx();
            }
        }

    if(cont == numVertices)
        return primeiro->getDegree();
        else{
            cout << "Grafo nao Regular !" << endl;
            return -1;
        }
}

void GrafoL::fechoTransitivoDireto(int vert){//utiliza a busca em profundidade para achar o fecho transitivo direto

    if(ehDirecionado){
        Vertice* v = buscaVertice(vert);
        int vetorDeMarcacao[10000];

        if(v != NULL){
            dfs(v, vetorDeMarcacao);
        }else
            cout << "Vertice inexistente !" << endl;
    }else
        cout << "Nao ha fecho transitivo direto para um vertice em um grafo nao direcionado !" << endl;
}

void GrafoL::fechoTransitivoIndireto(int vert){

    Fila fila;

    Vertice* p = primeiro;
    Aresta* a;
    int chave = vert;
    int vetorDeMarcacao[10000];

    while(p != NULL){
        vetorDeMarcacao[p->getId()] = 0;
        p = p->getProx();
    }

    fila.enfileira(vert);

    p = primeiro;

    while(!fila.vazia()){

        vetorDeMarcacao[fila.getInicio()] = 1;
        cout << fila.desenfileira() << ", ";
        while(p != NULL){
            if(vetorDeMarcacao[p->getId()] == 0){
                a = p->getArestas();

                while(a != NULL){
                    if(a->getId() == chave){
                        fila.enfileira(p->getId());
                        chave = p->getId();
                        vetorDeMarcacao[p->getId()] = 1;
                        break;
                    }
                    a = a->getProx();
                }
            }
            p = p->getProx();
        }
        p = primeiro;
    }
}

void GrafoL::imprimeVertices(){

    Vertice *p = primeiro;

    while(p != NULL){
        cout << p->getId() << " ";
        p = p->getProx();
    }

    cout << "\nQuantidade de Vertices : " << numVertices;

    cout << endl;
}

void GrafoL::imprimeArestas(){

    Vertice *p = primeiro;

    cout << "LISTA DE ADJACENCIAS : " << endl;

    while(p != NULL){
        cout << "[" << p->getId() << "]";

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

GrafoL* GrafoL::subgrafoInduzido(int * vet, int tam){

    GrafoL* grafo = new GrafoL();
    Vertice* p;
    Aresta* a;

    for(int i = 0; i < tam; i++){
        if(buscaVertice(vet[i]) != NULL){
                p = buscaVertice(vet[i]);
                grafo->insereVertice(vet[i]);
                a = p->getArestas();

                while(a != NULL){//nao precisa tratar o fato de uma aresta de um vertice nao estar no vetor passado, pois como insere so os vertices que estao no
                                 //vetor passado por parametro e o metodo de inserir aresta
                                 //ja verifica se existem os vertices passados como parametro , entao so sao inseridas as arestas entre os vertices do vetor.

                    grafo->insereAresta(p->getId(), a->getId(), a->getPeso());

                    a = a->getProx();
                }

        }//else
            //cout << "Nao eh possivel inserir o vertice " << vet[i] << ", pois nao existe no grafo !" << endl;
    }


    /*cout << "SUBGRAFO INDUZIDO PELOS VERTICES {";

    for(int i = 0; i < tam; i++)
        cout << vet[i] << ", ";

    cout << "} " << endl;

    grafo->imprimeArestas();*/
    return grafo;
}

int GrafoL::numVizinhosTerminais(Vertice* p, int *terminais, int tam){


    int numTerminaisVizinhos = 0;

    Aresta* a = p->getArestas();

    while(a != NULL){

        for(int i = 0; i < tam; i++)
            if(a->getId() == terminais[i])
                numTerminaisVizinhos += 1;

        a = a->getProx();

    }

    return numTerminaisVizinhos;
}

bool GrafoL::verificaSePodeSolucao(Vertice* p, int* vetorSolucao){

    if(vetorSolucao[p->getId()] != 0)
        return false;
    return true;
}

bool GrafoL::verificaSeEhTerminal(Vertice* p, int* terminais, int tam){

    int i = 0;

    while(i < tam){
        if(p->getId() == terminais[i])
            return true;
        i++;
    }

    return false;
}

GrafoL* GrafoL::kruskal(){

    int numComponentesConexas = 1;
    Vertice* p = primeiro;
    Aresta* a = p->getArestas();
    GrafoL* grafoSolucao = new GrafoL();

    int* arvores = new int[numVertices];
    ArestaSolucao* vetorDeArestas = new ArestaSolucao[numArestas];
    ListaArestaSolucao solucao;

    for(int i = 0; i < numVertices; i++)
        arvores[i] = retornaVerticeDoVetor(i);


    for(int i = 0; i < numArestas; i++){
        vetorDeArestas[i].setVertice1(-1);
        vetorDeArestas[i].setVertice2(-1);
        vetorDeArestas[i].setPeso(-1);
    }

    int i = 0;

    while(p != NULL){
        a = p->getArestas();

        while(a != NULL){

            if(!veSeJaTemArestaSolucao(vetorDeArestas, p->getId(), a->getId())){
                ArestaSolucao aux(p->getId(), a->getId(), a->getPeso());
                vetorDeArestas[i] = aux;
                i++;
            }

            a = a->getProx();
        }

        p = p->getProx();
    }

    ordenaArestas(vetorDeArestas, 0, numArestas);
    ListaArestaSolucao listaDeArestas;

    for (int i = 0; i < numArestas; i++)
        listaDeArestas.insereAresta(&vetorDeArestas[i]);


    //for (int i = 0; i < numArestas; i++)
        //cout << vetorDeArestas[i].getVertice1() << "-" << vetorDeArestas[i].getVertice2() << "//" << vetorDeArestas[i].getPeso() << endl;


    int cont = 0;
    for (int i = 0; cont < (numVertices-1) && !listaDeArestas.vazia() && i < numArestas; i++) {
        int arvore1;
        int arvore2;
        arvore1 = buscaArvore(vetorDeArestas[i].getVertice1(), arvores);
        arvore2 = buscaArvore(vetorDeArestas[i].getVertice2(), arvores);
        if (arvore1 != arvore2) {
            uneArvores( arvore1, arvore2, arvores);
            listaDeArestas.removeAresta(vetorDeArestas[i].getVertice1(), vetorDeArestas[i].getVertice2());
            grafoSolucao->insereVertice(vetorDeArestas[i].getVertice1());
            grafoSolucao->insereVertice(vetorDeArestas[i].getVertice2());
            grafoSolucao->insereAresta(vetorDeArestas[i].getVertice1(), vetorDeArestas[i].getVertice2(), vetorDeArestas[i].getPeso());
            solucao.insereAresta(&vetorDeArestas[i]);
            cont++;
        }
    }

    for(int i = 1; i < numVertices;i++)
        if(arvores[i] != arvores[0])
            numComponentesConexas = numComponentesConexas + 1;
    if(numComponentesConexas != 1)
        cout << "nao eh conexo !" << endl;
        else
            cout << "Eh conexo !" << endl;

    solucao.imprime();
    return grafoSolucao;
    delete [] arvores;

}

GrafoL* GrafoL::kruskal(int* numComponentesConexas){

    *numComponentesConexas = 1;
    Vertice* p = primeiro;
    Aresta* a = p->getArestas();
    GrafoL* grafoSolucao = new GrafoL();

    int* arvores = new int[numVertices];
    ArestaSolucao* vetorDeArestas = new ArestaSolucao[numArestas];
    ListaArestaSolucao solucao;

    for(int i = 0; i < numVertices; i++)
        arvores[i] = retornaVerticeDoVetor(i);


    for(int i = 0; i < numArestas; i++){
        vetorDeArestas[i].setVertice1(-1);
        vetorDeArestas[i].setVertice2(-1);
        vetorDeArestas[i].setPeso(-1);
    }

    int i = 0;

    while(p != NULL){
        a = p->getArestas();

        while(a != NULL){

            if(!veSeJaTemArestaSolucao(vetorDeArestas, p->getId(), a->getId())){
                ArestaSolucao aux(p->getId(), a->getId(), a->getPeso());
                vetorDeArestas[i] = aux;
                i++;
            }

            a = a->getProx();
        }

        p = p->getProx();
    }

    ordenaArestas(vetorDeArestas, 0, numArestas);
    ListaArestaSolucao listaDeArestas;

    for (int i = 0; i < numArestas; i++)
        listaDeArestas.insereAresta(&vetorDeArestas[i]);


    //for (int i = 0; i < numArestas; i++)
        //cout << vetorDeArestas[i].getVertice1() << "-" << vetorDeArestas[i].getVertice2() << "//" << vetorDeArestas[i].getPeso() << endl;


    int cont = 0;
    for (int i = 0; cont < (numVertices-1) && !listaDeArestas.vazia() && i < numArestas; i++) {
        int arvore1;
        int arvore2;
        arvore1 = buscaArvore(vetorDeArestas[i].getVertice1(), arvores);
        arvore2 = buscaArvore(vetorDeArestas[i].getVertice2(), arvores);
        if (arvore1 != arvore2) {
            uneArvores( arvore1, arvore2, arvores);
            listaDeArestas.removeAresta(vetorDeArestas[i].getVertice1(), vetorDeArestas[i].getVertice2());
            grafoSolucao->insereVertice(vetorDeArestas[i].getVertice1());
            grafoSolucao->insereVertice(vetorDeArestas[i].getVertice2());
            grafoSolucao->insereAresta(vetorDeArestas[i].getVertice1(), vetorDeArestas[i].getVertice2(), vetorDeArestas[i].getPeso());
            solucao.insereAresta(&vetorDeArestas[i]);
            cont++;
        }
    }

    for(int i = 1; i < numVertices;i++)
        if(arvores[i] != arvores[0])
            *numComponentesConexas = *numComponentesConexas + 1;
    if(*numComponentesConexas != 1)
        cout << "nao eh conexo !" << endl;
        else
            cout << "Eh conexo !" << endl;

    solucao.imprime();
    return grafoSolucao;
    delete [] arvores;

}


int GrafoL::buscaArvore(int id, int* arvores){//retorna em qual arvore o vertice esta

    int arvore = id;
    int aux = retornaIndice(arvores, numVertices, id);

    while(arvore != arvores[aux])
        arvore = arvores[aux];

    return arvore;
}

int GrafoL::buscaArvore(int id, int* arvores, GrafoL* newGrafo){//retorna em qual arvore o vertice esta

    int arvore = id;
    int aux = retornaIndice(arvores, numVertices, id, newGrafo);

    while(arvore != arvores[aux])
        arvore = arvores[aux];

    return arvore;
}

void GrafoL::uneArvores(int id, int id2, int* arvores){

    int arvore1 = arvores[retornaIndice(arvores, numVertices, id)];
    int arvore2 = arvores[retornaIndice(arvores, numVertices, id2)];
    int aux;
    int aux2;

    if(arvore1 < arvore2){
        aux = arvore1;
        aux2 = arvore2;
    }else{
        aux = arvore2;
        aux2 = arvore1;
    }

    for(int i = 0; i < numVertices; i++)
        if(arvores[i] == aux2)
            arvores[i] = aux;

}

void GrafoL::uneArvores(int id, int id2, int* arvores, GrafoL* newGrafo){

    int arvore1 = arvores[retornaIndice(arvores, numVertices, id, newGrafo)];
    int arvore2 = arvores[retornaIndice(arvores, numVertices, id2, newGrafo)];
    int aux;
    int aux2;

    if(arvore1 < arvore2){
        aux = arvore1;
        aux2 = arvore2;
    }else{
        aux = arvore2;
        aux2 = arvore1;
    }

    for(int i = 0; i < newGrafo->numVertices; i++)
        if(arvores[i] == aux2)
            arvores[i] = aux;

}

void GrafoL::ordenaArestas(ArestaSolucao vetorDeArestas[], int inicio, int fim){

	int i, j, pivo;
	ArestaSolucao aux;
	i = inicio;
	j = fim-1;
	pivo = vetorDeArestas[(inicio + fim) / 2].getPeso();

	while(i <= j){

		while(vetorDeArestas[i].getPeso() < pivo && i < fim)
			i++;

		while(vetorDeArestas[j].getPeso() > pivo && j > inicio)
			j--;

		if(i <= j){
            aux = vetorDeArestas[i];
			vetorDeArestas[i] = vetorDeArestas[j];
			vetorDeArestas[j] = aux;
			i++;
			j--;
		}
	}

	if(j > inicio)
        ordenaArestas(vetorDeArestas, inicio, j+1);

	if(i < fim)
        ordenaArestas(vetorDeArestas, i, fim);
}

bool GrafoL::veSeJaTemArestaSolucao(ArestaSolucao vetorDeArestas[], int id, int id2){

    for(int i = 0; i < numArestas; i++){
        if((id == vetorDeArestas[i].getVertice1() || id == vetorDeArestas[i].getVertice2()) && (id2 == vetorDeArestas[i].getVertice1() || id2 == vetorDeArestas[i].getVertice2()))
            return true;
    }

    return false;
}

bool GrafoL::veSeJaTemArestaSolucao(ArestaSolucao vetorDeArestas[], int id, int id2, int tam){

    for(int i = 0; i < tam; i++){
        if((id == vetorDeArestas[i].getVertice1() || id == vetorDeArestas[i].getVertice2()) && (id2 == vetorDeArestas[i].getVertice1() || id2 == vetorDeArestas[i].getVertice2()))
            return true;
    }

    return false;
}

void GrafoL::steinerGulosoRandomizado(int* terminais, int tam, float alfa, int numeroSolucoes){



}

void GrafoL::preencheListaDeCandidatos(ListaVerticeSolucao* listaDeCandidatos, int* terminais, int tam){

    Vertice* p = primeiro;

    int i = 0;
    while(p != NULL){
        if(!verificaSeEhTerminal(p , terminais, tam)){
            VerticeSolucao* a = new VerticeSolucao();
            a->setId(p->getId());
            a->setRankk(0);
            listaDeCandidatos->insereVertice(a);
            i++;
        }
        p = p->getProx();
    }
}


/*GrafoL* GrafoL::steinerGuloso(int* terminais, int tam){


    Vertice* p = primeiro;
    GrafoL* grafoAux;

    grafoAux = copiaGrafo();

    ListaVerticeSolucao* listaDeCandidatos = new ListaVerticeSolucao();

    int i = 0;
    while(p != NULL){
        if(!verificaSeEhTerminal(p , terminais, tam)){
            VerticeSolucao* a = new VerticeSolucao();
            a->setId(p->getId());
            a->setRankk(0);
            listaDeCandidatos->insereVertice(a);
            i++;
        }
        p = p->getProx();
    }

    atribuiRank(listaDeCandidatos, terminais, tam, grafoAux);
    ordenaListaDeCandidatos(listaDeCandidatos, 0, listaDeCandidatos->getTamanho());
    //listaDeCandidatos->imprime();

    GrafoL* newGrafo = new GrafoL();

    int numeroDeComponentesConexas = 0;

    for(int i = 0; i < tam;i++)
        newGrafo->insereVertice(terminais[i]);
    newGrafo = subgrafoInduzido(terminais, tam);
    newGrafo = montaArvore(newGrafo, &numeroDeComponentesConexas);

    if(listaDeCandidatos->vazia())
        newGrafo = kruskal();

    int* vetorAux2 = new int[numVertices];

    for(int i = 0; i < numVertices;i++)
        vetorAux2[i] = 0;

    for(int i = 0; i < tam;i++)
        vetorAux2[i] = terminais[i];

    int auxiliar = tam;

    while(numeroDeComponentesConexas != 1 && !listaDeCandidatos->vazia()){
        auxiliar = auxiliar +1;
        vetorAux2[auxiliar-1] = listaDeCandidatos->getPrimeiro()->getId();
        newGrafo->insereVertice(listaDeCandidatos->getPrimeiro()->getId());
        newGrafo = subgrafoInduzido(vetorAux2, auxiliar);
        newGrafo = montaArvore(newGrafo, &numeroDeComponentesConexas);
        grafoAux->retiraVertice(listaDeCandidatos->getPrimeiro()->getId());
        listaDeCandidatos->removeVertice();
        atribuiRank(listaDeCandidatos, terminais, tam, grafoAux);
        ordenaListaDeCandidatos(listaDeCandidatos, 0, listaDeCandidatos->getTamanho());

    }


    podaGrafo(newGrafo, terminais, tam);

    cout << "SOLUCAO : " << endl;

    newGrafo->imprimeArestas();
    delete [] vetorAux2;
    return newGrafo;
}*/

GrafoL* GrafoL::steinerGuloso(int* terminais, int tam){

    Vertice* p = primeiro;
    GrafoL* solucao = new GrafoL();
    GrafoL* grafoAux = new GrafoL();
    ListaVerticeSolucao* listaCandidatos = new ListaVerticeSolucao();
    int numComponentesConexas = 1;

    grafoAux = copiaGrafo();

    while(p != NULL){

        if(!verificaSeEhTerminal(p, terminais, tam)){
            VerticeSolucao* a = new VerticeSolucao();
            a->setId(p->getId());
            a->setRankk(0);
            listaCandidatos->insereVertice(a);
        }

        p = p->getProx();
    }

    if(listaCandidatos->vazia()){
        solucao = kruskal();
        solucao->imprimeArestas();
        return solucao;
    }


    //grafoAux->imprimeArestas();
    //listaCandidatos->imprime();

    atribuiRank(listaCandidatos, terminais, tam, grafoAux);
    ordenaListaDeCandidatos(listaCandidatos, 0, listaCandidatos->getTamanho());

    solucao = subgrafoInduzido(terminais, tam);
    solucao = kruskal(&numComponentesConexas);

    while(numComponentesConexas != 1 && !listaCandidatos->vazia()){

        Vertice* p = buscaVertice(listaCandidatos->getPrimeiro()->getId());
        Aresta* adj = p->getArestas();

        while(adj != NULL){

            solucao->insereVertice(listaCandidatos->getPrimeiro()->getId());
            solucao->insereVertice(adj->getId());
            solucao->insereAresta(listaCandidatos->getPrimeiro()->getId(), adj->getId(), adj->getPeso());

            adj = adj->getProx();
        }

        solucao = solucao->kruskal(&numComponentesConexas);
        grafoAux->retiraVertice(listaCandidatos->getPrimeiro()->getId());
        listaCandidatos->removeVertice();


        atribuiRank(listaCandidatos, terminais, tam, grafoAux);
        ordenaListaDeCandidatos(listaCandidatos, 0, listaCandidatos->getTamanho());
    }

    if(listaCandidatos->vazia() && numComponentesConexas != 1)
        cout << "Nao ha solucao, nao eh possivel criar uma arvore ligando os terminais !" << endl;
        else{
            cout << "SOLUCAO : " << endl;
            podaGrafo(solucao, terminais, tam);
            solucao->imprimeArestas();
        }
}


GrafoL* GrafoL::podaGrafo(GrafoL* newGrafo, int* terminais, int tam){

    Vertice* p = newGrafo->primeiro;

    while(p != NULL){
        if(p->getDegree() == 1 && !verificaSeEhTerminal(p, terminais, tam))
            newGrafo->retiraVertice(p->getId());
        p = p->getProx();
    }
}

GrafoL* GrafoL::copiaGrafo(){

    Vertice* p = primeiro;
    Aresta* a;
    GrafoL* grafoCopiado = new GrafoL();


    if(!ehDirecionado){

        while(p != NULL){
            a = p->getArestas();
            grafoCopiado->insereVertice(p->getId());

            while(a != NULL){
                grafoCopiado->insereVertice(a->getId());
                grafoCopiado->insereAresta(p->getId(), a->getId(), a->getPeso());
                a = a->getProx();
            }

            p = p->getProx();
        }

        return grafoCopiado;
    }else{
        grafoCopiado->setDirecionado(1);

        while(p != NULL){
            a = p->getArestas();
            grafoCopiado->insereVertice(p->getId());
            while(a != NULL){
                grafoCopiado->insereVertice(a->getId());
                grafoCopiado->insereArco(p->getId(), a->getId(), a->getPeso());
                a = a->getProx();
            }

            p = p->getProx();
        }

        return grafoCopiado;
    }
}



GrafoL* GrafoL::montaArvore(GrafoL* newGrafo, int* numComponentesConexas){

    *numComponentesConexas = 1;
    Vertice* p = newGrafo->primeiro;
    Aresta* a = p->getArestas();
    GrafoL* grafoSolucao = new GrafoL();


    if(newGrafo->getNumVertices() > 1){

        int* arvores = new int[newGrafo->numVertices];
        ArestaSolucao* vetorDeArestas = new ArestaSolucao[newGrafo->numArestas];
        ListaArestaSolucao solucao;

        for(int i = 0; i < newGrafo->numVertices; i++)
            arvores[i] = retornaVerticeDoVetor(i, newGrafo);


        for(int i = 0; i < newGrafo->numArestas; i++){
            vetorDeArestas[i].setVertice1(-1);
            vetorDeArestas[i].setVertice2(-1);
            vetorDeArestas[i].setPeso(-1);
        }

        int i = 0;

        while(p != NULL){
            a = p->getArestas();

            while(a != NULL){

                if(!veSeJaTemArestaSolucao(vetorDeArestas, p->getId(), a->getId(), newGrafo->numArestas)){
                    ArestaSolucao aux(p->getId(), a->getId(), a->getPeso());
                    vetorDeArestas[i] = aux;
                    i++;
                }

                a = a->getProx();
            }

            p = p->getProx();
        }

        ordenaArestas(vetorDeArestas, 0, newGrafo->numArestas);
        ListaArestaSolucao listaDeArestas;

        for (int i = 0; i < newGrafo->numArestas; i++)
            listaDeArestas.insereAresta(&vetorDeArestas[i]);


       // for (int i = 0; i < newGrafo->numArestas; i++)
            //cout << vetorDeArestas[i].getVertice1() << "-" << vetorDeArestas[i].getVertice2() << "//" << vetorDeArestas[i].getPeso() << endl;


        int cont = 0;
        for (int i = 0; cont < (newGrafo->numVertices-1) && !listaDeArestas.vazia() && i < newGrafo->numArestas; i++) {
            int arvore1;
            int arvore2;
            arvore1 = buscaArvore(vetorDeArestas[i].getVertice1(), arvores, newGrafo);
            arvore2 = buscaArvore(vetorDeArestas[i].getVertice2(), arvores, newGrafo);
            if (arvore1 != arvore2) {
                uneArvores(arvore1, arvore2, arvores, newGrafo);
                listaDeArestas.removeAresta(vetorDeArestas[i].getVertice1(), vetorDeArestas[i].getVertice2());
                solucao.insereAresta(&vetorDeArestas[i]);
                grafoSolucao->insereVertice(vetorDeArestas[i].getVertice1());
                grafoSolucao->insereVertice(vetorDeArestas[i].getVertice2());
                grafoSolucao->insereAresta(vetorDeArestas[i].getVertice1(), vetorDeArestas[i].getVertice2(), vetorDeArestas[i].getPeso());
                cont++;
            }
        }

        for(int i = 1; i < newGrafo->numVertices;i++)
            if(arvores[i] != arvores[0])
                *numComponentesConexas = *numComponentesConexas + 1;

        delete [] arvores;
        return grafoSolucao;
    }else{
        grafoSolucao->insereVertice(newGrafo->primeiro->getId());
        return grafoSolucao;
    }
}


void GrafoL::atribuiRank(ListaVerticeSolucao* listaDeCandidatos, int* terminais, int tam, GrafoL* grafoAux){

    float rankk = 0;
    float pesoNormalizado;
    Vertice* p = grafoAux->primeiro;
    Aresta* a;

    while(p != NULL){

        if(!verificaSeEhTerminal(p, terminais, tam) && p->getDegree() != 0){

            float soma = 0;
            a = p->getArestas();

            while(a != NULL){
                pesoNormalizado = normaliza(a->getPeso());
                soma = soma + pesoNormalizado;
                a = a->getProx();
            }

            rankk = ((soma/p->getDegree())-(numVizinhosTerminais(p, terminais, tam)));
            listaDeCandidatos->buscaVerticeSolucao(p->getId())->setRankk(rankk);
        }

        p = p->getProx();
    }

}

void GrafoL::ordenaListaDeCandidatos(ListaVerticeSolucao* listaDeCandidatos , int inicio, int fim){

    VerticeSolucao* vetorAux = new VerticeSolucao[listaDeCandidatos->getTamanho()];

    int cont = listaDeCandidatos->getTamanho();

    for(int i = 0; i < cont; i++)
        vetorAux[i] = *listaDeCandidatos->removeVertice();

    auxOrdenaListaCandidatos(vetorAux, inicio, fim);

    for(int i = cont-1; i >= 0; i--)
        listaDeCandidatos->insereVertice(&vetorAux[i]);

}

void GrafoL::auxOrdenaListaCandidatos(VerticeSolucao* vetorAux, int inicio, int fim){

    int i, j;
    float pivo;
    VerticeSolucao aux;
	i = inicio;
	j = fim-1;

	pivo = vetorAux[(inicio + fim) / 2].getRankk();

	while(i <= j){

		while(vetorAux[i].getRankk() < pivo && i < fim)
			i++;

		while(vetorAux[j].getRankk() > pivo && j > inicio)
			j--;

		if(i <= j){
            aux = vetorAux[i];
			vetorAux[i] = vetorAux[j];
			vetorAux[j] = aux;
			i++;
			j--;
		}
	}

	if(j > inicio)
        auxOrdenaListaCandidatos(vetorAux, inicio, j+1);

	if(i < fim)
        auxOrdenaListaCandidatos(vetorAux, i, fim);
}

float GrafoL::normaliza(float valor){//coloca o peso da aresta entre  1 e 10

    Vertice *p = primeiro;
    Aresta* a = p->getArestas();
    int maximo = a->getPeso();
    int minimo = a->getPeso();
    float x;

    while(p != NULL){
        a = p->getArestas();

        while(a != NULL){
            if(a->getPeso() > maximo)
                maximo = a->getPeso();
                else{
                    if(a->getPeso() <= minimo)
                        minimo = a->getPeso();
                }
            a = a->getProx();
        }

        p = p->getProx();
    }

    x = ((valor - minimo)/(maximo - minimo))*10;

    return x;
}

float GrafoL::pesoDaArvore(){

    Vertice* p = primeiro;
    Aresta* a;
    float soma = 0;

    while(p != NULL){
        a = p->getArestas();

        while(a != NULL){
            soma = soma + a->getPeso();
            a = a->getProx();
        }

        p = p ->getProx();
    }

    return soma/2;
}

int* GrafoL::djisktra(int part){

    bool pred[numVertices]; ///vetor marca predecessor

    int dist[numVertices]; ///vetor distancia

    int infinity=INT_MAX/2;

    Vertice* Q = new Vertice[numVertices];
    Q[0]=*primeiro;
    Fila fila;
    for(int i=0;i<(numVertices-1);i++){//*
        dist[i] = infinity;
        pred[i] = false;
        Q[i+1] = *Q[i].getProx();
        fila.enfileira(Q[i].getId());
    }

    fila.enfileira(Q[numVertices - 1].getId());///preenche vetores //*


    dist[part] = 0;

    int u=0;


    while(!fila.vazia()){ ///loop principal

        u = fila.getInicio();
        cout << u << endl;
        cout << fila.desenfileira() << endl;


        if(pred[u]==false){

            pred[u] = true;
            Aresta* aux = Q[u].getArestas();

            while(aux != NULL){ ///verifica vertices adjacentes e custo de cada

                Vertice* v = Q[u].getProx();
                int custo = aux->getPeso();//Q[u].getArestas()->getPeso(); //*

                if(dist[v->getId()] > (dist[u] + custo)){ ///atualiza o custo

                    dist[v->getId()] = dist[u] + custo;
                    fila.enfileira(v->getId());

                }
                aux = aux->getProx();
            }
        }

    }

    //for(int i = 0; i <= 6;i++)
        //cout << dist[i] << " ";
    return dist;//*
}
