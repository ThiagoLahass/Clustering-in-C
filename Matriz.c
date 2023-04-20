#include "Matriz.h"


struct matriz{
    double** matriz;
    int tamanho;
};

Matriz* inicializaMatriz(int qtdPontos){
    register int i;
    Matriz* m = (Matriz*)malloc(sizeof(Matriz));
    m->matriz = malloc(sizeof(double**) * qtdPontos);

    for(i=0;i<qtdPontos;i++){
        m->matriz[i] = calloc(qtdPontos, sizeof(double*));
    }
    m->tamanho = qtdPontos;
    return m;
}

int preencheMatriz(Matriz* m, Ponto** pontos){
    register int i, j, contador=0;
    int tamanho = get_TamanhoMatriz(m);

    //para cada linha da matriz,
    for(i=0;i<tamanho;i++){
        //percorra todas as colunas
        for(j=0;j<tamanho; j++){
            //se a linha for maior que a coluna,
            if(i > j){
                m->matriz[i][j] = calculaDistanciaEntrePontos(pontos[i], pontos[j]);
                contador++;
            }
            else break;
        }
    }
    return contador;
}

void imprimeMatrizRelevante(Matriz* m){
    register int i, j;
    int tamanho = get_TamanhoMatriz(m);
    //para cada linha da matriz,
    for(i=0;i<tamanho;i++){
        //percorra todas as colunas
        for(j=0;j<tamanho; j++){
            //se a linha for maior que a coluna,
            if(i > j){
                printf("%.2f\n", m->matriz[i][j]);
            }
            else break;
        }
    }
}

void destroiMatriz(Matriz* m){
    register int i;
    int tamanho = get_TamanhoMatriz(m);

    for(i=0;i<tamanho;i++){
        free(m->matriz[i]);
    }

    free(m->matriz);
    free(m);
}

int get_TamanhoMatriz(Matriz* m){ return m->tamanho; }

double getConteudoMatriz(Matriz* m, int linha, int coluna) { return m->matriz[linha][coluna]; }