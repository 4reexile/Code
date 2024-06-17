#include <stdio.h>

int main()
    {
        int number_2;
        int a,b,c,d;
        int sum;
        
        scanf("%d",&number_2);
        a = number_2/1000;
        b = (number_2%1000)/100;
        c = (number_2%100)/10;
        d = number_2%10;

        sum = a*8 + b*4 + c*2 + d;
        printf("%d\n",sum);
        printf("%d\n",a);
        printf("%d\n",b);
        printf("%d\n",c);
        printf("%d\n",d);

        //system("pause");
        return 0;
    }
