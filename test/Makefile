TEST_LIB = ../output/libconcur-c.so
TEST_LIB_IN_LOCAL = $(wildcard $(TEST_LIB))

TARGET = libconcur_unittest
BUILD_OUTPUT_DIR = ../output

SRC := $(wildcard ./*.c)
OBJS := $(SRC:./%.c=./$(BUILD_OUTPUT_DIR)/%.o)
DEPS := $(SRC:./%.c=./$(BUILD_OUTPUT_DIR)/%.d)
CONCUR_LIB_OBJS := $(wildcard ../output/*.o)

CFLAGS = -g -Wall -Werror
INCLUDE_PATH = -I ..
LD_FLAGS = -lpthread


ifeq (${TEST_LIB_IN_LOCAL},)
abort:
	@echo "${TEST_LIB} need to be built first."
endif

all::

ifneq ($(MAKECMDGOALS),cov)
ifneq ($(MAKECMDGOALS),test)
ifneq ($(MAKECMDGOALS),gencov)
-include $(DEPS)
endif
endif
endif

all:: ${BUILD_OUTPUT_DIR}/${TARGET}

${BUILD_OUTPUT_DIR}/%.d: %.c
	@mkdir -p $(BUILD_OUTPUT_DIR)
	$(CC) -MM -MT "$(BUILD_OUTPUT_DIR)/$(subst .c,.o,${notdir $<}) $(BUILD_OUTPUT_DIR)/$(subst .c,.d,${notdir $<})" -MF "$(subst .c,.d,${BUILD_OUTPUT_DIR}/${notdir $<})" $<

$(BUILD_OUTPUT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

${BUILD_OUTPUT_DIR}/${TARGET}: ${OBJS} ${CONCUR_LIB_OBJS}
	${CC} ${CFLAGS} ${LD_FLAGS} -o $@  $^

cov : CFLAGS += -fprofile-arcs -ftest-coverage

cov : LD_FLAGS += -fprofile-arcs -ftest-coverage

cov : all

test:
	@valgrind --leak-check=full --show-reachable=yes -v ${BUILD_OUTPUT_DIR}/${TARGET} 2>&1 | tee valgrind.log
	@grep "0 errors from 0 contexts" valgrind.log

gencov:
	@cp *.c $(BUILD_OUTPUT_DIR)
	@gcov -r -o $(BUILD_OUTPUT_DIR) $(BUILD_OUTPUT_DIR)/*.c

.PHONY: cov test gencov
