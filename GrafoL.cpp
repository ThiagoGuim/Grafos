#include "GrafoL.h"
#include "Fila.h"
#include "limits.h"
#include <iostream>

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

        if(vert1 == vert2)
            cout << "Nao eh possivel criar self-loops ! vertices (" << vert1 << "," << vert2 << ")" << endl;
            else{
                if(buscaAresta(vert1, vert2) == NULL){
                    if(p != NULL && t != NULL){
                        p->insereAresta(vert2, a, peso);
                        t->insereAresta(vert1, b, peso);
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

    if(p == NULL){
        cout << "Vertice inexistente ! " << endl;
    }

    while(p != NULL && p->getId() != vert){
        if(buscaAresta(p->getId(), vert) != NULL)
            p->retiraAresta(vert);
        p = p->getProx();
    }


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

void GrafoL::steinerGuloso(int *terminais, int tam){

    /*O algoritmo apresenta um grafo como solucao, que é um subgrafo S da instancia e uma arvore geradora
     de S.A caracteristica gulosa é garantida,pois o algoritmo analisa somente algumas situçoes a partir do vertice
     em que ele esta, ou seja,localmente.Sempre vai construindo a solucao colocando as arestas na mesma,nunca retirando.

     Inicio:
        Impossibilita todos os vertices nao terminais que tem grau 1 de aparecerem na soluçao,marcando eles com
        -1 no vetoSolucao.
        Ordenamos o vetor de terminais , recebido por parametro, de acordo com os seus graus em ordem decrescente.
        Pegamos o primeiro do vetor (com grau maior) e ligamos ele (vetorSolucao = 1),pois assim,
        teria mais chances de ele ter vizinhos terminais e ligá-los de uma vez.

        Enquanto todos os vertices terminais nao estiverem ligados
             ->Verifica se tem aresta para algum outro terminal fora da solucao
             ->Se tiver mais de um terminal como vizinho verifica qual aresta tem menor peso e coloca o vertice de destino na solucao(vetorSolucao = 1).
             ->Se nao tiver nenhum vertice terminal entre seus vizinhos vai para a extremidade da aresta de menor peso e a coloca na solucao(vetorSolucao = 1).
             ->Se nao tiver nenhum vizinho que nao esteja na solucao, o algoritmo vai para algum vertice da solucao.
    Fim;
        Obs: É claro que a solucao é um conjunto de arestas, mas colocamos como apresentaoçao da solucao um subgrafo composto por essas arestas mostrado
            através das suas listas de adjacência.
    */

    GrafoL solucao;
    solucao.setDirecionado(false);

    int maximo = buscaVertice(terminais[0])->getDegree();
    int indiceMax = 0;

    for(int i = 1;i < tam;i++){
        if(buscaVertice(terminais[i])->getDegree() > maximo){
            maximo = buscaVertice(terminais[i])->getDegree();
            indiceMax = i;
        }
    }

    int vetorSolucao[10000];


    Vertice* p = primeiro;


    while(p != NULL){
        vetorSolucao[p->getId()] = 0;
        p = p->getProx();
    }

    p = primeiro;

    while(p != NULL){ //Impossibilita todos os vertices nao terminais que tem grau 1
        if(p->getDegree() == 1 && !verificaSeEhTerminal(p, terminais, tam))
            vetorSolucao[p->getId()] = -1;
        p = p->getProx();
    }

    int cont = 0; //numero de terminais ligados


    Vertice* t = new Vertice(); //primeiro vertice que vai entrar no loop
    t = buscaVertice(terminais[indiceMax]);//Maior grau entre os terminais

    solucao.insereVertice(t->getId());  //colocamos ele na solucao
    vetorSolucao[t->getId()] = 1;
    cont++;


    while(cont < tam){

        p = primeiro;

        Vertice* aux = new Vertice();
        Aresta* a = t->getArestas();
        int pesoMax = INT_MAX;
        aux = NULL;

        while(a != NULL){//Verifica se tem aresta para algum outro terminal fora da solucao
            if(verificaSeEhTerminal(buscaVertice(a->getId()), terminais, tam) && verificaSePodeSolucao(buscaVertice(a->getId()),vetorSolucao)){
                if(a->getPeso() < pesoMax){
                    aux = buscaVertice(a->getId());
                    aux->setId(a->getId());
                    pesoMax = a->getPeso();
                }
            }
            a = a->getProx();
        }

        if(pesoMax == INT_MAX){//Se o pesoMax for igual ao INT_MAX, ele nao possui nenhum vizinho terminal.
            a = t->getArestas();
            while(a != NULL){//Verifica qual vizinho fora da solucao possui menor peso na aresta
                if(a->getPeso() < pesoMax && verificaSePodeSolucao(buscaVertice(a->getId()),vetorSolucao)){
                    aux = buscaVertice(a->getId());
                    aux->setId(a->getId());
                    pesoMax = a->getPeso();
                }

                a = a->getProx();
            }
        }

        if(aux == NULL){//Se aux, for NULL, o vertice nao tem nenhum vizinho que possa entrar na solucao
            vetorSolucao[t->getId()] = 2; //Marcamos como dois, porque assim nunca voltaremos nele, ja que nao tem mais nenhum vizinho que possa entrar na solucao
            while(p != NULL){
                if(vetorSolucao[p->getId()] == 1){//pegamos o primeiro e vertice da solucao
                    aux = p;
                    aux->setId(p->getId());
                    break;
                }
                p = p->getProx();
            }
        }

        if(aux == NULL){//Se ainda assim, aux for NULL, nao há solucao possivel, pois o grafo sera desconexo
            cout << "Nao tem solucao possivel !" << endl;
            break;
        }else{
            if(verificaSePodeSolucao(aux,vetorSolucao)){//Coloca a aresta na solucao
                vetorSolucao[aux->getId()] = 1;
                solucao.insereVertice(aux->getId());
                solucao.insereAresta(t->getId(), aux->getId());

                if(verificaSeEhTerminal(aux, terminais, tam))
                    cont++;
            }

            t = aux;
        }
    }
    cout << endl;
    cout << "SUBGRAFO SOLUCAO : " << endl;
    solucao.imprimeArestas();
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
