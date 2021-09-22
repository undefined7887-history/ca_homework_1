#ifndef CA_HOMEWORK_FICTION_H
#define CA_HOMEWORK_FICTION_H

#include <fstream>
#include <string>

struct fiction {
    char *name;
    int year;

    char *director;
};

void In(fiction &f, std::ifstream &stream);

void InRandom(fiction &f);

void Out(fiction &f, std::ofstream &stream);

double Quotient(fiction &f);

#endif //CA_HOMEWORK_FICTION_H
