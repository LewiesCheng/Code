/*�ļ���:BinaryTree.h*/
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

typedef int Status;      //���庯�����ص�����
typedef char QElemType;  //��������Ԫ�ص�����Ϊ�ַ���


typedef struct BiTNode{
	QElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//  ����ն�����T 
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

//  ��������������������н���ֵ��һ���ַ�����#�ַ���ʾ����
//  ������������ʾ�Ķ�����T
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

//�����ű�ʾ�����������T
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

//  ����T����� 
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

//   ����ݹ����T
void PreOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrderTraverse(T->lchild); 
	PreOrderTraverse(T->rchild); 
}

//   ����ݹ����T 
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); 
	printf("%c ",T->data);
	InOrderTraverse(T->rchild);
}


//   ����ݹ����T 
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); 
	PostOrderTraverse(T->rchild); 
	printf("%c ",T->data);
}
