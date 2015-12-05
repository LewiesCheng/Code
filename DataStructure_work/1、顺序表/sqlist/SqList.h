/*文件名:SqList.h*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//定义函数返回的类型
typedef int Status;
#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMENT 10    //线性表存储空间的分配增量
typedef char ElemType;  //定义数据元素的类型为字符型
typedef struct 
{
	ElemType *elem;
   	int length;
	int listsize;
} SqList;    //定义顺序表的存储结构

Status InitList(SqList &L)
//构造一个空的顺序表L
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

void DestroyList(SqList L)
//销毁顺序表L
{
	free(L.elem);
}

Status ListEmpty(SqList L)
//判断顺序表L是否为空，为空返回true，否则返回false
{
	if(!L.elem)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)
//返回顺序表L的长度
{
	return L.length;
}

void DispList(SqList L)
//打印顺序表中的元素
{
	int i = 1;
	while(i <= L.length)
	{
		printf("%c",L.elem[i-1]);
		i++;
	}
}

Status GetElem(SqList L,int i,ElemType &e)
//从顺序表L中查找第i个元素，由参数e返回其元素的值
{
	if(i <= L.length)
		e = L.elem[i-1];
	else
		return ERROR;
}

int LocateElem(SqList L, ElemType e)
//在顺序表L中查找元素e的位置，不存在则返回0
{
	int i = 1;
	ElemType *p = L.elem;
	while(i <= L.length)
	{
		if(e == *p++)
			break;
		++i;
	}
	if(i <= L.length)
		return i;
	else
		return 0;
}


Status ListInsert(SqList &L,int i,ElemType e)
//在顺序表L的第i个位置之前插入元素e
{
	ElemType *newbase,*p,*q;
	if(i < 1 || i > L.length + 1)
		return ERROR;
	if(L.length >= L.listsize)
	{
		newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = & (L.elem[i-1]);
	for(p = &(L.elem[L.length-1]); p >= q; --p)
		* (p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}


Status ListDelete(SqList &L,int i,ElemType &e)
//删除顺序表L中第i个元素，由e返回删除的元素值
{
	ElemType *p,*q;
	if(i < 1 || i > L.length + 1)
		return ERROR;
	p = &(L.elem[i-1]);
	e = *p;
	q = L.elem + L.length - 1;
	for(++p; p <= q; ++p)
		*(p - 1) = * p;
	--L.length;
	return OK;
}
