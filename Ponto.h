#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define NUM_INICIAL_DIMENSOES 10
#define DELIMITADOR ","

typedef struct ponto Ponto;

Ponto** lePontos(char* nomeArquivoEntrada);
Ponto* inicializaPonto(char* linha);
void imprimePontos(Ponto** pontos);
void destroiPontos(Ponto** pontos);
double calculaDistanciaEntrePontos(Ponto* x, Ponto* y);
int getQtdDimensoes(Ponto* p);
void setQtdDimensoes(Ponto* p, int qtdDimensoes);
char* getId(Ponto* p);
int* getCoordenadas(Ponto* p);

#endif // !PONTO_H