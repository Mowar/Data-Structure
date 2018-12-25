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

typedef  int  ElemType;  //元素类型
typedef struct node
{
	ElemType data;
	struct node *next;
}LinkNode, *LinkList;


//---------------------顺序表的操作-----------------------------
void Sqmenu();
Status InitList_Sq(SqList &L, int n);/*初始化顺序表*/
Status CreateList_Sq(SqList &L);/*建立顺序表*/
void PrintList_Sq(SqList L);/*输出顺序表*/
Status DeleteList_Sq(SqList &L,int i,ElemType &e);/*删除第i个元素*/
Status DeleteListX_Sq(SqList &L,ElemType x);/*删除值为x的元素*/
Status AdjustList_Sq(SqList &L);/*奇数排在偶数之前*/
Status OrderList_sq(SqList &L, int n);/*插入法生成递增有序表*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc );/*两个非递减有序表A和B，并把它们合并成一个非递减有序表C*/

//-------------------单链表的操作--------------------------------
void Linkmenu();                            /*菜单*/
Status Init_Linklist(LinkList &L);           /*初始化空表*/
Status Creat_Linklist(LinkList &L);         /*尾插法建立单链表*/
void Disp_Linklist(LinkList L);             /*单链表遍历*/
int length_Linklist(LinkList L);             /*计算单链表长度*/
void Reverse_Linklist(LinkList L);         /*单链表逆置*/
void DelEven_Linklist(LinkList L);         /*删除值为偶数的结点*/
Status Insert_Linklist(LinkList L, int x);     /*在有序单链表L中插入元素x，链表仍然有序*/
Status CreatOrder_Linklist(LinkList &L);   /*创建非递减有序单链表*/
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc);  /*两个非递减有序单链表La和Lb合并成一个非递增有序链表Lc*/
void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc); /*两个非递减有序单链表La和Lb合并成一个非递减有序链表Lc*/
void Split_Linklist(LinkList La, LinkList &Lb);  /*链表La按值分解成两个链表，La全部为奇数，Lb全部为偶数*/

//#endif // SQLIST_H_INCLUDED
