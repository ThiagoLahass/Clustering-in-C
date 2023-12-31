#include "Aresta.h"

struct aresta { // Conexão entre dois pontos
  Ponto* p1;
  Ponto* p2;
  double distancia; // Distância entre p1 e p2
};


/* Função que será passada ao qsort */
int compareArestas(const void* arg1, const void* arg2) {
  Aresta* a1 = *(Aresta**) arg1;
  Aresta* a2 = *(Aresta**) arg2;

  if (getDistancia(a1) < getDistancia(a2)) return -1;
  else if (getDistancia(a1) > getDistancia(a2)) return 1;
  return 0;
}

Aresta* inicializaAresta(Ponto *p1, Ponto *p2, double distancia) {
  Aresta* a = (Aresta*) malloc(sizeof(Aresta));
  a->p1 = p1;
  a->p2 = p2;
  a->distancia = distancia;
  return a;
}

Aresta** inicializaVetorArestas(int qtdArestas){
  Aresta** a = (Aresta**) malloc(sizeof(Aresta*) * qtdArestas);
  return a;
}

void preencheVetorArestas(Aresta** arestas, int qtdPontos, Ponto** pontos){
  register int i = 0, j = 0, idx = 0;
  register double distAtual;

  for (i = 0; i < qtdPontos; i++) {
    for (j = 0; j < qtdPontos; j++) {
      if (i > j){
        distAtual  = calculaDistanciaEntrePontos(pontos[i], pontos[j]);
        arestas[idx] = inicializaAresta(pontos[i], pontos[j], distAtual);
        idx++;
      }
      else break;
    }
  }
}

void destroiVetorArestas(Aresta** a, int qtdArestas){
  register int i = 0;
  for (i = 0; i < qtdArestas; i++) { destroiAresta(a[i]); }
  free(a);
}

void destroiAresta(Aresta *a) { free(a); }

void conectaArestas(Aresta** arestas, UnionTree* t, int qtdPontos, int qtdArestas, int k) {
  register int i = 0;
  register Ponto* p1, *p2;
  int numConexoes = qtdPontos - k;
  int numConexoesAtual = 0;

  if (numConexoes == 0) return; // Caso em que o número de pontos é igual ao de grupos desejados

  for (i = 0; i < qtdArestas; i++) {
    p1 = getPonto1(arestas[i]);
    p2 = getPonto2(arestas[i]);

    if (UF_find(t,p1) != UF_find(t, p2)) { // Se os pontos não estiverem conectados,
      UF_union(t, p1, p2); // Conecte-os
      numConexoesAtual++;
    }

    if(numConexoesAtual == numConexoes) break;
  }
}

/*GETTERS*/
Ponto* getPonto1(Aresta *a) { return a->p1; }

Ponto* getPonto2(Aresta *a) { return a->p2; }

double getDistancia(Aresta *a) { return a->distancia; }