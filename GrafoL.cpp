#include "GrafoL.h"
#include "Fila.h"
#include <iostream>

using namespace std;

GrafoL::GrafoL(){

    numVertices = 0;
    numArestas = 0;
    numArcos = 0;
    ehDirecionado = false;
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

int GrafoL::getNumArestas(){

    return numArestas;
}

bool GrafoL::ehGrafoDirecionado(){

    return ehDirecionado;
}

void GrafoL::setDirecionado(bool x){

    ehDirecionado = x;
}

bool GrafoL::ehGrafoPonderado(){

    return ehPonderado;
}

void GrafoL::setPonderado(bool x){

    ehPonderado = x;
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
                        p->increaseOutDegree();
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
                        p->increaseOutDegree();
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

int GrafoL::verticeDegree(int info){

    Vertice* p = buscaVertice(info);
    int degree;

    if(p == NULL){
        cout << "Vertice inexistente !(" << info << ")" << endl;
        return -1;
    }else{
            degree = p->getDegree();
            return degree;
    }
}

int GrafoL::verticeInDegree(int info){

    Vertice* p = buscaVertice(info);
    int inDegree;

    if(p == NULL){
        cout << "Vertice inexistente !(" << info << ")" << endl;
        return -1;
    }else{
            inDegree = p->getInDegree();
            return inDegree;
    }
}

int GrafoL::verticeOutDegree(int info){

    Vertice* p = buscaVertice(info);
    int outDegree;

    if(p == NULL){
        cout << "Vertice inexistente !(" << info << ")" << endl;
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

bool GrafoL::ehCompleto(){

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

bool GrafoL::ehbipartido(){//Duvida no vetor

    Vertice* p = primeiro;
    int vetorDeCores[10000];

    while(p != NULL){
        vetorDeCores[p->getInfo()] = 0;
        p = p->getProx();
    }

    p = primeiro;

    while(p != NULL){
        if(vetorDeCores[p->getInfo()] == 0)
            if(auxEhBipartido(p, vetorDeCores, 0) == false)
                    return false;
        p = p->getProx();
    }

    return true;

}

bool GrafoL::auxEhBipartido(Vertice* p, int* vetorDeCores, int cor){//Duvida em relacao ao vetor


    if(cor == 0)
        vetorDeCores[p->getInfo()] = 1;

    if(cor == 1)
        vetorDeCores[p->getInfo()] = 2;
        else
            vetorDeCores[p->getInfo()] = 1;

    Aresta* a = p->getArestas();

    while(a != NULL){
        if(a != NULL && vetorDeCores[a->getInfo()] == 0){
            if(auxEhBipartido(buscaVertice(a->getInfo()), vetorDeCores, vetorDeCores[p->getInfo()]) == false)
                return false;
        }else
            if(vetorDeCores[a->getInfo()] == vetorDeCores[p->getInfo()])
                return false;

        a = a->getProx();
    }

    return true;
}

void GrafoL::deepFirstSearch(){//Duvida em relacao ao vetor

    Vertice* p = primeiro;
    int vetorDeMarcacao[10000];

    while(p != NULL){
        vetorDeMarcacao[p->getInfo()] = 0;
        p = p->getProx();
    }

    p = primeiro;

    while(p != NULL){
        if(vetorDeMarcacao[p->getInfo()] == 0)
            dfs(p, vetorDeMarcacao);
        p = p->getProx();
    }
}

void GrafoL::dfs(Vertice* p, int* vetorDeMarcacao){

    Aresta* a = p->getArestas();

    vetorDeMarcacao[p->getInfo()] = 1;

    cout << p->getInfo() << ",";
    while(a != NULL){
        if(a != NULL && vetorDeMarcacao[a->getInfo()] == 0)
            dfs(buscaVertice(a->getInfo()), vetorDeMarcacao);
        a = a->getProx();
    }
}

void GrafoL::breadthFirstSearch(){

    Fila fila;

    Vertice* p = primeiro;

    int vetorDeMarcacao[10000];

    while(p != NULL){
        vetorDeMarcacao[p->getInfo()] = 0;
        p = p->getProx();
    }

    vetorDeMarcacao[primeiro->getInfo()] = 1;

    fila.enfileira(primeiro->getInfo());

    while(!fila.vazia()){
        Vertice* v = buscaVertice(fila.desenfileira());
        Aresta* a = v->getArestas();
        cout << v->getInfo() << ",";
        while(a != NULL){
            if(vetorDeMarcacao[a->getInfo()] == 0){
                vetorDeMarcacao[a->getInfo()] = 1;
                fila.enfileira(a->getInfo());
            }

            a = a->getProx();
        }
    }
}

int GrafoL::kRegularidade(){

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

void GrafoL::fechoTransitivoDireto(int vert){

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
    Vertice* v = buscaVertice(vert);
    Aresta* a;
    int chave = vert;
    int vetorDeMarcacao[10000];

    while(p != NULL){
        vetorDeMarcacao[p->getInfo()] = 0;
        p = p->getProx();
    }

    fila.enfileira(vert);

    p = primeiro;

    while(!fila.vazia()){

        vetorDeMarcacao[fila.getInicio()] = 1;
        cout << fila.desenfileira() << ", ";
        while(p != NULL){
            if(vetorDeMarcacao[p->getInfo()] == 0){
                a = p->getArestas();

                while(a != NULL){
                    if(a->getInfo() == chave){
                        fila.enfileira(p->getInfo());
                        chave = p->getInfo();
                        vetorDeMarcacao[p->getInfo()] = 1;
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

void GrafoL::auxFechoTransitivoIndireto(int chave){

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
