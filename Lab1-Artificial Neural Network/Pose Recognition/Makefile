CC  = g++
CFLAGS = -std=c++11 -O2
LDFLAGS = -lm

all: program
    
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

program: main.o  
	$(CC) $(CFLAGS) main.o $(LDFLAGS) -o ./executable/test

clean: 
	rm -f main.o ./executable/test
