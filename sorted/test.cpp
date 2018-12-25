#include<time.h>
#include<stdlib.h>
#include<stdio.h>

#include"sort.h"


int main(){
	int a[MAXSIZE]={0};
	int b[3] = {3, 2, 1};
	int j, i, k, chose;
	SqList L;
	L.length = 10;
	srand((unsigned int)time(NULL));
	for(j=0;j<10;j++)
		a[j] = rand()%100;

	while(1){

		menu();
		printf("请选择操作： ");
		scanf("%d", &chose);
		switch(chose){
		case 1:
			printf("产生随机数：\n");
			for(i=0;i<10;i++)
				printf("%d ", a[i]);
			printf("\n");
			printf("冒泡排序：\n");
			BubbleSort(a, 10);
			printf("选择插入排序：\n");
			BriefSort(a, 10);
			printf("直接插入排序: \n");
		//	CreateList(L, a, 10);
			InsertSort(L, a, 10);
			break;
		case 2:
			printf("快速排序：\n");
			QSort(L, 1, L.length);
			for( k = 1; k <= L.length; k++ )
				printf("%d ", L.r[k].key);
			break;

		case 3:
			printf("dk分别为3,2,1的希尔三趟排序：\n");
			ShellSort(L,b, 3);
			for( k = 1; k <= L.length; k++ )
				printf("%d ", L.r[k].key);
			break;

		case 4: 
			printf("堆排序：\n");
			HeapSort(L);
			for( k = 1; k <= L.length; k++ )
				printf("%d ", L.r[k].key);
			break;

		case 0:
			return 0;
		default:
			printf("请重新输入: ");
		}
	}
	return 0;
}
