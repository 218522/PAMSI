all: prog

prog: obj/main.o obj/Tree_red_black.o obj/Stoper.o obj/value_generator.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/Tree_red_black.o obj/Stoper.o obj/value_generator.o

obj/Tree_red_black.o: src/Tree_red_black.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Tree_red_black.o src/Tree_red_black.cpp

obj/value_generator.o: src/value_generator.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/value_generator.o src/value_generator.cpp

obj/Stoper.o: src/Stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Stoper.o src/Stoper.cpp

obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp


clean:
	rm -f obj/*.o
