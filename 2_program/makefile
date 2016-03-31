program: main.o tab_mng.o timer.o
	g++ main.o tab_mng.o timer.o -o program

main.o: main.cpp
	g++ -c main.cpp 

tab_mng.o: tab_mng.cpp tab_mng.h
	g++ -c tab_mng.cpp 

timer.o: timer.cpp timer.h
	g++ -c timer.cpp 
clean:
	rm -f *.o
