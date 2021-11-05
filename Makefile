CC = g++
CFLAGS = -Wall -g -O2 -std=c++17

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS = $(wildcard test/*.cpp)
TESTS = $(TEST_SRCS:.cpp=.exe)

run: cfgparser
	./cfgparser

cfgparser: $(OBJS)
	$(CC) $(CFLAGS) -o cfgparser $(OBJS)

test/test_%.exe: test/test_%.cpp $(filter-out src/main.cpp, $(SRCS))
	$(CC) $(CFLAGS) -o $@ $^

test: $(TESTS)
	@for i in $(TESTS); do echo -n "$$i"; ./$$i || exit 1; echo "  ...passed"; done

clean:
	rm -f cfgparser $(OBJS) $(TESTS)

.PHONY: run clean
