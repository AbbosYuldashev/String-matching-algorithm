#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

std::vector<int> computeLPSArray(const std::string& pattern) {
    std::vector<int> lps(pattern.length(), 0);
    int len = 0;
    int i = 1;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(const std::string& text, const std::string& pattern) {
    
    int M = pattern.length();
    int N = text.length();

    std::vector<int> lps = computeLPSArray(pattern);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            std::cout << "Pattern found at index " << (i - j) << std::endl;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
}

int main() {

    std::ifstream file("strings.txt");
    std::string text;

    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    text.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

    std::string pattern = "jF";

    auto start = high_resolution_clock::now();
    KMPSearch(text, pattern);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;



    return 0;
}
