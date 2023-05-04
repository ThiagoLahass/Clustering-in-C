#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "Ponto.h"

typedef struct unionTree UnionTree;

/// @brief aloca dinamicamente uma unionTree
/// @param tamanho quantos pontos devem ser armazenados
/// @return ponteiro para a estrutura
UnionTree* inicializaUnionTree(int tamanho);

/// @brief conexão de dois pontos - utiliza o wheigted quickUnion com path compression
/// @param t 
/// @param a ponto 1
/// @param b ponto 2
void UF_union(UnionTree* t, Ponto* a, Ponto* b);

/// @brief obtem a componente conexa de um ponto
/// @param t 
/// @param p ponto
/// @return inteiro que identifica a componente conexa
int UF_find(UnionTree* t,Ponto* p);

/// @brief liberação de memória da estrutura
/// @param t 
void destroiUnionTree(UnionTree* t);

#endif // !UNION_FIND_H