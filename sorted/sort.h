#include"DS.h"

#define MAXSIZE 100 /*�μ�����Ԫ�ص�������*/


typedef  int  KeyType;


typedef struct {
	KeyType  key;
    //InfoType  otherinfo;  // �����ֶ�
}RedType;


typedef struct{
	RedType  r[MAXSIZE+1];
    int        length; /*�μ�����Ԫ�ص�ʵ�ʸ���*/
}SqList, *LinkList;




void menu();
void BubbleSort(int a[], int n);
void BriefSort(int a[], int n);
void InsertSort(SqList &L, int a[], int n);
//Status CreateList(SqList &L, int a[], int n);

int Partition(SqList &L, int low, int high);
void QSort(SqList &L, int low, int high);

void ShellSort(SqList &L, int dlta[], int t);
void ShellInsert(SqList &L, int dk);

void HeapAdjust(SqList &L, int s, int m);
void HeapSort(SqList &L);