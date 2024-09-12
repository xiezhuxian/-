#define _CRT_SECURE_NO_WARNINGS  1
#include "sqlist.c"
void delnode1(SqList** L, ElemType x)
{
	int k = 0, i;  //k��¼ֵ������x��Ԫ�ظ���
	for (i = 0; i < (*L)->length; i++)
		if ((*L)->data[i] != x)
		{
			(*L)->data[k] = (*L)->data[i];
			k++;    //������x��Ԫ����1
		}
	(*L)->length = k;  //˳���L�ĳ��ȵ���k
}
void delnode2(SqList** L, ElemType x)
{
	int k = 0, i = 0; //k��¼ֵ����x��Ԫ�ظ���
	while (i < (*L)->length)
	{
		if ((*L)->data[i] == x)
			k++;
		else
			(*L)->data[i - k] = (*L)->data[i]; //��ǰԪ��ǰ��k��λ��
		i++;
	}
	(*L)->length -= k;	//˳���L�ĳ��ȵݼ�k
}

int Test2_3()
{
	ElemType a[] = { 1,2,2,1,0,2,4,2,3,1 };
	ElemType x = 2;
	SqList* L;
	CreateList(&L, a, 10);
	printf("L:"); DispList(L);
	printf("ɾ��ֵΪ%d��Ԫ��\n", x);
	delnode1(&L, x);
	printf("L:"); DispList(L);
	DestroyList(&L);
	return 1;
}
void swap(int* x, int* y)				//����x��y
{
	int tmp = *x;
	*x = *y; *y = tmp;
}
void move1(SqList** L)
{
	int i = 0, j = (*L)->length - 1;
	ElemType pivot = (*L)->data[0];			//��data[0]Ϊ��׼
	while (i < j)						//���������˽������м�ɨ��,ֱ��i=jΪֹ
	{
		while (i<j && (*L)->data[j]>pivot)
			j--;						//��������ɨ��,��һ��С�ڵ���pivot��Ԫ��
		while (i < j && (*L)->data[i] <= pivot)
			i++;						//��������ɨ��,��һ������pivot��Ԫ��
		if (i < j)
			swap(&((*L)->data[i]), &((*L)->data[j]));//��L->data[i]��L->data[j]���н���
	}
	swap(&((*L)->data[0]), &((*L)->data[i]));		//��L->data[0]��L->data[i]���н���
}

void move2(SqList** L)
{
	int i = 0, j = (*L)->length - 1;
	ElemType pivot = (*L)->data[0];	//��data[0]Ϊ��׼
	while (i < j)  				//��˳������˽������м�ɨ��,ֱ��i=jΪֹ
	{
		while (j > i && (*L)->data[j] > pivot)
			j--;				//��������ɨ��,��һ��С�ڵ���pivot��data[j]
		(*L)->data[i] = (*L)->data[j];	//�ҵ�������data[j],����data[i]��
		while (i < j && (*L)->data[i] <= pivot)
			i++;				//��������ɨ��,��һ������pivot�ļ�¼data[i]
		(*L)->data[j] = (*L)->data[i];	//�ҵ�������data[i],����data[j]��
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
	printf("ִ���ƶ�����\n");
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
			j--;					//��������ɨ��,��һ������Ԫ��
		while (i < j && (*L)->data[i] % 2 == 1)
			i++;					//��������ɨ��,��һ��ż��Ԫ��
		if (i < j)					//��i<j����L->data[i]��L->data[j]����
			swap(&((*L)->data[i++]), &((*L)->data[j--]));
	}
}
void move22(SqList** L)
{
	int i = -1, j;
	for (j = 0; j <= (*L)->length - 1; j++)
		if ((*L)->data[j] % 2 == 1)		//jָ������ʱ
		{
			i++;					//�������������1
			if (i != j)				//��i��j�����
				swap(&((*L)->data[i]), &((*L)->data[j]));//L->data[i]��L->data[j]����
		}
}

int Test2_5()
{
	SqList* L;
	ElemType a[] = { 8,2,7,1,5,10,4,6,3,9 };
	CreateList(&L, a, 10);
	printf("L:"); DispList(L);
	printf("ִ���ƶ�����\n");
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