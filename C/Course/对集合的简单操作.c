#include <stdio.h>
#include <stdlib.h>

//利用线性表实现集合的交集并集差集

typedef int DataType; 

struct node
{
	DataType element;
	struct node *next;
};
typedef struct node * SET;
void insert(DataType datax, SET set);

/*
  函数名： InitSet
  函数功能：根据参数num，初始化集合
  函数参数：集合元素的个数 
  返回值：集合头指针 
*/
SET InitSet(int num)
{
    //创建头结点
    SET p=(SET *)malloc(sizeof(SET));
    p->next = NULL;
    p->element = num;
    //将输入数据插入集合
    int temp;
    for(int i =0;i<num;i++)
    {
        scanf("%d",&temp);
        insert(temp, p);    
    }
    return p; 
}

/*
  函数名： find
  函数功能：在集合中查找值为datax的成员 
  函数参数：datax:待查找的值 ； set：集合的头结点 
  返回值：找到值为datax的成员返回1，否则返回0 
*/
int find(DataType datax, SET  set)
{
    //请在此处填写代码，在set集合中查找值为datax的成员，若找到返回1，否则返回0
    /**********  Begin  **********/
    SET p=set->next;
    
	while (p!=NULL)     //遍历链表
	{
		if(p->element==datax)
		    return 1;

		p=p->next;
	}
	return 0;
    /**********   End   **********/
}

/*
  函数名： insert
  函数功能：在集合set中插入值为datax的成员 ，插入位置在表头 
  函数参数：datax:待插入的值 ； set：集合的头结点 
  返回值：无 
*/
void insert(DataType datax, SET set)
{
    //请在此处填写代码，将datax插入集合set， 注意因集合元素是无序的，只需将新成员插入表头
    /**********  Begin  **********/
    SET p=(SET *)malloc(sizeof(SET)) ;
    p->element = datax;
    p->next = set->next;
    set->next = p;
    /**********   End   **********/
 }

/*
  函数名： copyList
  函数功能：将集合setA复制生成集合setB 
  函数参数：setA 、setB的头结点 
  返回值：无 
*/
void copySet(SET setA, SET setB)
{
    //请在此处填写代码，实现将集合setA的成员复制到集合setB的功能
    /**********  Begin  **********/
    SET copy1 = setA->next;
	SET copy2 = setB->next;
	while(copy1!=NULL)
	{
		insert(copy1->element,copy2);
		copy1 = copy1->next;
	}
    
    /**********   End   **********/
}

/*
  函数名： printSet
  函数功能：输出集合的元素，以空格作为元素之间分界符 
  函数参数：set的头结点 
  返回值：无 
*/
void printSet(SET set)
{
    //请在此处填写代码，实现输出集合元素的功能，元素之间以空格为分界符
    /**********  Begin  **********/
    SET p = set->next;
    while (p!=NULL)
	{
		printf("%d\t",p->element);
		p = p->next;
	}
    
    /**********  End  **********/
}

/*
  函数名： setUnion
  函数功能：求两个集合setA 和 setB的并集 
  函数参数：setA和setB的头结点 
  返回值：并集集合的头结点 
*/
SET setUnion(SET setA ,SET setB)
{
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET p = (SET *)malloc(sizeof(SET));
	p->next = NULL; //储存位置
	
	SET a = setA->next;
	SET b = setB->next;

	while (a != NULL)   //首先把整个setA塞进去（并不需要排序）
	{
		insert(a->element,p);
		a = a->next;
	}
	while (b != NULL)
	{
		if(find(b->element,setA) == 0)
			insert(b->element,p);
		b = b->next;
	}
	return p;

    /*
    突然发现上面有个copy函数
    可以直接调用copySet然后找到相同项删除其中的一个，但是似乎对setB进行了修改，不采用

    copySet(setA,setB);

    SET b = setB->next;
    while(b!=NULL)
    {
        if(find(b->element,setB) == 0)
            insert(b->element,p)
            b = b->next;
    }
    return p;

    */
    
    /**********  End  **********/
}

/*
  函数名： setIntersect
  函数功能：求两个集合setA 和 setB的交集 
  函数参数：setA和setB的头结点 
  返回值：交集集合的头结点 
*/
SET setIntersect(SET setA ,SET setB)
{
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET p = (SET *)malloc(sizeof(SET));
    p->next = NULL;
    
    SET a = setA->next;
    while(a != NULL)
    {
    	if(find(a->element,setB) == 1)  //与上面相反，直接找相同的，copySet函数....嗯
			insert(a->element, p);
    	a = a->next;
    }
    return p;
    
    /**********  End  **********/
}
    
/*
  函数名： setExcept
  函数功能：求两个集合setA 和 setB的差 
  函数参数：setA和setB的头结点 
  返回值：结果集合的头结点 
*/
SET setExcept(SET setA ,SET setB)
{
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET p = (SET *)malloc(sizeof(SET));
	p->next = NULL;

	SET a = setA->next;
	while(a != NULL)
	{
		if(find(a ->element,setB) == 0) //有相同的时候全都去掉不计入p
			insert(a ->element,p);
		a = a->next;
	}
	return p;
    
    /**********  End  **********/      
}   
      
    int main(void)
{   
    //第一个数是元素个数，而不是其中的元素
    int count;
    scanf("%d",&count);
    SET setA = InitSet(count);
    scanf("%d",&count);
    SET setB = InitSet(count);
    printf("\n并集:");
    printSet(setUnion(setA,setB));
    printf("\n交集:");
    printSet(setIntersect(setA,setB));
    printf("\n差集:");
    printSet(setExcept(setA,setB));
    
}
