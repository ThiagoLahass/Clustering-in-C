#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "Ponto.h"

typedef struct unionTree UnionTree;

UnionTree* inicializaUnionTree(int tamanho);
void UF_union(UnionTree* t, Ponto* a, Ponto* b);
int UF_find(UnionTree* t,Ponto* p);
void destroiUnionTree(UnionTree* t);

#endif // !UNION_FIND_H