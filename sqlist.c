#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
#include <assert.h>  
#define MaxSize 50  

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];       // 存放顺序表元素  
    int length;                   // 存放顺序表的长度  
} SqList;                        // 顺序表的类型  

void InitList(SqList** L) {
    *L = (SqList*)malloc(sizeof(SqList));   // 分配存放线性表的空间  
    if (*L == NULL) {
        perror("创建失败");
        exit(EXIT_FAILURE);  // 使用 EXIT_FAILURE 而不是 0，因为 0 通常表示成功  
    }
    (*L)->length = 0;
}

void CreateList(SqList** L, ElemType a[], int n) {
    InitList(L);
    for (int i = 0; i < n; i++)
        (*L)->data[i] = a[i];
    (*L)->length = n;
}

void DestroyList(SqList** L) {
    free(*L);
    *L = NULL;  // 避免野指针  
}
bool ListEmpty(SqList* L) {
    return (L->length == 0);
}

int ListLength(SqList* L) {
    return (L->length);
}

void DispList(SqList* L) {
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

// 修改 GetElem 以使用指针来接收元素值  
bool GetElem(SqList* L, int i, ElemType* e) {
    if (i < 1 || i > L->length)
        return false;
    *e = L->data[i - 1];
    return true;
}

int LocateElem(SqList* L, ElemType e) {
    int i = 0;
    while (i < L->length&& L->data[i] != e) i++;
    if (i >= L->length)
        return 0;
    else
        return i + 1;
}

bool ListInsert(SqList** L, int i, ElemType e) {
    int j;
    if (i < 1 || i >(*L)->length + 1)
        return false;
    i--;                           // 将顺序表位序转化为elem下标  
    for (j = (*L)->length; j > i; j--)
        (*L)->data[j] = (*L)->data[j - 1];
    (*L)->data[i] = e;
    (*L)->length++;                // 顺序表长度增1  
    return true;
}

bool ListDelete(SqList** L, int i, ElemType* e) {
    int j;
    if (i < 1 || i >(*L)->length)
        return false;
    i--;                           // 将顺序表位序转化为elem下标  
    *e = (*L)->data[i];
    for (j = i; j < (*L)->length - 1; j++)
        (*L)->data[j] = (*L)->data[j + 1];
    (*L)->length--;                // 顺序表长度减1  
    return true;
}