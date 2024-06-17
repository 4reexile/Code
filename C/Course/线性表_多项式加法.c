#include <stdio.h>
#include <stdlib.h>

//线性表实现多项式的加法
//结构体:
typedef struct tagNode
{
	float coef;   //系数
	int exp;      //指数
	struct tagNode *next;      
}Node,*Link;


/*
  函数功能：生成多项式
  函数名：Create_Link
  函数参数：无
  返回值：指向多项式的头指针 
*/
Link Create_Link(int num)        //尾插法建立(既然是*Link,不再用Node*了)
{
	float coef1=0;     //临时系数
	int exp1=0;        //临时指数
	
	Link head=(Node *)malloc(sizeof(Node));
	head->next=NULL;
	//Link p=NULL	  p是后指针
	Link q=head;	//q是前指针（靠近head）
	q->next=NULL;

	//输入
	for (int i=1;i<=num;i++)	//控制循环，不想用那个输入为0 0终止了，问题太多
	{
		printf("input the coef and exp");
		scanf("%f %d",&coef1,&exp1);    //输入
		Link p=(Node *)malloc(sizeof(Node));
		p->exp=exp1;
		p->coef=coef1;
		q->next=p;
		q=p;
	}
	q->next=NULL;
	return head;       //返回头结点

/*这就是那个当输入为0 0的时候终止输入的代码
int exp1=0;        //临时指数
float coef1=0;     //临时系数
Link p=NULL;
Link head=(Node *)malloc(sizeof(Node));
Link q=head;q->next=0;

do{
	scanf("%f %d",&coef1,&exp1);
	p=(Node *)malloc(sizeof(Node));
	p->coef=coef1;p->exp=exp1;
	q->next=p;
	q=p;
}while((coef1!=0)||(exp1!=0));
q->next=NULL;
return head;
*/
}


/*
   函数功能：输出多项式 
   函数名：Print_Poly
   函数参数：待输出多项式的头指针poly 
   返回值：无 
*/
void Print_Poly(Link head)        //打印多项式
{
	Link p=head->next;
	while (p!=NULL)	//遍历到链表末尾
	{
		if(p->coef>0)  
			printf("%.1fX^%d",p->coef,p->exp);
		else//照顾一下负数
			printf("(%.1f)X^%d",p->coef,p->exp);
		
		if (p->next != NULL)
			printf("+");   
		p=p->next;
	}
}


/*
   函数功能：进行多项式相加
   函数名：Add_Poly
   函数参数：polyAddLeft ：加法左边多项式头指针, polyAddRight：加法右边多项式头指针 
   返回值：指向结果多项式的头指针 
*/
Link Add_Poly(Link heada, Link headb)      //进行多项式相加
{
	Link headc=(Node *)malloc(sizeof(Node));
	headc->next=NULL;
	Link q=headc;	
	
	Link pa=heada->next;
	Link pb=headb->next;
	Link pc=headc->next;//链表pc是存放结果的地方

	while (pa!=NULL||pb!= NULL){    //如果都为空就结束
		Link p=(Node *)malloc(sizeof(Node));//p是pc后指针,q是前指针
		p->next=NULL;

		if (pa!=NULL&&pb!= NULL){    //都不为空再进行运算
			if(pa->exp<pb->exp){	//比较链表1跟链表2当前节点的指数大小,b的大
				p->exp=pa->exp;
				p->coef=pa->coef;
				q->next=p;
				q=p;
				pa=pa->next;
			}else if (pa->exp>pb->exp){     //a的这一项指数大
				p->exp=pb->exp;
				p->coef=pb->coef;
				q->next=p;
				q=p;
				pb=pb->next;
			}else{ //if(pa->exp==pb->exp)   //指数相同
				if (pa->coef+pb->coef==0)   //系数如果加起来等于0什么也不做
				{
					pa=pa->next;
					pb=pb->next;
				}else{       //系数加起来不为零
				
					p->exp=pa->exp;
					p->coef=pa->coef+pb->coef;
					q->next=p;
					q=p;
					pa=pa->next;
					pb=pb->next;
				}
			}
		}else if (pa!=NULL&&pb==NULL){//b多项式所有项处理完了，a还没处理完
			p->exp=pa->exp;
			p->coef=pa->coef;
			q->next=p;
			q=p;
			pa=pa->next;
		}else if (pa==NULL&&pb!=NULL){//a多项式所有项处理完了，b还没处理完
			p->exp=pb->exp;
			p->coef=pb->coef;
			q->next=p;
			q=p;
			pb=pb->next;
		}
	}
	return headc;
}

//主函数
int main()
{
	int n=0, m=0;
	Link pc=NULL;
	
	printf("多项式A\n");//创立多项式A
	printf("请输入多项式的项数：");
	scanf("%d", &n);
	Link pa=Create_Link(n);
	Print_Poly(pa);
	printf("\n");


	printf("多项式B\n");//创立多项式B
	printf("请输入多项式的项数：");
	scanf("%d", &m);
	Link pb=Create_Link(m);
	Print_Poly(pb);
	printf("\n");


	pc=Add_Poly(pa, pb);//计算出多项式C
	printf("\nRESULT:\n多项式C:");
	Print_Poly(pc);

	return 0;
}
