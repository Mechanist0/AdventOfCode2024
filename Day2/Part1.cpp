#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../PuzzleHelpers/PuzzleHelpers.h"

bool isDescending(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        bool test = vec[i] <= vec[i - 1];
        if (!test) {
            return false; // Not descending
        }
    }
    return true; // Descending
}

bool isAscending(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        bool test = vec[i] >= vec[i - 1];
        if (!test) {
            return false; // Not descending
        }
    }
    return true; // Descending
}

int main() {
    std::vector<std::vector<int>> puzzleInput;

    // Create a text string, which is used to output the text file
    std::string myText;
    // Read file
    std::ifstream MyReadFile("PuzzleInput.txt");
    while (std::getline(MyReadFile, myText)) {
        std::vector<int> levels;

        std::vector<std::string> out = split(myText, " ");
        for(int i = 0; i < out.size(); i++) {
            levels.push_back(std::stoi(out[i]));
        }

        puzzleInput.push_back(levels);
    }

    // It is considered good practice, and it can clean up unnecessary memory space.
    MyReadFile.close();

    int count = 0;
    for(int i = 0; i < puzzleInput.size(); i++) {
        // Check Ascending or Descending
        std::vector<int> current = puzzleInput[i];

        if(isAscending(current) || isDescending(current)) {
            // Check distance 1-3
            bool distLatch = true;
            for(int j = 1; j < current.size(); j++) {
                int dist = abs(current[j] - current[j-1]);
                std::cout << "[" << current[j] << " " << current[j-1] << "]" << " " << dist << " ";
                if(dist < 1 || dist > 3) {
                    distLatch = false;
                }
            }
            if(distLatch) count++;
            std::cout << "\n";
        }
    }
    std::cout << count;
}
