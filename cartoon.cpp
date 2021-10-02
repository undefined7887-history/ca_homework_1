#include "cartoon.h"
#include "utils.h"

void In(cartoon &c, FILE *file) {
    c.name = readString(file);
    c.year = readInt(file);

    char *type = readString(file);

    if (strcmp(type, "draw") == 0) {
        c.t = cartoon::DRAW;
    } else if (strcmp(type, "puppet") == 0) {
        c.t = cartoon::PUPPET;
    } else if (strcmp(type, "plasticine") == 0) {
        c.t = cartoon::PLASTICINE;
    } else {
        c.t = cartoon::DRAW;
    }

    // readString allocates string
    free(type);
}

void InRandom(cartoon &c) {
    c.name = randString(randInt(5, 10));
    c.year = randInt(1950, 2021);

    int type = randInt(0, 2);
    c.t = static_cast<cartoon::type>(type);
}

void Out(cartoon &c, FILE *file) {
    char *type;

    switch (c.t) {
        case cartoon::DRAW:
            type = (char *) "DRAW";
            break;
        case cartoon::PUPPET:
            type = (char *) "PUPPET";
            break;
        case cartoon::PLASTICINE:
            type = (char *) "PLASTICINE";
            break;
    }

    fprintf(file, "Cartoon: name = %s, year = %d, type = %s\n", c.name, c.year, type);
}

double Quotient(cartoon &c) {
    return static_cast<double>(c.year) / static_cast<double>(strlen(c.name));
}
