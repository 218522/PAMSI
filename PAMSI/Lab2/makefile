
all: prog

prog: obj/main.o obj/Tablica_dynamiczna.o obj/stoper.o obj/Interfejs.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/Tablica_dynamiczna.o obj/stoper.o obj/Interfejs.o

obj/stoper.o: src/stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/stoper.o src/stoper.cpp

obj/Tablica_dynamiczna.o: src/Tablica_dynamiczna.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Tablica_dynamiczna.o src/Tablica_dynamiczna.cpp 

obj/Interfejs.o: src/Interfejs.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Interfejs.o src/Interfejs.cpp

obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp








clean:
	rm -f obj/*.o
