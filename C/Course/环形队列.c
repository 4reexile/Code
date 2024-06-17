#include <stdio.h>
#include <stdlib.h>

/*
    1.创建空的环形队列
    2.队列为空判断
    3.队列为满判断
    4.入队
    5.出队
    6.取队首元素
    7.利用队列实现银行排队业务处理模拟
*/


/*此处是顺序队列数据结构定义*/
typedef int DataType;
struct seqQueue//请完成数据结构定义
{
    int MAXNUM;//记录顺序队列中最大元素个数
    int front, rear;//存放顺序队列的队首，队尾
    DataType* element;//存放数据元素的连续空间的起始地址
};

typedef struct seqQueue *PseqQueue;
//第一关
PseqQueue createNullQueue_seq(int m)
{//此处填写代码，创建一个空的顺序队列，能存放的最大元素个数为 m
 //若m=0，则返回NULL 
    if(m==0){
        return NULL;
    }else{
        PseqQueue p=(PseqQueue)malloc(sizeof(struct seqQueue));//头结点空间
        p->element=(DataType *)malloc(sizeof(struct seqQueue));//其余节点空间
        p->front=p->rear=0;//队首和队尾初始化
        p->MAXNUM=m;//最大元素
        return p;
    }
}

//第二关
int isNullQueue_seq(PseqQueue Q)
{
  //判断顺序（环形）队列是否为空，若为空，返回值为1，否则返回值为0,若队列不存在，则返回-1
    if(Q==NULL){
        return -1;
    }else{
        if(Q->front==Q->rear)
            return 1;
        else
            return 0;
    }
}


//第三关 
int isFullQueue_seq(PseqQueue Q)
{
  //判断环形队列是否已满，若已满，返回值为1，否则返回值为0
    if((Q->rear+1)%Q->MAXNUM==Q->front)
        return 1;
    else
        return 0;
}


//第四关
int enQueue_seq(PseqQueue Q ,DataType x)
{//在环形队列中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if(isFullQueue_seq(Q))
        return 0;
    else{
        Q->element[Q->rear]=x;
        Q->rear++;
        return 1;
    }    
}
 


//第五关
DataType delQueue_seq(PseqQueue Q)
{//出队并返回删除元素，若队列为空，则返回-1
    if(Q->front==Q->rear)
        return 1;
    else{
        DataType a=Q->element[Q->front];
        Q->front++;
        return a;
    }
}

//第六关
DataType front_seq(PseqQueue Q)
{// 取队首元素返回，若队列为空，则返回-1
    if (Q->front == Q->rear)
        return -1;
    else
        return (Q->element[Q->front]);
}

//销毁顺序队列，释放队列所占存储空间
int destroyQueue_seq(PseqQueue Q)
{
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (Q == NULL)
        return 0;
    else{
        int num = Q->rear;
        Q->MAXNUM = 0;
        free(Q->element);
        return num;
    }
}


//第七关
void queueApp(int a[],int n)
{
//参数用于传递顾客编号和顾客人数，输出顾客接受服务后离开顺序
    int i = 0;

    PseqQueue Q1 = createNullQueue_seq(n); //A窗口
    PseqQueue Q2 = createNullQueue_seq(n); //B窗口

    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0)
            enQueue_seq(Q2, a[i]);
        else
            enQueue_seq(Q1, a[i]);
    }
    
    while (Q1->front != Q1->rear && Q2->front != Q2->rear){
        a[i++] = delQueue_seq(Q1);
        a[i++] = delQueue_seq(Q1);
        a[i++] = delQueue_seq(Q2);
    }

    while (Q1->front != Q1->rear && Q2->front == Q2->rear){
        a[i++] = delQueue_seq(Q1);
    }

    while (Q2->front != Q2->rear && Q1->front == Q1->rear){
        a[i++] = delQueue_seq(Q2);
    }

    for (int i = 0; i < n; i++){
        printf(" %d", a[i]);
    }

}









