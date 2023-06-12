#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
void NaiveSearch(const std::string& text, const std::string& pattern) {
    
    int M = pattern.length();    int N = text.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j])
                break;        }
        if (j == M) {
            std::cout << "Pattern found at index " << i << std::endl;
        }
    }
    
}
int mains() {
    std::ifstream file("strings.txt");
    std::string text;
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
    text.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    std::string pattern = "jF";

    auto start = high_resolution_clock::now();
    NaiveSearch(text, pattern);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
