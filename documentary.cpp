#include <cstring>
#include "documentary.h"
#include "utils.h"

void In(documentary &d, std::ifstream &stream) {
    std::string name;
    stream >> name >> d.year >> d.duration;

    d.name = copyFromString(name);
}

void InRandom(documentary &d) {
    d.name = randString(randInt(5, 10));
    d.year = randInt(1950, 2021);
    d.duration = randInt(1, 10);
}

void Out(documentary &d, std::ofstream &stream) {
    stream << "Documentary: name = " << d.name << ", year = " << d.year << ", duration = " << d.duration << "\n";
}

double Quotient(documentary &d) {
    return static_cast<double>(d.year) / static_cast<double>(strlen(d.name));
}
