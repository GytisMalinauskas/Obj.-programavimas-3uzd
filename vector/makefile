# Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iheaders

# Šaltinio failai
SRC = $(wildcard source/*.cpp)

# Vykdomasis failas
TARGET = run

# Optimization levels
OPT_LEVELS = O1 O2 O3
OPT_FLAGS_O1 = -O1
OPT_FLAGS_O2 = -O2
OPT_FLAGS_O3 = -O3

# Pagrindinė taisyklė
all: $(OPT_LEVELS)

# Targets for each optimization level
O1: CXXFLAGS += $(OPT_FLAGS_O1)
O1: $(TARGET)_O1

O2: CXXFLAGS += $(OPT_FLAGS_O2)
O2: $(TARGET)_O2

O3: CXXFLAGS += $(OPT_FLAGS_O3)
O3: $(TARGET)_O3

# Vykdomojo failo taisyklė
$(TARGET)_O1:
	@echo "Building target with -O1: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O1) -o $@ $(SRC)

$(TARGET)_O2:
	@echo "Building target with -O2: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O2) -o $@ $(SRC)

$(TARGET)_O3:
	@echo "Building target with -O3: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O3) -o $@ $(SRC)

# Švaros taisyklė
clean:
	rm -f $(TARGET)_O1 $(TARGET)_O2 $(TARGET)_O3
