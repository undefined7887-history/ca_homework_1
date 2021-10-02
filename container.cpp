#include "container.h"

void Init(container &c) {
    c.len = 0;
}

void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.content[i];
    }
    c.len = 0;
}

void In(container &c, FILE *file) {
    while (!feof(file)) {
        if ((c.content[c.len] = In(file)) != nullptr) {
            c.len++;
        }
    }
}

void InRandom(container &c, int size) {
    while (c.len < size) {
        if ((c.content[c.len] = InRandom()) != nullptr) {
            c.len++;
        }
    }
}

void Out(container &c, FILE *file) {
    fprintf(file, "Container contains %d elements.\n", c.len);

    for (int i = 0; i < c.len; i++) {
        fprintf(file, "%d: ", i + 1);
        Out(*c.content[i], file);
    }
}

void ShakeSort(container &c) {
    int temp = c.len - 1;

    int left = 0;
    int right = c.len - 1;

    do {
        for (int i = left; i < right; i++) {
            if (Quotient(*c.content[i]) > Quotient(*c.content[i + 1])) {
                std::swap(c.content[i], c.content[i + 1]);
                temp = i;
            }
        }

        right = temp;
        for (int i = right; i > left; i--) {
            if (Quotient(*c.content[i]) < Quotient(*c.content[i - 1])) {
                std::swap(c.content[i], c.content[i - 1]);
                temp = i;
            }
        }

        left = temp;
    } while (left < right);
}
