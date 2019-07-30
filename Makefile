CXX=g++
CFLAGS=-std=c++17 -lstdc++fs -Wall -Werror
TARGET=battery_stat

all: main

main: main.cpp
	$(CXX) main.cpp $(CFLAGS) -o $(TARGET)

clean:
	rm -f *.o *.out $(TARGET)

