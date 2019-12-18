all: main.o linkQueue.o queue.o
	g++ -o run.exe main.o linkQueue.o queue.o

queue.o: queue.h queue.cpp
	g++ -c queue.cpp

linkQueue.o: linkQueue.cpp queue.h
	g++ -c linkQueue.cpp

main.o: main.cpp linkQueue.cpp queue.h
	g++ -c main.cpp

clean:
	del *.o *.exe