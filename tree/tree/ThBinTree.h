#include "DS.h"

typedef enum PointerTag {Link,Thread};

typedef int TElemType;
typedef struct BiThrNode{
	TElemType data;		//������
	struct BiThrNode *Lchild,*Rchild;	//���Һ���ָ����
	PointerTag Ltag,Rtag;				//���ұ�־
	} BiThrNode, *BiThrTree;

/*-------------------�����㷨---------------*/
Status CreateBiThrTree(BiThrTree &T);
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T);
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);
Status PostOrderThreading(BiThrTree &Thrt,BiThrTree T);
Status PreOrderTraverse_Thr(BiThrTree T);
Status InOrderTraverse_Thr(BiThrTree T);
Status PostOrderTraverse_Thr(BiThrTree T);

/*------------------��������---------------*/


