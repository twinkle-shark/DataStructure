#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 10
typedef struct{
    int *data;			//指示动态分配数组的指针 
    int MAXSIZE;		//顺序表的最大容量 
    int length;			//顺序表的当前长度 
}SqList;
/*********************
int &a 代表引用
int a;
int &b=a;
此时b就等于a，相当于取别名， 
**********************/
void InitSqList(SqList &L);
void InsertList(SqList &L,int length);
/***********************************
此处的&表示的是引用，可以看做是函数的对于的那个参数的实参的别名，
通过引用改变这个值参数的值，那么就相当于改变了主函数里的那个参数的值。可以通过这种方法来变相的增加函数的返回值。
而一般如果没有引用的话，传进函数的是实参的一个拷贝，改变参数的值就只是局部改变。这就是加了&和不加&的区别。
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
	/*初始化顺序表*/
	/*用malloc函数申请一片连续的存储空间*/
    L.data=(int*)malloc(sizeof(int)*INITSIZE);
    L.MAXSIZE=INITSIZE;
    L.length=0;
}
void InsertList(SqList &L,int length){
	/*增加动态数组的长度*/
	int *p=L.data;
	L.data=(int*)malloc(sizeof(int)*(L.MAXSIZE+length));
	for(int i=0;i<L.MAXSIZE;i++){
		L.data[i]=p[i];			//将数据复制到新区域 
	}
	L.MAXSIZE=L.MAXSIZE+length; //顺序表长度增加length 
	free(p);					//释放原来的内存空间 
} 
