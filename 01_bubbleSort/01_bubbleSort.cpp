/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 01
                                   BUBBLE SORT
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printVector(vector<T>& v);
template <class T>
void swapPositions(T& xp, T& yp);

template <class T>
void bubbleSortVector(vector<T>& v, bool echo = false) {
    /*  Implementação do BUBBLE SORT
    * Ordena os elementos de uma série em ordem crescente
    * ENTRADAS:
    * Ponteiro para Vetor v com elementos de qualquer datatype
    * Bool echo para imprimir os passos intermediários (default = false)
    */

    // Tamanho da entrada
    int n = v.size();

    // Reduz o subvetor não ordenado
    for (int i = 0; i <= n - 2; i++)
        // Percorre o subvetor não ordenado  
        for (int j = 0; j <= n - 2 - i; j++)
            // Compara elemento atual com o próximo 
            if (v[j + 1] < v[j]) {
                // Troca atual com próximo caso o próximo seja menor
                swapPositions(v[j], v[j + 1]);
                // Caso echo esteja True, imprime o vetor
                if (echo)
                    printVector(v);
            }
}

int main() {
    // Cria um vetor de elementos não ordenados (inteiros) 
    vector<int> v = { 30, 64, 25, 12, 22, 35, 22, 11, 10 };

    // Imprime o vetor não ordenado
    cout << "Unsorted vector:" << endl;
    printVector(v);

    // Ordena o vetor usando o BUBBLE SORT
    bubbleSortVector(v, false);

    // Imprime o vetor ordenado
    cout << endl << "Sorted vector (Bubble):" << endl;
    printVector(v);

    return 0;
}

template <class T>
void printVector(vector<T>& v) {
    /*  Função para Imprimir vetores
    * ENTRADA:
    * Ponteiro para Vetor v com elementos de qualquer datatype
    */

    // Itera todos os elementos do vetor v
    for (T n : v)
        // Imprime cada elemento
        cout << n << " ";
    cout << endl;
}

template <class T>
void swapPositions(T& xp, T& yp) {
    /*  Função para Trocar os valores de duas variáveis
    * ENTRADAS:
    * Ponteiros xp, yp para elementos de qualquer datatype
    */

    T temp = xp;    // Guarda o conteúdo apontado por xp em temp
    xp = yp;        // Guarda o conteúdo apontado por yp na pos. apontada por xp
    yp = temp;      // Guarda o conteúdo temp na posição apontada por yp
}