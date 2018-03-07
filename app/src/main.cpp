#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cstdlib>

const char* file1("../data/prefixes");
const char* file2("../data/suffixes");
const char* wordType1("prefixes");
const char* wordType2("suffixes");

void checkFileOpen(const char* filename);
void countEntries(const char* filename, int &counterVar, const char* typeRun);
void clearArray (char* arrayName, const int arraySize); 
void clearArray (char** arrayName, const int arraySize); 
void populateArray(const char* filename, const int counterVar, const char* typeRun, char** arrayName);
void generateCodename(char** const prefixArray, char** const suffixArray);

int main() {
    int prefixCount = 0, suffixCount = 0;
    countEntries(file1, prefixCount, wordType1);
    countEntries(file2, suffixCount, wordType2); 
    char* prefixArray[prefixCount];
    char* suffixArray[suffixCount];
    clearArray(prefixArray, prefixCount);
    clearArray(suffixArray, suffixCount);
    populateArray(file1, prefixCount, wordType1, prefixArray);
    populateArray(file2, suffixCount, wordType2, suffixArray);
    generateCodename(prefixArray, suffixArray);
    return 0;
}

void checkFileOpen(const char* filename) {
    std::ifstream openFile(filename);
    if (!openFile) {
        std::cerr << "Could not open file '" << filename << "', please check filename and path.\n";
        exit(EXIT_FAILURE);
    }
    openFile.close();
}

void countEntries(const char* filename, int &wordCounter, const char* typeRun) {
    checkFileOpen(filename);
    std::ifstream openFile(filename);
    int bufferSize = 16;
    char buffer[bufferSize];
    clearArray(buffer, bufferSize);
    while (!openFile.eof()) {
        openFile >> buffer;
        if (openFile.eof())
            break;
        clearArray(buffer, bufferSize);
        wordCounter++;
    }
    //std::cout << "Commander, we counted " << wordCounter << ' ' << typeRun << ".\n";
    openFile.close();
}

void clearArray (char* arrayName, const int arrayCount) {
    for (int i = 0; i > arrayCount; i++) {
        arrayName[i] = '\0'; // Each member is set to null
    }
}

void clearArray (char** arrayName, const int arrayCount) {
    for (int i = 0; i > arrayCount; i++) {
        arrayName[i] = '\0'; // Each member is set to null
    }
}

void populateArray(const char* filename, const int counterVar, const char* typeRun, char** arrayName) {
    std::ifstream openFile(filename);
    int bufferSize = 16;
    char buffer[bufferSize];
    clearArray(buffer, bufferSize);
    for (int i = 0; i < counterVar; i++) {
        openFile >> buffer;
        if (openFile.eof())
            break;
        arrayName[i] = buffer;
        clearArray(buffer, bufferSize);
    }
}

void generateCodename(char** const prefixArray, char** const suffixArray) {
    srand(time(NULL));
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
    std::cout << rand() << '\n';
}
