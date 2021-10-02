#ifndef CA_HOMEWORK_MOVIE_H
#define CA_HOMEWORK_MOVIE_H

#include <cstdio>
#include "fiction.h"
#include "cartoon.h"
#include "documentary.h"

// Movie describes generic movie type
struct movie {
    enum type {
        FICTION, CARTOON, DOCUMENTARY
    };
    type type;

    union {
        fiction fic;
        cartoon car;
        documentary doc;
    };
};

// In() creates movie from a file
movie *In(FILE *file);

// InRandom() creates random movie
movie *InRandom();

// Out() creates random movie
void Out(movie &m, FILE *file);

// Quotient() returns value calculated by: movie.year / len(movie.name)
double Quotient(movie &m);

#endif //CA_HOMEWORK_MOVIE_H
