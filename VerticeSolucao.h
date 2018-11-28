#ifndef VERTICESOLUCAO_H_INCLUDED
#define VERTICESOLUCAO_H_INCLUDED

///Classe criada para representar os vertices que entrarao na solucao do algoritmo Guloso ja que possuem como
///como caracter�sticas importantes somente o id e o rank segundo a fun��o crit�rio
class VerticeSolucao{

private:

    int id;
    float rankk;
    VerticeSolucao* prox;

public:

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
