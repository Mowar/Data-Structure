#include "HuffmanTree.h"

//在HT[i..i-1]中选择parent为0且weight最小的两个节点，其序号分别为s1,s2
void Select(HuffmanTree HT, int index, int *s1, int *s2){
	unsigned int i,mins1=INT_MAX;
	unsigned int mins2 = INT_MAX;
	for(i = 1; i <=index; i++){
		if(HT[i].parent ==0 && HT[i].weight < mins1){ 
			mins1 = HT[i].weight;
			*s1 = i;
			}
		}
	for(i = 1; i <=index; i++){
		if(i == *s1) continue;
		if(HT[i].parent ==0 && HT[i].weight < mins2) 
			{
				mins2 = HT[i].weight;
				*s2 = i;
			}
		}
	}
//构着huffmanTree
Status createHuffmanTree(HuffmanTree &HT, int *w, int n){
	if(n<=1) return ERROR;
	int m = 2*n -1;
	int i,s1=0,s2=0;
	HuffmanTree p;
	HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));
	for(p=HT+1,i=1; i <=n; ++i,++p, ++w){
		p->lchild=p->rchild=p->parent=0;
		p->weight = *w;
		}
	for(; i <=m; ++i, ++p) p->rchild = p->lchild = p->parent=p->weight = 0;
	for(i = n+1;i <= m; ++i){
		//选择HT[1..i-1]选择parent为0且weight最小的两个节点，其序号分别为s1,s2
		Select(HT,i-1,&s1,&s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		}
	return OK;
	}

//计算huffmanTree非叶结点的值
void sumHuffmanTree(HuffmanTree HT, int m, int *sum){
	int i;
	for(i =1;i <=m; i ++){
		if(HT[i].rchild !=0 && HT[i].lchild !=0) *sum +=HT[i].weight;
		}
	}