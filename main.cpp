#include <iostream>
#include <fstream>
#include <cstring>
#include "GrafoL.h"

using namespace std;

    ///Grupo 3

    ///Ant�nio Henrique Passamai Penizollo 201776041
    ///Braulio Silva Mendes Lucas 201776011
    ///Jo�o Victor Dutra Balboa 201776035
    ///Marcus Vin�cius Vasconcelos de Almeida Cunha 201776013
    ///Thiago Teixeira Guimar�es 201765061A

GrafoL* lerArquivo(char *nomeArq,GrafoL* grafo){

    FILE* arq;
    char ch;
    int linhas = 1;
    int numVertices, vert1, vert2, peso;
    int flag = 0;

    arq = fopen(nomeArq, "r");

    if(arq == NULL){
        printf("Arquivo nao encontrado !");
        return NULL;
    }else{
        while((ch = fgetc(arq)) != EOF)      //conta o numero de linhas
            if(ch == '\n')
                linhas++;

        rewind(arq);

        while((ch = fgetc(arq)) != '\n'){} //pula a primeira linha


        while((ch = fgetc(arq)) != '\n')    // V� se o arquivo � de um grafo ponderado ou n�o
            if(isspace(ch))
                flag++;
    }


    rewind(arq);

    bool ehDirecionado;
    cout << "Eh direcionado ?" << endl;
    cin >> ehDirecionado;

    grafo->setDirecionado(ehDirecionado);

    for(int i = 1;i <= linhas;i++){
        if(i == 1){
            fscanf(arq, "%d\n", &numVertices);
            printf("%d\n", numVertices);        // pegando a primeira linha e vendo a quantidade de vertices.

        }else{
            if(flag == 1){
                if(fscanf(arq, "%d %d\n", &vert1, &vert2) != EOF){
                    printf("%d %d\n", vert1, vert2);
                    grafo->insereVertice(vert1);       // insere o vertice correspondente no arquivo.
                    grafo->insereVertice(vert2);       // insere o vertice correspondente no arquivo.
                    if(!ehDirecionado)
                        grafo->insereAresta(vert1, vert2); // insere a aresta correspondente no arquivo ou o arco
                        else
                            grafo->insereArco(vert1, vert2);
                }
            }else{
                if(fscanf(arq, "%d %d %d\n", &vert1, &vert2, &peso) != EOF){
                    printf("%d %d %d\n", vert1, vert2, peso);
                    grafo->insereVertice(vert1);             // insere o vertice correspondente no arquivo.
                    grafo->insereVertice(vert2);             // insere o vertice correspondente no arquivo.
                    if(!ehDirecionado)
                        grafo->insereAresta(vert1, vert2, peso); // insere a aresta correspondente no arquivo ou o arco
                        else
                            grafo->insereArco(vert1, vert2, peso);
                }
            }
        }
    }

    fclose(arq);
    return grafo;
}


int main( int argc, char *argv[])
{
    string nomeArquivo;
    GrafoL* grafo = new GrafoL();

    /*cout << "Informe o nome do arquivo que deseja abrir : ";
    cin >> nomeArquivo;

    char *nomeArq = new char[nomeArquivo.length() + 1];              //Formata o nome de arquivo para os metodos
    memcpy(nomeArq, nomeArquivo.c_str(), nomeArquivo.length() + 1);  //das fun�oes abrirem direito.*/

    grafo = lerArquivo(argv[1], grafo);

    if(grafo != NULL){

        int terminais[3] = {2,4,3};

        grafo->imprimeArestas();
        grafo->steinerGuloso(terminais,3);
    }

    return 0;
}
