#ifndef __HAHS_H__
#define __HAHS_H__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>

#define HASH_INIT_SIZE 16 // 哈希表初始大小

// 此时哈希表用于存储字符串类型的键值对
typedef char * key_t;
typedef char * value_t;

// hash 节点
// 以list存储,单链表存储
typedef struct hash_node {
    key_t key;
    value_t value;
    struct hash_node *next;
} hash_node_t;

// hash 表
typedef struct {
    hash_node_t * buckets[HASH_INIT_SIZE]; // 哈希表
    // 哈希函数需要的种子值
    uint32_t seed;
}hash_table_t;

// 创建一个固定容量的哈希表
hash_table_t * hash_table_create(size_t size);
// 销毁哈希表
int hash_table_destroy(hash_table_t *table);

// 插入一个键值对
value_t hash_table_insert(hash_table_t *table, key_t key, value_t value);
// 查找一个键值对
value_t hash_table_search(hash_table_t *table, key_t key);
// 删除一个键值对
int hash_table_delete(hash_table_t *table, key_t key);
// 打印哈希表
void hash_table_print(hash_table_t *table);

#endif