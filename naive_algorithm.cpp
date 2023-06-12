#include <iostream>#include <fstream>
#include <string>#include <chrono>
void NaiveSearch(const std::string& text, const std::string& pattern) {
    int M = pattern.length();    int N = text.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {            if (text[i + j] != pattern[j])
                break;        }
        if (j == M) {
            std::cout << "Pattern found at index " << i << std::endl;        }
    }}
int main() {
    std::ifstream file("strings.txt");    std::string text;
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;        return 1;
    }
    text.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    std::string pattern = "DcoCtUkT4m";
    auto start = std::chrono::high_resolution_clock::now();    NaiveSearch(text, pattern);
    auto end = std::chrono::high_resolution_clock::now();    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " nanoseconds" << std::endl;
    return 0;
}
