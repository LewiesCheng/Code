#include"SqQueue.h"

int main(){
	SqQueue Q;
	printf("(1)��ʼ������q\n");
	InitQueue(Q);
	printf("(2)�ж϶����Ƿ�ǿ�:");
	if(QueueEmpty(Q))
		printf("�ǿ�\n");
	else
		printf("��\n");
	printf("(3)���ν�����Ԫ��a,b,c\n");
	EnQueue (Q,'a');
	EnQueue (Q,'b');
	EnQueue (Q,'c');
	char e;
	DeQueue (Q,e);
	printf("(4)����һ��Ԫ�أ������Ԫ��Ϊ:%c\n",e);
	printf("(5)�������q��Ԫ�ظ���:%d\n",QueueLength(Q));
	printf("(6)���ν�����Ԫ��d,e,f\n");
	EnQueue (Q,'d');
	EnQueue (Q,'e');
	EnQueue (Q,'f');
	printf("(7)�������q��Ԫ�ظ���:%d\n",QueueLength(Q));
	printf("(8)�����������:");
	if(!QueueTraverse(Q))
		printf("û��");
	printf("\n");
	printf("(9)�ͷŶ���\n");
	DestroyQueue(Q);
	return 0;
}
