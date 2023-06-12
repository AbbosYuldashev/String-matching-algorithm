#include <iostream> 
#include <fstream> 
#include <random> 
#include <string> 
 
std::string generateRandomString(int length) 
{ 
    static const char alphanum[] = 
        "0123456789" 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ" 
        "abcdefghijklmnopqrstuvwxyz"; 
 
    std::random_device rd; 
    std::mt19937 generator(rd()); 
    std::uniform_int_distribution<> distribution(0, sizeof(alphanum) - 2); 
 
    std::string randomString; 
    randomString.reserve(length); 
    for (int i = 0; i < length; ++i) { 
        randomString += alphanum[distribution(generator)]; 
    } 
    randomString += " "; 
 
    return randomString; 
} 
 
int main() 
{ 
    std::ofstream outputFile("strings.txt"); 
    if (!outputFile) { 
        std::cerr << "Failed to create the output file." << std::endl; 
        return 1; 
    } 
 
    const int numStrings = 500; 
    const int maxLength = 10;  
 
    std::random_device rd; 
    std::mt19937 generator(rd()); 
    std::uniform_int_distribution<> distribution(1, maxLength); 
 
    for (int i = 0; i < numStrings; ++i) { 
        int length = distribution(generator); 
        std::string randomString = generateRandomString(length); 
        outputFile << randomString; 
    } 
 
    outputFile.close(); 
    std::cout << "File 'strings.txt' created successfully." << std::endl; 
 
    return 0; 
}
