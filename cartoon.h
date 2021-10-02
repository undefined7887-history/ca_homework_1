#ifndef CA_HOMEWORK_CARTOON_H
#define CA_HOMEWORK_CARTOON_H

#include <cstdio>
#include <string>

// Cartoon is a concrete movie type
struct cartoon {
    char *name;
    int year;

    enum type {
        DRAW, PUPPET, PLASTICINE
    };

    type t;
};

void In(cartoon &c, FILE *file);

void InRandom(cartoon &c);

void Out(cartoon &c, FILE *file);

double Quotient(cartoon &c);

#endif //CA_HOMEWORK_CARTOON_H
