#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../PuzzleHelpers/PuzzleHelpers.h"

class LevelChecks {
    public:
        std::vector<int> levels;
        int errors;
};

int descendingErrors(const std::vector<int>& vec) {
    int errorCount = 0;
    for (size_t i = 1; i < vec.size(); i++) {
        int dist1 = abs(vec[i] - vec[i-1]);
        if (vec[i] > vec[i - 1]) {
            errorCount++; // Not descending
        } else if(dist1 < 1 || dist1 > 3) {
            errorCount++;
        }
    }
    return errorCount; // Descending
}

bool isDescending(const std::vector<int>& vec) {
    return descendingErrors(vec) == 0;
}


int ascendingErrors(const std::vector<int>& vec) {
    int errorCount = 0;
    for (size_t i = 1; i < vec.size(); i++) {
        int dist1 = abs(vec[i] - vec[i-1]);
        if (vec[i] < vec[i - 1]) {
            errorCount++; // Not descending
        } else if(dist1 < 1 || dist1 > 3) {
            errorCount++;
        }
    }
    return errorCount; // Descending
}

bool isAscending(const std::vector<int>& vec) {
    return ascendingErrors(vec) == 0;
}

int totalErrorCount(const std::vector<int>& vec) {
    int totalErrors = 0;

    int ascendingErrs = ascendingErrors(vec);
    int descendingErrs = descendingErrors(vec);

    totalErrors += (ascendingErrs < descendingErrs) ? ascendingErrs : descendingErrs;

    // Debug
    std::cout << ascendingErrs << " " << descendingErrs << " " << totalErrors << " | ";

    return totalErrors;
}

// bool checkSafty(const std::vector<int>& vec) {

// }

int main() {
    std::vector<LevelChecks> puzzleInput;

    // Create a text string, which is used to output the text file
    std::string myText;
    // Read file
    std::ifstream MyReadFile("TestInput.txt");
    while (std::getline(MyReadFile, myText)) {
        LevelChecks check;

        std::vector<std::string> out = split(myText, " ");
        for(int i = 0; i < out.size(); i++) {
            check.levels.push_back(std::stoi(out[i]));
        }

        puzzleInput.push_back(check);
    }

    // It is considered good practice, and it can clean up unnecessary memory space.
    MyReadFile.close();

    int count = 0;
    for(int i = 0; i < puzzleInput.size(); i++) {
        // Check Ascending or Descending
        LevelChecks current;
        current.levels.insert(current.levels.end(), puzzleInput[i].levels.begin(), puzzleInput[i].levels.end());
        current.errors = 0;

        current.errors = totalErrorCount(current.levels);

        for(int i = 0; i < current.levels.size(); i++) {
            std::cout << current.levels[i] << " ";
        }

        bool passes = current.errors <= 1;

        std::cout << "| " << current.errors << " " << passes << "\n";

        if(passes) count++;

    }

    std::cout << "Passing Levels: " << count;
}
