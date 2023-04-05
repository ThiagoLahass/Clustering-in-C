#include "Ponto.h"

struct ponto {
    char* id;
    int* coordenadas;
    int qtdDimensoes;
};

Ponto** lePontos(char* nomeArquivoEntrada) {
    FILE* arquivoDeEntrada = fopen(nomeArquivoEntrada, "r");
    if (arquivoDeEntrada == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivoEntrada);
        exit(1);
    }

    /* Descobrir quantas linhas (n° de pontos) tem o arquivo */
    int qtdLinhas = 0;
    while (!feof(arquivoDeEntrada)) {
        fscanf(arquivoDeEntrada, "%*[^\n]"); // Lê até o final da linha
        fscanf(arquivoDeEntrada, "%*c"); // Lê o caractere de nova linha
        qtdLinhas++;
    }
    fseek(arquivoDeEntrada, 0, SEEK_SET); // Voltar o ponteiro do arquivo para o início


    Ponto** pontos = (Ponto**) malloc(sizeof(Ponto*) * qtdLinhas); // Aloca um vetor de pontos
    char* linha = NULL; // auxiliar para ler a linha
    size_t tamLinha = 0;

    /* Lê os pontos */
    int qtdPontosLidos = 0; // Conta quantos pontos já foram lidos
    while (getline(&linha, &tamLinha, arquivoDeEntrada) > 0) {
        pontos[qtdPontosLidos] = inicializaPonto(linha);
        qtdPontosLidos++;
    }

    free(linha); // Alocado pelo getline()
    fclose(arquivoDeEntrada);
    return pontos;
}

Ponto* inicializaPonto(char* linha) {
    Ponto* ponto = (Ponto*) malloc(sizeof(Ponto));
    ponto->coordenadas = (int*) malloc(sizeof(int) * NUM_INICIAL_DIMENSOES);

    char* token;
    const char delimitador[] = DELIMITADOR;

    token = strtok(linha, delimitador);
    ponto->id = strdup(token);

    int idxCoordenada = 0;
    token = strtok(NULL, delimitador);
    while (token != NULL) {
        if (idxCoordenada == NUM_INICIAL_DIMENSOES) {
            ponto->coordenadas = (int*) realloc(ponto->coordenadas, sizeof(int) * NUM_INICIAL_DIMENSOES * 2);
            // NUM_INICIAL_DIMENSOES *= 2;
        } 
        ponto->coordenadas[idxCoordenada] = atoi(token);
        idxCoordenada++;
        token = strtok(NULL, delimitador);
    }

    ponto->qtdDimensoes = idxCoordenada;

    return ponto;
}

// FIXME: Invalid read of size 8
// Address 0x4bab2f0 is 0 bytes after a block of size 80 alloc'd
void imprimePontos(Ponto** pontos) {
    int i = 0;
    while (pontos[i] != NULL) {
        printf("%s", pontos[i]->id);
        int j = 0;
        for (j = 0; j < pontos[i]->qtdDimensoes; j++) {
            printf(",%d", pontos[i]->coordenadas[j]);
        }
        printf("\n");
        i++;
    }
}

// FIXME: Invalid read of size 8
// Address 0x4bab2f0 is 0 bytes after a block of size 80 alloc'd
void destroiPontos(Ponto **pontos) {
    int i = 0;
    while (pontos[i] != NULL) {
        free(pontos[i]->id);
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

char* getId(Ponto* p) { return p->id; }

int* getCoordenadas(Ponto* p) { return p->coordenadas; }