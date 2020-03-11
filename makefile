#all: clean TAD_lista.o TAD_lista.h main.o
#	@gcc TAD_lista.o main.o -o T1

#TAD_lista.o:
#	@gcc -c TAD_lista.c
	
#main.o:
#	@gcc -c main.c

#run:
#	@./T1

#Necessário rodar o make clean para limpar os arquivos .o
#Se não deletá-los, não será possível compilar a nova versão
#clean: 
#	@ rm *.o


CC=gcc					# C compiler

CFLAGS=-I. -g -Wall

#LIBS=-lm

DEPS= buscaRecursiva.h TAD_lista.h #mergesort.h		

#OBJ= buscaRecursiva.o TAD_lista.o mergesort.o main.o 
OBJ= buscaRecursiva.o TAD_lista.o main.o 


# rule for files ending in .o (.o file depends upon the .c version of the file and the .h files in the DEPS macro)

%.o: %.c $(DEPS)		
	$(CC) -c -o $@ $< $(CFLAGS)

### -o $@ puts the output on the left side of the :
### $< is the first item in the dependencies list

prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

### $@ left side of :
### $^ right side of the :

.PHONY: run

run:
	./prog

.PHONY: clean

clean:
	rm -f *.o  

.PHONY: debug

debug:
	gdb ./prog