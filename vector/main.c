#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int main()
{
    // 创建一个动态数组
    Vector* vector = create_vector(5);
    if (vector == NULL) {
        printf("Failed to create vector\n");
        return -1;
    }

    // 向动态数组末尾添加元素
    for (int i = 0; i < 10; i++) {
        if (vector_push_back(vector, i) != 0) {
            printf("Failed to push back %d\n", i);
            destroy_vector(vector);
            return -1;
        }
    }

    // 打印动态数组
    vector_print(vector);

    // 删除最后一个元素
    if (vector_pop_back(vector) != 0) {
        printf("Failed to pop back\n");
        destroy_vector(vector);
        return -1;
    }

    // 打印动态数组
    vector_print(vector);

    // 获取指定索引的元素
    int index = 3;
    ElementType* element = vector_get_by_index(vector, index);
    if (element != NULL) {
        printf("Element at index %d: %d\n", index, *element);
    } else {
        printf("Failed to get element at index %d\n", index);
    }

    // 在指定位置插入元素
    int insert_index = 2;
    ElementType insert_value = 99;
    if (vector_insert(vector, insert_index, insert_value) != 0) {
        printf("Failed to insert %d at index %d\n", insert_value, insert_index);
        destroy_vector(vector);
        vector = NULL;
        return -1;
    }

    // 打印动态数组
    vector_print(vector);

    // 删除指定位置的元素
    int delete_index = 4;
    if (vector_delete(vector, delete_index) != 0) {
        printf("Failed to delete element at index %d\n", delete_index);
        destroy_vector(vector);
        vector= NULL;
        return -1;
    }

    // 打印动态数组
    vector_print(vector);

    // 销毁动态数组
    destroy_vector(vector);
    vector = NULL;
    return 0;
}