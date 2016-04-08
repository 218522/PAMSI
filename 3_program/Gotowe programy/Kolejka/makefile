program: main.o kolejka_head.o element.o
	g++ -std=c++11 main.o kolejka_head.o element.o -o program

main.o: main.cpp
	g++ -std=c++11 -c main.cpp 

kolejka_head.o: kolejka_head.cpp kolejka_head.h element.h interface.h
	g++ -std=c++11 -c kolejka_head.cpp 

element.o: element.cpp element.h
	g++ -std=c++11 -c element.cpp 
clean:
	rm -f *.o
