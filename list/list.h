//#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include "DS.h"

typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

typedef  int  ElemType;  //Ԫ������
typedef struct node
{
	ElemType data;
	struct node *next;
}LinkNode, *LinkList;


//---------------------˳����Ĳ���-----------------------------
void Sqmenu();
Status InitList_Sq(SqList &L, int n);/*��ʼ��˳���*/
Status CreateList_Sq(SqList &L);/*����˳���*/
void PrintList_Sq(SqList L);/*���˳���*/
Status DeleteList_Sq(SqList &L,int i,ElemType &e);/*ɾ����i��Ԫ��*/
Status DeleteListX_Sq(SqList &L,ElemType x);/*ɾ��ֵΪx��Ԫ��*/
Status AdjustList_Sq(SqList &L);/*��������ż��֮ǰ*/
Status OrderList_sq(SqList &L, int n);/*���뷨���ɵ��������*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc );/*�����ǵݼ������A��B���������Ǻϲ���һ���ǵݼ������C*/

//-------------------�������Ĳ���--------------------------------
void Linkmenu();                            /*�˵�*/
Status Init_Linklist(LinkList &L);           /*��ʼ���ձ�*/
Status Creat_Linklist(LinkList &L);         /*β�巨����������*/
void Disp_Linklist(LinkList L);             /*����������*/
int length_Linklist(LinkList L);             /*���㵥��������*/
void Reverse_Linklist(LinkList L);         /*����������*/
void DelEven_Linklist(LinkList L);         /*ɾ��ֵΪż���Ľ��*/
Status Insert_Linklist(LinkList L, int x);     /*����������L�в���Ԫ��x��������Ȼ����*/
Status CreatOrder_Linklist(LinkList &L);   /*�����ǵݼ���������*/
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc);  /*�����ǵݼ���������La��Lb�ϲ���һ���ǵ�����������Lc*/
void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc); /*�����ǵݼ���������La��Lb�ϲ���һ���ǵݼ���������Lc*/
void Split_Linklist(LinkList La, LinkList &Lb);  /*����La��ֵ�ֽ������������Laȫ��Ϊ������Lbȫ��Ϊż��*/

//#endif // SQLIST_H_INCLUDED