#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    char op = 0;
    double a, b = 0;
    double sum = 1;
    int i, n;
    int stop = 1; // 正在定义变量

    do
    {
        printf("------------------------计算器--------------------------\n");
        printf("----------输入你想进行的运算：+、-、*、/、^、!----------\n");
        printf("-----------------------输入@退出------------------------\n");
        fflush(stdin);    // 只是在给你个开始界面
        scanf("%c", &op); // 在给符号位赋值

        switch (op)
        { // 判定开始

        case '+': // 加法计算
            printf("请输入第一个数\n");
            scanf("%lf", &a);
            printf("请输入第二个数\n");
            scanf("%lf", &b);
            printf("a + b =%.2f\n", a + b);
            break;

        case '-': // 减法计算
            printf("请输入被减数\n");
            scanf("%lf", &a);
            printf("请输入减数\n");
            scanf("%lf", &b);
            printf("a - b =%.2f\n", a - b);
            break;

        case '*': // 乘法计算
            printf("请输入第一个数\n");
            scanf("%lf", &a);
            printf("请输入第二个数\n");
            scanf("%lf", &b);
            printf("a * b =%.2f\n", a * b);
            break;

        case '/': // 除法计算
            printf("请输入被除数\n");
            scanf("%lf", &a);
            printf("请输入除数\n");
            scanf("%lf", &b);
            printf("a / b =%.2f\n", a / b);
            break;

        case '^': // 乘方计算
            printf("请输入底数\n");
            scanf("%lf", &a);
            printf("请输入指数\n");
            scanf("%lf", &b);
            printf("a ^ b =%.2f\n", pow(a, b));
            break;

        case '!': // 阶乘计算
            printf("请输入一个数\n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
                sum = sum * i;
            printf("%d!=%.2f\n", n, sum);
            break;

        case '@': // 光速退出程序
            stop = 0;
            break;
        }

    } while (stop);
    printf("------程序已经结束------\n");
    return 0;
}
