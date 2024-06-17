#include<stdio.h>
/*
    新的思维方法：
    取一个数的每一位的时候就可以用这个方法
    而且，你还可以写成自定义函数
*/

	int main(void)     
	{  
      int i,a,b,c;
      c=1;

        scanf("%d",&a);

        if(a%10==0)
            printf("0");
        else{
            while (a!=0) 
            {
                i=a/10;     //每次循环，b会成为a最后的一个数
                b=a%10;     //而a每次循环都会少一位
                a=i;        //这个i实际上暂存了少了最后一位的a数值
                c=c*b;      //c作为相乘得到的数
            }
            printf("%d",c);
        }
	  
      //system("pause");
       return 0;
	}
