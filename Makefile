CXX = clang++
CXX_FLAGS = -std=c++20 -g -fstandalone-debug -Iincludes -Wall -Wextra -Werror -fsanitize=address,null -fno-omit-frame-pointer -O0 -gdwarf-4 -Wno-unused-parameter 

exec: bin/exec
tests: bin/tests
bin/exec: ./src/driver.cc ./src/vending_machine.cc ./src/dispenser.cc ./src/item.cc ./includes/vending_machine.hpp ./includes/dispenser.hpp ./includes/item.hpp
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/vending_machine.cc ./src/dispenser.cc ./src/item.cc -o $@

bin/tests: ./tests/tests.cc ./src/vending_machine.cc ./src/item.cc ./src/dispenser.cc ./includes/vending_machine.hpp ./includes/dispenser.hpp ./includes/item.hpp
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/vending_machine.cc ./src/dispenser.cc ./src/item.cc -o $@
.DEFAULT_GOAL := exec

.PHONY: exec tests clean

clean:
	rm -rf bin/*
