#ifndef CA_HOMEWORK_FICTION_H
#define CA_HOMEWORK_FICTION_H

#include <cstdio>
#include <string>

// Fiction is a concrete movie type
struct fiction {
    char *name;
    int year;

    char *director;
};

void In(fiction &f, FILE *file);

void InRandom(fiction &f);

void Out(fiction &f, FILE *file);

double Quotient(fiction &f);

#endif //CA_HOMEWORK_FICTION_H
