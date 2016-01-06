edit: main.o
	$(CC) -o main -lstdc++ $(CXXFLAG) $(INCLUDE_FILES) -g

objects = main.o
CXXFLAG = -Wall -std=c++11
CC = g++
INCLUDE_FILES = BTreePreorderTraversal.cpp

main.o: $(INCLUDE_FILES)


test:
	rm callgrind.out*
	valgrind --tool=callgrind ./main
	callgrind_annotate --auto=yes `ls callgrind.out*` > report.txt
	~/gprof2dot.py -f callgrind -n0.5 -e0 `ls callgrind.out*` |dot -Tpng -o report.png
	rm callgrind.out*


.PHONY: clean
clean:
	-rm edit $(objects)
