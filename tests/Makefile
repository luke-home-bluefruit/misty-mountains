CXX=g++
OPTIONS=-Wall -Wextra -g

.PHONY: all
all: tests.counter

tests.counter: scopetests.cpp
	$(CXX) $(OPTIONS) \
	scopetests.cpp \
	../src/DummyThing.cpp \
	../src/ClocksDriver.cpp \
	-o tests.counter.exe

.PHONY: clean
clean:
	@rm tests.counter.exe
