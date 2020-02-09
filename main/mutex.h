#ifndef MUTEX_H
#define MUTEX_H

struct mutex_t;

typedef void (* _lock_func)(struct mutex_t *);
typedef void (* _unlock_func)(struct mutex_t *);

typedef struct mutex_t
{
    pthread_mutex_t _mutex;
    pid_t _holder;

    _lock_func lock;
    _unlock_func unlock;
} mutex_t;

mutex_t * _mutex_t();
void mutex_t_(mutex_t * mutex);

#endif
