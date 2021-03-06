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

    free(p);
}

Vertice* GrafoL::getPrimeiro(){
    return primeiro;
}


void GrafoL::setTerminal(int id){

    Vertice* p = buscaVertice(id);
    p->setTerminal(true);
}


int GrafoL::retornaIndice(int* vet, int tam, int id){

    int* gabarito = new int[numVertices];
    Vertice* p = primeiro;


    for(int j = 0; j < numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < numVertices; j++)
        if(gabarito[j] == id){
            delete[] gabarito;
            return j;
        }

    //cout<< "Indice nao encontrado!" << " Vertice : " << id <<endl;
    delete [] gabarito;
    return -1;

    free(p);
}

int GrafoL::retornaIndice(int id){

    int* gabarito = new int[numVertices];
    Vertice* p = primeiro;


    for(int j = 0; j < numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < numVertices; j++)
        if(gabarito[j] == id){
            delete[] gabarito;
            return j;
        }

    //cout<< "Indice nao encontrado!" << " Vertice : " << id <<endl;
    delete [] gabarito;
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
        if(gabarito[j] == id){
            delete [] gabarito;
            return j;
        }

    delete [] gabarito;
    //cout<< "Indice nao encontrado!" << " Vertice : " << id <<endl;
    return -1;
}

int GrafoL::retornaVerticeDoVetor(int i){//Passado o indice como par�metro, retorna o vertice correspondente

    int* gabarito = new int[numVertices];
    Vertice* p = primeiro;


    for(int j = 0; j < numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < numVertices; j++)
        if(i == j){
            int aux = gabarito[i];
            delete [] gabarito;
            return aux;
        }
    delete [] gabarito;
    return -1;
    free(p);
}

