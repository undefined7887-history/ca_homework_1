#include <cstdio>
#include <cstring>
#include "utils.h"
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage3(int size) {
    printf("incorrect number of items = %d. Set 0 < number <= 10000\n", size);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c = {};
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        FILE *file = fopen(argv[2], "rw");
        In(c, file);

        fclose(file);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);

        if ((size < 1) || (size > 10000)) {
            errMessage3(size);
            return 3;
        }

        InRandom(c, size);
    } else {
        errMessage2();
        return 2;
    }

    FILE *outFile1 = fopen(argv[3], "w+");
    fprintf(outFile1, "Input container:\n");
    Out(c, outFile1);

    FILE *outFile2 = fopen(argv[4], "w+");
    ShakeSort(c);
    fprintf(outFile2, "Sorted container:\n");
    Out(c, outFile2);

    Clear(c);
    fclose(outFile1);
    fclose(outFile2);

    printf("Stop\n");
    return 0;
}
