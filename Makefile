#!make -f

CXX=clang++
CXXFLAGS=-std=c++2a -Werror

HEADERS=snowman.hpp
OBJECTS=snowman.o

all: snowman

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy snowman.cpp -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,hicpp-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Test2.cpp:
	curl https://raw.githubusercontent.com/cpp-exercises/snowman-a/master/TestExample.cpp > Test2.cpp

snowman: snowman.cpp snowman.hpp
	$(CXX) $(CXXFLAGS) snowman.cpp -o snowman

clean:
	rm -f *.o demo test snowman
	rm -f Test2.cpp
