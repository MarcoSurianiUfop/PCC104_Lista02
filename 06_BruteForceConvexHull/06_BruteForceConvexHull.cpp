/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 06
                                 Convex Hull
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>

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

int orientation(vector<int>& T) {
    /*  Encontra a orientação da tripla (p, q, r)
    * ENTRADA:
    * Ponteiro para Vetor v com elementos da tripla
    * SAÍDA:
    * 0 --> (p, q, r) colinear
    * 1 --> Sentido Horário
    * 2 --> Sentido AntiHorário
    */

    // Usa a seguinte fórmula para determinar a orientação
    int val = (T[3] - T[1]) * (T[4] - T[2]) - (T[2] - T[0]) * (T[5] - T[3]);

    // Se a fórmula retorna 0: colinear
    if (val == 0) return 0;
    // Caso contrário, retorna 1 se H ou 2 se AH
    return (val > 0) ? 1 : 2;
}

Pontos bruteForceConvexHull(Pontos& P) {
    /*  Implementação do CONVEX HULL via Força Bruta
    * Encontra a casca convexa de um conjunto de pontos
    * ENTRADA:
    * Ponteiro para Classe de Pontos P com os pontos
    * SAÍDA:
    * Objeto da Classe de Pontos convexHull com os pontos da casca convexa
    * em sentido Anti-Horário e começando pelo ponto mais à esquerda
    */

    // Determina a quantidade de pontos em P
    int n = P.size();

    // Inicializa estrutura com a saída
    Pontos convexHull;

    // Inicializa estrutura auxiliar com triplas para cálculo da orientação
    vector<int> triplet;

    // Deve haver pelo menos 3 pontos, caso contrário retorna vazio
    if (n < 3) return convexHull;

    // Encontra o ponto mais à esquerda (leftmost point)
    // Supõe que leftmost é o primeiro ponto
    int leftmost = 0;
    // Percorre todos os pontos
    for (int i = 0; i < n; i++)
        // Se ponto atual está à esquera de leftmost, atualiza leftmost
        if (P.get_x(i) < P.get_x(leftmost))
            leftmost = i;

    // Começando do leftmost point, caminha no sentido AH
    // até voltar no leftmost point.

    // Ponto atual p (inicia em leftmost) e candidato a próximo ponto q
    int p = leftmost, q;

    // Tente encontrar novos pontos da casca até chegar em leftmost novamente
    do
    {
        // Imprime o ponto atual p (+1 para ficar mais intuitivo)
        cout << p + 1 << " , ";

        // Adicione o ponto atual p ao resultado
        convexHull.set_point(P.get_x(p), P.get_y(p));

        // Procure por um ponto q de forma que a tripla (p, q, x)
        // tenha orientação AH para qualquer x.

        // Candidato q é o próximo ponto após p
        // Módulo de (p+1) força a contagem a voltar a 1 quando ultrapassa n
        q = (p + 1) % n;

        // Percorre cada ponto 
        for (int i = 0; i < n; i++)
        {
            // Cria uma tripla com o ponto atual p, o ponto percorrido i
            // e o ponto candidato q e calcula a orientação da tripla
            triplet = { P.get_x(p), P.get_y(p),
                        P.get_x(i), P.get_y(i),
                        P.get_x(q), P.get_y(q) };
            if (orientation(triplet) == 2)
                // Caso i esteja mais AH do que candidato q, atualiza q
                q = i;
        }

        // Atualiza o ponto atual p com o candidato mais AH encontrado: q
        p = q;

    } while (p != leftmost);

    cout << endl;

    return convexHull;
}

int main() {
    // Cria um objeto P da classe Pontos e acrescenta um conjunto de pontos
    Pontos P;
    P.set_point(7, 1);
    P.set_point(0, 1);
    P.set_point(1, 0);
    P.set_point(3, 3);
    P.set_point(5, 4);
    P.set_point(3, 5);
    P.set_point(7, 7);
    P.set_point(1, 8);
    P.set_point(8, 1);
    P.set_point(2, 0);
    P.set_point(3, 0);

    // Imprime os pontos de P
    cout << "Pairs:" << endl;
    printPairs(P);

    // Calcula a casca convexa e armazena no objeto H da classe Pontos
    // Imprime os pontos do resultado H
    cout << endl << "Convex Hull: " << endl;
    Pontos H = bruteForceConvexHull(P);
    printPairs(H);

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