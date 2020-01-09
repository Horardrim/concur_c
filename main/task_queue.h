#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include "task.h"

typedef struct task_node
{
    task * _task;
    struct task_node * _next;
} task_node;

typedef struct task_queue
{
    task_node * _head;
    task_node * _tail;
} task_queue;

task_queue * init_task_queue();

void append_head(task_queue * target_queue, task * insert_task);

void append_tail(task_queue * target_queue, task * insert_task);

void clear_queue(task_queue * target_queue);

#endif
