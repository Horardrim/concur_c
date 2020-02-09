#ifndef THREAD_H
#define THREAD_H

#include "task.h"

struct thread_t;

typedef void * (* thread_routine)(void *);
typedef void (* _start_func)(struct thread_t *, task *);

typedef struct thread_t
{
    pthread_t _tid;
    volatile int _joined;
    volatile int _started;
    task *  _thread_task;
    thread_routine _main_routine;

    _start_func start;
} thread_t;

thread_t * _thread_t();
void thread_t_(thread_t * thread);

#endif
