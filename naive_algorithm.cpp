#include <iostream>
#include <string>

int naiveStringMatch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            return i; 
    }
    return -1; 
}
int main() {
    std::string text = "Hello, world!";
    std::string pattern = "world";
    int matchIndex = naiveStringMatch(text, pattern);
    if (matchIndex != -1)
        std::cout << "Pattern found at index: " << matchIndex << std::endl;
    else
        std::cout << "Pattern not found." << std::endl;
    return 0;
}
