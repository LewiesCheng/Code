/*文件名:proj3_1.cpp*/

#include"SqStack.h" 

int main()
{
	SqStack S;
	printf("(1)初始化栈：\n");
	InitStack (S);
	printf("(2)判断栈s是否非空：");
	if(StackEmpty(S))
		printf("非空\n");
	else printf("空\n");
	printf("(3)依次进栈元素a,b,c,d,e:\n");
	push(S,'a');
	push(S,'b');
	push(S,'c');
	push(S,'d');
	push(S,'e');
	printf("(4)判断栈s是否非空：");
	if(StackEmpty(S))
		printf("非空\n");
	else printf("空\n");
	
	printf("(5)栈的长度是：%d\n",StackLength(S));
	printf("(6)输出从栈顶到栈底元素:");
	StackTraverse(S);
	printf("\n(7)输出出栈序列:");
	StackGet(S);

	printf("\n(8)判断栈s是否非空：");
	if(StackEmpty(S))
		printf("非空\n");
	else printf("空\n");

	printf("(9)释放栈");
	DestroyStack(S);
	
}
