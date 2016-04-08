
all: prog

prog: obj/main.o obj/Stos.o obj/Kolejka.o obj/ILista.o obj/IStos.o obj/IKolejka.o obj/Lista.o obj/stoper.o obj/Test_lista.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/Stos.o obj/Kolejka.o obj/ILista.o obj/IStos.o obj/IKolejka.o obj/Lista.o obj/stoper.o obj/Test_lista.o


obj/IStos.o: src/IStos.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/IStos.o src/IStos.cpp

obj/Stos.o: src/Stos.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Stos.o src/Stos.cpp

obj/IKolejka.o: src/IKolejka.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/IKolejka.o src/IKolejka.cpp

obj/Kolejka.o: src/Kolejka.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Kolejka.o src/Kolejka.cpp

obj/ILista.o: src/ILista.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/ILista.o src/ILista.cpp 

obj/Lista.o: src/Lista.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Lista.o src/Lista.cpp 

obj/stoper.o: src/stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/stoper.o src/stoper.cpp

obj/Test_lista.o: src/Test_lista.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Test_lista.o src/Test_lista.cpp

obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp










clean:
	rm -f obj/*.o
