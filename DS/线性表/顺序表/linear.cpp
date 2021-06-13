#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 10
typedef struct{
    int *data;			//ָʾ��̬���������ָ�� 
    int MAXSIZE;		//˳����������� 
    int length;			//˳���ĵ�ǰ���� 
}SqList;
/*********************
int &a ��������
int a;
int &b=a;
��ʱb�͵���a���൱��ȡ������ 
**********************/
void InitSqList(SqList &L);
void InsertList(SqList &L,int length);
/***********************************
�˴���&��ʾ�������ã����Կ����Ǻ����Ķ��ڵ��Ǹ�������ʵ�εı�����
ͨ�����øı����ֵ������ֵ����ô���൱�ڸı�������������Ǹ�������ֵ������ͨ�����ַ�������������Ӻ����ķ���ֵ��
��һ�����û�����õĻ���������������ʵ�ε�һ���������ı������ֵ��ֻ�Ǿֲ��ı䡣����Ǽ���&�Ͳ���&������
*********************************/
int main(void) { 
    int i,a;
	SqList L;
	InitSqList(L);
	for(i=0;i<L.MAXSIZE;i++){
	    scanf("%d",&a);
	    L.data[i]=a;
	}
	for(i=0;i<L.MAXSIZE;i++){
	    printf("%d\n",L.data[i]);
	}
	InsertList(L,5);
	for(i=0;i<L.MAXSIZE;i++){
	    printf("%d\n",L.data[i]);
	}
	return 0;
}

void InitSqList(SqList &L){
	/*��ʼ��˳���*/
	/*��malloc��������һƬ�����Ĵ洢�ռ�*/
    L.data=(int*)malloc(sizeof(int)*INITSIZE);
    L.MAXSIZE=INITSIZE;
    L.length=0;
}
void InsertList(SqList &L,int length){
	/*���Ӷ�̬����ĳ���*/
	int *p=L.data;
	L.data=(int*)malloc(sizeof(int)*(L.MAXSIZE+length));
	for(int i=0;i<L.MAXSIZE;i++){
		L.data[i]=p[i];			//�����ݸ��Ƶ������� 
	}
	L.MAXSIZE=L.MAXSIZE+length; //˳���������length 
	free(p);					//�ͷ�ԭ�����ڴ�ռ� 
} 
