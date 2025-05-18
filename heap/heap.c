#include "heap.h"


// 创建堆
Heap*  HeapInit(int capacity)
{
    Heap* hp = (Heap*)malloc(sizeof(Heap));
    if (hp == NULL)
    {
        return NULL;
    }
    hp->arr = (HPDataType*)malloc(sizeof(HPDataType) * capacity);
    if (hp->arr == NULL)
    {
        free(hp);
        return NULL;
    }
    memset(hp->arr, 0, sizeof(HPDataType) * capacity);

    hp->size = 0;
    hp->capacity = capacity;
    return hp;
}



static void swap(int *a, int *b)
{
	 int c = *a;
	 *a = *b;
	 *b = c;
}
 
// 向下调整算法的操作对象是根节点（父结点）
/* 向下调整算法(小根堆)：传入父节点，并与较小的子节点进行交换，递归致最后一个父节点 */
static void AdjustDownLittle(HPDataType *arr, int n, int parent)
{
    if(parent >=n)
    {
        return;
    }
    int child = parent*2+1 ; // 左子节点

    if(child+1 < n && arr[child+1]< arr[child])
    {
        child = child+1; // 右子节点更小,使用右子节点
    }

    if(child < n && arr[child] < arr[parent])
    {
        swap(&arr[child], &arr[parent]); // 交换父节点和子节点，会导致 child的节点失效，需要调整
        AdjustDownLittle(arr, n, child); // 递归调整
    }

    return ;
}


// 向上调整法

static void AdjustUpLittle(HPDataType *arr, int n, int child)
{
    if(child <= 0)
    {
        return;
    }
    int parent = (child-1)/2; // 父节点

    if(arr[child] < arr[parent])
    {
        swap(&arr[child], &arr[parent]); // 交换父节点和子节点
        AdjustUpLittle(arr, n, parent); // 递归调整
    }

    return ;
}

// 向上调整法

static void AdjustUpLittle2(HPDataType *arr,int current)
{

    
    int parent = (current-1)/2; // 父节点

    while(current > 0 && arr[current] < arr[parent] )
    {
        swap(&arr[current], &arr[parent]);
        current = parent;
        parent = (current -1 )/2;
   }

}


// 向下调整法

static void AdjustDownLittle2(HPDataType *arr,int n ,int current)
{
    int child = current*2+1; // 左子节点

    while (child < n)
    {
        // 右子树更小
        if(child +1 < n && arr[child +1] < arr[child])
        {
            child++;
        }

        // 比较父亲节点
        if(arr[child] < arr[current])
        {
            swap(&arr[child],&arr[current]);
            
            current = child;
            child = current*2+1;
        }
        else
        {
            break;
        }
    }

}


// 向下调整法

static void AdjustDownLittle3(HPDataType *arr,int n ,int current)
{
    int child = current*2+1; // 左子节点

    while (child < n)
    {
        // 右子树更小
        if(child +1 < n && arr[child +1] < arr[child])
        {
            child++;
        }

        if(arr[child] < arr[current])
        {
            swap(&arr[child],&arr[current]);
            
            current = child;
            ·
        }
        else
        {
            break;
        }
    }
}

// 递归生成排列

void permute(char * str, int start,int end)
{
    if(start == end)
    {
        printf("%s\n",str);
        return;
    
    }

    // 构造不同的开头
    for (int i = start; i< end; i++)
    {
        swap(&str[start],&str[i]);
        permute(str,start+1,end);// 剩下的部分递归生成全排列
        swap(&str[start],&str[i]); // 交换回来
    }

}