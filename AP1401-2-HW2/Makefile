CXX = g++
CXXFLAGS = -std=c++23 -Wall -c
LXXFLAGS = -std=c++23
OBJECTS = src/main.o src/hw2.o src/unit_test.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET) -lgtest -lgtest_main -pthread
main.o: src/main.cpp src/unit_test.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp
hw2.o: src/hw2.cpp include/hw2.h
	$(CXX) $(CXXFLAGS) src/hw2.cpp
unit_test.o: src/unit_test.cpp
	$(CXX) $(CXXFLAGS) src/unit_test.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
