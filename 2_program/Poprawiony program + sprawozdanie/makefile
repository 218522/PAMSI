all: prog

prog: obj/main.o obj/timer.o obj/tab_mng.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/timer.o obj/tab_mng.o

obj/tab_mng.o: src/tab_mng.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/tab_mng.o src/tab_mng.cpp

obj/timer.o: src/timer.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/timer.o src/timer.cpp

obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp


clean:
	rm -f obj/*.o
