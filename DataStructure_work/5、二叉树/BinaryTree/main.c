#include"BinaryTree.h"

int main( ){
	BiTree T;
	InitBiTree(&T);
	CreateBiTree(&T);
	
	printf("\n(1)�����ű�ʾ�����������T��");
	BiTreeBreakets(T);
	printf("\n(2)���H�������Һ��ӽ��ֵ��");
	
	printf("\n(3)���������T��Ҷ�ӽ�������%d",BiTreeDepth(T));
	printf("\n(4)�������������ȣ�%d",BiTreeDepth(T));
	printf("\n(5)���ǰ�����������������:");
	PreOrderTraverse(T);
	printf("\n(6)����������������������:");
	InOrderTraverse(T);
	printf("\n(7)����������������������:");
	PostOrderTraverse(T);

	return 0;
}
