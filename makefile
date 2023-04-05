DIR_ENTRADA=./in-testes/teste.txt
DIR_SAIDA=./out-testes/saida.txt
QTD_GRUPOS=3

all: clean compile run

compile: ponto
	@ gcc -o trab1 *.o main.c -lm 
# -lm é usado para linkar a biblioteca math.h

ponto:
	@ gcc -c Ponto.c

run:
	@ ./trab1 ${DIR_ENTRADA} ${QTD_GRUPOS} ${DIR_SAIDA}

val:
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA} ${QTD_GRUPOS} ${DIR_SAIDA}

clean:
	@ rm -f *.o trab1