all: musicplay

musicplay: main.o funcoes_part1.o funcoes_part2.o playlist.o
	gcc *.o -o musicplay

main.o: main.c Bibliotecas.h
	gcc -c main.c

funcoes_part1.o: funcoes_part1.c playlist.h funcoes_part1.h
	gcc -c funcoes_part1.c

funcoes_part2.o: funcoes_part2.c playlist.h
	gcc -c funcoes_part2.c

playlist.o: playlist.c playlist.h
	gcc -c playlist.c

clean:
	rm musicplay *.o