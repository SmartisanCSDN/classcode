#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"


//扩容函数
void SeqListwax(SeqList * psl)
{
	ListType * temp = (ListType *)realloc(psl->data, sizeof(ListType)*psl->capacity * 2);
	psl->data = temp;
	psl->capacity *= 2;
}

//初始化函数
void SeqListInit(SeqList * psl, size_t capacity)
{
	assert(psl != NULL);
	psl->data = (ListType *)malloc(sizeof(ListType)*capacity);
	assert(psl->data != NULL);
	memset(psl->data, 0, sizeof(ListType)* capacity);
	psl->capacity = capacity;
	psl->size = 0;
}

//尾插函数
void SeqListPushBack(SeqList * psl, ListType value)
{
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == psl->capacity)
		SeqListwax(psl);
	assert(psl->data != NULL);
	psl->data[psl->size] = value;
	psl->size++;
}

//头插函数
void SeqListPushFront(SeqList * psl, ListType value)
{
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == psl->capacity)
		SeqListwax(psl);
	assert(psl->data != NULL);
	size_t temp = psl->size;
	while (temp > 0)
	{
		psl->data[temp] = psl->data[temp - 1];
		temp--;
	}
	psl->data[0] = value;
	psl->size++;
}

//尾删函数
void SeqListPopBack(SeqList * psl)
{
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == 0)
		printf("线性表空，无法删除！\n");
	else
	{
		psl->data[psl->size] = 0;
		psl->size--;
	}
}

//头删函数
void SeqListPopFront(SeqList * psl)
{
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == 0)
		printf("线性表空，无法删除！\n");
	else
	{
		size_t temp = 0;
		while (temp < psl->size)
		{
			psl->data[temp] = psl->data[temp + 1];
			temp++;
		}
		psl->data[psl->size] = 0;
		psl->size--;
	}
}

//展示线性表
void SeqList_show(SeqList *psl)
{
	assert(psl != NULL&&psl->data != NULL);
	for (size_t i = 0; i < psl->size; i++)
		printf("%d ", psl->data[i]);
	printf("\n");
}

//按值查找元素
size_t SeqListFind(SeqList * psl, ListType value)
{
	assert(psl != NULL&&psl->data != NULL);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->data[i] == value)
			return i;
	}
	return -1;
}

//在指定位置插入元素
void SeqListInsert(SeqList * psl, size_t index, ListType value)
{
	index--;
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == psl->capacity)
		SeqListwax(psl);
	assert(psl->data != NULL);
	if (index > psl->size || index < 0)
		printf("位置不合适,无法插入!\n");
	else
	{
		for (size_t i = psl->size; i > index; i--)
			psl->data[i] = psl->data[i - 1];
		psl->data[index] = value;
		psl->size++;
	}
}

//删除指定位置的元素
void SeqListErase(SeqList * psl, size_t index)
{
	index--;
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == 0)
		printf("线性表空,无法删除!\n");
	else if (index > psl->size || index < 0)
		printf("位置不合适,无法删除!\n");
	else
	{
		for (size_t i = index; i < psl->size; i++)
			psl->data[i] = psl->data[i + 1];
		psl->size--;
	}
}

//删除值为value的元素
void SeqListRemove(SeqList * psl, ListType value)
{
	int count = 0;
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->data[i] == value)
			count++;
		else
			psl->data[i - count] = psl->data[i];
	}
	size_t newsize = psl->size - count;
	for (size_t i = newsize; i < psl->size; i++)
		psl->data[i] = 0;
	psl->size = newsize;
}

//修改指定位置的值
void SeqListModify(SeqList * psl, size_t index, ListType value)
{
	assert(psl != NULL&&psl->data != NULL);
	if (index > psl->size || index < 0)
		printf("位置不合适,无法修改!\n");
	else
		psl->data[index-1] = value;
}


