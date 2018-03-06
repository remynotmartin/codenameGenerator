#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>

const char* file1("../data/prefixes.txt");
const char* file2("../data/suffixes.txt");

void checkFileOpen(const char* filename);
void countEntries(const char* filename, int &counterVar, const char* typeRun); // There are 42 Prefixes and 38 Suffixes
void populateArray();

int main() {
    checkFileOpen(file1);
    checkFileOpen(file2);
    int prefixCount = 0;
    int suffixCount = 0;
    countEntries(file1, prefixCount, "prefixes");
    countEntries(file2, suffixCount, "suffixes");
    return 0;
}

void checkFileOpen(const char* filename) {
    std::ifstream fileOpen(filename);
    if (!fileOpen) {
        std::cerr << "Could not open file '" << filename << "', please check filename and path.\n";
        exit(EXIT_FAILURE);
    }
}

void countEntries(const char* filename, int &wordCounter, const char* typeRun) {
    std::cout << "Function successfully prototyped!\n";
    std::cout << "We are currently looking at a file full of " << typeRun << ".\n";
}
