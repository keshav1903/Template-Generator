
CXX=g++
CXXFLAGS=-std=c++17 -O2 -Wall -Wextra -pedantic
TARGET=gen_template

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
