
run: test
	@./test

test: test.o
	g++ $< -g -o $@

test.o: main.cpp solu.h
	g++ -c -g $< -o $@

clean:
	rm *.o test

