#include <iostream>
#include <fstream>
#include <cstring>
#include "GrafoL.h"

using namespace std;

    ///Grupo 3

    ///Antônio Henrique Passamai Penizollo 201776041
    ///Braulio Silva Mendes Lucas 201776011
    ///João Victor Dutra Balboa 201776035
    ///Marcus Vinícius Vasconcelos de Almeida Cunha 201776013
    ///Thiago Teixeira Guimarães 201765061A

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


        while((ch = fgetc(arq)) != '\n')    // Vê se o arquivo é de um grafo ponderado ou não
            if(isspace(ch))
                flag++;
    }


    rewind(arq);

    bool ehDirecionado;
    cout << "Eh direcionado ?" << endl;
    //cin >> ehDirecionado;

    grafo->setDirecionado(0);//ehDirecionado);

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
    memcpy(nomeArq, nomeArquivo.c_str(), nomeArquivo.length() + 1);  //das funçoes abrirem direito.*/

    grafo = lerArquivo("grafo_209.txt", grafo);

    if(grafo != NULL){

        int terminais[21] = {178, 203, 180, 81, 116, 165, 28, 4 , 40, 93, 65, 133, 27, 195, 192, 194, 99, 196, 110, 131, 104};

        //grafo->imprimeArestas();
        grafo->steinerGuloso(terminais, 21);

    }

    return 0;
}
