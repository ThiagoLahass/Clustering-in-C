#include "Ponto.h"

struct ponto {
    char* id;
    int* coordenadas;
    int qtdDimensoes;
};

double calculaDistanciaEntrePontos(Ponto* x, Ponto* y) {
    double dist = 0.0;
    int i = 0;
    for (i = 0; i < x->qtdDimensoes; i++) {
        double sub = x->coordenadas[i] - y->coordenadas[i];
        dist += sub * sub;
    }
    return sqrt(dist);
}