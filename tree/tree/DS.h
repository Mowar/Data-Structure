#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;

#ifndef SQLIST_H_INCLUDED1
#define SQLIST_H_INCLUDED1
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;	//×óÓÒº¢×ÓÖ¸Õë
}BiTNode, *BiTree;
#endif
