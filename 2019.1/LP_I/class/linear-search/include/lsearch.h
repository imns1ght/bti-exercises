#ifndef LSEARCH_H
#define LSEARCH_H

// Apelido para ponteiro de função equal.
using Equal = bool (*)(const int &, const int &);

/*!
 * Realiza a busca linear no intervalo fornecido, [first, last), e
 * retorna um ponteiro para a primeira ocorrência do elemento `target`, se existir,
 * ou `nullptr`, caso contrário.
 */
const int * lsearch(const int *first, const int *last, int target, Equal eq);

#endif
