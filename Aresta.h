#ifndef ARESTA_H
#define ARESTA_H

#include "Ponto.h"
#include "UnionTree.h"

typedef struct aresta Aresta;

/// @brief comparação entre duas arestas utilizando as distâncias que deve ser repassado ao qsort
/// @param arg1 
/// @param arg2 
/// @return inteiro que representa o resultado da comparação
int compareArestas(const void* arg1, const void* arg2);

/// @brief inicializa dinamicamente uma aresta
/// @param p1 
/// @param p2 
/// @param distancia 
/// @return ponteiro para a aresta
Aresta* inicializaAresta(Ponto* p1, Ponto* p2, double distancia);

/// @brief inicializa dinamicamente um vetor de arestas
/// @param qtdArestas 
/// @return ponteiro para o início do vetor
Aresta** inicializaVetorArestas(int tamanho);


/// @brief Cada aresta do vetor de arestas recebe a distancia entre os pontos da aresta
/// @param arestas vetor de arestas
/// @param qtdPontos quantidade total de pontos
/// @param pontos vetor de pontos
void preencheVetorArestas(Aresta** arestas, int qtdPontos, Ponto** pontos);

/// @brief Utiliza o algoritmo de union-find para conectar arestas para gerar k número de grupos
/// @param arestas Vetor de arestas já ordenadas
/// @param t 
/// @param qtdPontos 
/// @param qtdArestas 
/// @param k número de grupos obtidos na linha de comando
void conectaArestas(Aresta** arestas, UnionTree* t, int qtdPontos, int qtdArestas, int k);

/// @brief liberação de memória do vetor de arestas
/// @param a 
/// @param qtdArestas 
void destroiVetorArestas(Aresta** a, int tamanho);

/// @brief liberação de memória de uma aresta
/// @param a 
void destroiAresta(Aresta* a);

/* GETTERS */
Ponto* getPonto1(Aresta* a);
Ponto* getPonto2(Aresta* a);
double getDistancia(Aresta* a);

#endif // !ARESTA_H