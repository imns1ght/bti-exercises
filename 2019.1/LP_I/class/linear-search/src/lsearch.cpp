#include "../include/lsearch.h"

/*!
 * Realiza a busca linear no intervalo fornecido, [first, last), e
 * retorna um ponteiro para a primeira ocorrência do elemento `target`, se existir,
 * ou `nullptr`, caso contrário.
 */
const int *lsearch(const int *first, const int *last, int target, Equal eq) {
        // Percorrer o range até que: (1) chegue ao final ou (2) achar o alvo.
        //while( first != last and *first != target )
        while ((first != last) && (!eq(*first, target))) {
                first++;
        }

        return first;
}
