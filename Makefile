# compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g # -Wall -Wextra for more warning -g for debugging

TARGET = calculator

SRCS = main.cpp mathfuncs.cpp randfuncs.cpp

# object files derived from SRCS by replaceing .cpp with .o
OBJS = $(SRCS:.cpp=.o)

# default target build all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
