# Simple makefile for compiling ShuffleDeck Homework and executing

# Default it should already call all - but it doesn't hurt to be explicit
ODIR = obj
UDIR = unitTest
_COMMON_OBJ = Deck.o Table.o Shuffler.o
_TEST_OBJ = $(_COMMON_OBJ)
_TARGET_OBJ = $(_COMMON_OBJ) main.o
TARGET_OBJ = $(patsubst %,$(ODIR)/%,$(_TARGET_OBJ))

_TEST_FILES = Shuffler_test.cpp Deck_test.cpp Table_test.cpp test_main.cpp
TEST_OBJ = $(patsubst %,$(ODIR)/%,$(_TEST_OBJ))
TEST_SOURCES = $(patsubst %,$(UDIR)/%,$(_TEST_FILES))
CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -O2 is for optimization
#  -std=gnu++14 - C++14 to make use of unique_ptr and for_each
#  --coverage to generate coverage of src and unit test
CXXFLAGS  = -g -Wall -O2 -std=gnu++14
TARGET = shuffle

.PHONY = all

all: $(TARGET) test

#compiles the source
$(TARGET): $(TARGET_OBJ)
	@echo "...Compiling source code..."
	@mkdir -p bin;
	@$(CXX) $(CXXFLAGS) -o bin/$(TARGET) $^
	@echo "[SUCCESS] Source compiled successfully - shuffle is located at bin/shuffle"

$(ODIR)/%.o: src/%.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

#unit test - it also executes the test_runner for you
test: $(TEST_OBJ)
	@echo "...Compiling unit test..."
	@mkdir -p bin
	@$(CXX) $(CXXFLAGS) $^ $(TEST_SOURCES) -lgtest -lgtest_main -lpthread -o bin/test_runner
	@echo "[SUCCESS] Unit test compiled successfully"
	@echo  "...Executing test_runner..."
	@cd bin; ./test_runner


#change into the bin directory and run gcovr
#create an HTML page for easier readability
#create an XML for Code Coverage Trend on Jenkins
#run gcovr to provide a nice display while compiling
#.NOTPARALLEL:
#coverage:
#	@echo "Running code coverage..."
#	#TODO: come back and understand why gcovr is having difficulty processing the src folder
#	#@cd src/bin && gcovr -r $(PWD)/src . && gcovr --html -o src_coverage.html -r $(PWD)/src . && gcovr --xml-pretty -r $(PWD)/src . > src_coverage.xml ;
#	#@echo "src coverage HTML created at src/bin/src_coverage.html"
#	@cd unitTest/bin && gcovr -r $(PWD)/unitTest . && gcovr --html -o unitTest_coverage.html -r $(PWD)/unitTest . && gcovr --xml-pretty -r $(PWD)/unitTest . > unitTest_coverage.xml ;
#	@echo "unitTest coverage HTML created at unitTest/bin/src_coverage.html"

#clean the binary folders
clean:
	$(RM) -r bin/ $(ODIR)
