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
    int kRegularidade();//retorna qual a k-regularidade de um grafo se houver
    bool ehCompleto();//retorna se o grafo eh completo ou nao
    bool ehbipartido();//retorna se o grafo eh bipartido ou nao
    bool auxEhBipartido(Vertice* p, int* vetorDeCores, int cor);
    void deepFirstSearch(FILE* arq);//busca em profundidade
    void dfs(Vertice* p, int* vetorDeMarcacao, FILE* arq);//auxiliar da busca em profundidade
    void dfs(Vertice* p, int* vetorDeMarcacao);
    bool todosMarcados(int* vetorDeMarcacao, int tam);
    void breadthFirstSearch();//busca em largura
    void fechoTransitivoDireto(int id, FILE* arq);//imprime o fecho transitivo direto do vertice id
    void fechoTransitivoIndireto(int id, FILE* arq);//imprime o fecho transitivo indireto do vertice id
    void insereVertice(int id);
    void insereVertice2(int id);
    void insereAresta(int vert1, int vert2);//insere aresta entre vert1 e vert2
    void insereAresta(int vert1, int vert2, int peso);
    void insereAresta2(int vert1, int vert2, int peso);
    void insereArco(int vert1, int vert2);//insere arco de vert1 para vert2
    void insereArco(int vert1, int vert2, int peso);
    void retiraVertice(int vert);//remove o vertice vert
    void retiraVertice2(int vert);
    void retiraAresta(int vert1, int vert2);//remove aresta entre o vert1 e vert2
    void retiraArco(int vert1, int vert2);//remove arco de vert1 para vert2

    int retornaIndice(int* vet, int tam, int id);
    int retornaIndice(int* vet, int tam, int id, GrafoL* newGrafo);
    int retornaIndice(int id);
    int retornaVerticeDoVetor(int i);
    int retornaVerticeDoVetor(int i, GrafoL* newGrafo);
    void setTerminal(int id);

    GrafoL* subgrafoInduzido(int * vet, int tam);
    int numVizinhosTerminais(Vertice* p, int *terminais, int tam);
    void atribuiRank(ListaVerticeSolucao* listaDeCandidatos, int* terminais, int tam, int maximo, int minimo);
    void auxOrdenaListaCandidatos(VerticeSolucao* vetorAux, int inicio, int fim);
    void ordenaListaDeCandidatos(ListaVerticeSolucao* listaDeCandidatos, int inicio, int fim);
    float normaliza(float valor, int maximo, int minimo);
    void achaMaximoMinimo(int* maximo, int* minimo);
    GrafoL* montaArvore(GrafoL* newGrafo, int* numComponentesConexas);
    GrafoL* podaGrafo(int* terminais, int tam);
    void steinerGuloso(FILE* arq);//algoritmo guloso para o problema da arvore de steiner,recebe os terminais atraves de um vetor pela main
    void steinerGuloso(FILE* arq, ListaVerticeSolucao* listaCandidatos, int* terminais, int tam,  float* pesoDaMelhorSolucao, int* numArestasDaMelhorSolucao, int* numVerticesDaMelhorSolucao);
    void steinerGulosoRandomizado(FILE* arq, float alfa, int numIteracoes);
    bool verificaSePodeSolucao(Vertice* p,int* vetorSolucao);//verifica se o vertice p pode entrar na solucao
    bool verificaSeEhTerminal(Vertice *p, int *terminais,int tam);//verifica se eh um terminal do problema da arvore de steiner
    GrafoL* copiaGrafo();
    float pesoDaArvore();
    int numComponentesConexas(int tam);

    int* djisktra(int verticePartida, FILE* arq);
    int retornaIndiceDaMenorEstimativa(int* distancias, int* abertos, int tam);
    GrafoL* kruskal(FILE* arq);
    void prim(FILE* arq, int noPartida);
    GrafoL* kruskal();
    int buscaArvore(int id, int* arvores);
    int buscaArvore(int id, int* arvores, GrafoL* newGrafo);
    void uneArvores(int id, int id2, int* arvores);
    void uneArvores(int id, int id2, int* arvores, GrafoL* newGrafo);
    void ordenaArestas(ListaArestaSolucao* listaDeArestas, int inicio, int fim,int tam);
    void auxOrdenaListaDeArestas(ArestaSolucao* vetorAux, int inicio, int fim);
    bool veSeJaTemArestaSolucao(ListaArestaSolucao* listaDeArestas, int id, int id2);
    void imprimeVertices();
    void imprimeArestas(FILE* arq);
    void quickSort(int vetorGraus[], int inicio, int fim);//para poder ordenar alguns vetores
    void teste(FILE* arq);
    void removeTudo();
    int numTerminais();
};

#endif // GRAFOL_H_INCLUDED
