/*�ļ���:proj3_1.cpp*/

#include"SqStack.h" 

int main()
{
	SqStack S;
	printf("(1)��ʼ��ջ��\n");
	InitStack (S);
	printf("(2)�ж�ջs�Ƿ�ǿգ�");
	if(StackEmpty(S))
		printf("�ǿ�\n");
	else printf("��\n");
	printf("(3)���ν�ջԪ��a,b,c,d,e:\n");
	push(S,'a');
	push(S,'b');
	push(S,'c');
	push(S,'d');
	push(S,'e');
	printf("(4)�ж�ջs�Ƿ�ǿգ�");
	if(StackEmpty(S))
		printf("�ǿ�\n");
	else printf("��\n");
	
	printf("(5)ջ�ĳ����ǣ�%d\n",StackLength(S));
	printf("(6)�����ջ����ջ��Ԫ��:");
	StackTraverse(S);
	printf("\n(7)�����ջ����:");
	StackGet(S);

	printf("\n(8)�ж�ջs�Ƿ�ǿգ�");
	if(StackEmpty(S))
		printf("�ǿ�\n");
	else printf("��\n");

	printf("(9)�ͷ�ջ");
	DestroyStack(S);
	
}
