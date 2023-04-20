#include "Ponto.h"
#include "Matriz.h"
#include "Aresta.h"
#include "union-find.h"
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
  int qtdPontos = getQuantidadePontos(pontos); // Obtem quantidade final de pontos

  // Cria e preenche a matriz com as distancias entre os pontos
  Matriz* distancias = inicializaMatriz(qtdPontos);
  int qtdArestas = preencheMatriz(distancias, pontos);

  /* Aresta: conexão entre dois pontos */
  Aresta** arestas = inicializaVetorArestas(qtdArestas); 
  preencheVetorArestas(arestas, distancias, pontos);
  qsort(arestas, qtdArestas, sizeof(Aresta*), compareArestas); // Ordena o vetor de arestas

  /*======== Aplicando o algorítmo ========*/
  int qtdGrupos = atoi(argv[2]);

  if (qtdGrupos > qtdPontos) {
    printf("O número de grupos não pode ser maior que a quantidade de pontos!\n");
    exit(1);
  }

  UnionTree* componentesConexas = inicializaUnionTree(qtdPontos);
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
  destroiMatriz(distancias);
  destroiVetorArestas(arestas, qtdArestas);
  destroiUnionTree(componentesConexas);
  destroiGrupos(gruposPontos, qtdGrupos);

  return 0;
}