#ifndef TEST_WRAPPER_H
#define TEST_WRAPPER_H

#include "task_queue_func_cases.h"

typedef int (* unit_test_func)(char * func_name);

void run_unit_test(unit_test_func func);

void run_unit_tests();


#endif
