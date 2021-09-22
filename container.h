#ifndef CA_HOMEWORK_CONTAINER_H
#define CA_HOMEWORK_CONTAINER_H

#include "movie.h"

struct container {
    enum {
        max_len = 10000
    };
    int len;
    movie *content[max_len];
};


void Init(container &c);

void Clear(container &c);

void In(container &c, std::ifstream &stream);

void InRandom(container &c, int size);

void Out(container &c, std::ofstream &stream);

void ShakeSort(container &c);

#endif //CA_HOMEWORK_CONTAINER_H
