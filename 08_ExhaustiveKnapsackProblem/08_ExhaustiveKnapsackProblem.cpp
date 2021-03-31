/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 08
                                Knapsack Problem
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void printKnapSack(vector< vector<T> >& M, T& W);

template <class T>
pair<T, vector<int>> exhaustiveKnapSackProblem(vector<vector<T>>& I, T& W) {
    /*  Implementação do KNAPSACK PROBLEM via Busca Exaustiva
    * Encontra a forma de encher uma mochila com os itens mais valiosos
    * possível, dada sua capacidade e um lista de itens com peso e valor
    * ENTRADAS:
    * Ponteiro para matriz I (vetor de vetores) com pesos e valores de cada
    * item, composto por elementos de qualquer datatype
    * Ponteiro para objeto W de qualquer datatype com capacidade da mochila
    * SAÍDA:
    * Objeto do tipo par (pair) contendo:
    *   1) Objeto do mesmo datatype das entradas com o valor final da mochila
    *   2) Vetor de inteiros com os itens que compõem a mochila
    */

    // Determina a quantidade de itens em I
    int n = I[0].size();

    // Cria um vetor com todos os índices de todos itens da mochila
    vector<int> index;
    for (int i = 0; i < n; i++)
        index.push_back(i);

    // Inicializa o peso e o valor acumulado na mochila para cada permutação
    T cumulative_weight, cumulative_value;

    // Inicia a quantidade de itens na mochila em cada permutação
    int itens_size;

    // Itens na mochila na permutação corrente
    vector<int> current_knap;

    // Iniciliza a saída com um Par (peso, vetor de itens)
    // 1) Objeto do mesmo datatype das entradas com o valor final da mochila
    // 2) Vetor de inteiros com os itens que compõem a mochila
    pair<T, vector<int>> current_maximum;

    // Realiza a análise da mochila atual expresso pela sequência
    // de vértices no vetor vertex. 
    // Ao terminar, atualiza o vetor vertex com a próxima permutação
    // lexicograficamente maior. 
    // Encerra o laço se não houver permutação maior.
    do {

        // Limpa a mochila atual e zera a sua quantidade de itens
        current_knap.clear();
        itens_size = 0;

        // Peso e valor acumulados são zerados
        cumulative_weight = 0;
        cumulative_value = 0;

        // Enquanto o próximo item na sequência de vertex couber na mochila
        while (cumulative_weight + I[0][index[itens_size]] <= W) {

            // Acrescenta o peso e o valor de tal item aos acumuladores
            cumulative_weight += I[0][index[itens_size]];
            cumulative_value += I[1][index[itens_size]];

            // Acreascenta o item à mochila atual e incrementa sua quantidade
            current_knap.push_back(index[itens_size]);
            itens_size++;

        } // Caso um novo item exceda o peso, para de encher a mochila

        // Caso o valor acumulado nessa mochila exceda o maior valor atual
        if (cumulative_value > current_maximum.first) {

            // Substitui o máximo atual pelos itens desta permutação
            current_maximum.first = cumulative_value;
            current_maximum.second.clear();
            current_maximum.second = current_knap;
        }

        // Tenta criar próxima permutação. Se falhar, encerra o laço.
    } while (next_permutation(index.begin(), index.end()));

    return current_maximum;
}

int main() {
    // Cria uma Matriz M (vetor de vetores) com pesos e valores
    // Primeira linha: pesos, Segunda linha: valores
    vector< vector<float> > V = { {  7,  3,  4,  5 },
                                  { 42, 12, 40, 25 } };

    // Declara a capacidade
    float W = 10;

    // Imprime capacidade e itens (peso, valor) da mochila
    printKnapSack(V, W);

    // Calcula valor máximo e itens que o compõem e determina a qtdade de itens
    pair<float, vector<int>> max_knap = exhaustiveKnapSackProblem(V, W);
    int m = max_knap.second.size();

    // Imprime o maior valor possível e os itens que compõem tal mochila
    cout << "Maximum Value: " << max_knap.first << endl;
    cout << "Itens: ";
    for (int i = 0; i < m; i++)
        cout << max_knap.second[i] + 1 << " , ";
    cout << endl;

    return 0;
}

template <class T>
void printKnapSack(vector< vector<T> >& M, T& W) {
    /*  Função para Imprimir KnapSack
    * ENTRADAS:
    * Ponteiro para Matriz M (vetor de vetores) com elementos de qualquer datatype
    * Ponteiro para objeto W de qualquer datatype com capacidade da mochila
    */

    // Determina a quantidade de itens em I
    int n = M[0].size();

    // Imprime cabeçalho
    cout << "Capacidade da Mochila (Peso): " << W << endl
        << "Itens da Mochila (Peso, Valor):" << endl;

    // Itera todos os itens da Matriz M
    for (int i = 0; i < n; i++)
        // Imprime par (peso, valor)
        cout << "(" << M[0][i] << " , " << M[1][i] << ")" << endl;
    cout << endl;
}