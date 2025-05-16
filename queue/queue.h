#ifndef __QUEUE_H__
#define __QUEUE_H__

/*
* 实现一个 固定长度的数组队列
*   front 用于记录队头元素，出队时就将该元素出队。
*   rear 用于指示下一个元素入队的索引，也就是说入队操作时直接将元素插入 rear 索引位置就可以了。
*   front 标识已经存储元素，rear标识未存储元素
*   规定 front(包含)和 rear(不包含)索引之间的元素就是队列元素，
*   出队操作时，直接向后移动索引 front 就可以了，不需要任何赋值操作。
*   front 向后移动的方式是：(front + 1) % N
*   rear 向后移动的方式是：(rear + 1) % N
*/

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