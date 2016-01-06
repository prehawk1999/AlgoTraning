edit: main.o
	$(CC) -o main -lstdc++ $(CXXFLAG) $(INCLUDE_FILES)

objects = main.o
CXXFLAG = -Wall -std=c++11
CC = g++
INCLUDE_FILES = WordPattern.cpp

main.o: $(INCLUDE_FILES)


.PHONY: clean
clean:
	-rm edit $(objects)
