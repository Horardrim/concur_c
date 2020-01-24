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

task * _task(void * task_param, task_handler handler);

void task_(task * task_to_destroy);

#endif
