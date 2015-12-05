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

//构建一个空栈S
Status InitStack(SqStack &S)
{
	S.base = (SElemType * )malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//若栈S为非空栈，则返回TRUE，否则返回FALSE
Status StackEmpty (SqStack &S)
{
	if(S.base == S.top)
		return FALSE;
	return TRUE;
}

//插入元素e为新的栈顶元素
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

//返回S的元素个数，即栈的长度
int StackLength (SqStack S)
{
	return S.top-S.base;
}

//输出从栈顶到栈底元素
void StackTraverse (SqStack S)
{
	SElemType *p = S.top;
	while(p > S.base)
	{
		printf("%c ",*(--p));
	}
}

//输出出栈序列
Status StackGet (SqStack &S)
{
	while(S.top > S.base)
	{
		printf("%c ",*(--S.top));
	}
}

//释放栈S
Status DestroyStack (SqStack &S)
{
	while(S.top > S.base)
	{
		free(S.top--);
	}
}
