#include <cstring>
#include "cartoon.h"
#include "utils.h"

void In(cartoon &c, std::ifstream &stream) {
    std::string name;
    stream >> name >> c.year;

    c.name = copyFromString(name);

    std::string type;
    stream >> type;

    if (type == "draw") {
        c.t = cartoon::DRAW;
    } else if (type == "puppet") {
        c.t = cartoon::PUPPET;
    } else if (type == "plasticine") {
        c.t = cartoon::PLASTICINE;
    } else {
        c.t = cartoon::DRAW;
    }
}

void InRandom(cartoon &c) {
    c.name = randString(randInt(5, 10));
    c.year = randInt(1950, 2021);

    int type = randInt(0, 2);
    c.t = static_cast<cartoon::type>(type);
}

void Out(cartoon &c, std::ofstream &stream) {
    std::string type;

    switch (c.t) {
        case cartoon::DRAW:
            type = "DRAW";
            break;
        case cartoon::PUPPET:
            type = "PUPPET";
            break;
        case cartoon::PLASTICINE:
            type = "PLASTICINE";
            break;
    }

    stream << "Cartoon: name = " << c.name << ", year = " << c.year << ", type = " << type << "\n";
}

double Quotient(cartoon &c) {
    return static_cast<double>(c.year) / static_cast<double>(strlen(c.name));
}
