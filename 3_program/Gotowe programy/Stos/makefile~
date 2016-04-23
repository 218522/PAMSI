program: main.o list_head.o element.o
	g++ -std=c++11 main.o list_head.o element.o -o program

main.o: main.cpp
	g++ -std=c++11 -c main.cpp 

list_head.o: list_head.cpp list_head.h element.h interface.h
	g++ -std=c++11 -c list_head.cpp 

element.o: element.cpp element.h
	g++ -std=c++11 -c element.cpp 
clean:
	rm -f *.o
