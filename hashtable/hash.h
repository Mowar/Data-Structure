#include "DS.h"

typedef int ElemType;
typedef struct{
	ElemType *elem;		//数据元素存储基址，动态分配数组
	int		count;		//当前数据元素的个数
	int		sizeindex;	//哈希表的长度
	}HashTable;

typedef struct node
{
	ElemType data;
	struct node *next;
}LinkNode, *LinkList;

typedef struct hash
	{
		LinkList p;		//哈希表
		int count;		//表中填入的记录个数
		int sizeindex;	//哈希表的长度
	}HashLinkTable;
//开放地址法
Status SearchHash(HashTable H,ElemType k, int &p, int &c);	//查找Hash表
Status InsertHash(HashTable &H,ElemType e);					//开放地址法插入数据元素

//链地址法
Status InsertHash(LinkNode *p, ElemType e,int length);		//采用链地址法构建HashTable
