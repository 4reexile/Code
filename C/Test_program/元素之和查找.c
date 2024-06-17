#include <stdio.h>

void compute(int data[],int n, int target)
{//在此处填写代码，在data数组中查找是否存在两个元素之和为target，并按要求输出
  /*-----------begin---------------*/ 
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
 /*-----------end---------------*/ 

}

int main(void)
{
    int a[]={-3,2,5,9,15,32};
    int x ;
    scanf("%d",&x);
    compute(a,6,x);
}
