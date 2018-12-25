#include"sort.h"

// 菜单
void menu(){
	printf("\n\n");
	printf("\t\t*********************541507120151-袁书泽*********************\n\n");
	printf("\t\t\t 常 用 的 内 部 排 序 算 法\n\n");
	printf("\t\t 1: 实 现 简 单 选 择 排 序、直 接 插 入 排 序 和 冒 泡 排 序\n");
	printf("\t\t 2: 实 现 快 速 排 序 算 法\n");
	printf("\t\t 3: 实 现 希 尔 排 序 算 法\n");
	printf("\t\t 4: 实 现 堆 排 序 算 法\n");
	printf("\t\t 0: 退 出 程 序\n\n");
	printf("请选择你的操作: ");
	}

//冒泡排序
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


//简单的选择排序
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

//直接插入排序
void InsertSort(SqList &L, int a[], int n){
	
	int i, j, k;
	for(i=0;i<n;i++)
		L.r[i+1].key = a[i];
	


	for( i = 2;i<=L.length;++i)

		if(L.r[i].key < L.r[i-1].key){  //需将L.r[i]插入有序子表
			L.r[0] = L.r[i];      //复制哨兵
			L.r[i] = L.r[i-1];

			for( j = i-2; L.r[0].key <= L.r[j].key;--j)
				L.r[j+1] = L.r[j];   //记录后移
			L.r[j+1] = L.r[0];      //插入到正确位置
		}
	
		
		for( k = 1; k <= L.length; k++ )
			printf("%d ", L.r[k].key);
	}


//快速排序
void QSort(SqList &L, int low, int high){
	if(low < high){  //长度大于1
		int pivotloc = Partition(L, low, high);//将L.r[low..high]一分为二
		QSort(L, low, pivotloc-1);  //对低子表递归排序， pivotloc是驱轴位置
		QSort(L, pivotloc+1, high);   //对高子表递归排序
	}
	
}

int Partition(SqList &L, int low, int high){
	L.r[0] = L.r[low];      //用子表的第一个记录做驱轴记录
	int pivotkey = L.r[low].key;   //驱轴记录关键字
	while(low<high){         //从表的两端交替的向中间扫描
		while(low<high&&L.r[high].key>=pivotkey) --high;
		L.r[low] = L.r[high];   // 将比驱轴记录小的机理移到低端
		while(low<high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low];   // 将比驱轴记录大的机理移到低端
	}
	L.r[low] = L.r[0];
	return low;   //返回驱轴位置
}


//希尔排序

void ShellInsert(SqList &L, int dk){
	int i = 0,j=0;
		//增量为dk，不是1， r[0]只是暂存单元不是哨兵， 当j<=0时，插入位置已找到
	for(int i = dk+1; i<=L.length;++i)

		if(L.r[i].key < L.r[i-dk].key){  //需将L.r[i]插入有序增量子表
			L.r[0] = L.r[i];		//暂存在L.r[0]中
//定义 int j
			for(j = i-dk;j>0 && L.r[0].key < L.r[j].key; j-=dk)
				L.r[j+dk] = L.r[j];		//记录后移，查找插入位置
			L.r[j+dk] = L.r[0];    //插入
		}
}

void ShellSort(SqList &L, int dlta[], int t){
	for(int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);//一趟增量为dlta【k】的插入排序
}



//堆排序
void HeapAdjust(SqList &L, int s, int m){
	//已知L.r[s..m]中记录的关键字除L.r[s].key之外均满足堆 的定义，本函数调整L.r[s]的关键字，使L.r[s..m]
	//成为一个大顶堆
	RedType rc;
	
	rc = L.r[s];
	for(int j = 2*s;j<=m;j*=2){		//沿key较大的孩子节点向下筛选
		if(j<m && L.r[j].key<L.r[j+1].key) ++j;     //j为key较大的记录的下标
		if(rc.key > L.r[j].key) break;			//rc应插入在位置s上

		L.r[s] = L.r[j];
		s = j;
	}

	L.r[s] = rc;		//插入
}

void HeapSort(SqList &L){

	int i = 0;
	RedType t;
	for(int i = L.length/2;i>0;--i)
		HeapAdjust(L, i, L.length);		//建成大顶堆

	for(i=L.length;i>1;--i){
		
		t = L.r[1];			//将堆顶记录和当前未经排序子序列L.r[1..i]中最后一个记录相互交换
		L.r[1] = L.r[i];
		L.r[i] = t;
		HeapAdjust(L, 1, i-1);  //将L.r[1..i-1]重新调整为大顶堆
	}
}
