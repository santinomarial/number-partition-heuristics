CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall
TARGET   := partition
SRCS     := $(wildcard *.cpp)
OBJS     := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

TEST_BIN := tests/test_kk
TEST_SRC := tests/test_kk.cpp kk.cpp

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_BIN)

.PHONY: clean test
