#include <stdio.h>
#include <stdlib.h>

//用栈来实现十进制转化为二进制

typedef int DataType;
 
//采用链式栈 
struct node{
   DataType element;  //数据元素 
   struct node *next; //指向下一个数据元素的指针,我更倾向于它是top指针
};
typedef struct node * Stack;
 
/*
   函数名：isEmpty 
   函数功能：判定栈是否为空 
   函数参数：栈头结点指针 
   返回值：若栈为空，则返回1，否则返回0
*/
int isEmpty(Stack s) 
{
   //此处请填写代码，用于实现判定栈是否为空的功能
   /**********  Begin  **********/
   if(s->next==NULL){ //头结点指向下一个节点还是空那这个栈就是空的
      return 1;
   }else{
      return 0;
   }
   /**********  End  **********/
}


/*
   函数名：createStack 
   函数功能：创建一个空栈，实际上只需要初始化栈头结点 
   函数参数：无 
   返回值：栈头结点指针 
*/
Stack createStack(void)  
{
   //此处请填写代码，用于创建一个空的链栈
   /**********  Begin  **********/
   Stack top=(Stack)malloc(sizeof(Stack));   //新建一个栈头结点
   top->element=0;
   top->next=NULL;  //栈顶设置为0

   return top;
   /**********  End  **********/
}

/*
   函数名：push 
   函数功能：向栈中压人一个数据元素值为x 
   函数参数：待压栈的数据元素，栈头结点指针 
   返回值：无
*/
void push(DataType  x,Stack s) 
{
   //表头作为栈顶，此处请填写代码实现压栈功能
   /**********  Begin  **********/
   Stack p=(Stack)malloc(sizeof(Stack));  //新建一个进行操作的节点
   Stack q=(Stack)malloc(sizeof(Stack));  //新建一个进行操作的节点

   p->element=x;
   p->next=NULL;  //赋值

   q=s;
   for(q->next;q->next!=NULL;q=q->next);
   q->next=p;  //与上一个节点连接
   //s=p;        //现在top指向了这个新的节点

   //没有返回值，top指针不动的话可能到时候要先遍历到栈顶再进行pop
   //最后还是选择没动top
   /**********  End  **********/
}

/*
   函数名：pop 
   函数功能：弹出栈顶元素并返回元素值 
   函数参数：栈头结点指针 
   返回值：栈顶元素的值 
*/
DataType pop(Stack s) 
{
   //此处请填写代码实现出栈并返回栈顶元素的功能，若栈为空，则返回-1
   /**********  Begin  **********/ 
   int n,m;
   Stack p=(Stack)malloc(sizeof(Stack));  //新建一个进行操作的节点
   Stack q=(Stack)malloc(sizeof(Stack));  //新建一个进行操作的节点
   p=q=s;

   for(p->next;p->next!=NULL;p=p->next);  //现在p指针到达了栈顶
   for(;q->next->next!=NULL;q=q->next);
   if(isEmpty(s)){   //空为1，非空为0
      printf("error");
      exit(0);
   }else{
      n=p->element;
      p->element=0;
      p->next=NULL;
      s=q;
      s->next=NULL;
      return n;
   }
   /**********  End  **********/
}

/*
   函数名：convert10to2
   函数功能：将十进制数x转换为二进制并输出 
   函数参数：十进制数x 
   返回值：无 
*/
void convert10to2(int x)
{
   //此处请填写代码实现将参数x转换为二进制并输出的功能，请使用上述栈的基本操作实现
   /**********  Begin  **********/
   int a,m;
   int n=x;
   Stack top=createStack();   //创建头结点
   //入栈
   while(n!=0){   
      m=n%2;   //m为余数
      n=n/2;   //n自己除去2
      push(m,top);  //入栈的是余数
   }
   //出栈和输出
   printf("十进制为:%d\n转化为二进制为:",x);
   while(!isEmpty(top)){//空为1，非空为0
      a=pop(top);
      printf("%d",a);
   }
   /**********  End  **********/
}

int main(void)
{
    int x;
    scanf("%d",&x);
    convert10to2(x);
}
