#ifndef CA_HOMEWORK_DOCUMENTARY_H
#define CA_HOMEWORK_DOCUMENTARY_H

#include <cstdio>
#include <string>

// Documentary is a concrete movie type
struct documentary {
    char *name;
    int year;

    int duration;
};

void In(documentary &d, FILE *file);

void InRandom(documentary &d);

void Out(documentary &d, FILE *file);

double Quotient(documentary &d);

#endif //CA_HOMEWORK_DOCUMENTARY_H
