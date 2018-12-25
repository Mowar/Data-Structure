#include "DST.h"

int EQ(ElemType a, ElemType b){
	//�ж�a��b�Ƿ���ȣ�����ȣ�return 1
	//����return 0
	if(a == b) return 1;

	return 0;
	}

int LT(ElemType a,ElemType b){
	//�� a < b; return 1
	//���� return 0
	if(a < b) return 1;

	return 0;
	}

Status DeleteBst(BiTree &T,ElemType e);
BiTree SearchBST(BiTree T, ElemType e){
	//�ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ���e ������Ԫ�أ�
	//�����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
	if((!T) || EQ(e,T->data)) return (T);	//���ҽ���
	else if(LT(e,T->data)) return SearchBST(T->lchild,e);  //���������м�������
	else return SearchBST(T->rchild,e);						//���������м�������
	}

Status SearchBST(BiTree T,ElemType e, BiTree f,BiTree &p){
	//�ڸ�ָ��T��ָ������������еݹ�ز�����ؼ��ֵ���e������Ԫ�أ������ҳɹ���
	//��ָ��pָ�������Ԫ�ؽڵ㣬������TRUE������ָ��pָ�����·���Ϸ��ʵ����
	//һ����㲢����FALSE,ָ��fָ��T��˫�ף�����ʼ����ΪNULL----������˫��ΪNULL
	if(!T) {p=f; return FALSE;}									//���Ҳ��ɹ�
	else if (EQ(e,T->data)) {p=T; return TRUE;}					//���ҽ���
	else if(LT(e,T->data)) return SearchBST(T->lchild,e,T,p);  //���������м�������
	else return SearchBST(T->rchild,e,T,p);						//���������м�������
	}

Status InsertBST(BiTree &T,ElemType e){
	//������������T���в����ڹؼ��ֵ���e������Ԫ��ʱ������e������TRUE
	//���򷵻�FALSE
	BiTree p,s;
	if(!SearchBST(T,e,NULL,p)){				//���Ҳ��ɹ�
		s = (BiTree) malloc(sizeof(BiTNode));
		s->data = e; s->lchild = s->rchild = NULL;
		if(!p) T=s;			//����ӵ�*sΪ�µĸ����
		else if (LT(e,p->data)) p->lchild = s; //����ӵ�*sΪ����
		else p->rchild = s;
		return TRUE;
		}
	else
		return FALSE;
	}

Status Delete(BiTree &p){
	//�Ӷ�����������ɾ�����p�����ؽ��������������
	BiTree q,s;
	if(!p->rchild) { //������������Ҫ�ؽ�����������
		q = p; p=p->lchild; free(q);
		}
	else if(!p->lchild) { //������������Ҫ�ؽ�����������
		q=p; p=p->rchild; free(q);
		}
	else{//��������������
		q=p; s=p->lchild;
		while(s->rchild){q=s;s=s->rchild;} //ת��Ȼ�����ҵ���ͷ----ֱ��ǰ��
		p->data = s->data;	//sָ��ɾ������"ǰ��"
		if(q!=p) q->rchild = s->lchild;	//�ؽ�*q��������
		else q->lchild = s->lchild;		//�ؽ�*q��������
		delete s;
		}
	return TRUE;
	}

Status DeleteBST(BiTree &T, ElemType e){
	//������������T�д��ڹؼ���e������Ԫ��ʱ����ɾ��������Ԫ�ؽ��
	//������TRUE�����򷵻�FALSE
	if(!T) return FALSE;
	else {
		if(EQ(e,T->data)) return Delete(T);	//�ҵ��ؼ��ֵ���e��Ԫ�أ���ɾ��
		else if(LT(e,T->data)) return DeleteBST(T->lchild,e);
		else return DeleteBST(T->rchild, e);
		}
	}