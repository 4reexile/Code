#include <stdio.h>

int main(void)
{
    /*********Begin*********/
    int a[10], b[10];
    int i, j, d = 0, k;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);  //得到的数据输入到a数组
        b[i] = a[i];
    }
    

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 10; i++)
        {
            if (b[i] > d)
            {
                d = b[i];  //利用b数组进行排序
                k = i;
            }
        }
        if (d == 0)
            break;
        b[k] = 0;
        a[j] = d;
        d = 0;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    /*********End**********/
    //system("pause");
    return 0;
}
