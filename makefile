test_result.o: test.c heap.h
	gcc -g -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	rm test_result.o