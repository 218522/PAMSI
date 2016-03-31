program: main.o tab_mng.o timer.o
	g++ -std=c++11 main.o tab_mng.o timer.o -o program

main.o: main.cpp
	g++ -std=c++11 -c main.cpp 

tab_mng.o: tab_mng.cpp tab_mng.h Interfejs.h
	g++ -std=c++11 -c tab_mng.cpp 

timer.o: timer.cpp timer.h
	g++ -std=c++11 -c timer.cpp 
clean:
	rm -f *.o
