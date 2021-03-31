/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 02
                                SELECTION SORT
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
void selectionSortVector(vector<T>& v, bool echo = false) {
    /*  Implementação do SELECTION SORT
    * Ordena os elementos de uma série em ordem crescente
    * ENTRADAS:
    * Ponteiro para Vetor v com elementos de qualquer datatype
    * Bool echo para imprimir os passos intermediários (default = false)
    */

    // Tamanho da entrada
    int n = v.size();

    // Index do menor elemento
    int min_idx;

    // Reduz o subvetor não ordenado
    for (int i = 0; i <= n - 2; i++)
    {
        // O menor elemento é o primeiro do subvetor não ordenado  
        min_idx = i;
        // Percorre o subvetor não ordenado  
        for (int j = i + 1; j <= n - 1; j++)
            // Encontra o menor elemento no subvetor não ordenado  
            if (v[j] < v[min_idx])
                min_idx = j;

        // Troca o menor elemento do subvetor não ordenado pelo seu primeiro elemento
        swapPositions(v[min_idx], v[i]);

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

    // Ordena o vetor usando o SELECTION SORT
    selectionSortVector(v, false);

    // Imprime o vetor ordenado
    cout << endl << "Sorted vector (Selection):" << endl;
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