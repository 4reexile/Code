#include <stdio.h>

int main(){
	
	int i,j,c,d;
	int v;
    printf("输入all看所有数字\n");
    printf("输入1~9的数字查看单独一行\n");
	scanf("%d",&v);

    if(v>0&&v<10){
        i=v;
    
        for(j=1;j<=i;j++)
        {
            printf("%d\t",i*j);
        }
    
    }else{
        for(i=i;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d\t",i*j);
        }
        printf("\n");
    }

    }
    //system("pause");
	return 0;
}
