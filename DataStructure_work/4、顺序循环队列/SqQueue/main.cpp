#include"SqQueue.h"

int main(){
	SqQueue Q;
	printf("(1)初始化队列q\n");
	InitQueue(Q);
	printf("(2)判断队列是否非空:");
	if(QueueEmpty(Q))
		printf("非空\n");
	else
		printf("空\n");
	printf("(3)依次进队列元素a,b,c\n");
	EnQueue (Q,'a');
	EnQueue (Q,'b');
	EnQueue (Q,'c');
	char e;
	DeQueue (Q,e);
	printf("(4)出队一个元素，输出该元素为:%c\n",e);
	printf("(5)输出队列q的元素个数:%d\n",QueueLength(Q));
	printf("(6)依次进队列元素d,e,f\n");
	EnQueue (Q,'d');
	EnQueue (Q,'e');
	EnQueue (Q,'f');
	printf("(7)输出队列q的元素个数:%d\n",QueueLength(Q));
	printf("(8)输出出队序列:");
	if(!QueueTraverse(Q))
		printf("没有");
	printf("\n");
	printf("(9)释放队列\n");
	DestroyQueue(Q);
	return 0;
}
