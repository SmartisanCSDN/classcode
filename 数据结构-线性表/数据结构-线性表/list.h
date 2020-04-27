#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define ListType int

//����˳���
typedef struct SeqList
{
	ListType * data; //ָ��˳��������ָ��
	size_t capacity; //˳��������
	size_t size;     //˳���Ԫ�ظ���
}SeqList;

void SeqListwax(SeqList * psl); //���ݺ���
void SeqListInit(SeqList * psl, size_t capacity); //��ʼ������
void SeqListPushBack(SeqList * psl, ListType value); //β�庯��
void SeqListPushFront(SeqList * psl, ListType value); //ͷ�庯��
void SeqListPopBack(SeqList * psl); //βɾ����
void SeqListPopFront(SeqList * psl); //ͷɾ����
void SeqList_show(SeqList * psl); //չʾ���Ա�
size_t SeqListFind(SeqList * psl, ListType value); //��ֵ����Ԫ��
void SeqListInsert(SeqList * psl, size_t index, ListType value); //��ָ��λ�ò���Ԫ��
void SeqListErase(SeqList * psl, size_t index); //ɾ��ָ��λ�õ�Ԫ��
void SeqListRemove(SeqList * psl, ListType value); //ɾ��ֵΪvalue��Ԫ��
void SeqListModify(SeqList * psl, size_t index, ListType value); //�޸�ָ��λ�õ�ֵ
#endif