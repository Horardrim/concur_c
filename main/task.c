#include "task.h"

task * _task(void * task_param, task_handler handler)
{
    task * new_task = (task *)malloc(sizeof(task));

    if (new_task == NULL)
    {
        return new_task;
    }

    new_task->_handler = handler;
    new_task->_task_params = task_param;

    return new_task;
}

void task_(task * task_to_destroy)
{
    free(task_to_destroy);
}
