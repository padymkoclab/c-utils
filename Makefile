
INCLUDE=-I
LIB=-lm
STRICT_MODE=-Werror -Wextra
C_FLAGS=-std=c11 -Wall

BUILD_DIR=build
MAIN_FILENAME=main.c
EXECUTABLE=$(BUILD_DIR)/_start

TEST_FOLDER=tests
TEST_FILENAME=test_$(FILENAME)
TEST_FILENAME_STARTSWITH=test_
TEST_EXECUTABLE_FILENAME=__$(TEST_FILENAME)__

TEST_RUNNER_PATH=utils/test
TEST_RUNNER_FILENAME=testrunner.c


.PHONY: test build docs clean

all: clean build

build: $(MAIN_FILENAME)
	@ mkdir -p $(BUILD_DIR)
	@ $(CC) -E $< > $(BUILD_DIR)/main.i
	@ $(CC) $(C_FLAGS) -S $(BUILD_DIR)/main.i -o $(BUILD_DIR)/main.s
	@ $(AS) -o $(BUILD_DIR)/main.o $(BUILD_DIR)/main.s
	@ $(CC) -o ./$(EXECUTABLE) $(BUILD_DIR)/main.o $(LIB)
	@ ./$(EXECUTABLE)

test:
	@ $(CC) ${TEST_RUNNER_PATH}/${TEST_RUNNER_FILENAME} -o $(TEST_EXECUTABLE_FILENAME);
	@ ./$(TEST_EXECUTABLE_FILENAME) --folder=${TEST_FOLDER} --filename_startswith=${TEST_FILENAME_STARTSWITH}
	@ rm $(TEST_EXECUTABLE_FILENAME)

docs:
	# generate/update docs

debug_macros:
	$(CC) -dM -E - < /dev/null | sed 's/^#define //g' | sort

debug_lookups:
	@ echo | $(CC) -E -Wp,-v -

debug_headers: $(MAIN_FILENAME)
	@ $(CC) -M $<

clean:
	@ rm -rf $(EXECUTABLE) $(BUILD_DIR)
