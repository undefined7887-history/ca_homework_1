#include "documentary.h"
#include "utils.h"

void In(documentary &d, FILE *file) {
    d.name = readString(file);
    d.year = readInt(file);
    d.duration = readInt(file);
}

void InRandom(documentary &d) {
    d.name = randString(randInt(5, 10));
    d.year = randInt(1950, 2021);
    d.duration = randInt(1, 10);
}

void Out(documentary &d, FILE *file) {
    fprintf(file, "Documentary: name = %s, year = %d, duration = %d\n", d.name, d.year, d.duration);
}

double Quotient(documentary &d) {
    return static_cast<double>(d.year) / static_cast<double>(strlen(d.name));
}
