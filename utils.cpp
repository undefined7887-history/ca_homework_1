#include <cstring>
#include "utils.h"

void initRand() {
    srand((unsigned) time(nullptr));
}

int randInt(int min, int max) {
    return std::rand() % (max - min + 1) + min;
}

char *randString(int len) {
    static const char numericalAlphabet[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    char *result = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        result[i] = numericalAlphabet[std::rand() % (sizeof(numericalAlphabet) - 1)];
    }

    // Zero terminated string
    result[len] = 0;

    return result;
}

char *copyFromString(std::string &str) {
    // Zero terminated string
    char *result = new char[str.length() + 1];

    std::memcpy(result, str.c_str(), str.length() + 1);

    return result;
}

