
DIR := ../../../src/node

test: $(DIR)/functionStack.h $(DIR)/functionStack.cpp main.cpp
	g++ -Wall -g -std=c++11 -I$(DIR) -o $@ main.cpp $(DIR)/functionStack.cpp
