#include "Ponto.h"

struct ponto {
    char* nome;
    double* coordenadas;
    int qtdDimensoes;
    int id; // Onde vai ser aplicado o algoritmo
};

Ponto** lePontos(char* nomeArquivoEntrada) {
    FILE* arquivoDeEntrada = fopen(nomeArquivoEntrada, "r");
    if (arquivoDeEntrada == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivoEntrada);
        exit(1);
    }

    /*======== Descobrir quantas dimensões tem o ponto =========*/
    int qtdDimensoes = -1; // Inicializa com -1 para desconsiderar o nome do ponto
    char* linha = NULL; // Auxiliar para ler a linha
    size_t tamLinha = 0; // Auxiliar para ler a linha
    getline(&linha, &tamLinha, arquivoDeEntrada); // Ler a primeira linha pra ver quantas dimensões tem

    char* token;
    const char delimitador[] = DELIMITADOR;

    token = strtok(linha, delimitador); // Divide a linha em tokens separados pelo delimitador
    while (token != NULL) {
        qtdDimensoes++;
        token = strtok(NULL, delimitador); // Passa para o próximo token
    }
    
    free(linha); // Alocado pelo getline()
    fseek(arquivoDeEntrada, 0, SEEK_SET); // Voltar o ponteiro do arquivo para o início


    /*======== Leitura dos pontos de fato =========*/
    int qtdPontos = 1000; // Chute da quantidade inicial de pontos
    Ponto** pontos = (Ponto**) malloc(sizeof(Ponto*) * qtdPontos); // Aloca um vetor de pontos
    linha = NULL; // Reset 
    tamLinha = 0; // Reset

    int qtdPontosLidos = 0; 
    while (getline(&linha, &tamLinha, arquivoDeEntrada) > 0) {
        if (qtdPontosLidos == qtdPontos) { // Se o vetor de pontos estiver cheio, realoca o vetor
            pontos = (Ponto**) realloc(pontos, sizeof(Ponto*) * qtdPontos * 2);
            qtdPontos *= 2;
        }
        pontos[qtdPontosLidos] = inicializaPonto(linha, qtdDimensoes, qtdPontosLidos);
        qtdPontosLidos++;
    }
    /* Se sobrou espaço no vetor ou deu a conta exata */
    if (qtdPontosLidos + 1 < qtdPontos || qtdPontosLidos == qtdPontos) {
        pontos = (Ponto**) realloc(pontos, sizeof(Ponto*) * (qtdPontosLidos + 1));
    }
    pontos[qtdPontosLidos] = NULL; // Marca o fim do vetor de pontos

    free(linha); // Alocado pelo getline()
    fclose(arquivoDeEntrada);
    return pontos;
}

Ponto* inicializaPonto(char* linha, int qtdDimensoes, int identificadorPonto) {
    Ponto* ponto = (Ponto*) malloc(sizeof(Ponto));
    ponto->coordenadas = (double*) malloc(sizeof(double) * qtdDimensoes);
    ponto->qtdDimensoes = qtdDimensoes;
    ponto->id = identificadorPonto;

    /*======== Pegando os dados da linha ========*/
    char* token;
    const char delimitador[] = DELIMITADOR;

    token = strtok(linha, delimitador); // Divide a linha em tokens separados pelo delimitador
    ponto->nome = strdup(token);

    int idxCoordenada = 0;
    token = strtok(NULL, delimitador); // Passa para o próximo token
    while (token != NULL) {
        ponto->coordenadas[idxCoordenada] = strtod(token, NULL); // Converte a string para double
        idxCoordenada++;
        token = strtok(NULL, delimitador); // Passa para o próximo token 
    }

    return ponto;
}

void imprimePonto(Ponto* p, FILE* arquivoSaida) { fprintf(arquivoSaida, "%s", p->nome); }

void imprimePontos(Ponto **pontos, FILE* arquivoSaida) {
  int i = 0;
  while (pontos[i] != NULL) {
    fprintf(arquivoSaida, "%s", pontos[i]->nome);
    int j = 0;
    for (j = 0; j < pontos[i]->qtdDimensoes; j++) {
      fprintf(arquivoSaida, ",%.20lf", pontos[i]->coordenadas[j]);
    }
    fprintf(arquivoSaida, "\n");
    i++;
  }
}

void destroiPonto(Ponto* p) {
    free(p->nome);
    free(p->coordenadas);
    free(p);
}

void destroiPontos(Ponto **pontos) {
    int i = 0;
    while (pontos[i] != NULL) {
        free(pontos[i]->nome);
        free(pontos[i]->coordenadas);
        free(pontos[i]);
        i++;
    }
    free(pontos);
}

double calculaDistanciaEntrePontos(Ponto* x, Ponto* y) {
    double dist = 0.0;
    int i = 0;
    for (i = 0; i < x->qtdDimensoes; i++) {
        double sub = x->coordenadas[i] - y->coordenadas[i];
        dist += sub * sub;
    }
    return sqrt(dist);
}

int getQtdDimensoes(Ponto* p) { return p->qtdDimensoes; }

void setQtdDimensoes(Ponto* p, int qtdDimensoes) { p->qtdDimensoes = qtdDimensoes; }

char* getNome(Ponto* p) { return p->nome; }

int getId(Ponto* p) { return p->id; }

double* getCoordenadas(Ponto* p) { return p->coordenadas; }

int getQuantidadePontos(Ponto** p) {
    int i = 0;
    while (p[i] !=  NULL) { i++; }
    return i;
}