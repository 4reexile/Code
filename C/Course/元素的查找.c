#include <stdio.h>
#include <stdlib.h>

/*
	find_pos1:顺序查找元素
 	find_pos2:二分查找元素
  	查找进阶放最后
*/

int find_pos1(int data[] ,int n, int key)
{//在数组data中查找给定数据key,n表示数组中数据元素的个数
 /*------------begin-----------------*/
    int i,j;
    int count=-1;
    for(i=0;i<n;i++)
    {
        if(data[i]==key)
        {
            count=i;
            break;
        }
    }

    if(count==-1)
    {
        return -1;
    }else{
        return count;
    }
 /*------------end-----------------*/
}

int find_pos2(int data[] ,int n, int key)
{//在数组data中查找给定数据key，n是数组中数据元素的个数，返回值是数据元素比较的次数.
    
 /*------------begin-----------------*/
    int mid,end,start=0,times=0;
    end=n-1;
    if(data[start]>key) 
        return 0;
    if(data[end]<key) 
        return 0;
    while(start <=end) {
        times++;
        mid = (start + end)/2;
        if(data[mid] == key){ 
            break;
        }    
        else if(data[mid] > key){ 
            end = mid - 1;
        }else{ 
            start = mid + 1;
        }
    }
    return times;
 /*------------end-----------------*/
}


int main(void)
{
    int a[]={99,23,5,189,-1,66};
    int x;
    int welldow;
    scanf("%d",&x);
//此处填写代码，调用find_pos，在a数组中查找给定数据x的位置，并输出函数返回的数据元素的位置
  /*------------begin-----------------*/

    //find_pos1
    welldow=find_pos1(a,6,x);

    if(welldow==-1)
    {
        printf("%d",-1);
    }else{
        printf("%d",welldow);
    }


    /*find_pos2
	printf("%d",find_pos(a,6,x));
    */
 /*------------end-----------------*/   
    
return 1;
}



/*
查找进阶:

#include <stdio.h>
void compute(int data[],int n, int target)
{//在此处填写代码，在data数组中查找是否存在两个元素之和为target，并按要求输出
  //*-----------begin---------------*
    int i,j,s=0;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(data[i]+data[j]==target){
                printf("%d,%d",i,j);
                s=1;
            }
        }
    }
    if(s!=0){
        return 0;
    }else if(s==0){
        printf("%d,%d",-1,-1);
        return 0;
    }
 //*-----------end---------------*

}

int main(void)
{
    int a[]={-3,2,5,9,15,32};
    int x ;
    scanf("%d",&x);
    compute(a,6,x);
}
*/
