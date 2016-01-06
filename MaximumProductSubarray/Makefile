edit: main.o
	$(CC) -o main $(CXXFLAG) $(INCLUDE_FILES)

objects = main.o
CXXFLAG = -Wall -std=c++11 -g
CC = g++
INCLUDE_FILES = MPS.cpp

main.o: $(INCLUDE_FILES)


.PHONY: clean
clean:
	-rm edit $(objects)
