#include "union-find.h"

struct unionTree {
    int* tree;
    int* size;
};

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

/* Wheigted quick union */
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

/* Quick union com compressão de caminho */
int UF_find(UnionTree* t,Ponto* p) {
    int componente = getId(p);
    while (componente != t->tree[componente]){
        t->tree[componente] = t->tree[t->tree[componente]];
        componente = t->tree[componente];
    }
    return componente;  
}

int getIdIndexUnionTree( UnionTree* t, Ponto* p) { return UF_find(t, p); }

void imprimeUnionTree(UnionTree* t, Ponto** pontos,int tamanho) {
    register int i = 0, contador = 0;
    for (i = 0; i < tamanho; i++) {
        printf("%d -> %s\n", UF_find(t, pontos[i]), getNome(pontos[i]));
        contador++;
    }
}

void destroiUnionTree(UnionTree* t){
    free(t->size);
    free(t->tree);
    free(t);
}