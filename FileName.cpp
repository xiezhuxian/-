#define _CRT_SECURE_NO_WARNINGS  1
#include "sqlist.c"
void delnode1(SqList** L, ElemType x)
{
	int k = 0, i;  //k记录值不等于x的元素个数
	for (i = 0; i < (*L)->length; i++)
		if ((*L)->data[i] != x)
		{
			(*L)->data[k] = (*L)->data[i];
			k++;    //不等于x的元素增1
		}
	(*L)->length = k;  //顺序表L的长度等于k
}
void delnode2(SqList** L, ElemType x)
{
	int k = 0, i = 0; //k记录值等于x的元素个数
	while (i < (*L)->length)
	{
		if ((*L)->data[i] == x)
			k++;
		else
			(*L)->data[i - k] = (*L)->data[i]; //当前元素前移k个位置
		i++;
	}
	(*L)->length -= k;	//顺序表L的长度递减k
}

int Test2_3()
{
	ElemType a[] = { 1,2,2,1,0,2,4,2,3,1 };
	ElemType x = 2;
	SqList* L;
	CreateList(&L, a, 10);
	printf("L:"); DispList(L);
	printf("删除值为%d的元素\n", x);
	delnode1(&L, x);
	printf("L:"); DispList(L);
	DestroyList(&L);
	return 1;
}
void swap(int* x, int* y)				//交换x和y
{
	int tmp = *x;
	*x = *y; *y = tmp;
}
void move1(SqList** L)
{
	int i = 0, j = (*L)->length - 1;
	ElemType pivot = (*L)->data[0];			//以data[0]为基准
	while (i < j)						//从区间两端交替向中间扫描,直至i=j为止
	{
		while (i<j && (*L)->data[j]>pivot)
			j--;						//从右向左扫描,找一个小于等于pivot的元素
		while (i < j && (*L)->data[i] <= pivot)
			i++;						//从左向右扫描,找一个大于pivot的元素
		if (i < j)
			swap(&((*L)->data[i]), &((*L)->data[j]));//将L->data[i]和L->data[j]进行交换
	}
	swap(&((*L)->data[0]), &((*L)->data[i]));		//将L->data[0]和L->data[i]进行交换
}

void move2(SqList** L)
{
	int i = 0, j = (*L)->length - 1;
	ElemType pivot = (*L)->data[0];	//以data[0]为基准
	while (i < j)  				//从顺序表两端交替向中间扫描,直至i=j为止
	{
		while (j > i && (*L)->data[j] > pivot)
			j--;				//从右向左扫描,找一个小于等于pivot的data[j]
		(*L)->data[i] = (*L)->data[j];	//找到这样的data[j],放入data[i]处
		while (i < j && (*L)->data[i] <= pivot)
			i++;				//从左向右扫描,找一个大于pivot的记录data[i]
		(*L)->data[j] = (*L)->data[i];	//找到这样的data[i],放入data[j]处
	}
	(*L)->data[i] = pivot;
	printf("i=%d\n", i);
}

int Test2_4()
{
	SqList* L;
	ElemType a[] = { 1,9,8,7,6 };
	CreateList(&L, a, 5);
	printf("L:"); DispList(L);
	printf("执行移动运算\n");
	move1(&L);
	printf("L:"); DispList(L);
	DestroyList(&L);
	return 1;
}
void move11(SqList** L)
{
	int i = 0, j = (*L)->length - 1;
	while (i < j)
	{
		while (i < j && (*L)->data[j] % 2 == 0)
			j--;					//从右向左扫描,找一个奇数元素
		while (i < j && (*L)->data[i] % 2 == 1)
			i++;					//从左向右扫描,找一个偶数元素
		if (i < j)					//若i<j，将L->data[i]和L->data[j]交换
			swap(&((*L)->data[i++]), &((*L)->data[j--]));
	}
}
void move22(SqList** L)
{
	int i = -1, j;
	for (j = 0; j <= (*L)->length - 1; j++)
		if ((*L)->data[j] % 2 == 1)		//j指向奇数时
		{
			i++;					//奇数区间个数增1
			if (i != j)				//若i、j不相等
				swap(&((*L)->data[i]), &((*L)->data[j]));//L->data[i]和L->data[j]交换
		}
}

int Test2_5()
{
	SqList* L;
	ElemType a[] = { 8,2,7,1,5,10,4,6,3,9 };
	CreateList(&L, a, 10);
	printf("L:"); DispList(L);
	printf("执行移动运算\n");
	move11(&L);
	printf("L:"); DispList(L);
	DestroyList(&L);
	return 1;
}

int main()
{
	Test2_3();
	Test2_4();
	Test2_5();
	//getchar();
	return 1;
}