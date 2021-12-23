CXX_FLAG = --std=c++11 -g

all: testbst

testbst: testbst.cpp intbst.cpp
	g++ $(CXX_FLAG) -o testbst testbst.cpp intbst.cpp

clean:
	rm -vf testbst