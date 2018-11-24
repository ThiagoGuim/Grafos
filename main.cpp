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
    char str;
    int numVertices, vert1, vert2, peso,vertTerm;
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

        while((ch = fgetc(arq)) != '\n'){}//pula a primeira linha

        while((ch = fgetc(arq)) != '\n')    // Vê se o arquivo é de um grafo ponderado ou não
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
                if(fscanf(arq, "%c %d %d %d\n",&str, &vert1, &vert2, &peso) != EOF){
                    //printf("%d %d %d\n", vert1, vert2, peso);
                    if(str == 'T'){
                        grafo->insereVertice(vert1);
                        grafo->setTerminal(vert1);
                    }else{
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
    }

    fclose(arq);
    return grafo;
}

void exibeMenu(){
    cout << " 1-Remover um vertice" << endl;
    cout << " 2-Remover uma aresta ou arco" << endl;
    cout << " 3- Mostrar o Grau de um vertice" << endl;
    cout << " 4- Mostrar a k-regularidade do Grafo" << endl;
    cout << " 5- Mostrar a ordem do Grafo" << endl;
    cout << " 6- Mostrar a vizinhança fechada de um vertice" << endl;
    cout << " 7- Mostrar a vizinhança aberta de um vertice" << endl;
    cout << " 8- Verificar se o Grafo eh completo " << endl;
    cout << " 9- Verificar se o Grafo eh bipartido " << endl;
    cout << " 10- Apresentar sequencia de graus do Grafo " << endl;
    cout << " 11- Mostrar fecho transitivo direto " << endl;
    cout << " 12- Mostrar fecho transitivo indireto " << endl;
    cout << " 13- Apresentar uma ordenação topológica de um Grafo " << endl;
    cout << " 14- Apresentar uma Arvore geradora minima (Kruskal) " << endl;
    cout << " 15- Apresentar uma Arvore geradora minima (Prim) " << endl;
    cout << " 16- Apresentar o custo do caminho mínimo entre  vértices (Dijkstra)" << endl;
    cout << " 17- Apresentar o custo do caminho mínimo entre dois vértices (Floyd)" << endl;
    cout << " 18- Apresentar uma Arvore geradora minima Steiner(Guloso)" << endl;
    cout << " 19- Apresentar uma Arvore geradora minima Steiner (Guloso Randomizado)" << endl;
    cout << " 20- Apresentar uma Arvore geradora minima Steiner (Guloso Reativo)" << endl;
    cout << " 21- Imprimir instancia " << endl;

    cout << " 0- Sair" << endl;
}


