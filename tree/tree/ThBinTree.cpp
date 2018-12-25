#include "ThBinTree.h"

Status CreateBiThrTree(BiThrTree &T){
	/*
	*      �Զ�����������������������-------�㷨��������:
	*  ������Ԫ�أ��жϽ��Ԫ���Ƿ��ǿ�����ʶ�����ǣ�ִ�пղ�����
	* ��������ִ�����в���:
	*     (1) �����ý��Ԫ��
	*     (2) ���ո÷��������ý���������:T->Lchild�����ݹ���øú���
	*     (3) ���ո÷��������ý���������:T->Rchild�����ݹ���øú���
	*/
	char ch = getchar();
	if(ch ==' ') T=NULL;
	else{
		//���ɸ��ڵ�
		if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
		T->data = ch;

		//����������
		CreateBiThrTree(T->Lchild);

		//����������
		CreateBiThrTree(T->Rchild);
		}
	return OK;
	}

void PreThreading(BiThrTree p, BiThrTree &pre){
	/*
	 *         ������p������-------�㷨��������
	 *   ����ÿ�����p,��:
	 *      (1)�жϽ���Ƿ�Ϊ�գ���Ϊ�գ��򷵻�
	 *      (2)��ǰ�����������������Ϊ�յ�ʱ��������ָ��ǰ
	 *	������ǰ�����Һ���Ϊ��ʱ��ǰ�����Һ���ָ��ǰ���p��
	 *		(3)������������
	 *      (4)�Һ�����������
	 */
	if(p){
		//ǰ������
		if(!p->Lchild){p->Ltag=Thread;p->Lchild=pre;}
		//�������
		if(!pre->Rchild){pre->Rtag=Thread;pre->Rchild=p;}
		pre = p;

		//������������
		PreThreading(p->Lchild,pre);

		//������������
		PreThreading(p->Rchild,pre);
		}
	}
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T){

	}

void InThreading(BiThrTree p, BiThrTree &pre);
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);

void PostThreading(BiThrTree p, BiThrTree &pre);
Status PostOrderThreading(BiThrTree &Thrt,BiThrTree T);

Status PreOrderTraverse_Thr(BiThrTree T);
Status InOrderTraverse_Thr(BiThrTree T);
Status PostOrderTraverse_Thr(BiThrTree T);