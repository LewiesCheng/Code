/*文件名:LinkList.h*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;  //定义数据元素的类型
typedef struct LNode	/*定义单链表结点类型*/
{
	ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//初始化单链表
void InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));  	/*创建头结点*/
	L->next=NULL;
}
//销毁单链表
void DestroyList(LinkList &L)
{
	LinkList p=L,q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
//判断单链表是否为空，空表返回1，否则返回0
int ListEmpty(LinkList L)
{
	if(!L)
		return 1;
	else
		return 0;
}
//返回单链表的长度
int ListLength(LinkList L)
{
	LinkList p = L;
	int i = 0;
	while(p -> next)
	{
		p = p -> next;
		++i;
	}
	return i;
}
//打印输出单链表的每个元素
void DispList(LinkList L)
{
	LinkList p = L;
	while(p -> next)
	{
		p = p -> next;
		printf("%c",p -> data);
	}
}
//获取单链表L中第i元素，由参数e返回
int GetElem(LinkList L,int i,ElemType &e)
{
	LinkList p = L -> next;
	int j = 1;
	while(p && j< i)
	{
		p = p -> next;
		++j;
	}
	if(!p || j> i)
		return 0;
	e = p -> data;
	return 1;
}
//在单链表L中查找数据元素e的位置，如不存在返回0
int LocateElem(LinkList L,ElemType e)
{
	LinkList p = L -> next;
	int i = 1;
	while(p)
	{
		if(p -> data == e)
			break;
		p = p -> next;
		++i;
	}
	if(p)
		return i;
	else return 0;
}
//在单链表L中第i个位置上插入元素e
int ListInsert(LinkList &L,int i,ElemType e)
{
	LinkList p = L;
	int j = 0;
	while(p && j< i-1)
	{
		p = p-> next;
		++j;
	}
	if(!p || j> i-1)
		return 0;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s -> data = e;
	s -> next = p -> next;
	p -> next = s;
	return 1; 
}
//删除第i个元素
int ListDelete(LinkList &L,int i,ElemType &e)
{
	LinkList p = L;
	int j = 0;
	while(p -> next&&j<i-1)
	{
		p = p -> next;
		++j;
	}
	if(!p->next || j> i-1)
		return 0;
	LinkList q = p -> next;
	p -> next = q -> next;
	e = q -> data;
	free(q);
	return 1;
}

//逆位序输入n个元素的值，建立带表头结点的单链表L
void CreatList_L(LinkList &L,int n)
{
	int i;
	for(i = n;i>0;--i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf("%c",&p->data);
		p -> next = L->next;
		L->next=p;
	}
}



