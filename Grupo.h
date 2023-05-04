#ifndef GRUPO_H
#define GRUPO_H

#include "Ponto.h"
#include "UnionTree.h"

typedef struct grupo Grupo;

/// @brief Inicializa um grupo dinamicamente
/// @param qtdPontosGrupo Número de pontos do grupo
/// @param idGrupo Identificador do grupo
/// @return Ponteiro para a estrutura alocada
Grupo *inicializaGrupo( int qtdPontosGrupo, int idGrupo);

/// @brief Inicializa um vetor de grupos dinamicamente
/// @param qtdGrupos Quantia de grupos
/// @param qtdPontos Quantia de pontos
/// @param t Estrutura com a informação das conexões de pontos
/// @param pontos Conjunto de pontos
/// @return Ponteiro para o início do vetor
Grupo** inicializaVetorGrupos( int qtdGrupos, int qtdPontos, UnionTree* t, Ponto** pontos );

/// @brief Preenche cada grupo com seus respectivos pontos
/// @param grupos vetor de grupos
/// @param qtdGrupos quantidade total de grupos
/// @param t 
/// @param pontos vetor de pontos
/// @param qtdPontos quantidade total de pontos
void preencheVetorGrupos(Grupo**grupos, int qtdGrupos, UnionTree* t, Ponto** pontos, int qtdPontos );

/// @brief Adiciona um ponto a um grupo
/// @param g 
/// @param p 
void addPontoGrupo(Grupo* g, Ponto* p);

/// @brief Liberação de memória de um grupo
/// @param g 
void destroiGrupo(Grupo *g);

/// @brief Liberação de memória de um vetor de grupos
/// @param grupos 
/// @param qtdGrupos 
void destroiGrupos(Grupo **grupos, int qtdGrupos);

/// @brief Realiza a ordenação dos pontos de um grupo (QuickSort)
/// @param g 
void ordenaPontosDoGrupo(Grupo *g);

/// @brief Realiza a ordenação dos grupos (QuickSort)
/// @param grupos 
/// @param qtdGrupos 
void ordenaTodosGrupos(Grupo** grupos, int qtdGrupos);

void imprimeGrupo(Grupo *g, FILE* arquivoSaida);

void imprimeGrupos(Grupo**  grupos, int qtdGrupos, FILE* arquivoSaida);


/*GETTERS*/


Ponto **getPontos(Grupo *g);

int getQtdPontos(Grupo *g);

int getQtdPontosAtual(Grupo *g);

int getIdGrupo(Grupo *g);


#endif // !GRUPO_H