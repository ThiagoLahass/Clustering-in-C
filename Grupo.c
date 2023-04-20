#include "Grupo.h"

struct grupo { // Conjunto de pontos
  Ponto** pontos;
  int qtdPontos;
  int qtdPontosAtual;
  int id; // Mesmo id que os pontos que os pontos contidos no grupo
};

/* Função que será passada ao qsort pontos */ 
int comparePontos(const void* arg1, const void* arg2) {
  Ponto* p1 = *(Ponto**) arg1;
  Ponto* p2 = *(Ponto**) arg2;
  return strcmp(getNome(p1), getNome(p2));
}

/* Função que será passada ao qsort grupos */
int compareGrupos(const void* arg1, const void* arg2) {
  Grupo* g1 = *(Grupo**) arg1;
  Grupo* g2 = *(Grupo**) arg2;
  return strcmp(getNome(g1->pontos[0]), getNome(g2->pontos[0]));
}

Grupo *inicializaGrupo( int qtdPontosGrupo, int idGrupo) {
  Grupo *g = (Grupo*) malloc(sizeof(Grupo));
  Ponto** ps = (Ponto**) calloc( qtdPontosGrupo, sizeof(Ponto*));
  g->pontos = ps;
  g->qtdPontos = qtdPontosGrupo;
  g->qtdPontosAtual = 0;
  g->id = idGrupo;
  return g;
}

Grupo** inicializaVetorGrupos( int qtdGrupos, int qtdPontos, UnionTree* t, Ponto** pontos ) {
  int idsGrupos[qtdGrupos]; // Vetor para salvar os ids unicos encontrados
  int qtdPontosGrupo[qtdGrupos]; // Vetor para salvar a quantidade de pontos de cada grupo
  int contador = 0; // Contador para acompanhar o número de ids únicos encontrados
  int i = 0;

  // "zerar" os vetores auxiliares
  for (i = 0; i < qtdGrupos; i++ ) {
    idsGrupos[i] = -1; // -1 pois não existe id -1
    qtdPontosGrupo[i] = 0;
  }

  for (i = 0; i < qtdPontos; i++ ) {
    int valorAtual = getIdIndexUnionTree(t, pontos[i]);
    int idJaAdicionado = 0; // Flag para verificar se o valor já foi adicionado ao novo vetor

    // Verifica se o valor já foi adicionado ao novo vetor
    for (int j = 0; j < contador; j++) {
      if (idsGrupos[j] == valorAtual) {
        qtdPontosGrupo[j] ++;
        idJaAdicionado = 1;
        break;
      }
    }

    // Se o valor ainda não foi adicionado ao novo vetor, adiciona-o
    if (!idJaAdicionado) {
      idsGrupos[contador] = valorAtual;
      qtdPontosGrupo[contador] ++;
      contador++;
    }
  }

  Grupo** grupos = (Grupo**) calloc(qtdGrupos, sizeof(Grupo*));

  for (i = 0; i < qtdGrupos; i++) {
    grupos[i] = inicializaGrupo(qtdPontosGrupo[i], idsGrupos[i]);
  }

  return grupos;
}

void preencheVetorGrupos(Grupo**grupos, int qtdGrupos, UnionTree* t, Ponto** pontos, int qtdPontos) {
  int i = 0, j = 0;
  for (i = 0; i < qtdPontos; i++ ) {
    for (j = 0; j < qtdGrupos; j++ ) {
      // Verifica se o ponto pertence ao grupo
      if (getIdIndexUnionTree(t, pontos[i]) == getIdGrupo(grupos[j])) {
        addPontoGrupo(grupos[j], pontos[i]);
        break;
      }
    }
  }
}

void addPontoGrupo(Grupo* g, Ponto* p) {
  g->pontos[g->qtdPontosAtual] = p;
  g->qtdPontosAtual++;
}

void destroiGrupo(Grupo *g) {
  free(g->pontos);
  free(g);
}

void destroiGrupos(Grupo **grupos, int qtdGrupos) {
  int i = 0;
  for (i = 0; i < qtdGrupos; i++) { destroiGrupo(grupos[i]); }
  free(grupos);
}

void imprimeGrupo(Grupo *g, FILE* arquivoSaida) {
  int i = 0;
  for (i = 0; i < g->qtdPontos; i++) {
    imprimePonto(g->pontos[i], arquivoSaida);
    if (i < g->qtdPontos - 1) { fprintf(arquivoSaida, ", "); }
  }  
}

void imprimeGrupos(Grupo**  grupos, int qtdGrupos, FILE* arquivoSaida) {
  int i = 0;
  for(i = 0; i < qtdGrupos; i++){
    imprimeGrupo(grupos[i], arquivoSaida);
    if( i < qtdGrupos - 1) { fprintf(arquivoSaida, "\n"); }
  }
}

Ponto **getPontos(Grupo *g) { return g->pontos; }

int getQtdPontos(Grupo *g) { return g->qtdPontos; }

int getQtdPontosAtual(Grupo *g) { return g->qtdPontosAtual; }

int getIdGrupo(Grupo *g) { return g->id; }

void ordenaPontosDoGrupo(Grupo *g) {
  qsort(g->pontos, g->qtdPontos, sizeof(Ponto*), comparePontos);
}

void ordenaTodosGrupos(Grupo** grupos, int qtdGrupos) {
  int i = 0;
  for (i = 0; i < qtdGrupos; i++) { 
    ordenaPontosDoGrupo(grupos[i]); 
  }
  qsort(grupos, qtdGrupos, sizeof(Grupo*), compareGrupos);
}