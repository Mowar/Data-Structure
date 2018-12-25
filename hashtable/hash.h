#include "DS.h"

typedef int ElemType;
typedef struct{
	ElemType *elem;		//����Ԫ�ش洢��ַ����̬��������
	int		count;		//��ǰ����Ԫ�صĸ���
	int		sizeindex;	//��ϣ��ĳ���
	}HashTable;

typedef struct node
{
	ElemType data;
	struct node *next;
}LinkNode, *LinkList;

typedef struct hash
	{
		LinkList p;		//��ϣ��
		int count;		//��������ļ�¼����
		int sizeindex;	//��ϣ��ĳ���
	}HashLinkTable;
//���ŵ�ַ��
Status SearchHash(HashTable H,ElemType k, int &p, int &c);	//����Hash��
Status InsertHash(HashTable &H,ElemType e);					//���ŵ�ַ����������Ԫ��

//����ַ��
Status InsertHash(LinkNode *p, ElemType e,int length);		//��������ַ������HashTable
