DIR_ENTRADA_1_PDF=./in/1pdf.txt
DIR_ENTRADA_2_PDF=./in/2pdf.txt
DIR_ENTRADA_1=./in/1.txt
DIR_ENTRADA_2=./in/2.txt
DIR_ENTRADA_3=./in/3.txt
DIR_ENTRADA_4=./in/4.txt
DIR_ENTRADA_5=./in/5.txt

DIR_SAIDA_1_PDF=./out/1pdf.txt
DIR_SAIDA_2_PDF=./out/2pdf.txt
DIR_SAIDA_1=./out/1.txt
DIR_SAIDA_2=./out/2.txt
DIR_SAIDA_3=./out/3.txt
DIR_SAIDA_4=./out/4.txt
DIR_SAIDA_5=./out/5.txt

QTD_GRUPOS=3 # Caso de teste qualquer

all: clean compile runAll valAll

compile: ponto aresta union grupo
	@ gcc -o trab1 *.o main.c -lm 
# -lm é usado para linkar a biblioteca math.h

ponto:
	@ gcc -c Ponto.c

aresta: union
	@ gcc -c Aresta.c

union: ponto
	@ gcc -c UnionTree.c

grupo: ponto
	@ gcc -c Grupo.c

run1pdf: clean compile
	@ ./trab1 ${DIR_ENTRADA_1_PDF} ${QTD_GRUPOS} ${DIR_SAIDA_1_PDF}

run2pdf: clean compile
	@ ./trab1 ${DIR_ENTRADA_2_PDF} ${QTD_GRUPOS} ${DIR_SAIDA_2_PDF}

run1: clean compile
	@ ./trab1 ${DIR_ENTRADA_1} 2 ${DIR_SAIDA_1}

run2: clean compile
	@ ./trab1 ${DIR_ENTRADA_2} 4 ${DIR_SAIDA_2}

run3: clean compile
	@ ./trab1 ${DIR_ENTRADA_3} 5 ${DIR_SAIDA_3}

run4: clean compile
	@ ./trab1 ${DIR_ENTRADA_4} 5 ${DIR_SAIDA_4}

run5: clean compile
	@ ./trab1 ${DIR_ENTRADA_5} 10 ${DIR_SAIDA_5}

runAll: run1 run2 run3 run4 run5

val1pdf: clean compile
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA_1_PDF} ${QTD_GRUPOS} ${DIR_SAIDA_1_PDF}

val2pdf: clean compile
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA_2_PDF} ${QTD_GRUPOS} ${DIR_SAIDA_2_PDF}

val1: clean compile
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA_1} 2 ${DIR_SAIDA_1}

val2: clean compile
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA_2} 4 ${DIR_SAIDA_2}

val3: clean compile
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA_3} 5 ${DIR_SAIDA_3}

val4: clean compile
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA_4} 5 ${DIR_SAIDA_4}

val5: clean compile
	@ valgrind --leak-check=full ./trab1 ${DIR_ENTRADA_5} 10 ${DIR_SAIDA_5}

valAll: val1 val2 val3 val4 val5

clean:
	@ rm -f *.o trab1 out/*