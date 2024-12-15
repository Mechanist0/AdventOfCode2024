#ifndef PUZZLEHELPERS_H
#define PUZZLEHELPERS_H

#include <string>
#include <vector>

// Split string by delimiter
std::vector<std::string> split(const std::string& s, const std::string& delimiter);

// Print vector generic
template <typename T>
void printVector(const std::vector<T>& vec);

#endif
