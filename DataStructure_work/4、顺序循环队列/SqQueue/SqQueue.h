/*�ļ���:SqQueue.h*/
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

#define MAXQSIZE 6
typedef int Status;      //���庯�����ص�����
typedef char QElemType;  //��������Ԫ�ص�����Ϊ�ַ���


typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

//����һ���ն���
Status InitQueue ( SqQueue &Q ){
	Q.base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

//������Ϊ�ǿգ��򷵻�TRUE�����򷵻�FALSE
Status QueueEmpty ( SqQueue Q ){
	if(!Q.front==Q.rear)
		return TRUE;
	return FALSE;
}

//����Q��Ԫ�ظ����������еĳ���
int QueueLength ( SqQueue Q ){
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//����Ԫ��eΪQ���µĶ���Ԫ��
Status EnQueue ( SqQueue &Q,QElemType e ){
	if((Q.rear+1)%MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1) % MAXQSIZE;
	return OK;
}

//�����в��գ���ɾ����ͷԪ�أ���e������ֵ��������OK��
//���򷵻�ERROR
Status DeQueue ( SqQueue &Q,QElemType &e ){
	if(Q.front==Q.rear)
		return ERROR;  
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return OK;
}

//���ٶ���Q
void DestroyQueue ( SqQueue &Q ){
	free(Q.base);
}

//�Ӷ�ͷ����β���η��ʶ���Q��ÿ��Ԫ��
Status QueueTraverse( SqQueue Q ){
	if(Q.front==Q.rear)
		return ERROR;
	do{
		printf("%c ",Q.base[Q.front]);
		Q.front = (Q.front+1)%MAXQSIZE;
	}while(Q.front!=Q.rear);
	return OK;
}
