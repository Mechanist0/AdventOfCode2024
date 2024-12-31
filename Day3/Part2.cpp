#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <regex>
#include <cmath>

std::vector<std::pair<int,int>> parseMultPairs(std::string& puzzleInput, bool* mSwitch) {
    std::vector<std::pair<int,int>> pairs;
    std::regex pattern(R"(mul\((\d+),(\d+)\)|don\'t\(\)|do\(\))");
    std::smatch match;

    std::string::const_iterator searchStart(puzzleInput.cbegin());
    while(regex_search(searchStart, puzzleInput.cend(), match, pattern)) {
        std::cout << '[' << match[0] << "," << match[0].length() << ']';

        if(match[0].length() == 7) {

            *mSwitch = false;
            searchStart = match.suffix().first;
            continue;
        }

        if(match[0].length() == 4) {

            *mSwitch = true;
            searchStart = match.suffix().first;
            continue;
        }

        if(*mSwitch) {
            int first = std::stoi(match[1]);
            int secon = std::stoi(match[2]);
            pairs.emplace_back(first, secon);
        }

        searchStart = match.suffix().first;
    }

    return pairs;
}

std::vector<int> multPairs(std::vector<std::pair<int,int>> &pairs) {
    std::vector<int> results;
    for(int i = 0; i < pairs.size(); i++) {
        results.push_back(pairs[i].first * pairs[i].second);
    }
    return results;
}

int addProducts(std::vector<int> &products) {
    return std::accumulate(products.cbegin(), products.cend(), 0);
}

int main() {
  // Create a text string, which is used to output the text file
  std::string myText;
  // Read file
  std::ifstream MyReadFile("PuzzleInput.txt");
  int count = 0;
  bool mSwitch = true;
  auto mSwitchPtr = &mSwitch;
  while (std::getline(MyReadFile, myText)) {
    std::vector<std::pair<int,int>> pairs = parseMultPairs(myText, mSwitchPtr);
    std::vector<int> products = multPairs(pairs);
    int result = addProducts(products);

    std::cout << "Pairs:\n";
    for(const auto& p : pairs) {
        std::cout << "[" << p.first << "," << p.second << "]";
    }
    std::cout << "\nProducts:\n";
    for(const auto& pr : products) {
        std::cout << pr << ",";
    }
    std::cout << "\nResult:\n" << result << "\n";
    count += result;
  }

  std::cout << "Solution: " << count;

  // It is considered good practice, and it can clean up unnecessary memory
  // space.
  MyReadFile.close();
}
