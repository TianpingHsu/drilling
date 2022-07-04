
BIN_DIR=./bin

run: test
	@${BIN_DIR}/test

test: test.o
	g++ $< -g -o $@
	@mkdir -p ${BIN_DIR}
	@mv ./test ${BIN_DIR}
	@mv *.o ${BIN_DIR}

test.o: ./src/main.cpp solu.h
	g++ -c -g $< -o $@ -I./inc -I./

clean:
	@rm ${BIN_DIR}* -rf

