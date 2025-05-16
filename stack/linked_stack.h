#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int ElementType;

// 栈的一个结点栈帧, 类型定义

typedef struct node {
    ElementType data; // 数据域
    struct node* next; // 指向下一个节点的指针
} Node;

// 栈的结构体
typedef struct {
    Node* top; // 指向栈顶元素的指针
    int size;  // 栈中元素的数量
} LinkedStack;

// 创建一个新的链式栈
LinkedStack * create_linked_stack() ;

// 销毁链式栈，释放内存
int destroy_linked_stack(LinkedStack * stack) ;

// 判断栈是否为空
int is_empty_linked_stack(LinkedStack * stack) ;

// 获取栈的大小
int get_size_linked_stack(LinkedStack * stack) ;

// 入栈操作
int push_linked_stack(LinkedStack * stack, ElementType value) ;
// 出栈操作
int pop_linked_stack(LinkedStack * stack, ElementType * value) ;

// 访问栈顶元素
int get_top_linked_stack(LinkedStack * stack, ElementType * value) ;

//  打印栈
int print_linked_stack(LinkedStack * stack) ;



#endif // __LINKED_STACK_H__