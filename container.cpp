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

void In(container &c, std::ifstream &stream) {
    while (!stream.eof()) {
        if ((c.content[c.len] = In(stream)) != nullptr) {
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

void Out(container &c, std::ofstream &stream) {
    stream << "Container contains " << c.len << " elements.\n";

    for (int i = 0; i < c.len; i++) {
        stream << i + 1 << ": ";
        Out(*c.content[i], stream);
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
