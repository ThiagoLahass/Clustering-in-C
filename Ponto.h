#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define DELIMITADOR ","

typedef struct ponto Ponto;

/// @brief Obtém os pontos de um arquivo de entrada
/// @param nomeArquivoEntrada 
/// @return Vetor com todos os pontos do arquivo
Ponto** lePontos(char* nomeArquivoEntrada);

/// @brief Dadas as informações de um ponto, aloca-o dinamicamente
/// @param linha 
/// @param qtdDimensoes número de dimensões do ponto
/// @param identificadorPonto id para individualizar o ponto
/// @return Ponteiro para a estrutura criada
Ponto* inicializaPonto(char* linha, int qtdDimensoes, int identificadorPonto);



/// @brief Liberação de memória de um ponto
/// @param p 
void destroiPonto(Ponto* p);

/// @brief Liberação de memória de um vetor de pontos
/// @param pontos 
void destroiPontos(Ponto** pontos);

/// @brief Dados dois pontos, calcula a distância euclidiana entre eles
/// @param x 
/// @param y 
/// @return distancia entre os pontos
double calculaDistanciaEntrePontos(Ponto* x, Ponto* y);


void imprimePonto(Ponto* p, FILE* arquivoSaida);

/*GETTERS E SETTER*/

int getQtdDimensoes(Ponto* p);


void setQtdDimensoes(Ponto* p, int qtdDimensoes);


char* getNome(Ponto* p);


int getId(Ponto* p);


double* getCoordenadas(Ponto* p);


int getQuantidadePontos(Ponto** p);



#endif // !PONTO_H