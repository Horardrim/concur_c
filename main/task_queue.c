#include "task_queue.h"

task_queue * init_task_queue()
{
    task_queue * new_task_queue = (task_queue *)malloc(sizeof(task_queue));
    new_task_queue->_head = NULL;
    new_task_queue->_tail = NULL;

    return new_task_queue;
}

void append_head(task_queue * target_queue, task * insert_task)
{
    if (target_queue->_head == NULL &&
        target_queue->_tail == NULL)
    {
        task_node * node = (task_node *)malloc(sizeof(task_node));
        node->_task = insert_task;
        node->_next = NULL;
        target_queue->_head = node;
        target_queue->_tail = node;
    }
    else if (target_queue->_head != NULL &&
             target_queue->_tail != NULL)
    {
        task_node * node = (task_node *)malloc(sizeof(task_node));
        node->_task = insert_task;
        node->_next = target_queue->_head;
        target_queue->_head = node;
    }
    else
    {
        printf("[WARNING] this condition shall not be hit when adding task from head.\n");
    }
}

void append_tail(task_queue * target_queue, task * insert_task)
{
    if (target_queue->_head == NULL &&
        target_queue->_tail == NULL)
    {
        task_node * node = (task_node *)malloc(sizeof(task_node));
        node->_task = insert_task;
        node->_next = NULL;
        target_queue->_head = node;
        target_queue->_tail = node;
    }
    else if (target_queue->_head != NULL &&
             target_queue->_tail != NULL)
    {
        task_node * node = (task_node *)malloc(sizeof(task_node));
        node->_task = insert_task;
        node->_next = NULL;
        target_queue->_tail->_next = node;
        target_queue->_tail = node;
    }
    else
    {
        printf("[WARNING] this condition shall not be hit when adding task from tail.\n");
    }
}

void clear_queue(task_queue * target_queue)
{
    if (target_queue->_head == NULL &&
        target_queue->_tail == NULL)
    {
        return;
    }

    while (target_queue->_head != target_queue->_tail)
    {
        task_node * node_remove = target_queue->_head;
        task * task_remove = node_remove->_task;
        free(task_remove);
        free(node_remove);

        target_queue->_head = node_remove->_next;
    }

    task_node * last_node = target_queue->_head;
    task * last_task = last_node->_task;
    free(last_node);
    free(last_task);

    target_queue->_head = NULL;
    target_queue->_tail = NULL;
}
