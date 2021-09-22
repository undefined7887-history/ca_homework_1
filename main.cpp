#include <iostream>
#include <cstring>
#include "utils.h"
#include "container.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void errMessage3(int size) {
    std::cout << "incorrect number of items = "
              << size
              << ". Set 0 < number <= 10000\n";
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    std::cout << "Start" << std::endl;
    container c{};
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        std::ifstream inStream(argv[2]);
        In(c, inStream);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = std::atoi(argv[2]);

        if ((size < 1) || (size > 10000)) {
            errMessage3(size);
            return 3;
        }

        InRandom(c, size);
    } else {
        errMessage2();
        return 2;
    }

    std::ofstream outStream1(argv[3]);
    outStream1 << "Input container:\n";
    Out(c, outStream1);

    std::ofstream outStream2(argv[4]);
    ShakeSort(c);
    outStream2 << "Sorted container:\n";
    Out(c, outStream2);

    Clear(c);
    std::cout << "Stop" << std::endl;
    return 0;
}