void chamaOpcaoDoMenu(int opcao, FILE* arq_saida, GrafoL* grafo){

    switch(opcao){
        case 0: {
            cout << "Algoritmo Encerrado. Os dados foram armazenados em arquivo." << endl;
            break;

        }
        case 1: {
            int vert;
            cout << "Qual vertice deseja retirar ? ";
            cin >> vert;
            grafo->retiraVertice(vert);
            fprintf(arq_saida, "1-Remover um vertice \nVertice retirado (%d)\n\n", vert);
            break;
        }
        case 2: {
            int vert, vert2;
            if(grafo->ehGrafoDirecionado()){
                cout << "Qual arco deseja retirar ? ";
                cin >> vert;
                cin >> vert2;
                grafo->retiraArco(vert, vert2);
                fprintf(arq_saida, "2-Remover um arco \nArco retirado (%d - %d)\n\n", vert, vert2);
            }else{
                cout << "Qual aresta deseja retirar ? ";
                cin >> vert;
                cin >> vert2;
                grafo->retiraAresta(vert, vert2);
                fprintf(arq_saida, "2-Remover uma aresta\nAresta retirada (%d , %d)\n\n", vert, vert2);
            }

            break;
        }
        case 3: {
            int vert;
            cout << "Qual Vertice deseja saber o grau ? ";
            cin >> vert;
            if(!grafo->ehGrafoDirecionado())
                fprintf(arq_saida, "3- Mostrar o Grau de um vertice \nGrau do vertice (%d) : %d\n\n", vert, grafo->getVerticeDegree(vert));
                else
                    fprintf(arq_saida, "3- Mostrar o Grau de um vertice \nGrau de entrada/saida do vertice (%d) : %d/%d\n\n", vert, grafo->getVerticeInDegree(vert), grafo->getVerticeOutDegree(vert));
            break;
        }
        case 4: {
            int i = grafo->kRegularidade();

            if(i != -1)
                fprintf(arq_saida, "4- Mostrar a k-regularidade do Grafo\n K-regularidade = Nao eh regular\n\n");
                else
                    fprintf(arq_saida, "4- Mostrar a k-regularidade do Grafo\n K-regularidade = %d\n\n", i);
            break;
        }
        case 5: {
            fprintf(arq_saida, "5- Mostrar a ordem do Grafo\n Ordem = %d\n\n", grafo->ordemDoGrafo());
            break;
        }
        case 6: {
            int vert;
            cout << "Qual vertice deseja saber a vizinhada fechada? ";
            cin >> vert;
            fprintf(arq_saida, "6- Mostrar a vizinhança fechada de um vertice\n");
            grafo->vizinhancaFechada(vert, arq_saida);
            break;
        }
        case 7: {
            int vert;
            cout << "Qual vertice deseja saber a vizinhada aberta? ";
            cin >> vert;
            fprintf(arq_saida, "7- Mostrar a vizinhança aberta de um vertice\n");
            grafo->vizinhancaAberta(vert, arq_saida);
            break;
        }
        case 8: {
            bool i = grafo->ehCompleto();

            if(i == true)
                fprintf(arq_saida, "8- Verificar se o Grafo eh completo\n Eh completo !\n\n ");
                else
                    fprintf(arq_saida, "8- Verificar se o Grafo eh completo\n Nao eh completo !\n\n ");
            break;
        }
        case 9: {
            bool i = grafo->ehbipartido();

            if(i == true)
                fprintf(arq_saida, "9- Verificar se o Grafo eh bipartido\n Eh bipartido !\n\n ");
                else
                    fprintf(arq_saida, "9- Verificar se o Grafo eh bipartido\n Nao eh bipartido !\n\n ");
            break;
        }
        case 10:{
            int vert;
            fprintf(arq_saida, "10- Apresentar sequencia de graus do Grafo\n");
            grafo->sequenciaDeGraus(arq_saida);
            break;
            break;
        }
        case 11:{
            if(grafo->ehGrafoDirecionado()){

                int vert;
                cout << "Qual vertice deseja saber o fecho transitivo direto? ";
                cin >> vert;
                fprintf(arq_saida, "11- Mostrar fecho transitivo direto do vertice (%d)\n", vert);
                grafo->fechoTransitivoDireto(vert, arq_saida);
                break;
            }

        }
        case 12:{
            if(grafo->ehGrafoDirecionado()){

                int vert;
                cout << "Qual vertice deseja saber o fecho transitivo indireto? ";
                cin >> vert;
                fprintf(arq_saida, "12- Mostrar fecho transitivo indireto do vertice (%d)\n", vert);
                grafo->fechoTransitivoIndireto(vert, arq_saida);
                break;
            }
            break;
        }
        case 13:{

            break;
        }
        case 14:{
            fprintf(arq_saida, "14- Apresentar uma Arvore geradora minima (Kruskal)\n");
            grafo = grafo->kruskal(arq_saida);
            break;
        }
        case 15:{
            fprintf(arq_saida, "15- Apresentar uma Arvore geradora minima (Prim)\n");
            grafo->prim(arq_saida, 4);
            break;
        }
        case 16:{
            fprintf(arq_saida, "16- Apresentar o custo do caminho mínimo entre  vértices (Dijkstra)\n");
            cout << "Qual vertice de partida ? " << endl;
            int verticePartida;

            cin >> verticePartida;

            grafo->djisktra(verticePartida, arq_saida);
            break;
        }
        case 17:{
            grafo->imprimeArestas(arq_saida);
            //cout << grafo->numComponentesConexas();
            break;
        }
        case 18:{
            fprintf(arq_saida, "18- Apresentar uma Arvore geradora minima Steiner(Guloso)\n");
            grafo->steinerGuloso(arq_saida);
            break;
        }
        case 19:{
            fprintf(arq_saida, "19- Apresentar uma Arvore geradora minima Steiner(Guloso Randomizado)\n");
            grafo->steinerGulosoRandomizado(arq_saida, 0.4, 500);
            break;
        }
        case 20:{

            break;
        }
        case 21:{
            grafo->imprimeArestas(arq_saida);
            break;
        }
        default:{
            cout << "ERRO: Opcao invalida!" << endl;
        }
    }
}

int main(int argc, char *argv[])
{

    GrafoL* grafo = new GrafoL();

    /*cout << "Informe o nome do arquivo que deseja abrir : ";
    cin >> nomeArquivo;

    char *nomeArq = new char[nomeArquivo.length() + 1];              //Formata o nome de arquivo para os metodos
    memcpy(nomeArq, nomeArquivo.c_str(), nomeArquivo.length() + 1);  //das funçoes abrirem direito.*/

    grafo = lerArquivo(argv[1], grafo);

    if(grafo != NULL){

        int opcao;

        exibeMenu();

        FILE* arq_saida;

        arq_saida = fopen(argv[2], "w");

        if(arq_saida == NULL)
            cout << "Erro na abertura do arquivo de saida!";
            else{
                while(opcao != 0){
                    cout << "\n\n\nOpcao : ";
                    cin >> opcao;
                    chamaOpcaoDoMenu(opcao, arq_saida, grafo);
                }

                fclose(arq_saida);
            }
    }else
        cout << "Nao foi possivel criar o grafo !";


    //if(grafo != NULL){

        //int terminais[14] = {797, 465, 968, 563, 209, 64, 241, 898, 771,835, 861, 102, 72, 321};
        //int terminais[14] = {30, 180, 81, 116, 132, 196, 88, 17, 191, 161, 19, 201, 144, 178};
        //int terminais[11] = {823, 886, 403, 156, 552, 402, 642, 124, 707, 525, 278};
        //int terminais[14] = {4332, 7142, 2383, 3417, 7496, 7022, 4210, 1696, 622,6767, 2822, 3184, 980, 6131};
        //int terminais[2] = {7, 6};
        //int terminais[5] = {659, 309, 553, 935, 591};
        //grafo->steinerGuloso(terminais, 14);
        //grafo->kruskal();
        //grafo->steinerGulosoRandomizado(terminais, 5, 0.3, 10);


    //}

    return 0;
}
