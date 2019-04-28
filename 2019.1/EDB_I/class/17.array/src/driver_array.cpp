#include <cassert>
#include <iostream>
#include "array.h"

int main(void) {
        sc::array<int, 5> A;

        // A.data[0] = 3;
        A.insert(3, 3);

        try {
                A.at(4, 6);
        } catch (const std::invalid_argument& xxx) {
                // faz o que for preciso para contornar o problema.
                std::cout << "Capturei a excecao\n";
                std::cout << "A msg da execao eh" << xxx.what() << std::endl;
        }

        // Teste #1: testando o metodo size().
        assert(A.size() == 5);

        // Teste #2: verificando se o fill() funciona.
        A.fill(-3);

        // todos os elementos tem que ser igual a -3
        for (const int& e : A.data) {
                std::cout << e << " ";
                assert(e == -3);
        }
        std::cout << std::endl;

        // Teste #3: testando a versão de consulta de uma posicao.
        int x = A.at(1);
        assert(x == -3);

        // Teste #4: Testando a versão de alteraçao de uma posicao.
        A.at(1) = 5;
        assert(A.at(1) == 5);

        // Preencher o vetor com sequencia numerica.
        for (auto i(0u); i < A.size(); i++) {
                std::cout << i + 1 << " ";
                A.at(i) = i + 1;
        }
        std::cout << std::endl;

        return 0;
}