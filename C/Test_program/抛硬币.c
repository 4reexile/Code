#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,t,s;
    n=1;
    s=0;

    while(n<=1000)
    {
        t = rand()%2;
        if(t)
            s++;
        n++;
    }
    printf("s=%d\n",s);
    printf("s/1000=%f\n",s/1000.0);

    return 0;
}
