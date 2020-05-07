
lab12: lab12Driver.o graph.o
	g++ -std=c++11 -o lab12 lab12Driver.o graph.o

graph.o: graph.cpp
	g++ -std=c++11 -c -g graph.cpp

lab12Driver.o: lab12Driver.cpp
	g++ -std=c++11 -c -g lab12Driver.cpp

clean:
	rm *.o lab12
