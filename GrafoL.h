#ifndef GRAFOL_H_INCLUDED
#define GRAFOL_H_INCLUDED
#include "Vertice.h"

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
    void setDirecionado(bool x);//seta para direcionado ou nao
    Vertice* buscaVertice(int id);//Recebe um id de algum vertice e retorna um ponteiro para esse vertice
    Aresta* buscaAresta(int vert1, int vert2);//Recebe as extremidades de alguma aresta ou calda/cabeça de um arco e retorna um ponteiro para essa aresta ou arco
    int getVerticeDegree(int id);
    int getVerticeInDegree(int id);
    int getVerticeOutDegree(int id);
    void sequenciaDeGraus();//imprime a sequencia de graus do grafo
    int grauDoGrafo();//retorna grau do grafo
    int ordemDoGrafo();//retorna ordem do grafo
    void vizinhancaAberta(int id);//imprime a vizinhança aberta do vertice id
    void vizinhancaFechada(int id);//imprime a vizinhança fechada do vertice id
    int kRegularidade();//retorna qual a k-regularidade de um grafo se houver
    bool ehCompleto();//retorna se o grafo eh completo ou nao
    bool ehbipartido();//retorna se o grafo eh bipartido ou nao
    bool auxEhBipartido(Vertice* p, int* vetorDeCores, int cor);
    void deepFirstSearch();//busca em profundidade
    void dfs(Vertice* p, int* vetorDeMarcacao);//auxiliar da busca em profundidade
    void breadthFirstSearch();//busca em largura
    void fechoTransitivoDireto(int id);//imprime o fecho transitivo direto do vertice id
    void fechoTransitivoIndireto(int id);//imprime o fecho transitivo indireto do vertice id
    void insereVertice(int id);
    void insereAresta(int vert1, int vert2);//insere aresta entre vert1 e vert2
    void insereAresta(int vert1, int vert2, int peso);
    void insereArco(int vert1, int vert2);//insere arco de vert1 para vert2
    void insereArco(int vert1, int vert2, int peso);
    void retiraVertice(int vert);//remove o vertice vert
    void retiraAresta(int vert1, int vert2);//remove aresta entre o vert1 e vert2
    void retiraArco(int vert1, int vert2);//remove arco de vert1 para vert2
    void steinerGuloso(int* terminais, int tam);//algoritmo guloso para o problema da arvore de steiner,recebe os terminais atraves de um vetor pela main
    bool verificaSePodeSolucao(Vertice* p,int* vetorSolucao);//verifica se o vertice p pode entrar na solucao
    bool verificaSeEhTerminal(Vertice *p, int *terminais,int tam);//verifica se eh um terminal do problema da arvore de steiner
    void imprimeVertices();
    void imprimeArestas();
    void quickSort(int vetorGraus[], int inicio, int fim);//para poder ordenar alguns vetores
};

#endif // GRAFOL_H_INCLUDED
