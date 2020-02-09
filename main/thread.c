#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "thread.h"

static void * thread_main_routine(void * param)
{
    thread_t * thread = (thread_t *)param;
    thread->_started = 1;
    thread->_thread_task->_handler(thread->_thread_task->_task_params);
    thread->_started = 0;
    return NULL;
}

static void _start(thread_t * thread, task * thread_task)
{
    thread->_thread_task = thread_task;
    int res = pthread_create(&thread->_tid, NULL, thread->_main_routine, thread);
    
    if (__builtin_expect(res != 0, 0))
    {
        thread->_thread_task = NULL;
        printf("[Warning] thread start failed.\n");
        return;
    }
}

thread_t * _thread_t()
{
    thread_t * ins = (thread_t *)malloc(sizeof(thread_t));

    if (__builtin_expect(ins == NULL, 0))
    {
        printf("[Warning] thread instance was allocated failed.\n");
        return ins;
    }

    ins->start = _start;
    ins->_thread_task = NULL;
    ins->_main_routine = thread_main_routine;
    ins->_started = 0;
    ins->_joined = 0;
    return ins;
}

void thread_t_(thread_t * thread)
{
    if (thread->_started != 0)
    {
        pthread_detach(thread->_tid);
    }
    free(thread);
}