int GrafoL::retornaVerticeDoVetor(int i, GrafoL* newGrafo){

    int* gabarito = new int[newGrafo->numVertices];
    Vertice* p = newGrafo->primeiro;


    for(int j = 0; j < newGrafo->numVertices; j++){//mapea
        gabarito[j] = p->getId();
        p = p->getProx();
    }

    for(int j = 0; j < newGrafo->numVertices; j++)
        if(i == j){
            int aux = gabarito[i];
            delete [] gabarito;
            return aux;
        }
    delete [] gabarito;
    return -1;
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
        if(p->getId() == id)
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

    Vertice *t = primeiro;

    if(!buscaVertice(id)){
        Vertice *p = new Vertice();
        p->setId(id);
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

        if(vert1 == vert2){}
            //cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
            else{
                if(buscaAresta(vert1, vert2) == NULL){
                    if(p != NULL && t != NULL){
                        p->insereAresta(vert2, peso);
                        t->insereAresta(vert1, peso);
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

        if(vert1 == vert2)
            cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
            else{
                if(buscaAresta(vert1, vert2) == NULL){
                    if(p != NULL && t != NULL){
                            p->insereAresta(vert2, peso);
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
                if(buscaAresta(p->getId(), vert) != NULL){
                    p->retiraAresta(vert);
                    numArestas--;
                }
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
                numVertices--;
            }else{
                aux->setProx(p->getProx());
                delete p;
                numVertices--;
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
                }//else
                    //cout << "Remocao impossivel,aresta inexistente entre " << vert1 << " e " << vert2 << endl;
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

void GrafoL::sequenciaDeGraus(FILE* arq){

    Vertice*p = primeiro;
    int* vetorGraus = new int[numVertices];
    int i = 0;

    if(p == NULL)
        fprintf(arq, "<>\n");
        else{
            while(p != NULL){
                vetorGraus[i] = p->getDegree();
                i++;
                p = p->getProx();
            }
            i = 0;

            quickSort(vetorGraus, i, numVertices);

            fprintf(arq, "<");

            while(i < numVertices){
                fprintf(arq, "%d, ", vetorGraus[i]);
                i++;
            }

            fprintf(arq, ">\n");
        }

    delete [] vetorGraus;
}

int GrafoL::grauDoGrafo(){

    int maior;
    Vertice*p = primeiro;

    if(p != NULL){
        maior = p->getDegree();
        while(p != NULL){
            if(p->getDegree() >= maior)
                maior = p->getDegree();
            p = p->getProx();
        }
        return maior;
    }else
        return -1;
}

int GrafoL::ordemDoGrafo(){
    return numVertices;
}

void GrafoL::vizinhancaAberta(int id, FILE* arq){

    Vertice*p = buscaVertice(id);
    Aresta* adj;

    if(p != NULL){
        adj = p->getArestas();
        fprintf(arq, " Vizinhanca aberta de (%d) = < %d, = ", id, id);
        while(adj != NULL){
            fprintf(arq, " %d, ", adj->getId());
            adj = adj->getProx();
        }
        fprintf(arq, " >\n ");
    }else
        fprintf(arq, " Vertice nao existe, sem vizinhanca ! ");
}

void GrafoL::vizinhancaFechada(int id, FILE* arq){

    Vertice*p = buscaVertice(id);
    Aresta* adj;

    if(p != NULL){
        adj = p->getArestas();
        fprintf(arq, " Vizinhanca fechada de (%d) = < %d, = ", id, id);
        while(adj != NULL){
            fprintf(arq, " %d, ", adj->getId());
            adj = adj->getProx();
        }
        fprintf(arq, " >\n ");
    }else
        fprintf(arq, " Vertice nao existe, sem vizinhanca ! ");
}

bool GrafoL::ehCompleto(){//verifica se todos os vertices possuem grau n-1,sendo n o numero de vertices

    int cont = 1;
    Vertice*p = primeiro;

    if(p != NULL){
        while(p->getProx() != NULL){
            if(p->getDegree() == p->getProx()->getDegree() && p->getDegree() == (numVertices)-1)
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

bool GrafoL::ehbipartido(){

    Vertice* p = primeiro;
    int vetorDeCores[numVertices];

    while(p != NULL){//Preenche o vetor de cores
        vetorDeCores[retornaIndice(p->getId())] = 0;
        p = p->getProx();
    }

    p = primeiro;

    while(p != NULL){
        if(vetorDeCores[retornaIndice(p->getId())] == 0)//Enquanto nao estiverem todos com alguma cor
            if(auxEhBipartido(p, vetorDeCores, 0) == false)
                    return false;
        p = p->getProx();
    }

    return true;

}

bool GrafoL::auxEhBipartido(Vertice* p, int* vetorDeCores, int cor){

    //Colore
    if(cor == 0)
        vetorDeCores[retornaIndice(p->getId())] = 1;

    if(cor == 1)
        vetorDeCores[retornaIndice(p->getId())] = 2;
        else
            vetorDeCores[retornaIndice(p->getId())] = 1;

    Aresta* a = p->getArestas();

    //Usa recursividade para ir colorindo o resto, se conseguir colorir as adjacencias de todos os vertices com cores diferentes do a deles proprios retorna true
    while(a != NULL){
        if(a != NULL && vetorDeCores[retornaIndice(a->getId())] == 0){
            if(auxEhBipartido(buscaVertice(a->getId()), vetorDeCores, vetorDeCores[retornaIndice(p->getId())]) == false)
                return false;
        }else
            if(vetorDeCores[retornaIndice(a->getId())] == vetorDeCores[retornaIndice(p->getId())])
                return false;

        a = a->getProx();
    }

    return true;
}

void GrafoL::deepFirstSearch(FILE* arq){

    Vertice* p = primeiro;
    int* vetorDeMarcacao = new int[numVertices];

    while(p != NULL){
        vetorDeMarcacao[retornaIndice(p->getId())] = 0;
        p = p->getProx();
    }

    p = primeiro;

    while(p != NULL){
        if(vetorDeMarcacao[retornaIndice(p->getId())] == 0)
            dfs(p, vetorDeMarcacao, arq);

        p = p->getProx();
    }

    delete [] vetorDeMarcacao;
}

void GrafoL::dfs(Vertice* p, int* vetorDeMarcacao, FILE* arq){

    Aresta* a = p->getArestas();

    vetorDeMarcacao[retornaIndice(p->getId())] = 1;
    fprintf(arq, "%d-> ", p->getId());
    while(a != NULL){
        if(a != NULL && vetorDeMarcacao[retornaIndice(a->getId())] == 0)
            dfs(buscaVertice(a->getId()), vetorDeMarcacao, arq);
        a = a->getProx();
    }
}

void GrafoL::dfs(Vertice* p, int* vetorDeMarcacao){

    Aresta* a = p->getArestas();

    vetorDeMarcacao[retornaIndice(p->getId())] = 1;

    while(a != NULL){
        if(a != NULL && vetorDeMarcacao[retornaIndice(a->getId())] == 0)
            dfs(buscaVertice(a->getId()), vetorDeMarcacao);
        a = a->getProx();
    }
}


void GrafoL::breadthFirstSearch(){//Usa a alocacao em uma fila para fazer a busca em largura

    Fila fila;

    Vertice* p = primeiro;

    int vetorDeMarcacao[numVertices];

    while(p != NULL){
        vetorDeMarcacao[retornaIndice(p->getId())] = 0;
        p = p->getProx();
    }

    vetorDeMarcacao[primeiro->getId()] = 1;

    fila.enfileira(primeiro->getId());

    Vertice* v;
    Aresta* a;

    while(!fila.vazia()){
        v = buscaVertice(fila.desenfileira());
        a = v->getArestas();
        cout << v->getId() << ",";
        while(a != NULL){
            if(vetorDeMarcacao[retornaIndice(a->getId())] == 0){
                vetorDeMarcacao[retornaIndice(a->getId())] = 1;
                fila.enfileira(a->getId());
            }

            a = a->getProx();
        }
    }
}

void GrafoL::kRegularidade(FILE* arq){//verifica se cada vertice tem grau igual ao do seu proximo

    int cont = 1;
    Vertice* p = primeiro;

    if(ehCompleto())
        fprintf(arq, "Grafo eh %d-Regular\n", p->getDegree());
        else{
            while(p->getProx() != NULL){
                if(p->getDegree() == p->getProx()->getDegree())
                    cont++;
                p = p->getProx();
            }
        }

    if(cont == numVertices)
        fprintf(arq, "Grafo eh %d-Regular\n", p->getDegree());
        else
            fprintf(arq, "Grafo nao regular !\n");

}

void GrafoL::fechoTransitivoDireto(int vert, FILE* arq){//utiliza a busca em profundidade para achar o fecho transitivo direto

    if(ehDirecionado){
        Vertice* v = buscaVertice(vert);
        int vetorDeMarcacao[numVertices];

        if(v != NULL){
            dfs(v, vetorDeMarcacao, arq);
        }else
            fprintf(arq, "Vertice inexistente !\n");
    }else
        fprintf(arq, "Nao ha fecho transitivo direto para um vertice em um grafo nao direcionado !\n");
}

void GrafoL::fechoTransitivoIndireto(int vert, FILE* arq){//Usa fila para achar o fecho transitivo Indireto

    Fila fila;

    Vertice* p = primeiro;
    Aresta* a;
    int chave = vert;
    int vetorDeMarcacao[numVertices];

    while(p != NULL){
        vetorDeMarcacao[retornaIndice(p->getId())] = 0;
        p = p->getProx();
    }

    fila.enfileira(vert);

    p = primeiro;

    while(!fila.vazia()){

        vetorDeMarcacao[retornaIndice(fila.getInicio())] = 1;
        fprintf(arq, "%d, ", fila.desenfileira());
        while(p != NULL){
            if(vetorDeMarcacao[retornaIndice(p->getId())] == 0){
                a = p->getArestas();

                while(a != NULL){
                    if(a->getId() == chave){
                        fila.enfileira(p->getId());
                        chave = p->getId();
                        vetorDeMarcacao[retornaIndice(p->getId())] = 1;
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

void GrafoL::imprimeGrafo(FILE* arq){

    Vertice *p = primeiro;
    fprintf(arq, "LISTA DE ADJACENCIAS : \n");

    while(p != NULL){
        fprintf(arq, "[%d]", p->getId());

        if(p->getArestas() != NULL)
            p->imprime(arq);
            else
                fprintf(arq, "---");
        fprintf(arq, "\n");
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



void GrafoL::kruskal(FILE* arq){

    int numComponentesConexas = 0;
    Vertice* p = primeiro;
    Aresta* a;
    GrafoL* grafoSolucao = new GrafoL();

    int* arvores = new int[numVertices];
    ListaArestaSolucao* listaDeArestas = new ListaArestaSolucao();

    for(int i = 0; i < numVertices; i++)
        arvores[i] = retornaVerticeDoVetor(i);//Preenche o vetor com as arvores de cada vertice que no inicio ser�o todas diferentes

    if(numArestas != 0){

        while(p != NULL){//Coloca todas as arestas na lista
            a = p->getArestas();

            while(a != NULL){

                if(!veSeJaTemArestaSolucao(listaDeArestas, p->getId(), a->getId()))
                    listaDeArestas->insereAresta(p->getId(), a->getId(), a->getPeso());

                a = a->getProx();
            }

            p = p->getProx();
        }

        ordenaArestas(listaDeArestas, 0, numArestas, listaDeArestas->getTamanho());//Ordena as arestas em ordem crescente

        ArestaSolucao* t = listaDeArestas->getPrimeiro();

        int cont = 0;
        while(t != NULL && cont < (numVertices-1) && !listaDeArestas->vazia()){//Enquanto a lista nao estiver vazia

            int arvore1;
            int arvore2;

            arvore1 = buscaArvore(t->getVertice1(), arvores);//Pega as arvores dos vertices
            arvore2 = buscaArvore(t->getVertice2(), arvores);

            if (arvore1 != arvore2) {//Se forem diferentes, deixa elas iguais
                uneArvores(arvore1, arvore2, arvores);
                grafoSolucao->insereVertice(t->getVertice1());
                grafoSolucao->insereVertice(t->getVertice2());
                grafoSolucao->insereAresta(t->getVertice1(), t->getVertice2(), t->getPeso());
                cont++;
            }

            t = t->getProx();
            listaDeArestas->removeAresta();
        }

        p = primeiro;

        while(p != NULL){//Se algum vertice tiver grau 0, coloca ele na solucao
            if(p->getDegree() == 0)
                grafoSolucao->insereVertice(p->getId());
            p = p->getProx();
        }


        for(p = primeiro; p != NULL;p = p->getProx()){//Conta o numero de componentes conexas segundo o vetor que corresponde as arvores de cada vertice
            int id = p->getId();
            for(int i = 0; i < numVertices;i++){
                if(id == arvores[i]){
                    numComponentesConexas = numComponentesConexas + 1;
                    break;
                }
            }
        }



        //cout << "ARVORE GERADORA MINIMAL (KRUSKAL)" << endl;
        grafoSolucao->imprimeGrafo(arq);
        //cout << "NUM DE COMP CONEXAS " << numComponentesConexas << endl;
        fprintf(arq, "NUM DE VERTICES : %d\n", grafoSolucao->getNumVertices());
        fprintf(arq, "NUM DE ARESTAS : %d\n", grafoSolucao->getNumArestas());
        fprintf(arq, "PESO DA ARVORE  : %f\n", grafoSolucao->pesoDaArvore());
        delete grafoSolucao;
        delete [] arvores;
        delete listaDeArestas;

    }else{
        while(p != NULL){
            grafoSolucao->insereVertice(p->getId());
            p = p->getProx();
        }

        numComponentesConexas = numVertices;

        fprintf(arq, "NUM DE VERTICES : %d\n", grafoSolucao->getNumVertices());
        fprintf(arq, "NUM DE ARESTAS : %d\n", grafoSolucao->getNumArestas());
        fprintf(arq, "PESO DA ARVORE  : %f\n", grafoSolucao->pesoDaArvore());
        delete grafoSolucao;
        delete [] arvores;
        delete listaDeArestas;
    }
}

void GrafoL::prim(FILE* arq, int noPartida){

    GrafoL * grafoAux = copiaGrafo();
    GrafoL * Prim = new GrafoL();
    bool visitados[grafoAux->numVertices];

    for(int i=0; i<grafoAux->numVertices; i++)
        visitados[i]= false;

    visitados[noPartida-1] = true;
    Vertice * p;
    Prim->insereVertice(noPartida);
    ArestaSolucao * vetorDeArestas = new ArestaSolucao[grafoAux->numArestas];
    Aresta *a;
    int arestas = 0;
    int aux = 0;
    int numVisitados = 1;
    do{
        for(int i=0; i<grafoAux->numVertices; i++)
        {
            if(visitados[i] == true)
            {
                p = grafoAux->buscaVertice(i+1);
                if( p != NULL){
                    a = p->getArestas();

                    while(a != NULL)
                    {
                        vetorDeArestas[arestas].setVertice1(p->getId());
                        vetorDeArestas[arestas].setVertice2(a->getId());
                        vetorDeArestas[arestas].setPeso(a->getPeso());
                        a = a->getProx();
                        arestas++;
                    }
                }
            }
        }

        grafoAux->auxOrdenaListaDeArestas(vetorDeArestas, 0, arestas-1);
        arestas = 0;
        aux = 0;

        while((visitados[vetorDeArestas[aux].getVertice2()-1]) == true)
            aux++;

        if(grafoAux->buscaVertice(vetorDeArestas[aux].getVertice2()) == NULL)
            Prim->insereVertice(vetorDeArestas[aux].getVertice2());

        if(!visitados[(vetorDeArestas[aux].getVertice2())-1])
        {
            Prim->insereAresta(vetorDeArestas[aux].getVertice1(), vetorDeArestas[aux].getVertice2(), vetorDeArestas[aux].getPeso());
            grafoAux->retiraAresta(vetorDeArestas[aux].getVertice1(), vetorDeArestas[aux].getVertice2());
            visitados[vetorDeArestas[aux].getVertice2() == true];
            numVisitados++;
        }

        grafoAux->imprimeGrafo(arq);
    } while(numVisitados <= grafoAux->numVertices);
    Prim->imprimeGrafo(arq);
}

GrafoL* GrafoL::kruskal(){

    int numComponentesConexas = 0;
    Vertice* p = primeiro;
    Aresta* a;
    GrafoL* grafoSolucao = new GrafoL();

    int* arvores = new int[numVertices];
    ListaArestaSolucao* listaDeArestas = new ListaArestaSolucao();

    for(int i = 0; i < numVertices; i++)
        arvores[i] = retornaVerticeDoVetor(i);

    if(numArestas != 0){

        while(p != NULL){
            a = p->getArestas();

            while(a != NULL){

                if(!veSeJaTemArestaSolucao(listaDeArestas, p->getId(), a->getId()))
                    listaDeArestas->insereAresta(p->getId(), a->getId(), a->getPeso());

                a = a->getProx();
            }

            p = p->getProx();
        }

        ordenaArestas(listaDeArestas, 0, numArestas, listaDeArestas->getTamanho());

        ArestaSolucao* t = listaDeArestas->getPrimeiro();

        int cont = 0;
        while(t != NULL && cont < (numVertices-1) && !listaDeArestas->vazia()){

            int arvore1;
            int arvore2;

            arvore1 = buscaArvore(t->getVertice1(), arvores);
            arvore2 = buscaArvore(t->getVertice2(), arvores);

            if (arvore1 != arvore2) {
                uneArvores(arvore1, arvore2, arvores);
                grafoSolucao->insereVertice(t->getVertice1());
                grafoSolucao->insereVertice(t->getVertice2());
                grafoSolucao->insereAresta(t->getVertice1(), t->getVertice2(), t->getPeso());
                cont++;
            }

            t = t->getProx();
            listaDeArestas->removeAresta();
        }

        p = primeiro;

        while(p != NULL){
            if(p->getDegree() == 0)
                grafoSolucao->insereVertice(p->getId());
            p = p->getProx();
        }


        for(p = primeiro; p != NULL;p = p->getProx()){
            int id = p->getId();
            for(int i = 0; i < numVertices;i++){
                if(id == arvores[i]){
                    numComponentesConexas = numComponentesConexas + 1;
                    break;
                }
            }
        }



        //cout << "ARVORE GERADORA MINIMAL (KRUSKAL)" << endl;
        //grafoSolucao->imprimeArestas(arq);
        //cout << "NUM DE COMP CONEXAS " << numComponentesConexas << endl;
        //fprintf(arq, "NUM DE VERTICES : %d\n", grafoSolucao->getNumVertices());
        //fprintf(arq, "NUM DE ARESTAS : %d\n", grafoSolucao->getNumArestas());
        delete [] arvores;
        delete listaDeArestas;
        return grafoSolucao;

    }else{
        while(p != NULL){
            grafoSolucao->insereVertice(p->getId());
            p = p->getProx();
        }

        numComponentesConexas = numVertices;

        //cout << "ARVORE GERADORA MINIMAL (KRUSKAL)" << endl;
        //grafoSolucao->imprimeArestas(arq);
        //cout << "NUM DE COMP CONEXAS " << numComponentesConexas << endl;
        delete [] arvores;
        delete listaDeArestas;
        return grafoSolucao;
    }

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

void GrafoL::ordenaArestas(ListaArestaSolucao* listaDeArestas, int inicio, int fim, int tam){

	ArestaSolucao vetorAux[tam];

    int cont = tam;

    ArestaSolucao* t = listaDeArestas->getPrimeiro();

    for(int i = 0; i < cont; i++){
        ArestaSolucao* aux = t;
        if(aux != NULL)
            vetorAux[i] = *aux;
        t = t->getProx();
    }

    auxOrdenaListaDeArestas(vetorAux, inicio, fim);

    ListaArestaSolucao* newListaDeArestas = new ListaArestaSolucao();

    for(int i = (cont-1); i >= 0; i--){
        ArestaSolucao* aux2 = &vetorAux[i];
        newListaDeArestas->insereAresta(aux2->getVertice1(), aux2->getVertice2(), aux2->getPeso());
        listaDeArestas->removeAresta();
    }

    ArestaSolucao* z = newListaDeArestas->getPrimeiro();

    ListaArestaSolucao* newListaDeArestas2 = new ListaArestaSolucao();

    while(z != NULL){
        newListaDeArestas2->insereAresta(z->getVertice1(), z->getVertice2(), z->getPeso());
        z = z->getProx();
    }

    ArestaSolucao* y = newListaDeArestas2->getPrimeiro();

    while(y != NULL){
        listaDeArestas->insereAresta(y->getVertice1(), y->getVertice2(), y->getPeso());
        y = y->getProx();
    }

    delete newListaDeArestas;
    delete newListaDeArestas2;
}

void GrafoL::auxOrdenaListaDeArestas(ArestaSolucao* vetorAux, int inicio, int fim){

    int i, j;
    float pivo;
    ArestaSolucao aux;
	i = inicio;
	j = fim-1;

	pivo = vetorAux[(inicio + fim) / 2].getPeso();

	while(i <= j){

		while(vetorAux[i].getPeso() < pivo && i < fim)
			i++;

		while(vetorAux[j].getPeso() > pivo && j > inicio)
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
        auxOrdenaListaDeArestas(vetorAux, inicio, j+1);

	if(i < fim)
        auxOrdenaListaDeArestas(vetorAux, i, fim);

}

bool GrafoL::veSeJaTemArestaSolucao(ListaArestaSolucao* listaDeArestas, int id, int id2){

    ArestaSolucao* p = listaDeArestas->getPrimeiro();

    while(p != NULL){
        if((id == p->getVertice1() || id == p->getVertice2()) && (id2 == p->getVertice1() || id2 == p->getVertice2()))
            return true;
        p = p->getProx();
    }

    return false;
}

void GrafoL::removeTudo(){

    Vertice* p = primeiro;
    Aresta* a;
    Aresta* aux;
    Vertice* aux2;

    while(p != NULL){
        a = p->getArestas();
        aux2 = p->getProx();

        while(a != NULL){
            aux = a->getProx();
            retiraAresta(p->getId(), a->getId());
            a = aux;
        }

        retiraVertice(p->getId());
        p = aux2;
    }
}


void GrafoL::steinerGuloso(FILE* arq){

    Vertice* p = primeiro;
    GrafoL* solucao;
    ListaVerticeSolucao* listaCandidatos = new ListaVerticeSolucao();
    int tam = numTerminais();
    int* terminais = new int[tam];

    int maximo;
    int minimo;


    int i = 0;
    while(p != NULL){//Preenche o vetor de terminais e a lista de candidatos
        if(p->veSeEhTerminal()){
            terminais[i] = p->getId();
            i++;
        }else
            listaCandidatos->insereVertice(p->getId(), 0);

        p = p->getProx();
    }

    solucao = subgrafoInduzido(terminais, tam);//A solucao a principio � o subgrafo induzido pelos vertices

    achaMaximoMinimo(&maximo, &minimo);
    atribuiRank(listaCandidatos, terminais, tam, maximo, minimo);//Atribui o rank aos vertices candidatos segundo a fun��o criterio
    ordenaListaDeCandidatos(listaCandidatos,0 ,listaCandidatos->getTamanho());//Ordena a lista de candidatos de forma crescente em rela��o ao rank

    Aresta* adj;
    Vertice* z;

    int numCompConexas = solucao->numComponentesConexas(solucao->getNumVertices());

    while(numCompConexas != 1 && !listaCandidatos->vazia()){//Enquanto o grafo nao for conexo, adiciona um vertice da lista

        z = buscaVertice(listaCandidatos->getPrimeiro()->getId());

        if(z != NULL){
            adj = z->getArestas();

            solucao->insereVertice(z->getId());

            while(adj != NULL){

                solucao->insereVertice(adj->getId());
                solucao->insereAresta(z->getId(), adj->getId(), adj->getPeso());
                adj = adj->getProx();
            }

            numCompConexas = solucao->numComponentesConexas(solucao->getNumVertices());

            listaCandidatos->removeVertice();
        }else
            break;
    }

    if(numCompConexas == 1){//Depois faz a AGM segundo o algoritmo de Kruskal
        solucao = solucao->kruskal();
        solucao->podaGrafo(terminais, tam);//Elimina os vertices do grafo que nao sao terminais e tem grau 1
        solucao->imprimeGrafo(arq);
        fprintf(arq, "NUM DE VERTICES : %d\n", solucao->getNumVertices());
        fprintf(arq, "NUM DE ARESTAS : %d\n", solucao->getNumArestas());
        fprintf(arq, "PESO DA ARVORE DE STEINER : %f", solucao->pesoDaArvore());
    }else
        fprintf(arq, "Nao ha solucao, nao eh possivel criar uma arvore ligando os terminais !\n");

    delete solucao;
    delete listaCandidatos;
    delete [] terminais;
}

void GrafoL::steinerGuloso(FILE* arq, ListaVerticeSolucao* listaCandidatos, int* terminais, int tam, float* pesoDaMelhorSolucao, int* numArestasDaMelhorSolucao, int* numVerticesDaMelhorSolucao){

    GrafoL* solucao = new GrafoL();

    solucao = subgrafoInduzido(terminais, tam);
    Aresta* adj;
    Vertice* z;

    int cont = 0;
    int x = solucao->numComponentesConexas(solucao->getNumVertices());

    while(x != 1 && cont < listaCandidatos->getTamanho()){

        z = buscaVertice(listaCandidatos->getPosicaoEscolhida(cont)->getId());
        cont++;
        if(z != NULL){
            adj = z->getArestas();

            solucao->insereVertice(z->getId());

            while(adj != NULL){

                solucao->insereVertice(adj->getId());
                solucao->insereAresta(z->getId(), adj->getId(), adj->getPeso());
                adj = adj->getProx();
            }

            x = solucao->numComponentesConexas(solucao->getNumVertices());

        }else
            break;
    }

    if(x == 1){
        solucao = solucao->kruskal();
        solucao->podaGrafo(terminais, tam);
        *pesoDaMelhorSolucao = solucao->pesoDaArvore();
        *numVerticesDaMelhorSolucao = solucao->numVertices;
        *numArestasDaMelhorSolucao = solucao->numArestas;
    }else{
        *pesoDaMelhorSolucao = 0;
        *numVerticesDaMelhorSolucao = 0;
        *numArestasDaMelhorSolucao = 0;
    }


    delete solucao;
}

void GrafoL::steinerGulosoRandomizado(FILE* arq, float alfa, int k){

    Vertice* p = primeiro;
    GrafoL* solucaoAtual;
    ListaVerticeSolucao* listaCandidatos = new ListaVerticeSolucao();

    int tam = numTerminais();
    int* terminais = new int[tam];

    float pesoDaMelhorSolucao;
    int numVerticesMelhorSolucao;
    int numArestasMelhorSolucao;

    int maximo;
    int minimo;

    int i = 0;
    while(p != NULL){//Preenche o vetor de terminais e a lista de candidatos
        if(p->veSeEhTerminal()){
            terminais[i] = p->getId();
            i++;
        }else
            listaCandidatos->insereVertice(p->getId(), 0);

        p = p->getProx();
    }

    achaMaximoMinimo(&maximo, &minimo);
    atribuiRank(listaCandidatos, terminais, tam, maximo, minimo);//Atribui o rank aos vertices candidatos segundo a fun��o criterio
    ordenaListaDeCandidatos(listaCandidatos, 0, listaCandidatos->getTamanho());//Ordena a lista de candidatos de forma crescente em rela��o ao rank

    steinerGuloso(arq, listaCandidatos, terminais, tam, &pesoDaMelhorSolucao, &numArestasMelhorSolucao, &numVerticesMelhorSolucao);//Coloca como melhor solucao a solucao gerada pelo guloso

    Vertice* z;
    Aresta* adj;

    int intervalo = 0;
    int posicaoSorteada;
    srand(time(NULL));
    int numCompConexas;


    if(!listaCandidatos->vazia()){
        for(int j = 0; j < k; j++){//Enquanto for menor que o numero de itera��es passadas por parametro, cria k solucoes.

            solucaoAtual = subgrafoInduzido(terminais, tam);
            numCompConexas = solucaoAtual->numComponentesConexas(tam);

            ListaVerticeSolucao* listaCandidatos2 = new ListaVerticeSolucao();

            p = primeiro;

            while(p != NULL){//Copia da lista de candidatos
                if(!p->veSeEhTerminal())
                    listaCandidatos2->insereVertice(p->getId(), 0);
                p = p->getProx();
            }

            atribuiRank(listaCandidatos, terminais, tam, maximo, minimo);
            ordenaListaDeCandidatos(listaCandidatos, 0, listaCandidatos2->getTamanho());

            while(numCompConexas != 1){

                intervalo = (int)(alfa*listaCandidatos2->getTamanho());//Sortea um numero entre a primeira posicao da lista e o alfa passado por parametro
                if(intervalo == 0)
                    posicaoSorteada = 0;
                    else
                        posicaoSorteada = rand() % intervalo;

                z = buscaVertice(listaCandidatos2->getPosicaoEscolhida(posicaoSorteada)->getId());

                if(z != NULL){
                    adj = z->getArestas();

                    solucaoAtual->insereVertice(z->getId());

                    while(adj != NULL){

                        solucaoAtual->insereVertice(adj->getId());
                        solucaoAtual->insereAresta(z->getId(), adj->getId(), adj->getPeso());
                        adj = adj->getProx();
                    }

                    numCompConexas = solucaoAtual->numComponentesConexas(solucaoAtual->getNumVertices());
                    listaCandidatos2->removeVerticeDaPosicao(posicaoSorteada);

                }else
                    break;

            }

            if(numCompConexas == 1){
                GrafoL* solucaoAux = new GrafoL();
                fprintf(arq, "SOLUCAO : %d\n", j);
                solucaoAux = solucaoAtual->kruskal();
                solucaoAux->podaGrafo(terminais, tam);

                delete solucaoAux;
            }else
                fprintf(arq, "Nao ha solucao, nao eh possivel criar uma arvore ligando os terminais !\n");


            if(solucaoAtual->pesoDaArvore() < pesoDaMelhorSolucao){//Ve se a solucao atual � melhor que a atual melhor solucao segundo a fun��o objetivo
                pesoDaMelhorSolucao = solucaoAtual->pesoDaArvore();
                numVerticesMelhorSolucao = solucaoAtual->numVertices;
                numArestasMelhorSolucao = solucaoAtual->numArestas;
            }

            delete solucaoAtual;
            delete listaCandidatos2;
        }
    }else{
        GrafoL* solucaoAtual = new GrafoL();
        solucaoAtual = kruskal();
        pesoDaMelhorSolucao = solucaoAtual->pesoDaArvore();
        numVerticesMelhorSolucao = solucaoAtual->numVertices;
        numArestasMelhorSolucao = solucaoAtual->numArestas;
        delete solucaoAtual;
    }

    fprintf(arq, "MELHOR SOLUCAO :\n");
    fprintf(arq, "NUM DE VERTICES : %d\n", numVerticesMelhorSolucao);
    fprintf(arq, "NUM DE ARESTAS : %d\n",  numArestasMelhorSolucao);
    fprintf(arq, "PESO DA ARVORE DE STEINER : %.2f",  pesoDaMelhorSolucao);

    delete solucaoAtual;
    delete [] terminais;
    delete  listaCandidatos;
}

int GrafoL::numComponentesConexas(int tam){//Conta o numero de componentes conexas utilizando busca em profundidade

    Vertice* p = primeiro;
    int vetorDeMarcacao[tam];

    while(p != NULL){
        vetorDeMarcacao[retornaIndice(p->getId())] = 0;
        p = p->getProx();
    }

    p = primeiro;
    int numComponentesConexas = 0;
    while(!todosMarcados(vetorDeMarcacao, numVertices)){

        if(vetorDeMarcacao[retornaIndice(p->getId())] == 0)
            dfs(p, vetorDeMarcacao);
        numComponentesConexas++;
        p = p->getProx();
    }

    return numComponentesConexas;
}

bool GrafoL::todosMarcados(int* vetorDeMarcacao, int tam){

    for(int i = 0; i < tam; i++)
        if(vetorDeMarcacao[i] == 0)
            return false;
    return true;

}

void GrafoL::podaGrafo(int* terminais, int tam){

    Vertice* p = primeiro;
    Vertice* aux = NULL;

    while(p != NULL){
        if(p->getDegree() == 1 && !p->veSeEhTerminal()){
            aux = p->getProx();
            retiraVertice(p->getId());
            p = aux;
        }else
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

void GrafoL::achaMaximoMinimo(int* maximo, int* minimo){

    Vertice* p = primeiro;
    Aresta* a = p->getArestas();
    *maximo = a->getPeso();
    *minimo = a->getPeso();

    while(p != NULL){
        a = p->getArestas();

        while(a != NULL){
            if(a->getPeso() > *maximo)
                *maximo = a->getPeso();
                else{
                    if(a->getPeso() <= *minimo)
                        *minimo = a->getPeso();
                }
            a = a->getProx();
        }

        p = p->getProx();
    }

}


void GrafoL::atribuiRank(ListaVerticeSolucao* listaDeCandidatos, int* terminais, int tam, int maximo, int minimo){

    float rankk = 0;
    float pesoNormalizado;
    Vertice* p = primeiro;
    Aresta* a;

    while(p != NULL){

        if(!p->veSeEhTerminal() && p->getDegree() != 0){

            float soma = 0;
            a = p->getArestas();

            while(a != NULL){
                pesoNormalizado = normaliza(a->getPeso(), maximo, minimo);
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

    VerticeSolucao vetorAux[fim];

    int cont = fim;

    VerticeSolucao* t = listaDeCandidatos->getPrimeiro();
    VerticeSolucao* aux;

    for(int i = 0; i < cont; i++){
        aux = t;
        if(aux != NULL)
            vetorAux[i] = *aux;
        t = t->getProx();
        listaDeCandidatos->removeVertice();
    }

    auxOrdenaListaCandidatos(vetorAux, inicio, fim);


    VerticeSolucao* aux2;
    for(int i = (cont-1); i >= 0; i--){
        aux2 = &vetorAux[i];
        listaDeCandidatos->insereVertice(aux2->getId(), aux2->getRankk());
    }
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

float GrafoL::normaliza(float valor, int maximo, int minimo){//coloca o peso da aresta entre  1 e 10

    float x;

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

        p = p->getProx();
    }

    return (float)(soma/2);
}

void GrafoL::djisktra(int verticePartida, FILE* arq){

    int* vertices = new int[numVertices];
    int* distancias = new int[numVertices];
    int* predecessores = new int[numVertices];
    int* abertos = new int[numVertices];

    Vertice* p = primeiro;

    while(p != NULL){

        int j = retornaIndice(p->getId());

        vertices[j] = p->getId();

        if(p->getId() == verticePartida){
            distancias[j] = 0;
            predecessores[j] = p->getId();
        }else{
            distancias[j] = INT_MAX;
            predecessores[j] = -1;
        }

        abertos[j] = -1;

        p = p->getProx();
    }

    p = primeiro;
    Aresta* adj;
    int numVerticesAbertos = numVertices;
    int IndiceVerticeComMenorEstimativa;

    while(numVerticesAbertos > 0){

        IndiceVerticeComMenorEstimativa = retornaIndiceDaMenorEstimativa(distancias, abertos, numVertices);

        if(abertos[IndiceVerticeComMenorEstimativa] == -1){

            abertos[IndiceVerticeComMenorEstimativa] = 1;

            adj = buscaVertice(vertices[IndiceVerticeComMenorEstimativa])->getArestas();

            while(adj != NULL){
                if(distancias[IndiceVerticeComMenorEstimativa] + adj->getPeso() < distancias[retornaIndice(adj->getId())]){
                    distancias[retornaIndice(adj->getId())] = distancias[IndiceVerticeComMenorEstimativa] + adj->getPeso();
                    predecessores[retornaIndice(adj->getId())] =  vertices[IndiceVerticeComMenorEstimativa];
                }

                adj = adj->getProx();
            }

        }

        numVerticesAbertos--;
    }


    fprintf(arq, "DISTANCIAS MINIMAS DO VERTICE %d PARA O RESTANTE DOS VERTICES DO GRAFO :\n", verticePartida);

    for(int i = 0;i < numVertices; i++)
        fprintf(arq, "PARA O VERTICE %d = %d\n", vertices[i], distancias[i]);

    delete [] vertices;
    delete [] distancias;
    delete [] predecessores;
    delete [] abertos;
}

int GrafoL::retornaIndiceDaMenorEstimativa(int* distancias, int* abertos, int tam){

    int menor;
    int indice = 0;

    for(int i = 0; i < tam; i++){
        if(abertos[i] == -1)
            menor = distancias[i];
    }

    for(int i = 0; i < tam; i++){
        if(abertos[i] == -1){
            if(distancias[i] < menor){
                menor = distancias[i];
                indice = i;
            }
        }
    }

    return indice;
}



int GrafoL::numTerminais(){

    Vertice* p = primeiro;

    int cont = 0;
    while(p != NULL){
        if(p->veSeEhTerminal())
            cont++;
        p = p->getProx();
    }

    return cont;
}


