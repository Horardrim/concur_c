#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include "mutex.h"

#define gettid() syscall(SYS_gettid)

static void _lock(mutex_t * mutex)
{
    int res = pthread_mutex_lock(&mutex->_mutex);
    if (__builtin_expect(res != 0, 0))
    {
        printf("[Warning] lock mutex failed\n");
        return;
    }

    mutex->_holder = gettid();
}

static void _unlock(mutex_t * mutex)
{
    int res = pthread_mutex_unlock(&mutex->_mutex);
    if (__builtin_expect(res != 0, 0))
    {
        printf("[Warning] unlock mutex failed\n");
        return;
    }
    mutex->_holder = 0;
}

mutex_t * _mutex_t()
{
    mutex_t * ins = (mutex_t *)malloc(sizeof(mutex_t));
    if (__builtin_expect(ins == NULL, 0))
    {
        return ins;
    }

    int res = pthread_mutex_init(&ins->_mutex, NULL);
    if (__builtin_expect(res != 0, 0))
    {
        free(ins);
        return NULL;
    }

    ins->_holder = 0;
    ins->lock = _lock;
    ins->unlock = _unlock;
    return ins;
}

void mutex_t_(mutex_t * mutex)
{
    int res = pthread_mutex_destroy(&mutex->_mutex);
    if (__builtin_expect(res != 0, 0))
    {
        printf("[Warning] destroy mutex failed\n");
    }
    free(mutex);
}