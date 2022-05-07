# Simple makefile for compiling ShuffleDeck Homework and executing

# Default it should already call all - but it doesn't hurt to be explicit
.PHONY = all

CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -O2 is for optimization
#  -std=gnu++14 - C++14 to make use of unique_ptr and for_each
#  -fprofile-arcs and -ftest-coverage to generate coverage of src and unit test
CXXFLAGS  = -g -Wall -O2 -std=gnu++14 -fprofile-arcs -ftest-coverage

# 
TARGET = shuffle

all: $(TARGET) test

#compiles the source
$(TARGET):
	@echo "...Compile source code..."
	@mkdir -p src/bin; cd src/bin ; $(CXX) $(CXXFLAGS) -o $(TARGET) ../Deck.cpp ../Table.cpp ../Shuffler.cpp ../main.cpp
	@echo "[SUCCESS] Source compiled successfully - shuffle is located at src/bin/shuffle"


#unit test - it also executes the test_runner for you
test:
	@echo "...Compiling unit test..."
	@mkdir -p unitTest/bin ; cd unitTest/bin ; $(CXX) $(CXXFLAGS) -o test_runner ../Deck_test.cpp ../Table_test.cpp ../Shuffler_test.cpp ../test_main.cpp -lgtest -lgtest_main -lpthread
	@echo "[SUCCESS] Unit test compiled successfully"
	@echo  "...Executing test_runner..."
	@cd unitTest/bin; ./test_runner

#change into the bin directory and run gcovr
#create an HTML page for easier readability
#create an XML for Code Coverage Trend on Jenkins
#run gcovr to provide a nice display while compiling
.NOTPARALLEL:
coverage:
	@echo "Running code coverage..."
	#TODO: come back and understand why gcovr is having difficult processing the cpp
	#@cd src/bin &&  gcovr -r $(PWD)/src . && gcovr --html -o src_coverage.html -r $(PWD)/src . && gcovr --xml-pretty -r $(PWD)/src . > src_coverage.xml ;
	#@echo "src coverage HTML created at src/bin/src_coverage.html"
	@cd unitTest/bin && gcovr -r $(PWD)/unitTest . && gcovr --html -o unitTest_coverage.html -r $(PWD)/unitTest . && gcovr --xml-pretty -r $(PWD)/unitTest . > unitTest_coverage.xml ;
	@echo "unitTest coverage HTML created at unitTest/bin/src_coverage.html"

#clean the binary folders
clean:
	$(RM) -r src/bin/ unitTest/bin/
