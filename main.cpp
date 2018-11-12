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

    grafo->setDirecionado(ehDirecionado);//ehDirecionado);

    for(int i = 1;i <= linhas;i++){
        if(i == 1){
            fscanf(arq, "%d\n", &numVertices);
            //printf("%d\n", numVertices);        // pegando a primeira linha e vendo a quantidade de vertices.

        }else{
            if(flag == 1){
                if(fscanf(arq, "%d %d\n", &vert1, &vert2) != EOF){
                    //printf("%d %d\n", vert1, vert2);
                    grafo->insereVertice(vert1);       // insere o vertice correspondente no arquivo.
                    grafo->insereVertice(vert2);       // insere o vertice correspondente no arquivo.
                    if(!ehDirecionado)
                        grafo->insereAresta(vert1, vert2); // insere a aresta correspondente no arquivo ou o arco
                        else
                            grafo->insereArco(vert1, vert2);
                }
            }else{
                if(fscanf(arq, "%d %d %d\n", &vert1, &vert2, &peso) != EOF){
                    //printf("%d %d %d\n", vert1, vert2, peso);
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


int main( /*int argc, char *argv[]*/)
{
    string nomeArquivo;
    GrafoL* grafo = new GrafoL();

    /*cout << "Informe o nome do arquivo que deseja abrir : ";
    cin >> nomeArquivo;

    char *nomeArq = new char[nomeArquivo.length() + 1];              //Formata o nome de arquivo para os metodos
    memcpy(nomeArq, nomeArquivo.c_str(), nomeArquivo.length() + 1);  //das fun�oes abrirem direito.*/

    grafo = lerArquivo("teste.txt", grafo);

    if(grafo != NULL){

        //int terminais[14] = {797, 465, 968, 563, 209, 64, 241, 898, 771,835, 861, 102, 99, 321};
        //int terminais[14] = {30, 180, 81, 116, 132, 196, 88, 17, 191, 161, 19, 201, 144, 178};
        //int terminais[14] = {4332, 7142, 2383, 3417, 7496, 7022, 4210, 1696, 622,6767, 2822, 3184, 980, 6131};
        //int terminais[2] = {7, 6};
        //grafo->imprimeArestas();
        //grafo->steinerGuloso(terminais, 14);
        grafo->kruskal();
        //grafo->steinerGulosoRandomizado(terminais, 5, 0.3, 10);


    }

    return 0;
}
