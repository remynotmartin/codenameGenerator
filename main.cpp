#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

int main() {
    std::srand(time(NULL));
    int prefixSeed = rand()%100 + 1;
    int suffixSeed = rand()%100 + 1;
    return 0;
}
