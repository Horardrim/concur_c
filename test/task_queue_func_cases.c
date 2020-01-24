#include "task_queue_func_cases.h"

typedef int (* unit_test_func)(char * func_name);
extern void run_unit_test(unit_test_func func);

/**
 * Test name: task_queue_func_case_001
 * Description: initiate an empty task queue. It's head and tail shall be NULL.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_001(char * unit_test_func_name)
{
    strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();

    if (test_queue == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    if (test_queue->_head != NULL ||
        test_queue->_tail != NULL)
    {
        printf("[ERROR] Both tail and head of a task queue shall have been NULL.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_002
 * Description: create an empty task queue and clean it, no memory issue shall have happened.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_002(char * unit_test_func_name)
{
    strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();

    if (test_queue == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    test_queue->clear(test_queue);
    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_003
 * Description: create an empty task queue and append a task from head, size will increase 1.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_003(char * unit_test_func_name)
{
    strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();
    task * test_task = _task(NULL, NULL);

    if (test_queue == NULL || test_task == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    int res = test_queue->append_head(test_queue, test_task);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    if (test_queue->_size != 1)
    {
        printf("[ERROR] Size shall have been 1 when append a task from head.\n");
        return 1;
    }

    if (test_queue->_head->_task != test_task)
    {
        printf("[ERROR] pointer of head shall have been test_task.\n");
        return 1;
    }

    if (test_queue->_tail->_task != test_task)
    {
        printf("[ERROR] pointer of tail shall have been test_task.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_004
 * Description: create an empty task queue and append a task from tail, size will increase 1.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_004(char * unit_test_func_name)
{
    strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();
    task * test_task = _task(NULL, NULL);

    if (test_queue == NULL || test_task == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    int res = test_queue->append_tail(test_queue, test_task);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    if (test_queue->_size != 1)
    {
        printf("[ERROR] Size shall have been 1 when append a task from head.\n");
        return 1;
    }

    if (test_queue->_head->_task != test_task)
    {
        printf("[ERROR] pointer of head shall have been test_task.\n");
        return 1;
    }

    if (test_queue->_tail->_task != test_task)
    {
        printf("[ERROR] pointer of tail shall have been test_task.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_005
 * Description: create an empty task queue and append two tasks from tail, size will be 2.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_005(char * unit_test_func_name)
{
strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();
    task * test_task1 = _task(NULL, NULL);
    task * test_task2 = _task(NULL, NULL);

    if (test_queue == NULL || test_task1 == NULL || test_task2 == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    int res = test_queue->append_tail(test_queue, test_task1);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from tail.\n");
        return 1;
    }

    res = test_queue->append_tail(test_queue, test_task2);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from tail second time.\n");
        return 1;
    }

    if (test_queue->_head->_task != test_task1)
    {
        printf("[ERROR] head pointer shall be test_task1.\n");
        return 1;
    }

    if (test_queue->_tail->_task != test_task2)
    {
        printf("[ERROR] tail pointer shall be test_task2.\n");
        return 1;
    }

    if (test_queue->_size != 2)
    {
        printf("[ERROR] Size shall have been 2 when appending 2 tasks from tail.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_006
 * Description: create an empty task queue and append two tasks from head, size will be 2.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_006(char * unit_test_func_name)
{
strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();
    task * test_task1 = _task(NULL, NULL);
    task * test_task2 = _task(NULL, NULL);

    if (test_queue == NULL || test_task1 == NULL || test_task2 == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    int res = test_queue->append_head(test_queue, test_task1);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from head .\n");
        return 1;
    }

    res = test_queue->append_head(test_queue, test_task2);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from head second time.\n");
        return 1;
    }

    if (test_queue->_head->_task != test_task2)
    {
        printf("[ERROR] head pointer shall be test_task2.\n");
        return 1;
    }

    if (test_queue->_tail->_task != test_task1)
    {
        printf("[ERROR] tail pointer shall be test_task1.\n");
        return 1;
    }

    if (test_queue->_size != 2)
    {
        printf("[ERROR] Size shall have been 2 when appending 2 tasks from head.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_007
 * Description: create an empty task queue and append one task from head then append the other from tail, size will be 2.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_007(char * unit_test_func_name)
{
strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();
    task * test_task1 = _task(NULL, NULL);
    task * test_task2 = _task(NULL, NULL);

    if (test_queue == NULL || test_task1 == NULL || test_task2 == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    int res = test_queue->append_head(test_queue, test_task1);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from head .\n");
        return 1;
    }

    res = test_queue->append_tail(test_queue, test_task2);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from tail second time.\n");
        return 1;
    }

    if (test_queue->_head->_task != test_task1)
    {
        printf("[ERROR] head pointer shall be test_task1.\n");
        return 1;
    }

    if (test_queue->_tail->_task != test_task2)
    {
        printf("[ERROR] tail pointer shall be test_task2.\n");
        return 1;
    }

    if (test_queue->_size != 2)
    {
        printf("[ERROR] Size shall have been 2 when appending 2 tasks.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_008
 * Description: create an empty task queue and append one task from tail then append the other from head, size will be 2.
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_008(char * unit_test_func_name)
{
strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();
    task * test_task1 = _task(NULL, NULL);
    task * test_task2 = _task(NULL, NULL);

    if (test_queue == NULL || test_task1 == NULL || test_task2 == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    int res = test_queue->append_tail(test_queue, test_task1);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from tail.\n");
        return 1;
    }

    res = test_queue->append_head(test_queue, test_task2);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from head second time.\n");
        return 1;
    }

    if (test_queue->_head->_task != test_task2)
    {
        printf("[ERROR] head pointer shall be test_task2.\n");
        return 1;
    }

    if (test_queue->_tail->_task != test_task1)
    {
        printf("[ERROR] tail pointer shall be test_task1.\n");
        return 1;
    }

    if (test_queue->_size != 2)
    {
        printf("[ERROR] Size shall have been 2 when appending 2 tasks.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

/**
 * Test name: task_queue_func_case_009
 * Description: create an empty task queue and append tasks(over 2) randomly from head or tail
 *              when clean the task queue size shall be 0 also both head and tail pointer shall be NULL
 *              Outage of memory will make this case failed.
 */
