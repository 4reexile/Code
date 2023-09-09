#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 这个程序实现评委算分：去掉最大值和最小值，再求平均值

int main()
{

    int score, sum, i; // 定义所需要的函数
    int max, min;
    float avg;

    i = 1; // 赋值
    max = 0;
    min = 10;
    sum = 0;

    while (i <= 10) // 循环控制条件
    {
        scanf("%d", &score); // 输入
        if (score > max)     // 自己能一个一个输入那是震撼我妈
            max = score;
        if (score < min)
            min = score;
        sum = sum + score;
        i++; // 循环控制变量
    }

    avg = (sum - max - min) / 8.0; // 求平均值
    printf("%.3f", avg);           // 输出

    //system("pause");
    return 0;
}
