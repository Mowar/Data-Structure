#include "DS.h"

typedef int ElemType;

#ifndef SQLIST_H_INCLUDED1
#define SQLIST_H_INCLUDED1
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
	}BiTNode, *BiTree;
#endif

/*
  ��������������ز���
	1. ����Ԫ��
	2. ɾ��Ԫ��
	3. ����Ԫ��
*/
Status InsertBST(BiTree &T,ElemType e);
Status DeleteBST(BiTree &T,ElemType e);
BiTree SearchBST(BiTree T, ElemType e);