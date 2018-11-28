#ifndef ARESTASOLUCAO_H_INCLUDED
#define ARESTASOLUCAO_H_INCLUDED


///Classe criada para representar as arestas que entrarao na solucao do algoritmo de Kruskal
class ArestaSolucao{

private:

    int vertice1, vertice2; //extremidades da aresta
    int peso;
    bool visitado;
    ArestaSolucao* prox;

public:

    ArestaSolucao();
    ~ArestaSolucao();

    int getVertice1();
    int getVertice2();
    int getPeso();
    int getVisitado();
    void setVertice1(int id);
    void setVertice2(int id);
    void setPeso(int id);
    void setVisitado(bool t);
    ArestaSolucao* getProx();
    void setProx(ArestaSolucao *p);
};

#endif // ARESTASOLUCAO_H_INCLUDED
