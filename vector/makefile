# Compiler settings
CXX = clang++
CXXFLAGS = -std=c++14 -Wall -I../../headers -I../headers -I../vector/headers -Ivector/headers

# Source files
SRC = $(wildcard source/*.cpp)

# Test files
TEST_SRC = $(wildcard test/testavimas.cpp) source/function.cpp

# Executable target
TARGET = vector

# Test executable target
TEST_TARGET = run_tests

# Optimization levels
OPT_LEVELS = O1 O2 O3
OPT_FLAGS_O1 = -O1
OPT_FLAGS_O2 = -O2
OPT_FLAGS_O3 = -O3

# Main rule
all: $(OPT_LEVELS) create-bundle

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
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET)_O2: $(SRC)
	@echo "Building target with -O2: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET)_O3: $(SRC)
	@echo "Building target with -O3: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

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
	rm -rf vector.app

# Create .app bundle
create-bundle: $(TARGET)_O1 $(TARGET)_O2 $(TARGET)_O3
	@echo "Creating .app bundle"
	mkdir -p vector.app/Contents/MacOS
	mkdir -p vector.app/Contents/Resources
	cp $(TARGET)_O1 vector.app/Contents/MacOS/vector_O1
	cp $(TARGET)_O2 vector.app/Contents/MacOS/vector_O2
	cp $(TARGET)_O3 vector.app/Contents/MacOS/vector_O3
	@echo "Generating Info.plist"
	@echo '<?xml version="1.0" encoding="UTF-8"?>' > vector.app/Contents/Info.plist
	@echo '<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">' >> vector.app/Contents/Info.plist
	@echo '<plist version="1.0">' >> vector.app/Contents/Info.plist
	@echo '<dict>' >> vector.app/Contents/Info.plist
	@echo '    <key>CFBundleName</key>' >> vector.app/Contents/Info.plist
	@echo '    <string>Vector</string>' >> vector.app/Contents/Info.plist
	@echo '    <key>CFBundleDisplayName</key>' >> vector.app/Contents/Info.plist
	@echo '    <string>Vector</string>' >> vector.app/Contents/Info.plist
	@echo '    <key>CFBundleIdentifier</key>' >> vector.app/Contents/Info.plist
	@echo '    <string>com.yourcompany.vector</string>' >> vector.app/Contents/Info.plist
	@echo '    <key>CFBundleVersion</key>' >> vector.app/Contents/Info.plist
	@echo '    <string>1.0</string>' >> vector.app/Contents/Info.plist
	@echo '    <key>CFBundleExecutable</key>' >> vector.app/Contents/Info.plist
	@echo '    <string>vector_launcher</string>' >> vector.app/Contents/Info.plist
	@echo '    <key>LSMinimumSystemVersion</key>' >> vector.app/Contents/Info.plist
	@echo '    <string>10.10.0</string>' >> vector.app/Contents/Info.plist
	@echo '</dict>' >> vector.app/Contents/Info.plist
	@echo '</plist>' >> vector.app/Contents/Info.plist
	@echo "Creating launcher script"
	@echo '#!/bin/bash' > vector.app/Contents/MacOS/vector_launcher
	@echo 'echo "Select optimization level:"' >> vector.app/Contents/MacOS/vector_launcher
	@echo 'echo "1) O1"' >> vector.app/Contents/MacOS/vector_launcher
	@echo 'echo "2) O2"' >> vector.app/Contents/MacOS/vector_launcher
	@echo 'echo "3) O3"' >> vector.app/Contents/MacOS/vector_launcher
	@echo 'read -p "Enter choice [1-3]: " choice' >> vector.app/Contents/MacOS/vector_launcher
	@echo 'case $$choice in' >> vector.app/Contents/MacOS/vector_launcher
	@echo '  1) exec "$$(dirname "$$0")/vector_O1" ;;' >> vector.app/Contents/MacOS/vector_launcher
	@echo '  2) exec "$$(dirname "$$0")/vector_O2" ;;' >> vector.app/Contents/MacOS/vector_launcher
	@echo '  3) exec "$$(dirname "$$0")/vector_O3" ;;' >> vector.app/Contents/MacOS/vector_launcher
	@echo '  *) echo "Invalid choice"; exit 1 ;;' >> vector.app/Contents/MacOS/vector_launcher
	@echo 'esac' >> vector.app/Contents/MacOS/vector_launcher
	chmod +x vector.app/Contents/MacOS/vector_launcher
	@echo ".app bundle created successfully."

# Build and create bundle
build-bundle: all
