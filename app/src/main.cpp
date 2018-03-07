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
void countEntries(const char* filename, int &counter, const char* typeRun);
void clearArray (char* arrayName, const int arraySize); 
void clearArray (char** arrayName, const int arraySize); 
void populateArray(const char* filename, const int counter, char** arrayName);
void generateCodename(char** const pArray, char** const sArray, const int pCount, const int sCount);

int main() {
    int prefixCount = 0, suffixCount = 0;
    countEntries(file1, prefixCount, wordType1);
    countEntries(file2, suffixCount, wordType2); 
    char* prefixArray[prefixCount];
    char* suffixArray[suffixCount];
    clearArray(prefixArray, prefixCount);
    clearArray(suffixArray, suffixCount);
    populateArray(file1, prefixCount, prefixArray);
    populateArray(file2, suffixCount, suffixArray);
    generateCodename(prefixArray, suffixArray, prefixCount, suffixCount);
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

void populateArray(const char* filename, const int counterVar, char** arrayName) {
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
    for (int i = 0; i < counterVar; i++) {
        std::cout << arrayName[i] << '\n'; 
    }
    openFile.close();
}

// The arrays will be accessed, but I don't want any of the elements to be changed by accident.
void generateCodename(char** const pArray, char** const sArray, const int pCount, const int sCount) {
    srand(time(NULL)); // Seeds the PRNG
    int pChoice = rand() % pCount;
    int sChoice = rand() % sCount;
    std::cout << pArray[pChoice] << '\n';
    std::cout << sArray[sChoice] << '\n';
}
