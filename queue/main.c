#include "queue.h"


int main()
{

    DynamicQueue * queue = create_dynamic_queue(10);

    print_dynamic_queue(queue);


    int ret = 0;


    ret = enqueue_dynamic_queue(queue,10);
    ret = enqueue_dynamic_queue(queue,20);
    ret = enqueue_dynamic_queue(queue,30);
    ret = enqueue_dynamic_queue(queue,40);
    ret = enqueue_dynamic_queue(queue,50);
    ret = enqueue_dynamic_queue(queue,60);
    ret = enqueue_dynamic_queue(queue,70);   
    ret = enqueue_dynamic_queue(queue,80);
    ret = enqueue_dynamic_queue(queue,90);
    ret = enqueue_dynamic_queue(queue,100);
    ret = enqueue_dynamic_queue(queue,110);
    print_dynamic_queue(queue);


    ElementType value = 0;;
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
    print_dynamic_queue(queue);

    ret = dequeue_dynamic_queue(queue,&value);
    printf("%d=>\n",value);


    ret = enqueue_dynamic_queue(queue,110);
    get_front_dynamic_queue(queue,&value);
    printf("%d=>\n",value);
}
