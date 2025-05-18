#ifndef __BAT_H__
#define __BAT_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 二叉树data结构

typedef int key_t;

// 二叉树节点结构
typedef struct node {
    key_t data; // 数据域
    struct node *left; // 左子树指针
    struct node *right; // 右子树指针
} Node;

// 二叉树结构
typedef struct {
    Node *root; // 根节点
} BinaryTree;

// 二叉树节点的创建
BinaryTree * create_binary_tree() ;

// 二叉树节点的销毁
int destroy_binary_tree(BinaryTree *tree) ;

// 二叉树节点的插入
int insert_binary_tree(BinaryTree *tree, key_t data) ;

// 二叉树节点的删除
// 删除在平衡二叉树中进行
int delete_binary_tree(BinaryTree *tree, key_t data) ;

// 二叉树节点的查找
Node * search_binary_tree(BinaryTree *tree, key_t data) ;

// 二叉树节点的遍历

// 先序遍历
int preorder_binary_tree(BinaryTree *tree) ;

// 中序遍历
int inorder_binary_tree(BinaryTree *tree) ;

// 后序遍历
int postorder_binary_tree(BinaryTree *tree) ;

// 层序遍历

int order_binary_tree(BinaryTree *tree);

#endif// __BAT_H__