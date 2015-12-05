/*文件名:BinaryTree.h*/
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

typedef int Status;      //定义函数返回的类型
typedef char QElemType;  //定义数据元素的类型为字符型


typedef struct BiTNode{
	QElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//  构造空二叉树T 
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

//  按先序序列输入二叉树中结点的值（一个字符），#字符表示空树
//  构造二叉链表表示的二叉树T
Status CreateBiTree (BiTree *T){
	QElemType ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}
	else{
		*T = (BiTNode *) malloc (sizeof(BiTNode));
		if(!*T){
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		CreateBiTree( &(*T)->lchild );
		CreateBiTree( &(*T)->rchild );
	}
	return OK;
}

//以括号表示法输出二叉树T
void BiTreeBreakets (BiTNode *T){
	if(T==NULL){
		return;	
	}
	printf("%c",T->data);
	if(T->lchild || T->rchild){
		printf("(");
	}
	BiTreeBreakets(T->lchild); 
	if(T->rchild){
		printf(",");
	}
	BiTreeBreakets(T->rchild);
	if (T->rchild) {
		printf(")");
	}
	
} 

//  返回T的深度 
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if(T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i>j?i+1:j+1;
}

//   先序递归遍历T
void PreOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrderTraverse(T->lchild); 
	PreOrderTraverse(T->rchild); 
}

//   中序递归遍历T 
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); 
	printf("%c ",T->data);
	InOrderTraverse(T->rchild);
}


//   后序递归遍历T 
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); 
	PostOrderTraverse(T->rchild); 
	printf("%c ",T->data);
}
