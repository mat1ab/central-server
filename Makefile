CXX = g++
CXXFLAGS = -std=c++20 -Wall -Iinclude

CURRENT_DIR = $(shell pwd)
BUILD_DIR = $(CURRENT_DIR)/build
LOG_DIR = $(BUILD_DIR)/logs

SOURCES = $(wildcard src/*.cpp) main.cpp
OBJECTS = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE = $(BUILD_DIR)/central_server

all: $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJECTS) | $(BUILD_DIR) $(LOG_DIR)
	$(CXX) $^ -o $@

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/main.o: main.cpp | $(BUILD_DIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(LOG_DIR):
	mkdir -p $(LOG_DIR)

clean:
	rm -rf $(BUILD_DIR)
