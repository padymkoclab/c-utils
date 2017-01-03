
FILENAME=main
C_FILENAME=$(FILENAME).c
EXECUTABLE_FILENAME=__$(FILENAME)__


TEST_FOLDER=tests
TEST_FILENAME=test_$(FILENAME)
TEST_FILENAME_STARTSWITh=test_
TEST_EXECUTABLE_FILENAME=__$(TEST_FILENAME)__

all: run_main

run_main: $(C_FILENAME)
	@ gcc -Wall -std=c11 -I /usr/include/ -o $(EXECUTABLE_FILENAME) $(C_FILENAME)
	@ ./$(EXECUTABLE_FILENAME)
	@ rm $(EXECUTABLE_FILENAME)

test:
	@ for filename in $(sort $(wildcard $(TEST_FOLDER)/*)); do \
		gcc -Wall -std=c11 $$filename -o $(TEST_EXECUTABLE_FILENAME); \
		./$(TEST_EXECUTABLE_FILENAME);\
		rm $(TEST_EXECUTABLE_FILENAME);\
	done
