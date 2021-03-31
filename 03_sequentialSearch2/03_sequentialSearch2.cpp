/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 03
                               SEQUENTIAL SEARCH 2
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printVector(vector<T>& v);

template <class T>
int sequentialSearch2Vector(std::vector<T>& v, T K) {
    /*  Implementação do SEQUENTIAL SEARCH 2
    * Encontra um elemento em uma série
    * ENTRADAS:
    * Ponteiro para Vetor v com elementos de qualquer datatype
    * Valor K a ser buscado
    * SAÍDAS:
    * Posição do primeiro elemento K ou -1 se não for encontrado
    */

    // Tamanho da entrada
    int n = v.size();

    // Inclui a chave de busca como elemento final do vetor v
    v.push_back(K);

    // Índice do elemento a ser buscado (começa no primeiro)
    int i = 0;

    // Enquanto o elemento atual for diferente da chave, buscar próximo elemento
    while (v[i] != K)
        i++;

    // Retira a chave de busca como elemento final do vetor v
    v.pop_back();

    // Caso tenha encontrado a chave antes do fim, retorne tal índice
    if (i < n)
        return i;
    else
        return -1; // Caso contrário, retorne -1
}

int main() {
    // Cria um vetor de elementos  
    std::vector<int> v = { 30, 64, 25, 12, 22, 35, 11, 10 };

    // Imprime o vetor 
    cout << "Full vector:" << endl;
    printVector(v);

    // Cria uma chave pertencente ao vetor, busca e imprime o resultado
    int K = 64;
    int pos = sequentialSearch2Vector(v, K);
    cout << endl << "Value: " << K << "\tPosition: " << pos + 1;

    // Cria uma chave não pertencente ao vetor, busca e imprime o resultado
    K = 100;
    pos = sequentialSearch2Vector(v, K);
    cout << endl << "Value: " << K << "\tPosition: " << pos + 1;

    // Observação para o usuário
    cout << endl << endl << "* Position 0 means element was not found." << endl;

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