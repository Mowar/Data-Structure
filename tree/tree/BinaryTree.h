#include "DS.h"

/*----------------�������Ļ����㷨--------*/
Status CreateBiTree(BiTree &T);
void preOrder(BiTree T);
void midOrder(BiTree T);
void posOrder(BiTree T);
Status preTraverse(BiTree T);
Status midTraverse(BiTree T);
Status posTraverse(BiTree T);
Status LevelOrderTraverse(BiTree T);

/*--------------�������Ļ�������-----------*/
void preOrderLeaf(BiTree T);
void leaf_one(BiTree T);
int leaf_two(BiTree T);
int leaf_three(BiTree T);
int postTreeDepth(BiTree T);