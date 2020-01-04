#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>

typedef void * (* task_handler)(void *);

typedef struct task
{
    void * _task_params;
    task_handler  _handler;
} task;

task * create_task(void * task_param, task_handler handler);

void destroy_task(task * task_to_destroy);

#endif
