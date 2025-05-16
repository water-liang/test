#include "hash.h"


/* murmur_hash2  hash 函数*/
static uint32_t hash(const void* key, int len, uint32_t seed)
{
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    uint32_t h = seed ^ len;
    const unsigned char * data = (const unsigned char*)key;
    while (len >= 4) {
        uint32_t k = *(uint32_t*)data;
        k *= m;
        k ^= k >> r;
        k *= m;
        h *= m;
        h ^= k;
        data += 4;
        len -= 4;
    }
    switch (len) {
        case 3: h ^= data [2] << 16;
        case 2: h ^= data [1] << 8;
        case 1: h ^= data [0];
            h *= m;
    };
    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;
    return h;
}


// 创建一个固定容量的哈希表
hash_table_t * hash_table_create(size_t size)
{
    hash_table_t *table = (hash_table_t *)malloc(sizeof(hash_table_t));
    if (table == NULL) {
        return NULL;
    }

    memset(table, 0, sizeof(hash_table_t));
    table->seed = time(NULL);
    return table;
}

// 销毁哈希表
int hash_table_destroy(hash_table_t *table)
{
    if(table == NULL)
    {
        return -1;
    }

    // 释放每个桶中的链表
    for (int i = 0; i < HASH_INIT_SIZE; i++) {
        hash_node_t *node = table->buckets[i];
        while (node) {
            hash_node_t *temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(table);
    return 0;
}

// 插入一个键值对
// 返回旧值，不存在，则返回null
value_t hash_table_insert(hash_table_t *table, key_t key, value_t value)
{
    if (table == NULL || key == NULL || value == NULL) {
        return -1;
    }

    // 计算哈希值
    uint32_t hash_value = hash(key, strlen(key), table->seed) % HASH_INIT_SIZE;
    //2.遍历哈希桶，查找 Key 是否存在
    hash_node_t * curr = table->buckets[hash_value];
    while (curr != NULL)
    {
        if(strcmp(curr,key) == 0)
        {
            // 如果 Key 已经存在，则更新 Value
            value_t old_value = curr->value;
            curr->value = value;
            return old_value;
        }
        curr = curr->next;
    }

    // 3.如果 Key 不存在，则创建新的节点
    hash_node_t *new_node = (hash_node_t *)malloc(sizeof(hash_node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->key = key;
    new_node->value = value;
    // 用头插法
    new_node->next = table->buckets[hash_value];
    table->buckets[hash_value] = new_node;

    return NULL;
}


// 查找一个键值对
value_t hash_table_search(hash_table_t *table, key_t key)
{
    if (table == NULL || key == NULL) {
        return NULL;
    }

    // 计算哈希值
    uint32_t hash_value = hash(key, strlen(key), table->seed) % HASH_INIT_SIZE;
    //2.遍历哈希桶，查找 Key 是否存在
    hash_node_t * curr = table->buckets[hash_value];
    while (curr !=NULL)
    {
        if(strcmp(curr->key,key) == 0)
        {
            // 如果 Key 已经存在，则返回 Value
            return curr->value;
        }
        curr = curr->next;
    }
    
    return NULL;
}


// 删除一个键值对
int hash_table_delete(hash_table_t *table, key_t key)
{
    if (table == NULL || key == NULL) {
        return -1;
    }

    // 计算哈希值
    uint32_t hash_value = hash(key, strlen(key), table->seed) % HASH_INIT_SIZE;
    //2.遍历哈希桶，查找 Key 是否存在
    hash_node_t * curr = table->buckets[hash_value];
    // 退化成list的删除操作
    hash_node_t * p_curr = NULL;
    while (curr !=NULL)
    {
        if(strcmp(curr->key,key) == 0)
        {
            // curr为头节点
            if (p_curr == NULL)
            {
               table->buckets[hash_value] = curr->next;
            }
            else
            {
                p_curr->next = curr->next;  
            }
            
            return 0;
        }
        p_curr = curr;
        curr = curr->next;
    }

    return -1;
}


void hash_table_print(hash_table_t *table)
{
    if (table == NULL) 
    {
        return NULL;
    }

    for (size_t i = 0; i < HASH_INIT_SIZE; i++)
    {
        hash_node_t * curr = table->buckets[i];

        while (curr!=NULL)
        {
            printf("key:%s value:%s",curr->key,curr->value);
            curr = curr->next;
        }
        
    }
    
    return NULL;
}