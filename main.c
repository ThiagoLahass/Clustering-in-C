#include "Ponto.h"
#include "Aresta.h"
#include "UnionTree.h"
#include "Grupo.h"

int main(int argc, char** argv) {
  /**
   * @brief Significado de cada parâmetro:
   * argv[0] = ./trab1
   * argv[1] = nome_arquivo_entrada
   * argv[2] = k -> número de grupos
   * argv[3] = nome_arquivo_saida
   */

  if (argc < 4) {
    printf("Use: ./trab1 <nome_arquivo_entrada> k <nome_arquivo_saida>\n");
    return 1; 
  }
  
  /*======== Leitura dos dados de entrada ========*/
  Ponto** pontos = lePontos(argv[1]); // Vetor com todos os pontos

  /*======== Tratando os dados ========*/
  int qtdPontos = getQuantidadePontos(pontos); // Obtem quantidade de pontos

  // obtem o numero de arestas necessarias
  int qtdArestas = qtdPontos * (qtdPontos -1) / 2;

  /* Aresta: conexão entre dois pontos */
  Aresta** arestas = inicializaVetorArestas(qtdArestas); 
  //preenche as arestas com as disntacias entre os pares de pontos unicos
  preencheVetorArestas(arestas, qtdPontos, pontos);
  // Ordena o vetor de arestas
  qsort(arestas, qtdArestas, sizeof(Aresta*), compareArestas); 

  /*======== Aplicando o algoritmo ========*/
  int qtdGrupos = atoi(argv[2]);
  if (qtdGrupos > qtdPontos) {
    printf("O número de grupos não pode ser maior que a quantidade de pontos!\n");
    exit(1);
  }

  UnionTree* componentesConexas = inicializaUnionTree(qtdPontos);
  //utiliza o problema de union-find para conectar os pontos em grupos
  conectaArestas(arestas, componentesConexas, qtdPontos, qtdArestas, qtdGrupos);

  /*======== Criando os grupos de pontos ========*/
  Grupo**  gruposPontos = inicializaVetorGrupos(qtdGrupos, qtdPontos, componentesConexas, pontos);
  preencheVetorGrupos(gruposPontos, qtdGrupos, componentesConexas, pontos, qtdPontos);
  ordenaTodosGrupos(gruposPontos, qtdGrupos);

  /*======== Imprimindo os grupos de pontos ========*/
  FILE* arquivoDeSaida = fopen(argv[3], "w");
  if (arquivoDeSaida == NULL) {
    printf("Erro ao abrir o arquivo %s\n", argv[3]);
    exit(1);
  }
  imprimeGrupos(gruposPontos, qtdGrupos, arquivoDeSaida);
  fclose(arquivoDeSaida);

  /*======== Liberando toda a memória alocada ========*/
  destroiPontos(pontos);
  destroiVetorArestas(arestas, qtdArestas);
  destroiUnionTree(componentesConexas);
  destroiGrupos(gruposPontos, qtdGrupos);

  return 0;
}