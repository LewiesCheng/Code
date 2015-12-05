#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char SElemType; 
typedef int Status;
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//����һ����ջS
Status InitStack(SqStack &S)
{
	S.base = (SElemType * )malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//��ջSΪ�ǿ�ջ���򷵻�TRUE�����򷵻�FALSE
Status StackEmpty (SqStack &S)
{
	if(S.base == S.top)
		return FALSE;
	return TRUE;
}

//����Ԫ��eΪ�µ�ջ��Ԫ��
Status push (SqStack &S, SElemType e)
{
	if(S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType * )realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
    }
	*S.top++ = e;
	return OK;
}

//����S��Ԫ�ظ�������ջ�ĳ���
int StackLength (SqStack S)
{
	return S.top-S.base;
}

//�����ջ����ջ��Ԫ��
void StackTraverse (SqStack S)
{
	SElemType *p = S.top;
	while(p > S.base)
	{
		printf("%c ",*(--p));
	}
}

//�����ջ����
Status StackGet (SqStack &S)
{
	while(S.top > S.base)
	{
		printf("%c ",*(--S.top));
	}
}

//�ͷ�ջS
Status DestroyStack (SqStack &S)
{
	while(S.top > S.base)
	{
		free(S.top--);
	}
}
