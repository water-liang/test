#include "bat.h"


// 二叉树的递归删除
static int destroy_binary_tree_node(Node *node)
{
    if(NULL == node)
    {
        return 0;
    }

    destroy_binary_tree_node(node->left);
    destroy_binary_tree_node(node->right);

    free(node);

    return 0;
}

// 二叉树节点的创建
BinaryTree * create_binary_tree()
{
    // 创建 树
    BinaryTree * root = (BinaryTree *) malloc(sizeof(BinaryTree));
    if(NULL == root)
    {
        return NULL;
    }

    memset(root,0,sizeof(BinaryTree));

    return root;
}

// 二叉树节点的销毁
int destroy_binary_tree(BinaryTree *tree)
{
    if(NULL == tree)
    {
        return 0;
    }
    Node * root = tree->root;

    //递归销毁
    destroy_binary_tree_node(root);
    free(tree);
    return 0;
}

// 插入node
static int  insert_binary_tree_node(Node *root, Node* data_node)
{
    if(NULL == root)
    {
        return -1;
    }

    // 修正为标准BST插入逻辑：小的在左，大的在右
    if(data_node->data < root->data)
    {
        if(NULL == root->left)
        {
            root->left = data_node;
        }
        else
        {
            return insert_binary_tree_node(root->left,data_node);
        }
    }
    else
    {
        if(NULL == root->right)
        {
            root->right = data_node;
        }
        else
        {
            return insert_binary_tree_node(root->right,data_node);
        }
    }

    return 0;
}

// 二叉树节点的插入
int insert_binary_tree(BinaryTree *tree, key_t data)
{
    if(NULL == tree)
    {
        return -1;
    }

    Node * node = (Node *) malloc(sizeof(Node));
    if(NULL == node)
    {
        return -1;
    }

    memset(node,0,sizeof(Node));

    node->data = data;

    // 如果树为空，则将新节点作为根节点
    if(tree->root == NULL)
    {
        tree->root = node;
        return 0;
    }
    else
    {
        return insert_binary_tree_node(tree->root,node);
    }

    return 0;
}

// 查询node
static Node * search_binary_tree_node(Node * node,key_t data)
{
    if(NULL == node)
    {
        return NULL;
    }

    if(node->data == data){
        return node;
    }else if (data < node->data){
        return search_binary_tree_node(node->left,data);
    }else{
        return search_binary_tree_node(node->right,data);
    }
        
}

// 二叉树节点的查找
Node * search_binary_tree(BinaryTree *tree, key_t data)
{
    if(NULL == tree || NULL == tree->root )
    {
        return NULL;
    }

    return search_binary_tree_node(tree->root,data);

}

// 先序遍历
static int preorder_prinf(Node * root)
{
    if(NULL == root)
    {
        return 0;
    }

    printf("%d  ",root->data);
    preorder_prinf(root->left);
    preorder_prinf(root->right);
    return 0;
}

// 先序遍历
int preorder_binary_tree(BinaryTree *tree) 
{
    if(NULL == tree || NULL == tree->root )
    {
        return 0;
    }

    preorder_prinf(tree->root);
    printf("\n");
    return 0;
}



