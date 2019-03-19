#ifndef INVERSE_H
#define INVERSE_H

#include <iostream> // std::cout, std::cin
#include <fstream>  // std::ifstream
#include <vector>   // std::vector

using namespace std;

/**!
 * Write in the file "invertido.txt" the numbers read from "numbers.txt"
 * in reverse order.
 * 
 * \param ofs Reference to the output file stream we want to write.
 * \param numbers Vector of the numbers from "numbers.txt"
 */
void writeInverse(ofstream &ofs, vector<int> numbers);

#endif