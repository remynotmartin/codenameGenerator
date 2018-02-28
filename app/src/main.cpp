#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>

const std::string file1("../data/prefixes.txt");
const std::string file2("../data/suffixes.txt");

int main() {
    
    std::ifstream prefixFile(file1);
    if (!prefixFile) {
        std::cerr << "Could not open file '" << file1 << "'\n";
        exit(EXIT_FAILURE);
    }
    std::ifstream suffixFile(file2);
    if (!suffixFile) {
        std::cerr << "Could not open file '" << file2 << "'\n";
        exit(EXIT_FAILURE);
    }
    
    // There are 42 Prefixes and 38 Suffixes
    int prefixCount = 0;
    int suffixCount = 0;

    std::cout << "We counted " << prefixCount <<  " prefixes, commander.\n";
    std::cout << "We counted " << suffixCount <<  " suffixes, commander.\n";

    /*
    std::srand(time(NULL));
    int prefixSeed = rand()%100 + 1;
    int suffixSeed = rand()%100 + 1;
    */
    return 0;

}
