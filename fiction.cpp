#include "fiction.h"
#include "utils.h"

void In(fiction &f, FILE *file) {
    f.name = readString(file);
    f.year = readInt(file);
    f.director = readString(file);
}

void InRandom(fiction &f) {
    f.name = randString(randInt(5, 10));
    f.year = randInt(1950, 2021);
    f.director = randString(randInt(10, 20));
}

void Out(fiction &f, FILE *file) {
    fprintf(file, "Fiction: name = %s, year = %d, director = %s\n", f.name, f.year, f.director);
}

double Quotient(fiction &f) {
    return static_cast<double>(f.year) / static_cast<double>(strlen(f.name));
}
