#include "linked_stack.h"

// 创建一个新的链式栈
LinkedStack * create_linked_stack() 
{
    LinkedStack * stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// 销毁链式栈，释放内存
int destroy_linked_stack(LinkedStack * stack)
{
    if (stack == NULL )
    {
        return 0;
    }
    
    Node* top = NULL;

    top = stack->top;
    while (top!=NULL)
    {
        Node * next = top->next;
        free(top);
        stack->size--;
        top = next;
    }
    
    free(stack);
    return 0;

}


// 判断栈是否为空
int is_empty_linked_stack(LinkedStack * stack)
{
    if (stack==NULL)
    {
        return -1;
    }

    return stack->size?0:-1;
    
}


// 获取栈的大小
int get_size_linked_stack(LinkedStack * stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    
    return stack->size;
}


// 入栈操作
int push_linked_stack(LinkedStack * stack, ElementType value)
{
    if (stack == NULL)
    {
        return -1;
    }

    // 后进先出，应该用头插法
    Node * temp_node = (Node * )malloc(sizeof(Node));
    memset(temp_node,0,sizeof(temp_node));
    temp_node->data = value;
    temp_node->next = stack->top;

    // 加入top list
    stack->top = temp_node;
    stack->size++;

    return 0;
}


// 出栈操作
int pop_linked_stack(LinkedStack * stack, ElementType * value)
{
    if (stack == NULL || value == NULL)
    {
        return -1;
    }
    if(stack->top == NULL)
    {
        return -1;
    }

    Node * top = stack->top;
    *value = top->data;
    // 释放内存
    stack->top = top->next;
    stack->size--;

    free(top);

    return 0;
}

// 访问栈顶元素
int get_top_linked_stack(LinkedStack * stack, ElementType * value)
{
    if (stack == NULL || value == NULL)
    {
        return -1;
    }
    if(stack->top == NULL)
    {
        return -1;
    }

    *value = stack->top->data;
    return 0;
    
}


//  打印栈
int print_linked_stack(LinkedStack * stack)
{
        if (stack == NULL)
    {
        return -1;
    }

    Node * top = stack->top;

    while (top!=NULL)
    {
        Node * next = top->next;
        printf("%d  ",top->data);
        top = next;
    }

    return 0;
    
}