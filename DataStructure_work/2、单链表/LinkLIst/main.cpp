/*�ļ���:exp2-2.cpp*/
#include "LinkList.h"

int main()
{
	LinkList h;
	ElemType e;
	int n;
	printf("(1)��ʼ��������h\n");
	InitList(h);
/*	printf("(2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');*/
	printf("(2)����ͷ�巨����������\n");
	printf("�����뵥������ĸ�����");
	scanf("%d",&n);
	getchar();
	CreatList_L(h,n);
	printf("(3)���������h:");
	DispList(h);
	printf("(4)������h����=%d\n",ListLength(h));
	printf("(5)������hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("(6)������h�ĵ�3��Ԫ��=%c\n",e);
	printf("(7)Ԫ��a��λ��=%d\n",LocateElem(h,'a'));
	printf("(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("(9)���������h:");
	DispList(h);
	printf("(10)ɾ��h�ĵ�3��Ԫ��\n");
    ListDelete(h,3,e);
	printf("(11)���������h:");
	DispList(h);
	printf("(12)�ͷŵ�����h\n");
	DestroyList(h);
}

