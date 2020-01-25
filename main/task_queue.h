#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include "task.h"

struct task_node;
struct task_queue;

typedef void (* _clear_func)(struct task_queue *);
typedef int (* _append_head_func)(struct task_queue *, task *);
typedef int (* _append_tail_func)(struct task_queue *, task *);

typedef struct task_node
{
    task * _task;
    struct task_node * _next;
} task_node;

typedef struct task_queue
{
    task_node * _head;
    task_node * _tail;
    unsigned int _size;

    _clear_func clear;
    _append_head_func append_head;
    _append_tail_func append_tail;
} task_queue;

task_queue * _task_queue();
void task_queue_(task_queue * queue);

task_node * _task_node(task * incoming_task);
void task_node_(task_node * node);

#endif
