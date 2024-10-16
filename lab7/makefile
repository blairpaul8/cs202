CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		nqueens nqueen2

nqueens:	nqueens.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
nqueen2:	nqueen2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f nqueens
	rm -f nqueen2


test:		test-8 test-10
test-2: test-8-2 test-10-2

test-8:	nqueens
	@echo Testing board size of 8 input/output...
	@diff --suppress-common-lines -y <(./nqueens 8) output

test-10: nqueens
	@echo Testing board size of 10 input/output...
	@diff --suppress-common-lines -y <(./nqueens 10) output2



test-8-2:	nqueen2
	@echo Testing board size of 8 input/output...
	@diff --suppress-common-lines -y <(./nqueen2 8) output

test-10-2: nqueen2
	@echo Testing board size of 10 input/output...
	@diff --suppress-common-lines -y <(./nqueen2 10) output2

