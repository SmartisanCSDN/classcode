#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"


//���ݺ���
void SeqListwax(SeqList * psl)
{
	ListType * temp = (ListType *)realloc(psl->data, sizeof(ListType)*psl->capacity * 2);
	psl->data = temp;
	psl->capacity *= 2;
}

//��ʼ������
void SeqListInit(SeqList * psl, size_t capacity)
{
	assert(psl != NULL);
	psl->data = (ListType *)malloc(sizeof(ListType)*capacity);
	assert(psl->data != NULL);
	memset(psl->data, 0, sizeof(ListType)* capacity);
	psl->capacity = capacity;
	psl->size = 0;
}

//β�庯��
void SeqListPushBack(SeqList * psl, ListType value)
{
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == psl->capacity)
		SeqListwax(psl);
	assert(psl->data != NULL);
	psl->data[psl->size] = value;
	psl->size++;
}

//ͷ�庯��
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

//βɾ����
void SeqListPopBack(SeqList * psl)
{
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == 0)
		printf("���Ա�գ��޷�ɾ����\n");
	else
	{
		psl->data[psl->size] = 0;
		psl->size--;
	}
}

//ͷɾ����
void SeqListPopFront(SeqList * psl)
{
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == 0)
		printf("���Ա�գ��޷�ɾ����\n");
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

//չʾ���Ա�
void SeqList_show(SeqList *psl)
{
	assert(psl != NULL&&psl->data != NULL);
	for (size_t i = 0; i < psl->size; i++)
		printf("%d ", psl->data[i]);
	printf("\n");
}

//��ֵ����Ԫ��
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

//��ָ��λ�ò���Ԫ��
void SeqListInsert(SeqList * psl, size_t index, ListType value)
{
	index--;
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == psl->capacity)
		SeqListwax(psl);
	assert(psl->data != NULL);
	if (index > psl->size || index < 0)
		printf("λ�ò�����,�޷�����!\n");
	else
	{
		for (size_t i = psl->size; i > index; i--)
			psl->data[i] = psl->data[i - 1];
		psl->data[index] = value;
		psl->size++;
	}
}

//ɾ��ָ��λ�õ�Ԫ��
void SeqListErase(SeqList * psl, size_t index)
{
	index--;
	assert(psl != NULL&&psl->data != NULL);
	if (psl->size == 0)
		printf("���Ա��,�޷�ɾ��!\n");
	else if (index > psl->size || index < 0)
		printf("λ�ò�����,�޷�ɾ��!\n");
	else
	{
		for (size_t i = index; i < psl->size; i++)
			psl->data[i] = psl->data[i + 1];
		psl->size--;
	}
}

//ɾ��ֵΪvalue��Ԫ��
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

//�޸�ָ��λ�õ�ֵ
void SeqListModify(SeqList * psl, size_t index, ListType value)
{
	assert(psl != NULL&&psl->data != NULL);
	if (index > psl->size || index < 0)
		printf("λ�ò�����,�޷��޸�!\n");
	else
		psl->data[index-1] = value;
}


