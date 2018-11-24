#ifndef VERTICESOLUCAO_H_INCLUDED
#define VERTICESOLUCAO_H_INCLUDED

class VerticeSolucao{

private:


public:
    int id;
    float rankk;
    VerticeSolucao* prox;

    VerticeSolucao();
    ~VerticeSolucao();

    int getId();
    float getRankk();
    void setRankk(float valor);
    void setId(int id);
    VerticeSolucao* getProx();
    void setProx(VerticeSolucao *p);

};

#endif // VERTICESOLUCAO_H_INCLUDED
