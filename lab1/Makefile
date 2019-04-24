all: kmp

kmp: kmp.o test.o 
	g++ kmp.o test.o -o kmp.exe

kmp.o: kmp.cpp
	g++ -c kmp.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf *.o kmp