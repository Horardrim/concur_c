#include "task_queue.h"

task_queue * _task_queue()
{
    task_queue * new_task_queue = (task_queue *)malloc(sizeof(task_queue));

    if (new_task_queue == NULL)
    {
        return new_task_queue;
    }

    new_task_queue->_head = NULL;
    new_task_queue->_tail = NULL;
    new_task_queue->_size = 0;

    new_task_queue->clear = _clear;
    new_task_queue->append_head = _append_head;
    new_task_queue->append_tail = _append_tail;
    return new_task_queue;
}

void task_queue_(task_queue * queue)
{
    queue->clear(queue);
    free(queue);
}

void _append_head(task_queue * target_queue, task * insert_task)
{
    if (target_queue->_head == NULL &&
        target_queue->_tail == NULL)
    {
        task_node * node = _task_node(insert_task);
        if (node == NULL)
        {
            return;
        }

        target_queue->_head = node;
        target_queue->_tail = node;
    }
    else if (target_queue->_head != NULL &&
             target_queue->_tail != NULL)
    {
        task_node * node = _task_node(insert_task);
        if (node == NULL)
        {
            return;
        }

        node->_next = target_queue->_head;
        target_queue->_head = node;
    }
    else
    {
        printf("[WARNING] the situation that either head or tail is NULL shall not happen when adding task from head.\n");
        return;
    }

    target_queue->_size += 1;
}

void _append_tail(task_queue * target_queue, task * insert_task)
{
    if (target_queue->_head == NULL &&
        target_queue->_tail == NULL)
    {
        task_node * node = _task_node(insert_task);
        if (node == NULL)
        {
            return;
        }

        target_queue->_head = node;
        target_queue->_tail = node;
    }
    else if (target_queue->_head != NULL &&
             target_queue->_tail != NULL)
    {
        task_node * node = _task_node(insert_task);
        if (node == NULL)
        {
            return;
        }

        target_queue->_tail->_next = node;
        target_queue->_tail = node;
    }
    else
    {
        printf("[WARNING] the situation that either head or tail is NULL shall not happen when adding task from head.\n");
        return;
    }

    target_queue->_size += 1;
}

void _clear(task_queue * target_queue)
{
    if (target_queue->_head == NULL &&
        target_queue->_tail == NULL)
    {
        return;
    }

    while (target_queue->_head != target_queue->_tail)
    {
        task_node * node_remove = target_queue->_head;
        task_node_(node_remove);

        target_queue->_head = node_remove->_next;
    }

    task_node * last_node = target_queue->_head;
    task_node_(last_node);

    target_queue->_head = NULL;
    target_queue->_tail = NULL;
    target_queue->_size = 0;
}

task_node * _task_node(task * incoming_task)
{
    task_node * node = (task_node *)malloc(sizeof(task_node));

    if (node == NULL)
    {
        return node;
    }

    node->_task = incoming_task;
    node->_next = NULL;

    return node;
}

void task_node_(task_node * node)
{
    task_(node->_task);
    free(node);
}
