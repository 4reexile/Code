#include<stdio.h>
void solve(int n){
    int temp=n%10;
    int i;
  
    if((i=n/10)!=0){       //递归，你思考一下
        solve(i);
    }
  
    if(n)
        printf(" %d", temp);
    else
        printf("%d", temp);
    }

int main(void)
{
    int n;
    scanf("%d",&n);
    solve(n);
    return 0;
}
