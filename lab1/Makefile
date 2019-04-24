all: kmpAndTest

kmpAndTest: kmp.o test.o 
	g++ kmp.o  -o kmp.exe
	g++ test.o -o test.exe -lgtest -lpthread

kmp.o: kmp.cpp
	g++ -c kmp.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf *.o kmp
