#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef int HPDataType;
 
typedef struct heap
{
 HPDataType *arr;
 int size;
 int capacity;
}Heap;



// 创建堆
void HeapInit(Heap* hp);

#endif// __HEAP_H__