# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -m64 -Wall -Iheaders -Icatch2

# Source files
SRC = $(wildcard source/*.cpp)
SRC_NO_MAIN = $(filter-out source/main.cpp, $(SRC))

# Test files
TESTS = test/testavimas.cpp

# Executable file
TARGET = run

# Optimization levels
OPT_LEVELS = O1 O2 O3
OPT_FLAGS_O1 = -O1
OPT_FLAGS_O2 = -O2
OPT_FLAGS_O3 = -O3

# Main rule
all: $(OPT_LEVELS) test

# Targets for each optimization level
O1: CXXFLAGS += $(OPT_FLAGS_O1)
O1: $(TARGET)_O1.exe

O2: CXXFLAGS += $(OPT_FLAGS_O2)
O2: $(TARGET)_O2.exe

O3: CXXFLAGS += $(OPT_FLAGS_O3)
O3: $(TARGET)_O3.exe

# Rule for building executable with -O1
$(TARGET)_O1.exe: $(SRC)
	@echo "Building target with -O1: $@"
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

# Rule for building executable with -O2
$(TARGET)_O2.exe: $(SRC)
	@echo "Building target with -O2: $@"
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

# Rule for building executable with -O3
$(TARGET)_O3.exe: $(SRC)
	@echo "Building target with -O3: $@"
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

# Rule for building and running tests
test: test_executable.exe

test_executable.exe: $(TESTS) $(SRC_NO_MAIN)
	@echo "Building test executable..."
	$(CXX) $(CXXFLAGS) -o $@ $(TESTS) $(SRC_NO_MAIN)

run_tests: test_executable.exe
	@echo "Running tests..."
	./test_executable.exe

# Clean rule
clean:
	rm -f $(TARGET)_O1.exe $(TARGET)_O2.exe $(TARGET)_O3.exe test_executable.exe
