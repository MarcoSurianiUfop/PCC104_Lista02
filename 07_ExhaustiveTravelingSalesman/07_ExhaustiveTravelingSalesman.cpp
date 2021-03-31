/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 07
                            Traveling Salesman Problem
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void printMatrix(vector< vector<T> >& M);

template <class T>
int exhaustiveTravelingSalesmanProblem(vector<vector<T>>& graph, int& s) {
    /*  Implementação do TRAVELING SALESMAN PROBLEM via Busca Exaustiva
    * Encontra o menor caminho para viajar entre n cidades a partir de uma fonte
    * ENTRADAS:
    * Ponteiro para matriz graph (vetor de vetores) com distâncias entre os
    * vértices, composto por elementos de qualquer datatype
    * Inteiro s (source) com vértice fonte
    */

    // Tamanho da entrada
    int n = graph.size();

    // Cria um vetor com todos os vértices exceto a fonte (source)
    vector<T> vertex;
    for (int i = 0; i < n; i++)
        if (i != s)
            vertex.push_back(i);

    // Inicializa variável com o custo do menor caminho
    // Inicialmente, assume-se valor infinito
    int min_path = INT_MAX;

    // Inicializa vértice atual
    int k;

    // Inicializa o custo do caminho atual
    T current_pathweight;

    // Imprime cabeçalho
    cout << "Paths -> Weights" << endl;

    // Realiza a análise do caminho atual expresso pela sequência
    // de vértices no vetor vertex. 
    // Ao terminar, atualiza o vetor vertex com a próxima permutação
    // lexicograficamente maior. 
    // Encerra o laço se não houver permutação maior.
    do {

        // Começa a análise no vértice fonte (source)
        k = s;

        // Inicialmente, o custo do caminho é 0
        current_pathweight = 0;

        // Varredura de cada vértice do grafo
        for (int i = 0; i < n - 1; i++) {
            // Acumula custo de ir do vértice atual ao próximo
            current_pathweight += graph[k][vertex[i]];
            // Atualiza o vértice atual
            k = vertex[i];
        }
        // Aceumula custo de voltar para a fonte (source)
        current_pathweight += graph[k][s];

        // Imprime o caminho atual e seu custo
        // Adiciona 1 aos vértices para ficar mais intuitivo
        cout << s + 1;
        for (int i = 0; i < n - 1; i++)
            cout << " , " << vertex[i] + 1;
        cout << " -> " << current_pathweight << endl;

        // Atualiza, se for o caso, o menor caminho
        min_path = min(min_path, current_pathweight);

        // Tenta criar próxima permutação. Se falhar, encerra o laço.
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main() {
    // Cria uma Matriz de Adjacência M (vetor de vetores) com as distâncias
    vector< vector<int> > M = { { 0, 10, 15, 20 },
                                { 10, 0, 35, 25 },
                                { 15, 35, 0, 30 },
                                { 20, 25, 30, 0 } };

    // Imprime as distâncias
    cout << "Graph:" << endl;
    printMatrix(M);

    // Escolhe o nó inicial (fonte ou source)
    int s = 0;

    // Calcula e imprime o custo de todos caminhos possíveis e indica o menor
    cout << endl << "Minimum Path: " <<
        exhaustiveTravelingSalesmanProblem(M, s) << endl;

    return 0;
}

template <class T>
void printMatrix(vector< vector<T> >& M) {
    /*  Função para Imprimir Matrizes
    * ENTRADA:
    * Ponteiro para Matriz M (vetor de vetores) com elementos de qualquer datatype
    */

    // Itera todos os vetores da Matriz M
    for (vector<T> v : M) {
        // Itera todos os elementos do vetor v
        for (T n : v)
            // Imprime cada elemento
            cout << n << "\t";
        cout << endl;
    }

    cout << endl;
}