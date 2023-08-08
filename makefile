test_results.o: main.c heap.h
	gcc -g -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	rm test_results.o
