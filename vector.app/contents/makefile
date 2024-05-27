# Compiler settings
CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Iheaders -Ivector/catch2

# Source files
SRC = $(wildcard source/*.cpp)

# Test files
TEST_SRC = $(wildcard test/testavimas.cpp) source/function.cpp

# Executable target
TARGET = run

# Test executable target
TEST_TARGET = run_tests

# Optimization levels
OPT_LEVELS = O1 O2 O3
OPT_FLAGS_O1 = -O1
OPT_FLAGS_O2 = -O2
OPT_FLAGS_O3 = -O3

# Main rule
all: $(OPT_LEVELS)

# Targets for each optimization level
O1: CXXFLAGS += $(OPT_FLAGS_O1)
O1: $(TARGET)_O1

O2: CXXFLAGS += $(OPT_FLAGS_O2)
O2: $(TARGET)_O2

O3: CXXFLAGS += $(OPT_FLAGS_O3)
O3: $(TARGET)_O3

# Target rules for executables with different optimization levels
$(TARGET)_O1: $(SRC)
	@echo "Building target with -O1: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O1) -o $@ $^

$(TARGET)_O2: $(SRC)
	@echo "Building target with -O2: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O2) -o $@ $^

$(TARGET)_O3: $(SRC)
	@echo "Building target with -O3: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O3) -o $@ $^

# Rule for test compilation
tests: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC)
	@echo "Building test target: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^


# Run tests
run-tests: $(TEST_TARGET)
	@echo "Running test target: $<"
	./$(TEST_TARGET)

# Clean rule
clean:
	rm -f $(TARGET)_O1 $(TARGET)_O2 $(TARGET)_O3 $(TEST_TARGET)
