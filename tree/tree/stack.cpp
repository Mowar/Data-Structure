#include "stack.h"

//Á´Õ»³õÊ¼»¯
Status InitStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)return ERROR;
	S->top->next = NULL;
	S->count = 0;
	return OK;
}

//Á´Õ»ÈëÕ»
Status Push(LinkStack *S, Elemtype e)
{
		LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
		if(!s)return ERROR;
		s->data = e;
		s->next = S->top->next;
		S->top->next = s;
		S->count++;
	return OK;

}

Status StackEmpty(LinkStack S)
{
	if(S.top->next == NULL){return TRUE;}
	else{return FALSE;}
}

//Á´Õ»³öÕ»
Status Pop(LinkStack *S, Elemtype *e)
{
	LinkStackPtr p;
	if(StackEmpty(*S))
	{
		return ERROR;
	}
	p = S->top->next;
	*e = p->data;
	S->top->next = p->next;
	free(p);
	S->count--;
	return OK;

}

Status GetTop(LinkStack *S,Elemtype *e){

	if(StackEmpty(*S)) return ERROR;

	*e = (S->top->next)->data;
	return OK;
}