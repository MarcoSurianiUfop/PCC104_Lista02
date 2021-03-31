/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 09
                              Breadth-First Search
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>  

using namespace std;

class Grafo {
    // Classe para armazenar grafos marcados (vértices, arestas e marcações)
private:
    // Inteiro com a quantidade de vértices. Os vértices são [0, ..., nodes-1]
    // Não é possível rotular os vértices!!
    int n_nodes = 0;
    // Vetor de arestas com pares de inteiros
    vector<pair<int, int>> edges;
    // Vetor com marcações dos nós
    vector<int> vertex_marks;
public:
    // Entrada da quantidade de vértices
    // Possível melhoria: só realiza se n_nodes = 0 (proibido alterar)
    void set_nodes(int n) { n_nodes = n; }

    // Devolve a quantidade de vértices
    int get_nodes() { return n_nodes; }

    // Entrada de arestas: recebe coordenadas inteiras (x, y) 
    // e armazena como um par em vertex
    // O primeiro vértice é sempre menor que o segundo para facilitar a análise
    void set_edge(int x, int y) {
        if (x <= y)
            edges.push_back(pair<int, int>(x, y));
        else
            edges.push_back(pair<int, int>(y, x));
    }

    // Saída de arestas: devolve a (n+1)-esima aresta (origem e destino)
    int get_o(int n) { return edges[n].first; }
    int get_d(int n) { return edges[n].second; }

    // Retorna a quantidade arestas armazenadas
    int num_edges() { return edges.size(); }

    // Entrada das marcações
    void set_marks(vector<int> vm) {
        vertex_marks.clear();
        vertex_marks = vm;
    }

    // Retorna as marcações
    vector<int> get_marks() { return vertex_marks; }

    // Retorna a marcação do vértice n
    int get_mark(int n) { return vertex_marks[n]; }
};

void bfs(Grafo& G, int& v, vector<int>& visited_vertex, int& count) {
    /*  Implementação do BREADTH-FIRST SEARCH (visita os vértices)
    * Visita os vértices conectados ao vértice v e os marca
    * na ordem que foram encontrados com auxílio da variável global count
    * ENTRADAS:
    * Ponteiro para objeto do tipo Grafo G = <V, E, M>
    * Ponteiro para índice do vértice visitado v
    * Ponteiro para vetor com marcações visited_vertex
    *          ** Marcações: 0: não visitado, n: n-ésima visita
    * Ponteiro para variável global count
    * SAÍDA:
    * Altera o vetor de marcações visited_vertex e o ceontador count
    */

    // Incrementa o contador e marca o vértice v com seu valor
    count++;
    visited_vertex[v] = count;

    // Inicializa uma fila bfs_queue e acrescenta o vértice v
    queue<int> bfs_queue;
    bfs_queue.push(v);

    // Inicializa o próximo vértice w
    int w;

    // Enquanto a fila não estiver vazia
    while (!bfs_queue.empty()) {

        // Percorre todas as arestas de G
        for (int j = 0; j < G.num_edges(); j++) {

            // w é o destino da aresta atual
            w = G.get_d(j);

            // Caso a origem da aresta atual seja o primeiro vértice da fila
            // (ou seja, o vértice w é adjacente ao primeiro vértice da fila)
            // e caso o vértice atual ainda tenha marcação 0 (não visitado)
            if (G.get_o(j) == bfs_queue.front() && visited_vertex[w] == 0) {

                // Incrementa o contador e marca o vértice w com seu valor
                count++;
                visited_vertex[w] = count;

                // Adiciona w à fila
                bfs_queue.push(w);
            }
        }

        // Remove o primeiro vértice da fila
        bfs_queue.pop();
    }
}

void BFS(Grafo& G) {
    /*  Implementação do BREADTH-FIRST SEARCH (itera os vértices)
    * Marca cada vértice V de um Grafo G = <V, E, M> no vetor de marcações M
    * com um inteiro que representa a ordem na qual eles foram encontrados
    * pela primeira vez pelo bfs
    * ENTRADAS:
    * Ponteiro para objeto do tipo Grafo G = <V, E, M>
    * SAÍDA:
    * Altera o vetor de marcações M do Grafo G = <V, E, M> seguindo bfs
    */

    // Cria vetor M de marcações e marca todos vértices com zero (não visitado)
    vector<int> visited_vertex;
    for (int i = 0; i < G.get_nodes(); i++)
        visited_vertex.push_back(0);

    // Inicializa contador global começando em zero
    int count = 0;

    // Varre cada vértice v do grafo G
    for (int v = 0; v < G.get_nodes(); v++)
        // Caso o vértice ainda não foi visitado
        if (visited_vertex[v] == 0)
            // Visite o vértice v e seus adjacentes usando bfs
            bfs(G, v, visited_vertex, count);

    // Altera o vetor M do grafo G com as marcações realizadas
    G.set_marks(visited_vertex);
}

int main() {
    // Cria um objeto da Classe Grafo
    Grafo G;

    // Acrescenta 11 vértices ao grafo G
    int num_nodes = 11;
    G.set_nodes(num_nodes);

    // Acrescenta arestas ao grafo G
    G.set_edge(0, 1);
    G.set_edge(0, 3);
    G.set_edge(1, 2);
    G.set_edge(2, 3);
    G.set_edge(2, 10);
    G.set_edge(3, 4);
    G.set_edge(3, 6);
    G.set_edge(4, 8);
    G.set_edge(6, 7);
    G.set_edge(5, 9);

    // Imprime o Grafo G
    cout << "Grafo:" << endl;
    cout << "01 --- 00     05 --- 09" << endl;
    cout << "|      |" << endl;
    cout << "02 --- 03 --- 04 --- 08" << endl;
    cout << "|      |" << endl;
    cout << "10     06 --- 07" << endl << endl;

    // Imprime uma lista com os nós
    cout << "NDS: ";
    for (int i = 0; i < num_nodes; i++)
        cout << i << " , ";
    cout << endl;

    // Executa o algoritmo BFS, que marca automaticamente os vértices de G
    BFS(G);

    // Imprime a marcação de cada nó
    cout << "BFS: ";
    for (int i = 0; i < num_nodes; i++)
        cout << G.get_mark(i) << " , ";
    cout << endl;

    return 0;

}