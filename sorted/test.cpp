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
		printf("��ѡ������� ");
		scanf("%d", &chose);
		switch(chose){
		case 1:
			printf("�����������\n");
			for(i=0;i<10;i++)
				printf("%d ", a[i]);
			printf("\n");
			printf("ð������\n");
			BubbleSort(a, 10);
			printf("ѡ���������\n");
			BriefSort(a, 10);
			printf("ֱ�Ӳ�������: \n");
		//	CreateList(L, a, 10);
			InsertSort(L, a, 10);
			break;
		case 2:
			printf("��������\n");
			QSort(L, 1, L.length);
			for( k = 1; k <= L.length; k++ )
				printf("%d ", L.r[k].key);
			break;

		case 3:
			printf("dk�ֱ�Ϊ3,2,1��ϣ����������\n");
			ShellSort(L,b, 3);
			for( k = 1; k <= L.length; k++ )
				printf("%d ", L.r[k].key);
			break;

		case 4: 
			printf("������\n");
			HeapSort(L);
			for( k = 1; k <= L.length; k++ )
				printf("%d ", L.r[k].key);
			break;

		case 0:
			return 0;
		default:
			printf("����������: ");
		}
	}
	return 0;
}
