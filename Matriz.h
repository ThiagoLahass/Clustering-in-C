#ifndef MATRIZ_H
#define MATRIZ_H

#include "Ponto.h"

typedef struct matriz Matriz;

Matriz* inicializaMatriz(int qtdPontos);

int preencheMatriz(Matriz* m, Ponto** pontos); //retorna a quantidade de pares únicos

void imprimeMatrizRelevante(Matriz* m);


int get_TamanhoMatriz(Matriz* m);

double getConteudoMatriz(Matriz* m, int linha, int coluna);

void destroiMatriz(Matriz* m);

#endif