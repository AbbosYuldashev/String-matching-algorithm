#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_map> 

using namespace std;
using namespace std::chrono;

void computeBadCharacterTable(const std::string& pattern, std::unordered_map<char, int>& badCharTable) {
    int m = pattern.length();
    for (int i = 0; i < m; i++) {
        badCharTable[pattern[i]] = i;
    }
}

void BoyerMooreSearch(const std::string& text, const std::string& pattern) {
    
    int n = text.length();
    int m = pattern.length();

    std::unordered_map<char, int> badCharTable;
    computeBadCharacterTable(pattern, badCharTable);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            std::cout << "Pattern found at index " << shift << std::endl;
            shift += (shift + m < n) ? m - badCharTable[text[shift + m]] : 1;
        } else {
            int badCharShift = j - badCharTable[text[shift + j]];
            shift += std::max(1, badCharShift);
        }
    }
    
}

int mainss() {
    std::ifstream file("strings.txt");
    std::string text;

    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    text.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

    std::string pattern = "jF";

    auto start = high_resolution_clock::now();
    BoyerMooreSearch(text, pattern);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    return 0;
}
