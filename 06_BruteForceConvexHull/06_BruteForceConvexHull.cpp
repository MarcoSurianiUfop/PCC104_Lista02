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

    // Calcula coeficientes da reta entre os pontos [i] e [j]
    int get_a(int i, int j) { return V[j].second - V[i].second; }
    int get_b(int i, int j) { return V[i].first - V[j].first; }
    int get_c(int i, int j) {
        return V[i].first * V[j].second - V[i].second * V[j].first;
    }

    // Informa se o ponto [k] está acima ou abaixo da reta definida por a, b, c
    int get_r(int k, int a, int b, int c) {
        return a * V[k].first + b * V[k].second - c;
    }  

    // Retorna a quantidade pontos armazenada
    int size() { return V.size(); }
};

void printPairs(Pontos& P);


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

    // Inicializa estrutura auxiliar added_to_convexhull
    // Informa se ponto já pertence à casca convexa ou não
    // Inicialmente, nenhum ponto pertence à casca
    vector<bool> added_to_convexhull;
    for (int i = 0; i < n; i++) {
        added_to_convexhull.push_back(false);
    }

    // Deve haver pelo menos 3 pontos, caso contrário retorna vazio
    if (n < 3) return convexHull;

    // Inicializa variáveis que serão úteis
    // a, b, c : coeficientes de reta
    int a, b, c;
    // sign : -1 se ponto está abaixo da reta; 1 caso contrário
    // current_sign : -1 se todos pontos estão abaixo da reta; 1 caso contrário
    int current_sign, sign;
    // sign_changed : determina se sign está igual ou diferente de current_sign
    bool sign_changed;

    // Percorre cada ponto da lista de Pontos
    for (int i = 0; i < n; i++) {
        // Percorre cada ponto após [i]
        for (int j = i + 1; j < n; j++) {
            // Calcula os coeficientes da reta entre [i] e [j]
            a = P.get_a(i, j);
            b = P.get_b(i, j);
            c = P.get_c(i, j);

            // current_sign = 0 (desconhecido)
            current_sign = 0;

            // sign_changed = false (não alterou)
            sign_changed = false;

            // Testa cada ponto [k] diferente de [i] e [j]
            // para saber se estão todos abaixo ou acima da reta [i] a [j]
            // Percorre cada ponto da lista de Pontos
            for (int k = 0; k < n; k++) {
                // Pula os pontos [i] e [j] da reta atual
                if (k != i && k != j) {
                    
                    // Calcula se [k] está abaixo ou acima da reta
                    sign = (P.get_r(k, a, b, c) < 0) ? -1 : 1;
                    
                    // Se current_sign = 0, atribua o valor de sign
                    // Caso contrário, se os sinais de sign e current_sign
                    // forem diferentes, o sinal alterou -> signigica que
                    // alguns pontos estão abaixo da reta e outros acima ->
                    // ou seja, [i] ou [j] não paertencem ao convex hull
                    if (current_sign == 0) {
                        current_sign = sign;
                    } else if (current_sign + sign == 0) {

                        // Indica que a reta [i] a [j] não está na casca
                        sign_changed = true;

                        // Quebra o laço for: não adianta continuar testando
                        break;
                    }
                }
            }

            // Caso o sinal não tenha alterado, todos pontos [k] estão 
            // abaixo ou acima da reta [i] a [j], 
            // ou seja, [i] e [j] peertecem à convex hull
            if (!sign_changed) {

                // Se ponto [i] ainda não foi acrescentado à casca, acrescente
                if (!added_to_convexhull[i]) {

                    // Atualize added_to_convexhull
                    added_to_convexhull[i] = true;

                    // Adicione o ponto atual ao resultado
                    convexHull.set_point(P.get_x(i), P.get_y(i));
                }

                // Se ponto [j] ainda não foi acrescentado à casca, acrescente
                if (!added_to_convexhull[j]) {

                    // Atualize added_to_convexhull
                    added_to_convexhull[j] = true;

                    // Adicione o ponto atual ao resultado
                    convexHull.set_point(P.get_x(j), P.get_y(j));
                }
            }
        }
    }

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
    P.set_point(2, 1);
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
