test_results.o: test.c heap.h
	gcc -g -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	rm test_results.o