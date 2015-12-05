/*�ļ���:SqList.h*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//���庯�����ص�����
typedef int Status;
#define LIST_INIT_SIZE 100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10    //���Ա�洢�ռ�ķ�������
typedef char ElemType;  //��������Ԫ�ص�����Ϊ�ַ���
typedef struct 
{
	ElemType *elem;
   	int length;
	int listsize;
} SqList;    //����˳���Ĵ洢�ṹ

Status InitList(SqList &L)
//����һ���յ�˳���L
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

void DestroyList(SqList L)
//����˳���L
{
	free(L.elem);
}

Status ListEmpty(SqList L)
//�ж�˳���L�Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false
{
	if(!L.elem)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)
//����˳���L�ĳ���
{
	return L.length;
}

void DispList(SqList L)
//��ӡ˳����е�Ԫ��
{
	int i = 1;
	while(i <= L.length)
	{
		printf("%c",L.elem[i-1]);
		i++;
	}
}

Status GetElem(SqList L,int i,ElemType &e)
//��˳���L�в��ҵ�i��Ԫ�أ��ɲ���e������Ԫ�ص�ֵ
{
	if(i <= L.length)
		e = L.elem[i-1];
	else
		return ERROR;
}

int LocateElem(SqList L, ElemType e)
//��˳���L�в���Ԫ��e��λ�ã��������򷵻�0
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
//��˳���L�ĵ�i��λ��֮ǰ����Ԫ��e
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
//ɾ��˳���L�е�i��Ԫ�أ���e����ɾ����Ԫ��ֵ
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
