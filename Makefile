CXX = g++
CXXFLAGS = -std=c++20 -Wall -Iinclude

LDFLAGS =

SOURCES = $(wildcard src/*.cpp) main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = central_server

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
