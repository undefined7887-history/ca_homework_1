#ifndef CA_HOMEWORK_CARTOON_H
#define CA_HOMEWORK_CARTOON_H
#include <fstream>
#include <string>

struct cartoon {
    char *name;
    int year;

    enum type {
        DRAW, PUPPET, PLASTICINE
    };

    type t;
};

void In(cartoon &c, std::ifstream &stream);

void InRandom(cartoon &c);

void Out(cartoon &c, std::ofstream &stream);

double Quotient(cartoon &c);

#endif //CA_HOMEWORK_CARTOON_H
