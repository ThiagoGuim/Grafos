#ifndef GRAFOL_H_INCLUDED
#define GRAFOL_H_INCLUDED
#include "Vertice.h"
#include "VerticeSolucao.h"
#include "ArestaSolucao.h"
#include "ListaVerticeSolucao.h"
#include "ListaArestaSolucao.h"

class GrafoL{

private:
    int numVertices;
    int numArestas;
    int numArcos;
    bool ehDirecionado;
    Vertice* primeiro;

public:

    GrafoL();
    ~GrafoL();

    ///Funcionalidades do Grafo
    int getNumVertices();
    int getNumArestas();
    int getNumArcos();
    bool ehGrafoDirecionado();//Se eh direcionado ou nao
    Vertice* getPrimeiro();
    void setDirecionado(bool x);//seta para direcionado ou nao
    Vertice* buscaVertice(int id);//Recebe um id de algum vertice e retorna um ponteiro para esse vertice
    Aresta* buscaAresta(int vert1, int vert2);//Recebe as extremidades de alguma aresta ou calda/cabeça de um arco e retorna um ponteiro para essa aresta ou arco
    int getVerticeDegree(int id);
    int getVerticeInDegree(int id);
    int getVerticeOutDegree(int id);
    void sequenciaDeGraus(FILE* arq);//imprime a sequencia de graus do grafo
    int grauDoGrafo();//retorna grau do grafo
    int ordemDoGrafo();//retorna ordem do grafo
    void vizinhancaAberta(int id, FILE* arq);//imprime a vizinhança aberta do vertice id
    void vizinhancaFechada(int id, FILE* arq);//imprime a vizinhança fechada do vertice id
    void kRegularidade(FILE* arq);//retorna qual a k-regularidade de um grafo se houver
    bool ehCompleto();//retorna se o grafo eh completo ou nao
    bool ehbipartido();//retorna se o grafo eh bipartido ou nao
    bool auxEhBipartido(Vertice* p, int* vetorDeCores, int cor);
    void deepFirstSearch(FILE* arq);//busca em profundidade
    void dfs(Vertice* p, int* vetorDeMarcacao, FILE* arq);//auxiliar da busca em profundidade
    void dfs(Vertice* p, int* vetorDeMarcacao);
    void breadthFirstSearch();//busca em largura
    void fechoTransitivoDireto(int id, FILE* arq);//imprime o fecho transitivo direto do vertice id
    void fechoTransitivoIndireto(int id, FILE* arq);//imprime o fecho transitivo indireto do vertice id
    void setTerminal(int id);//seta o vertice como terminal
    void insereVertice(int id);
    void insereAresta(int vert1, int vert2);//insere aresta entre vert1 e vert2
    void insereAresta(int vert1, int vert2, int peso);
    void insereArco(int vert1, int vert2);//insere arco de vert1 para vert2
    void insereArco(int vert1, int vert2, int peso);
    void retiraVertice(int vert);//remove o vertice vert
    void retiraAresta(int vert1, int vert2);//remove aresta entre o vert1 e vert2
    void retiraArco(int vert1, int vert2);//remove arco de vert1 para vert2
    void kruskal(FILE* arq);
    void djisktra(int verticePartida, FILE* arq);
    void prim(FILE* arq, int noPartida);


    ///Mapea o Grafo
    int retornaIndice(int* vet, int tam, int id);
    int retornaIndice(int* vet, int tam, int id, GrafoL* newGrafo);
    int retornaIndice(int id);
    int retornaVerticeDoVetor(int i);
    int retornaVerticeDoVetor(int i, GrafoL* newGrafo);


    ///Relacionadas ao Algoritmo Guloso

    void steinerGuloso(FILE* arq);//Algoritmo guloso para o problema da arvore de steiner
    void atribuiRank(ListaVerticeSolucao* listaDeCandidatos, int* terminais, int tam, int maximo, int minimo);
    void auxOrdenaListaCandidatos(VerticeSolucao* vetorAux, int inicio, int fim);
    void ordenaListaDeCandidatos(ListaVerticeSolucao* listaDeCandidatos, int inicio, int fim);
    void achaMaximoMinimo(int* maximo, int* minimo);//Auxiliar que acha as arestas com menor e maior peso
    float normaliza(float valor, int maximo, int minimo);//Auxiliar que coloca os pesos das arestas sempre entre 1 e 10
    void podaGrafo(int* terminais, int tam);//Retira os vertices que possuem grau 1 e nao sao terminais da arvore gerada a partir do algoritmo guloso

    void steinerGuloso(FILE* arq, ListaVerticeSolucao* listaCandidatos, int* terminais, int tam,  float* pesoDaMelhorSolucao, int* numArestasDaMelhorSolucao, int* numVerticesDaMelhorSolucao);//Retorna uma solucao do Algoritmo Guloso
    void steinerGulosoRandomizado(FILE* arq, float alfa, int numIteracoes);//Algoritmo guloso randomizado para o problema da arvore de steiner

    ///Auxiliares

    GrafoL* subgrafoInduzido(int * vet, int tam);//Retorna um ponteiro para um subgrafo Induzido pelo vetor de vertices passado como parâmetro
    int numVizinhosTerminais(Vertice* p, int *terminais, int tam);
    bool todosMarcados(int* vetorDeMarcacao, int tam);//Auxiliar paara ver se todos os vertices ja foram visitados
    bool verificaSePodeSolucao(Vertice* p,int* vetorSolucao);//verifica se o vertice p pode entrar na solucao
    GrafoL* copiaGrafo();//Retorna um ponteiro para um grafo identico a instância
    float pesoDaArvore();//Retorna o peso das arestas de uma arvore
    int numComponentesConexas(int tam);//Retorna o numero de Componentes conexas do Grafo

    int retornaIndiceDaMenorEstimativa(int* distancias, int* abertos, int tam);//Auxiliar dijkstra
    GrafoL* kruskal();//
    int buscaArvore(int id, int* arvores);//Retorna a arvore que o vertice pertence no algoritmo de Kruskal
    int buscaArvore(int id, int* arvores, GrafoL* newGrafo);
    void uneArvores(int id, int id2, int* arvores);//Une as arvores de dois vertices no algoritmo de Kruskal
    void uneArvores(int id, int id2, int* arvores, GrafoL* newGrafo);
    void ordenaArestas(ListaArestaSolucao* listaDeArestas, int inicio, int fim,int tam);
    void auxOrdenaListaDeArestas(ArestaSolucao* vetorAux, int inicio, int fim);
    bool veSeJaTemArestaSolucao(ListaArestaSolucao* listaDeArestas, int id, int id2);
    void imprimeGrafo(FILE* arq);//Imprime lista de adjacências do grafo
    void quickSort(int vetorGraus[], int inicio, int fim);//para poder ordenar alguns vetores
    void removeTudo();//Deleta todos os vertices e arestas do grafo
    int numTerminais();
};

#endif // GRAFOL_H_INCLUDED
