
BIN_DIR=./bin

run: test
	@${BIN_DIR}/test

dummy: dummy.cpp
	g++ -g -DTEST $< -o $@ -I./inc -I./ --std=c++2a

test: test.o
	g++ $< -g -o $@  --std=c++2a
	@mkdir -p ${BIN_DIR}
	@mv ./test ${BIN_DIR}
	@mv *.o ${BIN_DIR}

test.o: ./src/main.cpp solu.h
	g++ -c -g -DTEST $< -o $@ -I./inc -I./ --std=c++2a

clean:
	@rm ${BIN_DIR}* -rf
	@rm dummy -rf
