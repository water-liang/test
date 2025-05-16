#include "queue.h"
#include <stdbool.h>

// 创建
DynamicQueue * create_dynamic_queue(int capacity)
{
    DynamicQueue * queue = (DynamicQueue *)malloc(sizeof(DynamicQueue));
    if (queue == NULL)
    {
        return NULL;
    }

    memset(queue,0,sizeof(DynamicQueue));

    queue->data = (ElementType*) malloc(sizeof(ElementType)*capacity);
    if(NULL== queue->data)
    {
        free(queue);
        return NULL;
    }
    memset(queue->data,0,sizeof(ElementType)*capacity);

    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;

    return queue;
    
}

// 销毁
int destroy_dynamic_queue(DynamicQueue * queue)
{
    if(NULL==queue) return 0;

    if(NULL!=queue->data)
    {
        free(queue->data);
    }

    free(queue);
    return 0;
}


int is_empty_dynamic_queue(DynamicQueue * queue)
{
    return queue->size ==0? true:false;
}

int is_full_dynamic_queue(DynamicQueue * queue)
{
    return queue->size == queue->capacity?true:false;
}

// 入队
// 队头插入元素
int enqueue_dynamic_queue(DynamicQueue * queue, ElementType value)
{
    //判断队列是否满
    if(is_full_dynamic_queue(queue))
    {
        return -1;
    }

    // 插入尾部
    *(queue->data+queue->rear) = value;
    // 修改rear位置
    queue->rear = (queue->rear+1)%(queue->capacity);
    
    queue->size++;

    return 0;
}

// 出队
// front 出队
int dequeue_dynamic_queue(DynamicQueue * queue, ElementType * value)
{
    if(is_empty_dynamic_queue(queue))
    {
        return -1;
    }

    *value =  queue->data[queue->front];

    queue->data[queue->front] = -1;
    queue->front = (queue->front+1)%(queue->capacity);
    queue->size--;
    return 0;
}


int get_front_dynamic_queue(DynamicQueue * queue, ElementType * value)
{
    if(is_empty_dynamic_queue(queue))
    {
        return -1;
    }

    *value = queue->data[queue->front];
    return 0;
}

int print_dynamic_queue(DynamicQueue * queue)
{
    if(NULL==queue) return 0;

    for(int i =0;i< queue->capacity;i++)
    {
        printf("%d ==>",queue->data[i]);
    }
    printf("\n");
    return 0;
}