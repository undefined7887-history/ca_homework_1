#ifndef CA_HOMEWORK_MOVIE_H
#define CA_HOMEWORK_MOVIE_H

#include "fiction.h"
#include "cartoon.h"
#include "documentary.h"

struct movie {
    enum type {FICTION, CARTOON, DOCUMENTARY};
    type type;

    union {
        fiction fic;
        cartoon car;
        documentary doc;
    };
};

movie *In(std::ifstream &stream);

movie *InRandom();

void Out(movie &m, std::ofstream &stream);

double Quotient(movie &m);

#endif //CA_HOMEWORK_MOVIE_H
