
#include <stdio.h>

//辗转相除,你值得拥有

int main()
{
    int m, n, max, min, b, c;
    scanf("%d%d", &m, &n);
    c = m % n;
    b = m * n;
    while (c != 0)
    {
        m = n;
        n = c;
        c = m % n;
    }
    max = n;
    min = b / max;
    printf("\n最大公约数为:%d\n最小公倍数为:%d\n", max, min);

    // system("pause");
    return 0;
}
