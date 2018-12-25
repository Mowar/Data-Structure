#include "DS.h"
#include <limits.h>
typedef struct {
	unsigned int  weight;
	unsigned int  parent, lchild, rchild;
	} HTNode, *HuffmanTree;      //��̬��������洢��������
//typedef char * * HuffmanCode;  //��̬��������洢�����������

Status createHuffmanTree(HuffmanTree &HT,int *w,int n);	//����huffmanTree
void sumHuffmanTree(HuffmanTree HT,int m, int *sum);//����huffmanTree��Ҷ����ֵ
void Select(HuffmanTree Ht, int i, int *s1, int *s2);		//ѡ��parentΪ0��weight��С�����ڵ㣬����ŷֱ�Ϊs1��s2;