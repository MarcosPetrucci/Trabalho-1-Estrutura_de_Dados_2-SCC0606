

all: clean TAD_lista.o TAD_lista.h main.o
	@gcc TAD_lista.o main.o -o T1

TAD_lista.o:
	@gcc -c TAD_lista.c
	
main.o:
	@gcc -c main.c

run:
	@./T1

#Necessário rodar o make clean para limpar os arquivos .o
#Se não deletá-los, não será possível compilar a nova versão
clean: 
	@ rm *.o
