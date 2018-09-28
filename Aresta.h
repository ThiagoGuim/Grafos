#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta{

private:
    int id;
    int peso;
    Aresta* prox;

public:
    Aresta();
    ~Aresta();
    int getId();
    void setId(int id);
    Aresta* getProx();
    void setProx(Aresta *p);
    int getPeso();
    void setPeso(int peso);
};



#endif // ARESTA_H_INCLUDED
