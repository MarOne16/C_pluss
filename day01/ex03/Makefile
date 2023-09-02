CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra

# List of source files
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

# List of header files
HDRS = Weapon.hpp HumanA.hpp HumanB.hpp

# Output executable name
TARGET = main

all: $(TARGET)

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
