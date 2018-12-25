#define SQLIST_H_INCLUDED

#include "DS.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Elemtype;

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

Status IsEmpty_LinkStack(LinkStack S);
Status InitSqStack(LinkStack *s);
Status PushSq(LinkStack *s, int n);
Status PopSq(LinkStack *s, Elemtype *e);
