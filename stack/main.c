#include "linked_stack.h"


int main()
{
    int ret = 0;
    LinkedStack * stack = create_linked_stack();
    if(stack == NULL )
    {
        return -1;
    }

    print_linked_stack(stack);

    ret = push_linked_stack(stack,10);
    ret = push_linked_stack(stack,20);
    ret = push_linked_stack(stack,30);
    ret = push_linked_stack(stack,40);
    ret = push_linked_stack(stack,50);

    print_linked_stack(stack);
    printf("==============\n");

    ElementType value=0;
    ret = pop_linked_stack(stack,&value);
    printf("%d\n",value);
    ret = pop_linked_stack(stack,&value);
    printf("%d\n",value);
    ret = pop_linked_stack(stack,&value);
    printf("%d\n",value);

    ret = pop_linked_stack(stack,&value);
    printf("%d\n",value);

    ret = pop_linked_stack(stack,&value);
    printf("%d\n",value);

    ret = pop_linked_stack(stack,&value);
    printf("%d\n",value);

    ret = pop_linked_stack(stack,&value);
    printf("%d\n",value);
    
    printf("==============pop===");
    print_linked_stack(stack);

    printf("==============\n");

    ret = get_top_linked_stack(stack,&value);
    printf("%d\n",value);
    print_linked_stack(stack);

    destroy_linked_stack(stack);
    stack = NULL;


     printf("==========destory====\n");

    print_linked_stack(stack);

    return 0;
}