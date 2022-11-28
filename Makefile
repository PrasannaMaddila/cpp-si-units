CC=g++
FLAGS=-std=c++20 -fsanitize=address -fpermissive
GTEST=-lgtest
UNIT=unit
UNITS=units
TESTFILE=test_units

units: $(TESTFILE).cpp $(UNITS).hpp
	@clear
	$(CC) $(TESTFILE).cpp $(GTEST) $(FLAGS) -o $(TESTFILE).o

run: $(TESTFILE).o 
	@clear
	@echo "Running test suite for units.hpp ... "
	./$(TESTFILE).o

unit: $(UNIT).cpp
	$(CC) $(FLAGS) $(UNIT).cpp -o $(UNIT).o
	./$(UNIT).o


