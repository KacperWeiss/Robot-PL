CPP = g++ -Wall -pedantic -std=c++11 -c -g -Iinc

__start__: roboty
	./roboty

roboty: obj obj/sciezka.o obj/lacze_do_gnuplota.o obj/robot.o obj/wektor.o obj/main.o obj/scena.o obj/obiekt.o obj/figura.o
	g++ obj/sciezka.o obj/lacze_do_gnuplota.o obj/robot.o obj/wektor.o obj/main.o  obj/scena.o obj/obiekt.o obj/figura.o -o roboty

obj:
	mkdir obj

obj/main.o: src/main.cpp
	${CPP} src/main.cpp -o obj/main.o

# obj/scena.o: inc/scena.hpp src/scena.cpp
# 	${CPP} src/scena.cpp -o obj/scena.o

obj/figura.o: src/figura.cpp inc/figura.hpp
	${CPP} src/figura.cpp -o obj/figura.o

obj/obiekt.o: src/obiekt.cpp inc/obiekt.hpp
	${CPP} src/obiekt.cpp -o obj/obiekt.o

obj/sciezka.o: inc/sciezka.hpp src/sciezka.cpp
	${CPP} src/sciezka.cpp -o obj/sciezka.o

 obj/wektor.o: inc/wektor.hpp src/wektor.cpp
	${CPP} src/wektor.cpp -o obj/wektor.o

obj/robot.o: inc/robot.hpp src/robot.cpp
	${CPP} src/robot.cpp -o obj/robot.o

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hpp src/lacze_do_gnuplota.cpp
	${CPP} src/lacze_do_gnuplota.cpp -o obj/lacze_do_gnuplota.o

obj/scena.o: src/scena.cpp inc/scena.hpp
	${CPP} src/scena.cpp -o obj/scena.o

clear:
	rm -rf obj robot.dat sciezka.dat roboty scena*.dat
