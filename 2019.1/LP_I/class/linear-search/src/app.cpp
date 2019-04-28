#include <cassert>
#include <iostream>  // cout
#include <iterator>  // std::begin() e std::end()

#include "../include/lsearch.h"

bool equal_abs(const int& a, const int& b) {
        return abs(a) == abs(b);
}

bool equal(const int& a, const int& b) {
        return a == b;
}

int main(void) {
        // Espaço de busca.
        int A[]{3, 4, -2, 50, -38, 10, 17, 38, -28};
        int target1{38};  // alvo 1
        int target2{28};  // alvo 2

        std::cout << ">>> A [ ";
        for (const auto& e : A) {
                std::cout << e << " ";
        }
        std::cout << "]\n";

        auto result = lsearch(std::begin(A), std::end(A), target1, equal_abs);
        //assert (result == &A[4]); // &A[4] A+4
        std::cout << ">>> Target = " << target1 << std::endl;

        if (result != std::end(A)) {
                std::cout << "\tFound " << *result << " at location " << (result - A) << ".\n";
        } else {
                std::cout << "\tNOT FOUND!\n";
        }

        result = lsearch(std::begin(A), std::end(A), target2, equal_abs);
        assert(result == (A + 8));
        std::cout << ">>> Target = " << target2 << std::endl;

        if (result != std::end(A)) {
                std::cout << "\tFound " << *result << " at location " << (result - A) << ".\n";
        } else {
                std::cout << "\tNOT FOUND!\n";
        }

        std::cout << ">>> Passou nos testes!!!\n";

        return 0;
}
