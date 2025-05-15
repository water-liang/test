typedef int ElementType;
typedef struct {
    ElementType *data;   // 指向动态分配数组的指针
    int size;            // 当前动态数组中元素的数量,
    int capacity;       // 动态数组的容量
} Vector;

// 创建一个动态数组
Vector* create_vector(int initial_capacity);

// 销毁一个 Vector 动态数组，释放内存
int destroy_vector(Vector* vector);

// 向动态数组末尾添加一个元素
int vector_push_back(Vector* vector, ElementType value);

// 从动态数组中删除最后一个元素
int vector_pop_back(Vector* vector);

// 获取动态数组中指定索引的元素
ElementType*  vector_get_by_index(Vector* vector, int index);

// 动态数组指定位置插入元素
int vector_insert(Vector* vector, int index, ElementType value);

// 删除动态数组中指定位置的元素
int vector_delete(Vector* vector, int index);

//遍历打印整个 Vector 动态数组
int vector_print(Vector* vector);



