#include "bat.h"
#include <stdio.h>

int main() {
    BinaryTree *tree = create_binary_tree();
    if (!tree) {
        printf("Create tree failed!\n");
        return 1;
    }

    // 插入节点
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < n; ++i) {
        insert_binary_tree(tree, values[i]);
    }

    // 先序遍历
    printf("Preorder: ");
    preorder_binary_tree(tree);

    // 查找节点
    int find_val = 4;
    Node *found = search_binary_tree(tree, find_val);
    if (found) {
        printf("Found node with value %d\n", found->data);
    } else {
        printf("Node with value %d not found\n", find_val);
    }

    // 销毁树
    destroy_binary_tree(tree);
    return 0;
}
