/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 04
                              BruteForceStringMatch
    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int bruteForceStringMatch(vector<char>& T, vector<char>& P) {
    /*  Implemaentação do STRING MATCH
    * Procura por um pedaço de texto em um texto maior
    * ENTRADAS:
    * Ponteiro para Vetor de caracteres T com texto
    * Ponteiro para Vetor de caracteres P com padrão
    * SAÍDAS:
    * Posição do primeiro elemento de P em T ou -1 se não for encontrado
    */

    // Tamanho da entrada
    int n = T.size();
    int m = P.size();

    // Índices de busca nos vetores T e P, respectivamente
    int i, j;

    // Percorre o texto T até onde o padrão P couber
    for (i = 0; i <= n - m; i++)
    {
        // Volta para o início do padrão P
        j = 0;

        // Enquanto o índice j estiver no tamanho do padrão P e
        // enquanto o texto e o padrão coincidirem
        while (j < m && P[j] == T[i + j])
            // Prossiga a busca para o próximo caractere do padrão
            j++;

        // Caso a busca pelo padrão tenha chegado até o fim,
        // retorno o índice i
        if (j == m)
            return i;
    }

    // Caso todas as buscas tenham falhado, retorno -1
    return -1;
}

int main()
{
    // Cria um string com um Texto e converte em vetor de caracteres
    string sT = "Marco Aurelio";
    vector<char> T(sT.begin(), sT.end());

    // Imprime o Texto
    cout << "Text   : " << sT << endl;

    // Cria um string com um Padrão presente e converte em vetor de caracteres
    string sP = "arc";
    vector<char> P1(sP.begin(), sP.end());

    // Busca o primeiro padrão e imprime o resultado
    int pos = bruteForceStringMatch(T, P1);
    cout << "Pattern: " << sP << "\tPosition: " << pos + 1 << endl;

    // Cria um string com um Padrão não presente e converte em vetor de caracteres
    sP = "booo";
    vector<char> P2(sP.begin(), sP.end());

    // Busca o segundo padrão e imprime o resultado
    pos = bruteForceStringMatch(T, P2);
    cout << "Pattern: " << sP << "\tPosition: " << pos + 1 << endl;

    // Observação para o usuário
    cout << endl << endl << "* Position 0 means element was not found." << endl;

    return 0;
}