/*文件名:exp2-1.cpp*/

#include"SqList.h"

int main()
{
	SqList L;
	ElemType e;
	printf("(1)初始化顺序表L\n");
	InitList(L);
	printf("(2)依次采用尾插法插入a,b,c,d,e元素\n");
	ListInsert(L,1,'a');
	ListInsert(L,2,'b');
	ListInsert(L,3,'c');
	ListInsert(L,4,'d');
	ListInsert(L,5,'e');
	printf("(3)输出顺序表L:\n");
	DispList(L);
	printf("(4)顺序表L长度=%d\n",ListLength(L));
	printf("(5)顺序表L为%s\n",(ListEmpty(L)?"空":"非空"));
	GetElem(L,3,e);
	printf("(6)顺序表L的第3个元素=%c\n",e);
	printf("(7)元素a的位置=%d\n",LocateElem(L,'a'));
	printf("(8)在第4个元素位置上插入f元素\n");
	ListInsert(L,4,'f');
	printf("(9)输出顺序表L:");
	DispList(L);
	printf("\n(10)删除L的第3个元素");
    ListDelete(L,3,e);
	printf("\n(11)输出顺序表L:");
	DispList(L);
	printf("\n(12)释放顺序表L\n");
	DestroyList(L);
}
