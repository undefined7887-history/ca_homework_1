#ifndef CA_HOMEWORK_DOCUMENTARY_H
#define CA_HOMEWORK_DOCUMENTARY_H

#include <fstream>
#include <string>

struct documentary {
    char *name;
    int year;

    int duration;
};

void In(documentary &d, std::ifstream &stream);

void InRandom(documentary &d);

void Out(documentary &d, std::ofstream &stream);

double Quotient(documentary &d);

#endif //CA_HOMEWORK_DOCUMENTARY_H
