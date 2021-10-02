#include "movie.h"
#include "utils.h"

movie *In(FILE *file) {
    movie *mov;

    int movieType;
    fscanf(file, "%d", &movieType);

    switch (movieType) {
        case 1:
            mov = new movie;
            mov->type = movie::FICTION;
            In(mov->fic, file);
            return mov;

        case 2:
            mov = new movie;
            mov->type = movie::CARTOON;
            In(mov->car, file);
            return mov;

        case 3:
            mov = new movie;
            mov->type = movie::DOCUMENTARY;
            In(mov->doc, file);
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

void Out(movie &m, FILE *file) {
    switch (m.type) {
        case movie::FICTION:
            Out(m.fic, file);
            break;
        case movie::CARTOON:
            Out(m.car, file);
            break;
        case movie::DOCUMENTARY:
            Out(m.doc, file);
            break;

        default:
            printf("Incorrect movie!\n");
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
