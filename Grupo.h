#ifndef GRUPO_H
#define GRUPO_H

#include "Ponto.h"
#include "UnionTree.h"

typedef struct grupo Grupo;

Grupo *inicializaGrupo( int qtdPontosGrupo, int idGrupo);
Grupo** inicializaVetorGrupos( int qtdGrupos, int qtdPontos, UnionTree* t, Ponto** pontos );
void preencheVetorGrupos(Grupo**grupos, int qtdGrupos, UnionTree* t, Ponto** pontos, int qtdPontos );
void addPontoGrupo(Grupo* g, Ponto* p);
void destroiGrupo(Grupo *g);
void destroiGrupos(Grupo **grupos, int qtdGrupos);
void imprimeGrupo(Grupo *g, FILE* arquivoSaida);
void imprimeGrupos(Grupo**  grupos, int qtdGrupos, FILE* arquivoSaida);
Ponto **getPontos(Grupo *g);
int getQtdPontos(Grupo *g);
int getQtdPontosAtual(Grupo *g);
int getIdGrupo(Grupo *g);
void ordenaPontosDoGrupo(Grupo *g);
void ordenaTodosGrupos(Grupo** grupos, int qtdGrupos);

#endif // !GRUPO_H