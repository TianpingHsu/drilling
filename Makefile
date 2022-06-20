
run: test
	@./test

test: test.o
	g++ $< -g -o $@

test.o: ./src/main.cpp solu.h
	g++ -c -g $< -o $@ -I./inc -I./

clean:
	@rm *.o test

