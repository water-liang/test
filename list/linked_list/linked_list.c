#include "linked_list.h"

// 创建一个新的链表
LinkedList* create_linked_list()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL; // 内存分配失败
    }
    list->head = NULL; // 初始化头指针为空
    list->tail = NULL; // 初始化尾指针为空
    list->size = 0;    // 初始化链表大小为0
    return list;
}

// 销毁链表，释放内存
int  destroy_linked_list(LinkedList* list)
{
    if (list == NULL ) 
    {
        return -1; // 链表为空，无法销毁
    }

    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
    return 0;
}

// 尾插入链表
int add_node_to_tail(LinkedList* list, DataType value)
{
    if (list == NULL) {
        return -1; // 链表为空，无法插入
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -1; // 内存分配失败
    }
    new_node->data = value;
    new_node->next = NULL;

    // 如果尾结点指针是 NULL，说明链表尾插前为空，那么新结点同时成为第一个结点和尾结点
    if (list->tail == NULL) {
        // 链表为空，头尾指针都指向新节点
        list->head = new_node;
        list->tail = new_node;
        list->size++; // 更新链表大小
        return 0;
    } 

    // 链表非空，将新节点添加到尾部
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++; // 更新链表大小
    return 0;
}

// 头插入链表
int add_node_to_head(LinkedList* list, DataType value)
{
    if (list == NULL) {
        return -1; // 链表为空，无法插入
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -1; // 内存分配失败
    }
    new_node->data = value;
    new_node->next = list->head; // 新节点指向原来的头节点

    if (list->tail == NULL)
    {
       list->tail = new_node; // 如果链表为空，尾指针也指向新节点
    }
    
    list->head = new_node; // 更新头指针
    list->size++; // 更新链表大小
    return 0;

}

// 删除链表中的节点
int delete_node(LinkedList* list, DataType value)
{
    if (list == NULL || list->head == NULL) {
        return -1; // 链表为空，无法删除
    }
    Node* current = list->head;
    Node* previous = NULL;
    while(current!=NULL)
    {
        // 确定删除的节点
        if (current->data == value)
        {
            // 如果删除的是头节点
            if(current == list->head)
            {
                list->head = current->next; // 更新头指针
                if (current->next == NULL) // 只有一个节点
                {
                    list->tail = NULL; // 更新尾指针
                }
            }
            else
            {
                // 删除中间节点
                previous->next = current->next; // 更新前一个节点的指针
                if (current->next == NULL) // 如果删除的是尾节点
                {
                    list->tail = previous; // 更新尾指针
                }
            }

            free(current);
            list->size--; // 更新链表大小
            return 0;
        }

        previous = current;
        current = current->next;
        
    }

    return 0;

}

// 查找链表中的节点
Node* find_node(LinkedList* list, DataType value)
{
    if (list == NULL || list->head == NULL) 
    {
        return NULL; // 链表为空，无法查找
    }
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current; // 找到节点，返回指针
        }
        current = current->next;
    }
    return NULL; // 未找到节点
}

// 遍历打印链表
int print_linked_list(LinkedList* list)
{
    if (list == NULL || list->head == NULL) 
    {
        return -1; // 链表为空，无法打印
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return 0;
} 