static int task_queue_func_case_009(char * unit_test_func_name)
{
strncpy(unit_test_func_name, __FUNCTION__, 512);
    printf("%s start\n", __FUNCTION__);

    task_queue * test_queue = _task_queue();
    task * test_task1 = _task(NULL, NULL);
    task * test_task2 = _task(NULL, NULL);
    task * test_task3 = _task(NULL, NULL);

    if (test_queue == NULL || test_task1 == NULL || test_task2 == NULL || test_task3 == NULL)
    {
        printf("[ERROR] memory outage happend.\n");
        return 1;
    }

    int res = test_queue->append_tail(test_queue, test_task1);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from head .\n");
        return 1;
    }

    res = test_queue->append_head(test_queue, test_task2);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from head second time.\n");
        return 1;
    }

    res = test_queue->append_tail(test_queue, test_task3);
    if (res != 0)
    {
        printf("[ERROR] memory outage happend when appending from tail third time.\n");
        return 1;
    }

    if (test_queue->_head->_task != test_task2)
    {
        printf("[ERROR] head pointer shall be test_task2.\n");
        return 1;
    }

    if (test_queue->_head->_next->_task != test_task1)
    {
        printf("[ERROR] pointer of middle one shall be test_task1.\n");
        return 1;
    }

    if (test_queue->_tail->_task != test_task3)
    {
        printf("[ERROR] tail pointer shall be test_task3.\n");
        return 1;
    }

    if (test_queue->_size != 3)
    {
        printf("[ERROR] Size shall have been 3 when appending 3 tasks.\n");
        return 1;
    }

    test_queue->clear(test_queue);
    if (test_queue->_size != 0)
    {
        printf("[ERROR] Size shall have been 0 when clearing task queue.\n");
        return 1;
    }

    if (test_queue->_head != NULL || test_queue->_tail != NULL)
    {
        printf("[ERROR] both head and tail pointer shall have been NULL.\n");
        return 1;
    }

    task_queue_(test_queue);
    return 0;
}

void run_task_queue_func_cases()
{
    run_unit_test(task_queue_func_case_001);
    run_unit_test(task_queue_func_case_002);
    run_unit_test(task_queue_func_case_003);
    run_unit_test(task_queue_func_case_004);
    run_unit_test(task_queue_func_case_005);
    run_unit_test(task_queue_func_case_006);
    run_unit_test(task_queue_func_case_007);
    run_unit_test(task_queue_func_case_008);
    run_unit_test(task_queue_func_case_009);
}
