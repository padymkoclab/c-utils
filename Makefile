
C_STD_VERSION=c11
WARNNING=-Wall -Wextra
WARNNING=

FILENAME=setup
MAIN_FILENAME=$(FILENAME).c
MAIN_EXECUTABLE_FILENAME=__$(FILENAME)__


TEST_FOLDER=tests
TEST_FILENAME=test_$(FILENAME)
TEST_FILENAME_STARTSWITH=test_
TEST_EXECUTABLE_FILENAME=__$(TEST_FILENAME)__

TEST_RUNNER_PATH=utils/test
TEST_RUNNER_FILENAME=testrunner.c

all: compile

compile: $(MAIN_FILENAME)
	@ gcc $(WARNNING) -std=${C_STD_VERSION} -I /usr/include/ -o $(MAIN_EXECUTABLE_FILENAME) $(MAIN_FILENAME)
	@ ./$(MAIN_EXECUTABLE_FILENAME) -h
	@ rm $(MAIN_EXECUTABLE_FILENAME)

test:
	@ gcc -Wall -Wextra -std=${C_STD_VERSION} ${TEST_RUNNER_PATH}/${TEST_RUNNER_FILENAME} -o $(TEST_EXECUTABLE_FILENAME);
	@ ./$(TEST_EXECUTABLE_FILENAME) --folder=${TEST_FOLDER} --filename_startswith=${TEST_FILENAME_STARTSWITH}
	@ rm $(TEST_EXECUTABLE_FILENAME)

docs:
	# generate/update docs

macros:
	gcc -dM -E - < /dev/null | sed 's/^#define //g' | sort
