CXX= g++
CXX_FLAGS= -g -Wall


SOURCES= $(wildcard *.cpp)
OBJS= $(patsubst %.cpp, %.o, $(SOURCES))
DEP_FILES=$(patsubst %.cpp, %_deps.mk, $(SOURCES))


all: main

include deps.mk

main: $(OBJS)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) -c $<

%_deps.mk: %.cpp
	$(CXX) -MM -MF $@ $<

deps.mk: $(DEP_FILES)
	rm -f deps.mk
	cat $(DEP_FILES) > deps.mk

tests:
	./main tests/test1 
	./main tests/test2
	./main tests/test3
	./main tests/test4
	./main tests/test5
	./main tests/test6
	./main tests/test7
	./main tests/test8
	./main tests/test9
	./main tests/fact
	./main tests/fib

clean: 
	clear
	rm -f $(OBJS)
	rm -f $(DEP_FILES)

