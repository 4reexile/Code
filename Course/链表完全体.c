#include <stdio.h>
#include <stdlib.h>
//第一关代码

struct node
{//此处填写代码，定义链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data;
    struct node * next;
};

struct node *mycreateList()
{//此处填写代码，创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
    struct node * ori=(struct node *)malloc(sizeof(struct node));
    ori->data=0;
    ori->next=NULL;
    return ori;

}


//第二关代码

void myinsertHead(struct node * head, int insData )
{
	/*在此处完成任务，实现在head为表头d 链表的头插数据元素insData的功能*/
	//begin
    struct node* ori=(struct node *)malloc(sizeof(struct node));
    ori->data=insData;
    ori->next=head->next;
    head->next=ori;
	//end 
}

void myinsertTail(struct node *  head , int insData )
{
	/*在此处完成任务，在head为表头的单链表表尾插入数据元素insData*/
	//begin
    struct node * q=head;
    struct node * p=(struct node *)malloc(sizeof(struct node));

    while(q->next!=NULL){
        q=q->next;
    }

    p->data=insData;
	p->next=NULL;
    q->next=p;
	//end 	
}

void myprintList(struct node *L)
{
     /*在此处完成任务，输出head为表头链表中的数据，每输出一个数据换一行*/
	//begin
	struct node * q=L->next;

    while(q->next!=NULL){
        printf("%d\n",q->data);
        q=q->next;
    }

	printf("%d\n",q->data);
	//end 
    
}

//第三关代码
 void reverseList_link( struct node *L)
 {
    //请在此处填入代码，实现链表逆置功能 
 	//begin
 	struct node * p=L->next;
    struct node * q=p;
    struct node * head=(struct node *)malloc(sizeof(struct node));

    head->data=p->data;
    head->next=NULL;
    L->next=head;
    p=p->next;
    free(q);
    q=p;

    while(p->next!=NULL){
        struct node * head=(struct node*)malloc(sizeof(struct node));
        //我要是不写上面这个，就会显示内存超出，为什么呢
        head->data=p->data;
        head->next=L->next;
        L->next=head;
        p=p->next;
        free(q);
        q=p;
    }

    struct node * head2=(struct node *)malloc(sizeof(struct node));
    head2->data=p->data;
    head2->next=L->next;
    L->next=head2;
    free(p);
	//end 
 }


//第四关代码
int locateAndChange( struct node *L, int data)
 {
    //请在此处填入代码，在头结点为L的链表中查找 与data值相等的第一个结点，若能找到该结点，则将该结点的值与前驱结点的值交换
    //若未找到与data值相等的结点，则返回值为-1，若找到的结点无前驱结点，则返回值为0，否则返回值为前驱结点的值
 	//begin
struct node * p=L->next;
struct node * q=p;

    if(p->data==data&&L->next==p){
        return 0;
    }

    p=p->next;
 	while(p->next!=NULL){
        if(p->data==data){
            int temp=p->data;
            p->data=q->data;
            q->data=temp;
            return p->data;
        }
        p=p->next;
        q=q->next;
    }

    if(p->data==data){
        int temp=p->data;
        p->data=q->data;
        q->data=temp;
        return p->data;
    }else{
        return -1;
    }
	//end 
 }

//第五关代码
int destroyList(struct node *L)
{
  //请在此处填写代码，实现将链表L的结点空间回收
 //返回值为回收结点的个数，含头结点在内   
int count=0;
    struct node * p=L->next;
    struct node * q=p;
    free(L);
    count++;

    while(p->next!=NULL){
        p=p->next;
        free(q);
        q=p;
        count++;
    }
    
    free(p);
    count++;
    return count;
}


