#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>

const char* file1("../data/prefixes.txt");
const char* file2("../data/suffixes.txt");

//void countEntries(std::ifstream openFile, int counter);
void checkFileOpen(const char* filename);

int main() {
    checkFileOpen(file1);
    checkFileOpen(file2);
    
    // There are 42 Prefixes and 38 Suffixes
    int prefixCount = 0;
    int suffixCount = 0;
    
    //countEntries(prefixFile, prefixCount);
    //countEntries(suffixFile, suffixCount);

    std::cout << "We counted " << prefixCount <<  " prefixes, commander.\n";
    std::cout << "We counted " << suffixCount <<  " suffixes, commander.\n";

    return 0;

}

void checkFileOpen(const char* filename) {
    std::ifstream fileOpen(filename);
    if (!fileOpen) {
        std::cerr << "Could not open file '" << filename << "', please check filename and path.\n";
        exit(EXIT_FAILURE);
    }
}

/*
void countEntries(std::ifstream filename, int wordCounter) {

    std::cout << "Function successfully prototyped! Awaiting further definition.\n";

}
*/
