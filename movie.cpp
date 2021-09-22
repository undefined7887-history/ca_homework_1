#include "movie.h"
#include "utils.h"

movie *In(std::ifstream &stream) {
    movie *mov;

    int movieType;
    stream >> movieType;

    switch (movieType) {
        case 1:
            mov = new movie;
            mov->type = movie::FICTION;
            In(mov->fic, stream);
            return mov;

        case 2:
            mov = new movie;
            mov->type = movie::CARTOON;
            In(mov->car, stream);
            return mov;

        case 3:
            mov = new movie;
            mov->type = movie::DOCUMENTARY;
            In(mov->doc, stream);
            return mov;

        default:
            return nullptr;
    }
}

movie *InRandom() {
    movie *mov;

    int movieType = randInt(1, 3);

    switch (movieType) {
        case 1:
            mov = new movie;
            mov->type = movie::FICTION;
            InRandom(mov->fic);
            return mov;

        case 2:
            mov = new movie;
            mov->type = movie::CARTOON;
            InRandom(mov->car);
            return mov;

        case 3:
            mov = new movie;
            mov->type = movie::DOCUMENTARY;
            InRandom(mov->doc);
            return mov;

        default:
            return nullptr;
    }
}

void Out(movie &m, std::ofstream &stream) {
    switch (m.type) {
        case movie::FICTION:
            Out(m.fic, stream);
            break;
        case movie::CARTOON:
            Out(m.car, stream);
            break;
        case movie::DOCUMENTARY:
            Out(m.doc, stream);
            break;

        default:
            stream << "Incorrect movie!\n";
    }
}

double Quotient(movie &m) {
    switch (m.type) {
        case movie::FICTION:
            return Quotient(m.fic);
        case movie::CARTOON:
            return Quotient(m.car);
        case movie::DOCUMENTARY:
            return Quotient(m.doc);

        default:
            return 0;
    }
}
