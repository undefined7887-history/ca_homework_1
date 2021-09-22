#include <cstring>
#include "fiction.h"
#include "utils.h"

void In(fiction &f, std::ifstream &stream) {
    std::string name;
    std::string director;

    stream >> name >> f.year >> director;

    f.name = copyFromString(name);
    f.director = copyFromString(director);
}

void InRandom(fiction &f) {
    f.name = randString(randInt(5, 10));
    f.year = randInt(1950, 2021);
    f.director = randString(randInt(10, 20));
}

void Out(fiction &f, std::ofstream &stream) {
    stream << "Fiction: name = " << f.name << ", year = " << f.year << ", director = " << f.director << "\n";
}

double Quotient(fiction &f) {
    return static_cast<double>(f.year) / static_cast<double>(strlen(f.name));
}
