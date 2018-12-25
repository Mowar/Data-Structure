#include "list.h"

void Sqmenu()
	{
	printf("\t\t\t   顺序表基本操作\n\n");
	printf("\t\t\t1.建  立  顺  序  表\n");
	printf("\t\t\t2.遍  历  顺  序  表\n");
	printf("\t\t\t3.删 除 第 i 个 元 素\n");
	printf("\t\t\t4.删 除 值 为 x 的 元 素\n");
	printf("\t\t\t5.奇 数 排 在 偶 数 之 前\n");
	printf("\t\t\t6.插 入 法 生 成 递 增 有 序 表\n");
	printf("\t\t\t7.两个非递减有序表La和Lb合并成非递减有序表Lc\n");
	printf("\t\t\t0.退          出\n\n");
	}

/*初始化顺序表*/
Status InitList_Sq(SqList &L, int n)
	{
	L.elem=(ElemType*)malloc(n*sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	L.listsize=n;
	return OK;
	}

/*建立顺序表*/
Status CreateList_Sq(SqList &L)
	{
	int n, i;
	printf("请输入顺序表长度：");
	scanf_s("%d", &n);
	if(InitList_Sq(L, n))
		{
		printf("请输入%d个元素：", n);
		for(i = 0; i < n; i++)
			{
			scanf_s("%d", &L.elem[i]);
			L.length++;
			}
		return OK;
		}
	else
		return ERROR;
	}

/*输出顺序表*/
void PrintList_Sq(SqList L)
	{
	int i;
	printf("顺序表中元素为：\n");
	for(i = 0; i < L.length; i++)
		{
		printf("%d ", L.elem[i]);
		}
	printf("\n");
	}

/*删除第i个元素*/
Status DeleteList_Sq(SqList &L,int i,ElemType &e)
	{
	ElemType *p, *q;
	if( (i<1) || (i>L.length) ) return ERROR;
	p = &(L.elem[i-1]);
	e = *p;
	q = L.elem+L.length-1;	//q = int(L.elem) + sizeof(ElemType) * (L.length-1)  隐式转化
	for(++p; p <= q; ++p) *(p-1) = *p;
	--L.length;
	return OK;
	}
//1、 i++ 返回原来的值，但i自增1；++i 返回加1后的值,i依旧自增1
//2、 i++ 不能作为左值，而++i 可以

/*删除值为x的元素，删除成功返回OK，删除失败返回ERROR*/
Status DeleteListX_Sq(SqList &L,ElemType x)
	{
	ElemType *p, *q;
	q = L.elem+L.length-1;
	p = L.elem;
	for(p; p <=q; ++p){
		if(*p == x){
			for(++p; p <= q; ++p) *(p-1) = *p;
			--L.length;
			return OK;
			}
		}

	return ERROR;
	}

/*奇数排在偶数之前*/
Status AdjustList_Sq(SqList &L)
	{
	/*
	 *算法描述:
	 *从最后一个元素开始，判断是
	 *否为奇数，倘若是奇数，与从开头开始的偶数互换，然后各下标加一
	 *结束的标识是两下标相同
	 */
	ElemType *start, *end;
	int temp;
	start = L.elem;
	end = L.elem + L.length -1;
	while(start!=end){
		
		//从头开始找偶数
		while(start<end && *start %2 != 0) ++start;
		
		//从尾开始找奇数
		while(start<end && *end %2 ==0) --end;
		
		//互换元素
		temp = *start; *start = *end; *end = temp;
		}
	return OK;
	}

/*插入法生成递增有序表，有序表生成成功返回OK，失败返回ERROR*/
Status OrderList_sq(SqList &L, int n)
	{
	int i, j, x,k;  /*x表示每次待插入的元素*/
	printf("请输入插入的元素:");
	L.length = 0;
	for(i = 0; i < n; i++){
		scanf_s("%d",&x);
		for(j = 0; j < i;j ++) if(x <= L.elem[j]) break;
		for(k=i;j < k; k--) L.elem[k] = L.elem[k-1];
		L.elem[j] = x;
		++ L.length;
		}
	return OK;
	}

/*两个非递减有序表A和B，并把它们合并成一个非递减有序表C*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc )
	{
	/*
	 *算法描述如下:
	 *从La和Lb中的第一个元素开始比较，如果La中元素较小，就将La中
	 *元素插入到Lc中，然后取La的下一个元素；否则将Lb中元素插入到
	 *Lc中，然后取Lb的下一个元素。执行此操作，直到所有元素都插入到Lc当中。
	 */
	ElemType *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La.elem; pb = Lb.elem;
	Lc.listsize = Lc.length = La.length+Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem) exit (OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
		{
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
		}
	while(pa <= pa_last) *pc++ = *pa++;
	while(pb <= pb_last) *pc++ = *pb++;
	}
