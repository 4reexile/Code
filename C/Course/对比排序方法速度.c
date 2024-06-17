#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
   函数名：Input
   函数功能：生成随机数塞进数组
   函数参数：数组，数组长度
   返回值：无
*/
void Input_Arr(int arr[], int length)
{
    int i;
    srand((unsigned int)time(NULL)); // 更改种子
    for (i = 0; i < length; i++)
    {
        arr[i] = rand();
    }
}

/*
   函数名：PrintfArr
   函数功能：输出数组
   函数参数：数组，数组长度
   返回值：无
*/
void Printf_Arr(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%6d ", arr[i]);
    }
    printf("\n");
}

/*
   函数名：Cope_Arr
   函数功能：复制一个新的数组用来排序
   函数参数：数组，数组长度
   返回值: 数组指针？
//*
int * Cope_Arr(int arr[], int length)
{
    int b[length];
    int i;
    for (i = 0; arr[i] != '\0'; i++)
    {
        b[i] = arr[i];
    }
    b[i] = '\0';
    return b;
}
*/

/*
   函数名：QuickSort
   函数功能：快速排序
   函数参数：数组，数组头尾
   返回值：无
*/
void QuickSort(int arr[], int left, int right)
{
    if (left > right)
    {
        return;
    }
    int i = left;
    int j = right;
    int p = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] >= p)
        {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= p)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = p;
    QuickSort(arr, left, i - 1);
    QuickSort(arr, i + 1, right);
}

/*
   函数名：Insert_Sort
   函数功能：插入排序
   函数参数：数组，数组头尾
   返回值：无
*/
void Insert_Sort(int arr[], int n)
{
    int i, j, temp, p, q;

    for (i = 1; i < n; i++)
    {
        p = i;
        temp = arr[p];
        while (p > 0)
        {
            if (arr[p - 1] > temp)
            {
                arr[p] = arr[p - 1];
                p--;
            }
            else
            {
                break;
            }
        }
        arr[p] = temp;
    }
}

/*
   函数名：Shell_Sort
   函数功能：希尔排序
   函数参数：数组指针，数组长度
   返回值：无
   像个插入排序的优化版本
*/
void Shell_Sort(int arr[], int n)
{

    int i, gap = n;
    while (gap > 1)
    {
        gap = gap / 2; // 分组，当gap=1的时候，我滴任务完成啦
        for (i = 0; i < n - gap; i++)
        {
            int p = i;            // 已经有序的最后一个元素位置
            int x = arr[p + gap]; // 需要排序的元素对应位置
            while (p >= 0)
            {
                if (arr[p] > x) // 大的放后面
                {
                    arr[p + gap] = arr[p];
                    p = p - gap;
                }
                else // 否则就不用变
                {
                    break;
                }
            } // 最小的就放最前面
            arr[p + gap] = x;
        }
    }
}

/*
   函数名：Bubble_Sort
   函数功能：冒泡排序
   函数参数：数组指针，数组长度
   返回值：无
*/
void Bubble_Sort(int arr[], int n)
{

    int i = 0, flag = 0;
    int temp;

    // n-1趟排序
    for (i = 0; i < n - 1; i++)
    {
        int j = 0;

        for (j = 0; j < n - i - 1; j++) // 一趟冒泡排序
        {
            if (arr[j] > arr[j + 1])
            {
                // 交换arr[j], arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0) // 若某一趟排序中没有元素交换则说明所有元素已经有序，不需要再排序
        {
            break;
        }
    }
}

int main()
{
    int num, i;
    printf("Enter the number of random numbers you want\n");
    scanf("%d", &num);
    int a[num];
    int a1[num];
    int a2[num];
    int a3[num];

    Input_Arr(a, num); // 产生随机数组
    printf("排序前：\n");
    // Printf_Arr(a, num); // 输出排序前的序列

    for (i = 0; i < num; i++)
    {
        a1[i] = a[i];
        a2[i] = a[i];
        a3[i]=a[i];
    }
    a1[i] = a2[i] = '\0';

    printf("排序后：\n");

    clock_t start_time1 = clock();
    QuickSort(a, 0, num - 1); // 快速排序
    clock_t end_time1 = clock();

    clock_t start_time2 = clock();
    Insert_Sort(a1, num); // 插入排序  前面经过了快速排序，那么假如直接进行插入排序，那么时间肯定是0
    clock_t end_time2 = clock();

    clock_t start_time3 = clock();
    Shell_Sort(a2, num); // 希尔排序
    clock_t end_time3 = clock();

    clock_t start_time4 = clock();
    Bubble_Sort(a3, num); // 希尔排序
    clock_t end_time4 = clock();

    printf("1 快速排序用时 %.1lf ms\n", (double)(end_time1 - start_time1) * 1000 / CLOCKS_PER_SEC);
    printf("2 插入排序用时 %.1lf ms\n", (double)(end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC);
    printf("3 希尔排序用时 %.1lf ms\n", (double)(end_time3 - start_time3) * 1000 / CLOCKS_PER_SEC);
    printf("4 冒泡排序用时 %.1lf ms\n", (double)(end_time4 - start_time4) * 1000 / CLOCKS_PER_SEC);

    return 0;
}

/*

   函数名：Swap
   函数功能：交换数组元素
   函数参数：数组指针，数组两个地址
   返回值：无

Swap(int arr[],int a1,int a2)
{
    int temp;
    temp=arr[a1];
    arr[a1]=arr[a2];
    arr[a2]=temp;
}
*/
