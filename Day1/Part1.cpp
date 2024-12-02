#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <ranges>
#include <cmath>

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

int main() {
    std::vector<int> leftID;
    std::vector<int> rightID;

    // Create a text string, which is used to output the text file
    std::string myText;
    // Read file
    std::ifstream MyReadFile("PuzzleInput.txt");
    int count = 0;
    while (std::getline(MyReadFile, myText)) {
        // Replace the "   " with one " "
        std::string replacedString = std::regex_replace(myText, std::regex("   "), " "); // replace '   ' -> ' '

        // Split the string
        std::vector<std::string> splitString = split(replacedString, " ");

        // Convert to int and add to vector
        leftID.push_back((int) std::stoi(splitString[0]));
        rightID.push_back((int) std::stoi(splitString[1]));
    }

    // It is considered good practice, and it can clean up unnecessary memory space.
    MyReadFile.close();

    // Sort accending
    std::sort(leftID.begin(), leftID.end());
    std::sort(rightID.begin(), rightID.end());

    // Zip the two vectors together
    std::vector<int> distanceVec;
    auto zipped = std::views::zip(leftID, rightID);

    // Get the distance between the two lists
    for(auto [a, b] : zipped) {
        distanceVec.push_back(abs(a - b));
    }

    // Debug info
    // for(int i = 0; i < leftID.size(); i++) {
    //     std::cout << leftID[i];
    //     std::cout << " ";
    //     std::cout << rightID[i];
    //     std::cout << " ";
    //     std::cout << static_cast<int>(distanceVec[i]);
    //     std::cout << "\n";
    // }

    int result = 0;// = std::accumulate(distanceVec.begin(), distanceVec.end(), 0);
    for(int i = 0; i < distanceVec.size(); i++) {
        result+=distanceVec[i];
    }
    std::cout << result;
}
