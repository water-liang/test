#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
*   重点
*/

// 数组扩容

static int vector_resize(Vector* v)
{
    if (v == NULL) {
        return -1; // Invalid vector
    }
    int new_capacity = v->capacity * 2;
    ElementType* new_data = (ElementType*)realloc(v->data, new_capacity * sizeof(ElementType));
    if (new_data == NULL) {
        return -1; // Memory allocation failed
    }
    v->data = new_data;
    v->capacity = new_capacity;
    return 0;
}

// 创建一个动态数组
Vector* create_vector(int initial_capacity)
{
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    if (vector == NULL) {
        return NULL; // 内存分配失败
    }
    memset(vector, 0, sizeof(Vector)); // 初始化结构体

    vector->data = (ElementType*)malloc(initial_capacity * sizeof(ElementType));
    if (vector->data == NULL) {
        free(vector);
        return NULL; // 内存分配失败
    }
    memset(vector->data, 0, initial_capacity * sizeof(ElementType)); // 初始化数组
    vector->size = 0;
    vector->capacity = initial_capacity;
    return vector;
}

// 销毁一个 Vector 动态数组，释放内存
int destroy_vector(Vector* vector)
{
    if (vector == NULL) {
        return -1; // Invalid vector
    }
    if (vector->data != NULL) {
        free(vector->data);
        vector->data = NULL; // Avoid dangling pointer
    }
    free(vector);
    return 0;
}

// 向动态数组末尾添加一个元素
int vector_push_back(Vector* vector, ElementType value)
{
    if (vector == NULL) {
        return -1; // Invalid vector
    }
    // 检查是否需要扩展容量

    if (vector->size >= vector->capacity) {
        if (vector_resize(vector) != 0) {
            return -1; // Memory allocation failed
        }
    }
    vector->data[vector->size++] = value;
    return 0;
}

// 从动态数组中删除最后一个元素
int vector_pop_back(Vector* vector)
{
    if (vector == NULL || vector->size == 0) {
        return -1; // Invalid vector or empty vector
    }
    vector->data[vector->size - 1] = 0; // Optional: Clear the last element
    vector->size--;

    return 0;
}

// 获取动态数组中指定索引的元素
ElementType*  vector_get_by_index(Vector* vector, int index)
{
    if (vector == NULL || index < 0 || index >= vector->size) {
        return NULL; // Invalid vector or index out of bounds
    }
    return &vector->data[index];

}

// 动态数组指定位置插入元素
int vector_insert(Vector* vector, int index, ElementType value)
{
    if (vector == NULL || index < 0 || index > vector->size) {
        return -1; // Invalid vector or index out of bounds
    }
    // 检查是否需要扩展容量
    if (vector->size >= vector->capacity) {
        if (vector_resize(vector) != 0) {
            return -1; // Memory allocation failed
        }
    }
    // 移动元素以插入新元素
    // 元素往后移动
    for (int i = vector->size; i > index; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index] = value;
    vector->size++;
    return 0;

}

// 删除动态数组中指定位置的元素
int vector_delete(Vector* vector, int index)
{
    if (vector == NULL || index < 0 || index >= vector->size) {
        return -1; // Invalid vector or index out of bounds
    }
    // 元素往前移动
    for (int i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->data[vector->size - 1] = 0; // Optional: Clear the last element
    vector->size--;
    return 0;
}

//遍历打印整个 Vector 动态数组
int vector_print(Vector* vector)
{
    if (vector == NULL) {
        return -1; // Invalid vector
    }
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
    return 0;
}