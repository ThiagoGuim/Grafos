#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta{

private:
    int info;
    int peso;
    Aresta* prox;

public:
    Aresta();
    ~Aresta();
    int getInfo();
    void setInfo(int info);
    Aresta* getProx();
    void setProx(Aresta *p);
    int getPeso();
    void setPeso(int peso);
};



#endif // ARESTA_H_INCLUDED
