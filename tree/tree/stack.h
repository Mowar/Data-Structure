#include "DS.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef BiTree Elemtype;

#ifndef SQLIST_H_INCLUDED2
#define SQLIST_H_INCLUDED2
typedef struct StackNode
{
   Elemtype data;		//�ڵ�������
   struct StackNode *next;   //�ڵ�ָ����
}StackNode,*LinkStackPtr;   //�ڵ�ָ��

typedef struct LinkStack
{ 
   LinkStackPtr top;  //ջ��ָ��
   int count;            //ջ��Ԫ�ظ���
}LinkStack;
#endif
Status InitStack(LinkStack *s);
Status Push(LinkStack *s, Elemtype e);
Status Pop(LinkStack *s, Elemtype *e);
Status StackEmpty(LinkStack S);
Status GetTop(LinkStack *s,Elemtype *e);