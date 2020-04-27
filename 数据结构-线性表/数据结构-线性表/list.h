#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define ListType int

//定义顺序表
typedef struct SeqList
{
	ListType * data; //指向顺序表数组的指针
	size_t capacity; //顺序表的容量
	size_t size;     //顺序表元素个数
}SeqList;

void SeqListwax(SeqList * psl); //扩容函数
void SeqListInit(SeqList * psl, size_t capacity); //初始化函数
void SeqListPushBack(SeqList * psl, ListType value); //尾插函数
void SeqListPushFront(SeqList * psl, ListType value); //头插函数
void SeqListPopBack(SeqList * psl); //尾删函数
void SeqListPopFront(SeqList * psl); //头删函数
void SeqList_show(SeqList * psl); //展示线性表
size_t SeqListFind(SeqList * psl, ListType value); //按值查找元素
void SeqListInsert(SeqList * psl, size_t index, ListType value); //在指定位置插入元素
void SeqListErase(SeqList * psl, size_t index); //删除指定位置的元素
void SeqListRemove(SeqList * psl, ListType value); //删除值为value的元素
void SeqListModify(SeqList * psl, size_t index, ListType value); //修改指定位置的值
#endif