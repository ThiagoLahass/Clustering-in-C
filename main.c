#include "Ponto.h"

int main(int argc, char** argv) {
  /**
   * @brief Significado de cada parâmetro:
   * argv[0] = ./trab1
   * argv[1] = nome_arquivo_entrada
   * argv[2] = k - número de grupos
   * argv[3] = nome_arquivo_saida
   */

  if (argc < 4) {
    printf("Use: ./trab1 <nome_arquivo_entrada> k <nome_arquivo_saida>\n");
    return 1; 
  }

  Ponto** pontos = lePontos(argv[1]);
  imprimePontos(pontos);
  destroiPontos(pontos);





  return 0;
}