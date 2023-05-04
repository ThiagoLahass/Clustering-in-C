#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define DELIMITADOR ","

typedef struct ponto Ponto;

Ponto** lePontos(char* nomeArquivoEntrada);
Ponto* inicializaPonto(char* linha, int qtdDimensoes, int identificadorPonto);
void imprimePonto(Ponto* p, FILE* arquivoSaida);
void destroiPonto(Ponto* p);
void destroiPontos(Ponto** pontos);
double calculaDistanciaEntrePontos(Ponto* x, Ponto* y);
int getQtdDimensoes(Ponto* p);
void setQtdDimensoes(Ponto* p, int qtdDimensoes);
char* getNome(Ponto* p);
int getId(Ponto* p);
double* getCoordenadas(Ponto* p);
int getQuantidadePontos(Ponto** p);

#endif // !PONTO_H