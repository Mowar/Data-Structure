#include "DS.h"
#include <limits.h>
typedef struct {
	unsigned int  weight;
	unsigned int  parent, lchild, rchild;
	} HTNode, *HuffmanTree;      //动态分配数组存储哈夫曼树
//typedef char * * HuffmanCode;  //动态分配数组存储哈夫曼编码表

Status createHuffmanTree(HuffmanTree &HT,int *w,int n);	//构着huffmanTree
void sumHuffmanTree(HuffmanTree HT,int m, int *sum);//计算huffmanTree非叶结点的值
void Select(HuffmanTree Ht, int i, int *s1, int *s2);		//选择parent为0且weight最小的两节点，其序号分别为s1和s2;