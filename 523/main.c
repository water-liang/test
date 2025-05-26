
#include <stdio.h>

// list node
typedef struct node {
    int data;
    struct node * next; 
}Node;


typedef struct mylist {
    Node* head;
}Mylist;

int fanzhuan(Mylist* mylist)
{
    Node * p = mylist->head;

    Mylist * new_list = malloc(sizeof(struct mylist));
    new_list->head = NULL;
    
    while(p!=NULL)
    {
        Node * new_node  = malloc(sizeof(struct node));
        new_node->data = p->data;

        // insert new_head
        new_node->next = new_list->head;
        new_list->head = new_node;

        // next
        p = p->next;
    }

    Node * new_p = new_list->head;
    while(new_p!=NULL)
    {
        printf("%d",new_p->data);

        // next
        new_p = new_p->next;
    }

}

int liang(Node * head)
{
    if(head == NULL)
    {
        return 0;
    }

    liang(head->next);
    printf("%d",head->data);
}




int fanzhuan2(Mylist* mylist)
{
    Node * current = mylist->head;

    Node * pre = NULL;
    Node * pnext = NULL;

    while (current!=NULL)
    {
        pnext= current->next;
        // swap
        current->next = pre;
        //next
        pre = current;
        current =pnext;
    }
    

}

// 
static int number =0;
int test(int n)
{
    if(n==0)
    {
        return 0;
    }
    int number =test(n-1)+test(n-2);
    return number;
}

