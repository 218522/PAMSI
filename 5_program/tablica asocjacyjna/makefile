
all: prog

prog: obj/main.o obj/HashTab.o obj/AssocTab.o obj/Stoper.o obj/list_head.o obj/element.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/HashTab.o obj/AssocTab.o obj/Stoper.o obj/list_head.o obj/element.o

obj/HashTab.o: src/HashTab.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/HashTab.o src/HashTab.cpp

obj/AssocTab.o: src/AssocTab.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/AssocTab.o src/AssocTab.cpp

obj/list_head.o: src/list_head.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/list_head.o src/list_head.cpp 

obj/element.o: src/element.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/element.o src/element.cpp 

obj/Stoper.o: src/Stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Stoper.o src/Stoper.cpp

obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp


clean:
	rm -f obj/*.o
