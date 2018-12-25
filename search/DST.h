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
  二叉排序数的相关操作
	1. 插入元素
	2. 删除元素
	3. 查找元素
*/
Status InsertBST(BiTree &T,ElemType e);
Status DeleteBST(BiTree &T,ElemType e);
BiTree SearchBST(BiTree T, ElemType e);