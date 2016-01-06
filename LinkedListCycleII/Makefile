edit: main.o
	$(CC) -o main $(CXXFLAG) $(INCLUDE_FILES)

objects = main.o
CXXFLAG = -Wall -std=c++11
CC = g++
INCLUDE_FILES = LinkedListCycleII.cpp

main.o: $(INCLUDE_FILES)


.PHONY: clean
clean:
	-rm edit $(objects)
