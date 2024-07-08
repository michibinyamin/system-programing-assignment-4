# email - michibinyamin@gmail.com
# Id - 208768978
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -fPIC
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_FILES = main.cpp
TEST_FILES = Test.cpp
HDR_FILES = Node.hpp Tree.hpp Complex.hpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

EXEC = tree
TEST_EXEC = test

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXEC) $(LDFLAGS)

$(TEST_EXEC): $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ_FILES) -o $(TEST_EXEC) $(LDFLAGS)

%.o: %.cpp $(HDR_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES) $(EXEC) $(TEST_EXEC)

run: $(EXEC)
	./$(EXEC)

run_tests: $(TEST_EXEC)
	./$(TEST_EXEC)
