#include "task_queue_func_cases.h"

typedef int (* unit_test_func)(char * func_name);
extern void run_unit_test(unit_test_func func);

/**
 * Test name: task_queue_func_case_001
 * Description: initiate an empty task queue. It's head and tail shall be NULL.
 */
static int task_queue_func_case_001(char * unit_test_func_name)
{
    strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = init_task_queue();

    if (test_queue->_head != NULL ||
        test_queue->_tail != NULL)
    {
        printf("[ERROR] Both tail and head of a task queue shall have been NULL.\n");
        return 1;
    }
    free(test_queue);
    return 0;
}

void run_task_queue_func_cases()
{
    run_unit_test(task_queue_func_case_001);
}
