all: Threads

Threads: threads.cpp
	g++ -std=c++11 -pthread -Wall -g -o Threads threads.cpp

clean:
	if [ -e Threads ]; then rm Threads; fi;
	if [ -e *~ ]; then rm *~; fi;
	if [ -e *.o ]; then rm *.o; fi;
	if [ -e *.gch ]; then rm *.gch; fi;
