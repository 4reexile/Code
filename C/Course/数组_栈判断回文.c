#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

// 队列数据元素结构
typedef struct node
{
   DataType info;
   struct node *next;
} queuedata;

typedef struct queueRecord
{
   queuedata *front, *rear;
} linkqueue;
typedef struct node *pqueuedata;
typedef struct queueRecord *PLinkQueue;

/*
函数名:createEmptyQueue_link
函数功能:创建一个空队列
函数参数:无
返回值:无
*/
PLinkQueue createEmptyQueue_link()
{
   // 创建一个空队列，实质：生成一个LINKQUEUE类型的结点，并给front 和 rear 成员赋值
   // 请在此处填写代码，完成相应功能
   /*-------begin----------*/
   PLinkQueue p = (PLinkQueue)malloc(sizeof(linkqueue));
   p->front = NULL;
   p->rear = NULL;
   /*-------end----------*/
}

/*
函数名:isEmptyQueue_link
函数功能:判断队列是否为空
函数参数:队列指针
返回值:布尔值0或1
*/
int isEmptyQueue_link(PLinkQueue queue)
{
   // 判定队列是否为空，实质： 看队列的front指针是否为空，若为空，则队列为空
   /*-------begin----------*/
   PLinkQueue p;
   p = queue;
   if (p->front == NULL)
      return 1;
   else
      return 0;
   /*-------end----------*/
}

/*
函数名:enQueue_link
函数功能:将数据插入队尾
函数参数:数据x,队列指针
返回值:无
*/
void enQueue_link(DataType x, PLinkQueue queue)
{
   // 将数据元素x插入队尾。实质：生成一个struct node类型的结点，并给相应成员赋值后插入队尾
   /*-------begin----------*/
   pqueuedata p = (pqueuedata)malloc(sizeof(struct node));
   if (queue->front == NULL && queue->rear == NULL)
   {
      queue->front = p;
      queue->rear = p;
   }
   p->info = x;
   p->next = NULL;
   queue->rear->next = p;
   queue->rear = queue->rear->next;
   /*-------end----------*/
}

/*
函数名:deQueue_link
函数功能:将数据出队
函数参数:队列指针
返回值:出队数据
*/
DataType deQueue_link(PLinkQueue Q)
{
   // 出队，实质： 取出Q队列的队首结点，返回该结点的数据元素，并将该结点使用enQueue_link(QueueData *p,PLinkQueue Q)插入队尾
   // 本函数为针对本实验特殊设计，可实现秘钥的循环使用
   /*-------begin----------*/
   pqueuedata p = Q->front;
   DataType a = Q->front->info;
   Q->front = Q->front->next;
   free(p);
   return a;
   /*-------end----------*/
}

// 下面放自己在有关栈的实验中写过的栈的代码，或者如果会用stl中的stack也可以用
// 注意需要根据具体情况做必要修改
/*-------begin----------*/
struct zhan
{
   DataType element;
   struct zhan *next;
};

typedef struct zhan *PtrToNode;
typedef struct zhan *stack;

int emptystack(stack s)
{

   if (s->element == 0 && s->next == NULL)
      return 1;
   else
      return 0;
}
stack createStack(void)
{

   stack top = (stack)malloc(sizeof(struct zhan));
   top->element = 0;
   top->next = NULL;
   return top;
}

void pushstack(DataType x, stack s)
{

   stack a = (struct zhan *)malloc(sizeof(struct zhan));
   a->element = x;
   a->next = s->next;
   s->next = a;
}
DataType popstack(stack s)
{
   int a;

   if (emptystack(s))
      return -1;
   else
   {
      stack node = s->next;
      a = node->element;
      s->next = node->next;
      free(node);

      return a;
   }
}
/*-------end----------*/

/*
函数功能：输入字符串，使用栈和队列，判断该字符串是否是回文，是回文则返回1，否则返回0
输入参数： src 放的是要判断是否是回文的字符串
返回值：1：回文；0：不是回文
*/
int ishuiwen(char src[])
{
   /*-------begin----------*/
   PLinkQueue p1 = createEmptyQueue_link();
   stack p2 = createStack();
   int i = 0;
   int j = 0;
   while (src[i] != '\0')
   {
      enQueue_link(src[i], p1);
      i++;
   }
   while (src[j] != '\0')
   {
      pushstack(src[j], p2);
      j++;
   }
   while (isEmptyQueue_link(p1) != 1)
   {
      DataType x1 = deQueue_link(p1);
      DataType x2 = popstack(p2);
      if (x1 != x2)
         return 0;
   }
   return 1;
   /*-------end----------*/
}

int main(void)
{
   // 请自行补充完整主函数，调用函数ishuiwen进行判断。

   /*-------begin----------*/
   char a[100] = {'0'};
   scanf("%s",a);

   int res = ishuiwen(a);
   if (res == 1)
      printf("yes");
   else
      printf("no");
   /*-------end----------*/
   return 0;
}
