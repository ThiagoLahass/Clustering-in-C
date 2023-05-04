#include "UnionTree.h"

struct unionTree {
    int* tree;
    int* size;
};

/// @brief aloca dinamicamente uma unionTree
/// @param tamanho quantos pontos devem ser armazenados
/// @return ponteiro para a estrutura
UnionTree* inicializaUnionTree(int tamanho) {
    register int i = 0;
    UnionTree* t = malloc(sizeof(UnionTree));
    t->tree = malloc(tamanho * sizeof(int));
    t->size = malloc(tamanho * sizeof(int));
    
    for (i = 0; i < tamanho; i++) {
        t->tree[i] = i;
        t->size[i] = 1;
    }
    return t;
}


/// @brief conexão de dois pontos - utiliza o wheigted quickUnion com path compression
/// @param t 
/// @param a ponto 1
/// @param b ponto 2
void UF_union(UnionTree* t, Ponto* a, Ponto* b) {
    int i = UF_find(t, a);
    int j = UF_find(t, b);

    if(i == j) return;

    if (t->size[i] < t->size[j]) {
        t->tree[i] = j;
        t->size[j] += t->size[i];
    } else {
        t->tree[j] = i;
        t->size[i] += t->size[j];
    }
}


/// @brief obtem a componente conexa de um ponto
/// @param t 
/// @param p ponto
/// @return inteiro que identifica a componente conexa
int UF_find(UnionTree* t,Ponto* p) {
    int componente = getId(p);
    while (componente != t->tree[componente]){
        t->tree[componente] = t->tree[t->tree[componente]];
        componente = t->tree[componente];
    }
    return componente;  
}

void imprimeUnionTree(UnionTree* t, Ponto** pontos,int tamanho) {
    register int i = 0, contador = 0;
    for (i = 0; i < tamanho; i++) {
        printf("%d -> %s\n", UF_find(t, pontos[i]), getNome(pontos[i]));
        contador++;
    }
}

/// @brief liberação de memória da estrutura
/// @param t 
void destroiUnionTree(UnionTree* t){
    free(t->size);
    free(t->tree);
    free(t);
}