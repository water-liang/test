#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 元素类型
typedef int ElementType;

// 队列节点
typedef struct dynamicqueue
{
    ElementType * data;
    int front;  // 队头
    int rear;   // 队尾
    int size;   // 队列当前大小
    int capacity;   // 队列最大容量
}DynamicQueue;

DynamicQueue * create_dynamic_queue(int capacity);
int destroy_dynamic_queue(DynamicQueue * queue);
int is_empty_dynamic_queue(DynamicQueue * queue);
int is_full_dynamic_queue(DynamicQueue * queue);
int enqueue_dynamic_queue(DynamicQueue * queue, ElementType value);
int dequeue_dynamic_queue(DynamicQueue * queue, ElementType * value);
int get_front_dynamic_queue(DynamicQueue * queue, ElementType * value);
int print_dynamic_queue(DynamicQueue * queue);

#endif// queue.h