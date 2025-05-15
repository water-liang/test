
#include "linked_list.h"


int main()
{
    LinkedList* list = create_linked_list();
    if (list == NULL) {
        printf("Failed to create linked list.\n");
        return -1;
    }

    // 添加节点到链表
    add_node_to_tail(list, 1);
    add_node_to_tail(list, 2);
    add_node_to_tail(list, 3);

    // 打印链表
    print_linked_list(list);

    // 查找节点
    Node* found_node = find_node(list, 2);
    if (found_node != NULL) {
        printf("Found node with value: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }

    // 删除节点
    delete_node(list, 2);
    print_linked_list(list);

    // 销毁链表
    destroy_linked_list(list);

    return 0;
}