#ifndef ASK_FILE_H
#define ASK_FILE_H

#include <fstream>   // std::ifstream
#include <iostream>  // std::cout, std::cin
#include <string>    // std::string

using namespace std;
/**!
 * Asks user for the name of an input file , tries to open
 * the file and assigns it to the ifstream passed as reference .
 * If the input file name provided by the user does not exist ,
 * the function keeps asking the user to try again .
 *
 * \param ifs_ Reference to the input file stream we want to open.
 * \param msg_ Message to show to the user, asking for a file name.
 * \return A string with the input file name provided by the user.
 */
string askUserFileName(ifstream &ifs_, string msg_ = "");

#endif