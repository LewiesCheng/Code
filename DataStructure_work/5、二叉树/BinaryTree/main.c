#include"BinaryTree.h"

int main( ){
	BiTree T;
	InitBiTree(&T);
	CreateBiTree(&T);
	
	printf("\n(1)以括号表示法输出二叉树T：");
	BiTreeBreakets(T);
	printf("\n(2)输出H结点的左、右孩子结点值：");
	
	printf("\n(3)输出二叉树T的叶子结点个数：%d",BiTreeDepth(T));
	printf("\n(4)输出二叉树的深度：%d",BiTreeDepth(T));
	printf("\n(5)输出前序遍历二叉树的序列:");
	PreOrderTraverse(T);
	printf("\n(6)输出中序遍历二叉树的序列:");
	InOrderTraverse(T);
	printf("\n(7)输出后序遍历二叉树的序列:");
	PostOrderTraverse(T);

	return 0;
}
