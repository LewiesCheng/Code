/*文件名:SqQueue.h*/
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

#define MAXQSIZE 6
typedef int Status;      //定义函数返回的类型
typedef char QElemType;  //定义数据元素的类型为字符型


typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

//构造一个空队列
Status InitQueue ( SqQueue &Q ){
	Q.base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

//若队列为非空，则返回TRUE，否则返回FALSE
Status QueueEmpty ( SqQueue Q ){
	if(!Q.front==Q.rear)
		return TRUE;
	return FALSE;
}

//返回Q的元素个数，即队列的长度
int QueueLength ( SqQueue Q ){
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//插入元素e为Q的新的队列元素
Status EnQueue ( SqQueue &Q,QElemType e ){
	if((Q.rear+1)%MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1) % MAXQSIZE;
	return OK;
}

//若队列不空，则删除队头元素，用e返回其值，并返回OK；
//否则返回ERROR
Status DeQueue ( SqQueue &Q,QElemType &e ){
	if(Q.front==Q.rear)
		return ERROR;  
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return OK;
}

//销毁队列Q
void DestroyQueue ( SqQueue &Q ){
	free(Q.base);
}

//从队头到队尾依次访问队列Q中每个元素
Status QueueTraverse( SqQueue Q ){
	if(Q.front==Q.rear)
		return ERROR;
	do{
		printf("%c ",Q.base[Q.front]);
		Q.front = (Q.front+1)%MAXQSIZE;
	}while(Q.front!=Q.rear);
	return OK;
}
