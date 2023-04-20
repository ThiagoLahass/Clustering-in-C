#ifndef ARESTA_H
#define ARESTA_H

#include "Ponto.h"
#include "Matriz.h"
#include "UnionTree.h"

typedef struct aresta Aresta;

int compareArestas(const void* arg1, const void* arg2);
Aresta* inicializaAresta(Ponto* p1, Ponto* p2, double distancia);
Aresta** inicializaVetorArestas(int tamanho);
void preencheVetorArestas(Aresta** arestas, Matriz* distancias, Ponto** pontos);
void imprimeVetorArestas(Aresta** a, int tamanho);
void destroiVetorArestas(Aresta** a, int tamanho);
void destroiAresta(Aresta* a);
Ponto* getPonto1(Aresta* a);
Ponto* getPonto2(Aresta* a);
double getDistancia(Aresta* a);
void conectaArestas(Aresta** arestas, UnionTree* t, int qtdPontos, int qtdArestas, int k);

#endif // !ARESTA_H