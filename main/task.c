#include "task.h"

task * create_task(void * task_param, task_handler handler)
{
    task * new_task = (task *)malloc(sizeof(task));
    new_task->_handler = handler;
    new_task->_task_params = task_param;

    return new_task;
}

void destroy_task(task * task_to_destroy)
{
    free(task_to_destroy);
}
