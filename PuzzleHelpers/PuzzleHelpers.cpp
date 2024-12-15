#include "PuzzleHelpers.h" // Include the header file
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    std::string str = s;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    tokens.push_back(str);

    return tokens;
}

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "]\n";
}
