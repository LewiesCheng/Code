/*�ļ���:LinkList.h*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;  //��������Ԫ�ص�����
typedef struct LNode	/*���嵥����������*/
{
	ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//��ʼ��������
void InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));  	/*����ͷ���*/
	L->next=NULL;
}
//���ٵ�����
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
//�жϵ������Ƿ�Ϊ�գ��ձ���1�����򷵻�0
int ListEmpty(LinkList L)
{
	if(!L)
		return 1;
	else
		return 0;
}
//���ص�����ĳ���
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
//��ӡ����������ÿ��Ԫ��
void DispList(LinkList L)
{
	LinkList p = L;
	while(p -> next)
	{
		p = p -> next;
		printf("%c",p -> data);
	}
}
//��ȡ������L�е�iԪ�أ��ɲ���e����
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
//�ڵ�����L�в�������Ԫ��e��λ�ã��粻���ڷ���0
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
//�ڵ�����L�е�i��λ���ϲ���Ԫ��e
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
//ɾ����i��Ԫ��
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

//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
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



