/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 05
                            Brute Force Closest Pair
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

class Pontos {
    // Classe para armazenar uma lista com pontos no plano
private:
    // Cria um vetor com pares de inteiros
    vector<pair<int, int>> V;
public:
    // Entrada de pontos: recebe coordenadas inteiras (x, y) 
    // e armazena como um par em V
    void set_point(int x, int y) { V.push_back(pair<int, int>(x, y)); }

    // Saída de pontos: devolve o (n+1)-esimo ponto (coordenada x ou y
    int get_x(int n) { return V[n].first; }
    int get_y(int n) { return V[n].second; }

    // Retorna a quantidade pontos armazenada
    int size() { return V.size(); }
};

void printPairs(Pontos& P);

double bruteForceClosestPair(Pontos& P) {
    /*  Implementação do CLOSEST PAIR via Força Bruta
    * Calcula a distância entre os pontos mais próximos
    * ENTRADA:
    * Ponteiro para Classe de Pontos P com os pontos
    */

    // Determina a quantidade de pontos em P
    int n = P.size();

    // Inicializa a saída com valor infinito
    double d = numeric_limits<float>::infinity();

    // Inicializa uma variável auxiliar para calcular distâncias
    double dist;

    // Percorre cada ponto do conjunto P
    for (int i = 0; i < n - 1; i++)
        // Percorre do ponto i+1 até o final
        for (int j = i + 1; j < n; j++)
        {
            // Se a distância entre os pontos for menor que d, atualiza d
            dist = pow(pow(P.get_x(i) - P.get_x(j), 2) +
                pow(P.get_y(i) - P.get_y(j), 2), 0.5);
            d = (dist < d) ? dist : d;
        }

    return d;
}

int main() {
    // Cria um objeto P da classe Pontos e acrescenta um conjunto de pontos
    Pontos P;
    P.set_point(0, 1);
    P.set_point(1, 0);
    P.set_point(3, 0);
    P.set_point(0, 5);
    P.set_point(7, 7);
    P.set_point(1, 8);
    P.set_point(8, 1);

    // Imprime os pontos de P
    cout << "Pairs:" << endl;
    printPairs(P);

    // Calcula e imprime a distância entrae os pontos mais próximos de P
    cout << "Closest Distance: " << bruteForceClosestPair(P) << endl;

    return 0;
}

void printPairs(Pontos& P) {
    /*  Função para Imprimir vetores
    * ENTRADA:
    * Ponteiro para objeto P com pontos
    */

    // Determina a quantidade de pontos em P
    int n = P.size();

    // Itera todos os elementos do objeto P e imprimea cada par
    for (int i = 0; i < n; i++)
        cout << "(" << P.get_x(i) << " , " << P.get_y(i) << ")" << endl;
}