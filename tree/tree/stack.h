#include "DS.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef BiTree Elemtype;

#ifndef SQLIST_H_INCLUDED2
#define SQLIST_H_INCLUDED2
typedef struct StackNode
{
   Elemtype data;		//节点数据域
   struct StackNode *next;   //节点指针域
}StackNode,*LinkStackPtr;   //节点指针

typedef struct LinkStack
{ 
   LinkStackPtr top;  //栈顶指针
   int count;            //栈中元素个数
}LinkStack;
#endif
Status InitStack(LinkStack *s);
Status Push(LinkStack *s, Elemtype e);
Status Pop(LinkStack *s, Elemtype *e);
Status StackEmpty(LinkStack S);
Status GetTop(LinkStack *s,Elemtype *e);