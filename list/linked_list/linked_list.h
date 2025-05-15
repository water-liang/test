#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;

// 定义链表节点结构体
typedef struct node {
    DataType data;           // 数据域
    struct node* next;      // 指向下一个节点的指针
} Node;

// 定义链表结构体
typedef struct LinkedList {
    Node* head;             // 指向链表头节点的指针
    Node* tail;             // 指向链表尾节点的指针
    int size;              // 链表中节点的数量
} LinkedList;

// 创建一个新的链表
LinkedList* create_linked_list();
// 销毁链表，释放内存
int  destroy_linked_list(LinkedList* list);
// 尾插入链表
int add_node_to_tail(LinkedList* list, DataType value);
// 头插入链表
int add_node_to_head(LinkedList* list, DataType value);
// 删除链表中的节点
int delete_node(LinkedList* list, DataType value);
// 查找链表中的节点
Node* find_node(LinkedList* list, DataType value);
// 遍历打印链表
int print_linked_list(LinkedList* list);

#endif // __LINKED_LIST_H__