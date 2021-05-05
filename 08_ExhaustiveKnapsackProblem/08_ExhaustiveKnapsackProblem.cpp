/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 08
                                Knapsack Problem
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printKnapSack(vector< vector<T> >& M, T& W);

vector<int> decimal2binary(int dec, int n) {
    /*  Converte um decimal em binário com n dígitos
    * ENTRADAS:
    * Inteiro dec a ser convertido
    * Inteiro n com tamanho da saída
    * SAÍDA:
    * Vator de inteiros bin com tamanho n contendo dec em binário
    */

    // Inicializa a saída: vetor com n valores zero
    vector<int> bin(n, 0);

    // Indicador do dígito atual, começando pelo último (n-1)
    int i = n - 1;

    // Enquanto o valor dec for maior que 0, ele ainda pode ser dividido
    while (dec > 0) {
        // O dígito atual é o resto da divisão por 2 de dec
        bin[i] = dec % 2;

        // Reduz dec à metade, arredondando para baixo
        dec = (dec % 2 == 0) ? dec / 2 : (dec - 1) / 2;

        // Decrementa o dígito atual
        i--;
    }

    return bin;
}

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

    // Inicializa o peso e o valor acumulado na mochila para cada permutação
    T cumulative_weight, cumulative_value;

    // Vetores com subset atual S, e subset com valor máximo S_max
    vector<int> S, S_max;

    // Iniciliza a saída com um Par (peso, vetor de itens)
    // 1) Objeto do mesmo datatype das entradas com o valor final da mochila
    // 2) Vetor de inteiros com os itens que compõem a mochila
    pair<T, vector<int>> current_maximum;

    // Realiza a análise de cada mochila possível expresso pela sequência
    // de valores binários no vetor S (subset). 
    // Itera cada um dos 2^n subconjuntos possíveis.
    for (int i = 0; i < pow(2, n); i++) {
        
        // Subconjunto atual é a conversão da cardinalidade em binário
        S = decimal2binary(i, n);

        // Peso e valor acumulados são zerados
        cumulative_weight = 0;
        cumulative_value = 0;

        // Itera cada item da mochila
        for (int j = 0; j < n; j++) {

            // Se tal item pertencer ao subconjunto atual
            if (S[j] == 1) {

                // Acrescenta o peso e o valor de tal item aos acumuladores
                cumulative_weight += I[0][j];
                cumulative_value += I[1][j];
            }
        } 

        // Caso o peso dos itens não exceda a capacidade da mochila
        if (cumulative_weight <= W) {

            // Caso o valor acumulado nessa mochila exceda o maior valor atual
            if (cumulative_value > current_maximum.first) {

                // Substitui o máximo atual pelos itens desta permutação
                current_maximum.first = cumulative_value;
                current_maximum.second.clear();
                S_max = S;
            }
        }
    } 
    
    // Converte os binários do maior subconjunto nos respectivos itens da mochila
    int k = 0;
    for (int i : S_max) {
        // Para cada item, se ele pertencer à mochil (S=1), acrescente-o à saída
        if (i == 1) { current_maximum.second.push_back(k); }
        k++;
    }

    return current_maximum;
}

int main() {
    // Cria uma Matriz M (vetor de vetores) com pesos e valores
    // Primeira linha: pesos, Segunda linha: valores
    vector< vector<float> > V = { { 14,  6,  8, 10 },
                                  { 42, 12, 40, 25 } };

    // Declara a capacidade
    float W = 20;

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
