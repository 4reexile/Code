#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*此处是顺序栈数据结构定义*/
typedef int DataType;
struct seqStack
{//有3个数据成员
  int MAXNUM;//用于记录顺序栈中能存放的最大元素个数的 整型 MAXNUM   
  int top;//用于存放顺序栈的栈顶位置，初始化为0或-1 均可  整型  curNum
  DataType *element;//用于存放顺序栈数据元素的连续空间的起始地址  
};

typedef struct seqStack *PseqStack;
//第一关
PseqStack createNullStack_seq(int m)
{//此处填写代码，创建一个空的顺序栈，能存放的最大元素个数为 m,栈顶top设置为0
 //若m=0，则返回NULL 
    if(m==0)
        return NULL;//m=0可不就是无吗
    
    struct seqStack * slist=(struct seqStack *)malloc(sizeof(struct seqStack));//头结点分配空间
    
    if(slist!=NULL){//当新建的顺序栈不为空时
        slist->element=(DataType *)malloc(sizeof(DataType)*m);//创建m个element的空间

        if(slist->element){//写入头结点数据
            slist->MAXNUM=m;
            slist->top=0;
            return slist;
        }
    }
    return NULL;//否则返回NULL
}

//第二关
int isNullStack_seq(PseqStack L)
{
  //判断顺序栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
    if (L==NULL){
        return -1;
    }else if(L->top==0){
        return 1;
    }else{
        return 0;
    }
}


//第三关 
int isFullStack_seq(PseqStack L)
{
  //判断顺序栈是否已满，若已满，返回值为1，否则返回值为0
    if(L->top==L->MAXNUM){
        return 1;
    }else{
        return 0;
    }
}

//第四关
int push_seq(PseqStack L ,DataType x)
{//在顺序栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if(isFullStack_seq(L)||L==NULL){
        return 0;
    }else{
        L->element[L->top]=x;
        L->top=L->top+1; 
        return 1;
    }
}

//第五关
DataType pop_seq(PseqStack L)
{//弹栈并返回删除元素，若栈为空，则返回-1
    int p=0;

    if(L->top==0){
        return -1;
    }else{
        p=L->element[L->top-1];
        L->top=L->top-1;
        return p;
    }
}

//第六关
DataType top_seq(PseqStack L)
{// 取栈顶元素返回，若栈为空，则返回-1
    if(L->top ==0){
        return -1;
    }else{
        return L->element[L->top];
    }
}


//销毁顺序栈，释放栈所占存储空间
int destroystack_seq(PseqStack L)
{
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    int m;
    
    if(L==NULL){
        return 0;
    }else{
        m=L->top;
        free(L->element);
        L->element=NULL;
        L->top=NULL;
        L->MAXNUM=0;
        return m;
    }
}


//第七关
//使用已实现的栈操作，实现数制转换

void print(PseqStack L)
{
//逐个弹出栈L中的数据元素并输出，输出数据间不需要任何间隔符号
    int x; 

    for(int i=0;i < L->MAXNUM;i++){
        x=pop_seq(L);
        printf("%d",x);
    }

}
    
void convert(int data,int k)  
{  
    //利用栈实现将data转换为k进制，k可能是2，8，16. 在本函数内实现转换并调用print函数输出转换后的结果
    //十六进制时输出 A ,B ,C, D,E,F 使用大写字母

    struct seqStack* slist=createNullStack_seq(9);//调用创建函数,最大就是9，请不要搞事
    int i,x; 
    char a; 

    while(data>0){
        push_seq(slist,data%k); 
        data/=k;
    }

    while(slist->top!=0){
        x=pop_seq(slist);
        if(x!=-1){
            if(x>9){ 
                printf("%c",x+55);//实现大于9的数字转换为大写字母
            }else
            printf("%d",x);
        }
    }  

}










