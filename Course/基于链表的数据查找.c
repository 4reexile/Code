#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct link{
	int num;
	struct link *next;
}lin;

int main()
{ 
	lin *head,*tail,*p,*q;
	int size = sizeof(lin),position=1,number=1,flag=1,stop=1;
	head=(lin*)malloc(size);
	tail=head;

	printf("请输入数据\n");

	while(position++<7){ 
		p=(lin*)malloc(size);	//新的链表p
		scanf("%d",&p->num);

		tail->next=p;	//指向这个新的链表
		tail=p;
	} 
	p->next=NULL; //结束链表 会吃掉最后一个数字

	printf("\n你输入的数据是\n");
	for(p=head->next;p!=NULL;p=p->next)		//输出
		printf("%d ",p->num); 

		//scanf("%d",&position);

	
		printf("\n--------请输入1-5-------\n");
		printf("1.-----查找数据位置-----\n");
		printf("2.-------查找数据-------\n");
		printf("3.-------插入数据-------\n");
		printf("4.-------删除节点-------\n");
		printf("5.---------退出---------\n");

	do{
		fflush(stdin);    //清除输入
        scanf("%d",&position);     //反复利用（）
		 
		switch (position){

			case 1:
				printf("请输入你想查找的数据位置:");
				scanf("%d",&position);

				if(position>6||position<1)
					printf("序号溢出\n");
				else{
					for(p=head;position>0;p=p->next){
						position--;
					}	
						printf("所查数值：%d\n",p->num);
				}
				break;

			case 2:
				printf("请输入你想查找的数据:");
				scanf("%d",&position);

				for(p=head->next;p!=NULL;p=p->next){
					if(position==p->num){	
						printf("数据的位置为：%d\n",number);
					flag=0;
					} 
					number++;
				}
				if(flag)
					printf("该值不在链表内\n");
				break;

			case 3:
				printf("请输入插入到的位置:");
				scanf("%d",&position);

				if(position>7||position<1)
					printf("序号溢出");
				else{
					q=(lin*)malloc(size);
					printf("请输入你的数据的值:");
					scanf("%d",&q->num);	//给新的节点赋值

					for(p=head;position>1;p=p->next){		//找到添加的位置，>0会在后一位
						position--;
					}
					q->next=p->next;	//新的节点的next指向它前面的next所指的节点
					p->next=q; 	//它前面的next所指的节点指向它

					for(p=head->next;p!=NULL;p=p->next)//新的输出
						printf("%d ",p->num);
				}
				break;

			case 4:
				printf("请输入删除节点的位置:");
				scanf("%d",&position);

				if(position>7||position<1)
					printf("序号溢出");
				else{
					for(p=head;position>1;p=p->next){
						position--;
					}									//找到删除的位置，>0会在前一位
						p->next=p->next->next;	//直接跳过
					for(p=head->next;p!=NULL;p=p->next)		//输出新的
						printf("%d ",p->num);
				}
				break;

			case 5:
				stop = 0;
					break;
		}

	}while (stop);
	//system("pause");
	return  0;
}
