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
//void populateArray(const char* filename, int &counterVar, const char* typeRun, const char* arrayName);

int main() {
    int prefixCount = 0;
    int suffixCount = 0;
    countEntries(file1, prefixCount, "prefixes");
    countEntries(file2, suffixCount, "suffixes");
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
    //std::cout << "We are currently looking at a file of " << typeRun << ".\n";
    std::ifstream openFile(filename);
    std::string buffer = ""; // initialize empty string
    while (!openFile.eof()) {
        openFile >> buffer;
        if (openFile.eof())
            break;
        //std::cout << buffer << '\n';
        buffer.clear();
        wordCounter++;
    }
    std::cout << "Commander, we counted " << wordCounter << ' ' << typeRun << ".\n";
}
