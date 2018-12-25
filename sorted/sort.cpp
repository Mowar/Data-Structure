#include"sort.h"

// �˵�
void menu(){
	printf("\n\n");
	printf("\t\t*********************541507120151-Ԭ����*********************\n\n");
	printf("\t\t\t �� �� �� �� �� �� �� �� ��\n\n");
	printf("\t\t 1: ʵ �� �� �� ѡ �� �� ��ֱ �� �� �� �� �� �� ð �� �� ��\n");
	printf("\t\t 2: ʵ �� �� �� �� �� �� ��\n");
	printf("\t\t 3: ʵ �� ϣ �� �� �� �� ��\n");
	printf("\t\t 4: ʵ �� �� �� �� �� ��\n");
	printf("\t\t 0: �� �� �� ��\n\n");
	printf("��ѡ����Ĳ���: ");
	}

//ð������
void BubbleSort(int a[], int n){
	int i, j;
	int t;
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			if(a[i] > a[j]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(int k = 0;k < n;k++)
		printf("%d ", a[k]);
	printf("\n");
}


//�򵥵�ѡ������
void BriefSort(int a[], int n){
	int i, j, k, index, temp;
	for(i = 0;i < n;i++){
		index = a[i];
		k = i;

		for(j = i+1;j < n;j++){
			if(a[j]<index){
				index = a[j];
				k = j;
			}
		}

		if(i!=k){
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
	for(int t=0;t<n;t++)
		printf("%d ", a[t]);
	printf("\n");
}

//ֱ�Ӳ�������
void InsertSort(SqList &L, int a[], int n){
	
	int i, j, k;
	for(i=0;i<n;i++)
		L.r[i+1].key = a[i];
	


	for( i = 2;i<=L.length;++i)

		if(L.r[i].key < L.r[i-1].key){  //�轫L.r[i]���������ӱ�
			L.r[0] = L.r[i];      //�����ڱ�
			L.r[i] = L.r[i-1];

			for( j = i-2; L.r[0].key <= L.r[j].key;--j)
				L.r[j+1] = L.r[j];   //��¼����
			L.r[j+1] = L.r[0];      //���뵽��ȷλ��
		}
	
		
		for( k = 1; k <= L.length; k++ )
			printf("%d ", L.r[k].key);
	}


//��������
void QSort(SqList &L, int low, int high){
	if(low < high){  //���ȴ���1
		int pivotloc = Partition(L, low, high);//��L.r[low..high]һ��Ϊ��
		QSort(L, low, pivotloc-1);  //�Ե��ӱ�ݹ����� pivotloc������λ��
		QSort(L, pivotloc+1, high);   //�Ը��ӱ�ݹ�����
	}
	
}

int Partition(SqList &L, int low, int high){
	L.r[0] = L.r[low];      //���ӱ�ĵ�һ����¼�������¼
	int pivotkey = L.r[low].key;   //�����¼�ؼ���
	while(low<high){         //�ӱ�����˽�������м�ɨ��
		while(low<high&&L.r[high].key>=pivotkey) --high;
		L.r[low] = L.r[high];   // ���������¼С�Ļ����Ƶ��Ͷ�
		while(low<high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low];   // ���������¼��Ļ����Ƶ��Ͷ�
	}
	L.r[low] = L.r[0];
	return low;   //��������λ��
}


//ϣ������

void ShellInsert(SqList &L, int dk){
	int i = 0,j=0;
		//����Ϊdk������1�� r[0]ֻ���ݴ浥Ԫ�����ڱ��� ��j<=0ʱ������λ�����ҵ�
	for(int i = dk+1; i<=L.length;++i)

		if(L.r[i].key < L.r[i-dk].key){  //�轫L.r[i]�������������ӱ�
			L.r[0] = L.r[i];		//�ݴ���L.r[0]��
//���� int j
			for(j = i-dk;j>0 && L.r[0].key < L.r[j].key; j-=dk)
				L.r[j+dk] = L.r[j];		//��¼���ƣ����Ҳ���λ��
			L.r[j+dk] = L.r[0];    //����
		}
}

void ShellSort(SqList &L, int dlta[], int t){
	for(int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);//һ������Ϊdlta��k���Ĳ�������
}



//������
void HeapAdjust(SqList &L, int s, int m){
	//��֪L.r[s..m]�м�¼�Ĺؼ��ֳ�L.r[s].key֮�������� �Ķ��壬����������L.r[s]�Ĺؼ��֣�ʹL.r[s..m]
	//��Ϊһ���󶥶�
	RedType rc;
	
	rc = L.r[s];
	for(int j = 2*s;j<=m;j*=2){		//��key�ϴ�ĺ��ӽڵ�����ɸѡ
		if(j<m && L.r[j].key<L.r[j+1].key) ++j;     //jΪkey�ϴ�ļ�¼���±�
		if(rc.key > L.r[j].key) break;			//rcӦ������λ��s��

		L.r[s] = L.r[j];
		s = j;
	}

	L.r[s] = rc;		//����
}

void HeapSort(SqList &L){

	int i = 0;
	RedType t;
	for(int i = L.length/2;i>0;--i)
		HeapAdjust(L, i, L.length);		//���ɴ󶥶�

	for(i=L.length;i>1;--i){
		
		t = L.r[1];			//���Ѷ���¼�͵�ǰδ������������L.r[1..i]�����һ����¼�໥����
		L.r[1] = L.r[i];
		L.r[i] = t;
		HeapAdjust(L, 1, i-1);  //��L.r[1..i-1]���µ���Ϊ�󶥶�
	}
}
