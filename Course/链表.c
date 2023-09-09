#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct stud_node{  //链表结构体
    int num; 
    char name[20]; 
    int score; 
    struct stud_node *next; 
}stu;

/*
使用链表来储存编号,名字,成绩
仅包括创建链表和输出链表
*/
int main(){ 
    struct stud_node *head,*tail,*p;
    int num,score; 
    char name[20]; 
    int size = sizeof(stu); 

    head=(stu *)malloc(size);      
    //没给tail分配空间，后面怎么调用
    tail=head;

    printf("input num,name and score:\n"); 
    scanf("%d",&num); 
    
    while(num != 0){ 
        //p=malloc(size); 你怎么少了强制类型转换啊
        //分配一个结构体stud_node的大小的空间，并把空间地址赋予p

        p=(stu *)malloc(size);  //新的链表1
        scanf("%s%d",name,&score); 
        p->num=num; 
        strcpy(p->name,name); //复制
        p->score=score; 
        
        tail->next=p;   //*next指向新的链表1，tail同
        tail=p;
        scanf("%d",&num); 
    } 
    p->next=NULL; //结束链表

    //for(p=head;p->next != NULL;p=p->next)head是空指针，头结点
    for(p=head->next;p != NULL;p=p->next)   //输出
        printf("%d %s %d\n",p->num,p->name,p->score);

    //system("pause");     
    return 0;
}
