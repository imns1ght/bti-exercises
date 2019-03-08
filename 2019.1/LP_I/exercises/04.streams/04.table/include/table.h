#ifndef TABLE_H
#define TABLE_H

#include <iostream> // cout, endl
#include <iomanip>  // setw, setfill
#include <fstream>  // std::ifstream
#include <sstream>  // ostringstream
#include <string>   // std::string
#include <vector>   // vector

using namespace std;

void printTable(const std::vector<string> &hItems, const std::vector<int> &cellNumbers);
int readHeader(ifstream &headerItems, std::vector<string> &hItems);
int readInteger(ifstream &numbers, std::vector<int> &cellNumbers);

#endif