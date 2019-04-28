
/*
 * TAD: Container Sequencial (aka sequencia, lista)
 *
 * OPERAÇÕES DESEJÁVEIS
 * 0) Criar uma lista de qualquer tipo.
 * 1) Inserir um elemento em uma posição qualquer.
 *    1.1) Inserir uma sequência de elementos em uma posição específica.
 * 2) Remover um elemento em uma posição qualquer.
 *    2.1) Remover um sequência de elementos da lista, indicados por um range.
 * 3) Sobrescrever/Alterar um elemento em uma posição específica.
 * 4) Recuperar o tamanho do container.
 * 5) Recuperar o 1ro e último elemento
 * 6) Preencher a lista/container com um valor específico.
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <cstdlib>  // size_t
#include <exception>
#include <iostream>  // std::cerr

namespace sc {

template <typename T, size_t SIZE>
struct array {
        T data[SIZE];  //!< Area de armazenamento dos dados.

        /// Insere um elemento `value` na posição `pos`, sem verificar os limites da lista.
        void insert(size_t pos, const T& value) { data[pos] = value; }

        /// Insere um elemento `value` na posição `pos`, verificando os limites da lista.
        /*!
         * @throw Gera excecao...
         */
        void at(size_t pos, const T& value) {
                if (pos >= SIZE) {
                        throw std::invalid_argument(
                            "[array::at()] Posicao informada alem dos limites do array.");
                }

                data[pos] = value;
        }

        /// Retorna o tamanho do array (numero de elementos).
        size_t size() const { return SIZE; }

        /// Preenche **todo** o array com o valor especificado.
        void fill(const T& value) {
                // Percorrer e preencher.
                for (T& e : data) {
                        e = value;
                }
        }

        /// Recupera o valor do array na posicao especificada.
        /*! Utilizada do lado esquerdo de uma atribuicao.
         * x = array.at( pos );
         */
        T at(size_t pos) const {
                if (pos >= SIZE) {
                        throw std::invalid_argument(
                            "[array::at() const] Posicao informada alem dos limites do array.");
                }

                return data[pos];
        }

        T& at(size_t pos) {
                if (pos >= SIZE) {
                      throw std::invalid_argument(
                            "[array::at() const] Posicao informada alem dos limites do array.");
                }
                
                return data[pos];
        }
};

}  // namespace sc

#endif
