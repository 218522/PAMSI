program: main.o stos_head.o element.o
	g++ -std=c++11 main.o stos_head.o element.o -o program

main.o: main.cpp
	g++ -std=c++11 -c main.cpp 

stos_head.o: stos_head.cpp stos_head.h element.h interface.h
	g++ -std=c++11 -c stos_head.cpp 

element.o: element.cpp element.h
	g++ -std=c++11 -c element.cpp 
clean:
	rm -f *.o
