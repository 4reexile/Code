#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
   函数名：Insert_Sort
   函数功能：插入排序
   函数参数：数组指针，数组长度
   返回值：无
*/
void Insert_Sort(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        int p = i;        // 已经有序的最后一个元素位置，第一个元素不排序
        int x = a[p + 1]; // 需要排序的元素

        while (p >= 0)
        {
            if (a[p] > x) // 若前一个数字大于x，则需将他向右移动
            {
                a[p + 1] = a[p];
                p--;
            }
            else // 前面元素小于x
            {
                break;
            }
        }
        // 前面的数字都大于x，x放在下标为0处,全判断完了这p就变成-1了啊
        a[p + 1] = x;
    }
}

/*
   函数名：Shell_Sort
   函数功能：希尔排序
   函数参数：数组指针，数组长度
   返回值：无
   像个插入排序的优化版本
*/
void Shell_Sort(int *a, int n)
{

    int i, gap = n;
    while (gap > 1)
    {
        gap = gap / 2; // 分组，当gap=1的时候，我滴任务完成啦
        for (i = 0; i < n - gap; i++)
        {
            int p = i;          // 已经有序的最后一个元素位置
            int x = a[p + gap]; // 需要排序的元素对应位置
            while (p >= 0)
            {
                if (a[p] > x)   //大的放后面
                {
                    a[p + gap] = a[p];
                    p = p - gap;
                }
                else//否则就不用变
                {
                    break;
                }
            }//最小的就放最前面
            a[p + gap] = x;
        }
    }
}

/*
   函数名：Select_Sort
   函数功能：选择排序
   函数参数：数组，数组长度
   返回值：无
*/
void Select_Sort(int *a, int n)
{

    int begin = 0;   // 保存数组的起始位置
    int p = n - 1; // 保存换数组的末尾位置

    while (begin < p)
    {
        int maxi = begin; // 保存最大元素下标
        int mini = begin; // 保存最小元素下标

        // 遍历数组同时寻找最小和最大元素坐标
        for (int i = begin; i <= p; i++)
        {
            if (a[i] < a[mini])
            {
                mini = i;
            }
            if (a[i] > a[maxi])
            {
                maxi = i;
            }
        }

        // 将最小元素交换到起始位置
        Swap(a + begin, a + mini);

        // 判断最大值的位置是否在起始位置
        if (maxi == begin)
        {
            maxi = mini;
        }

        // 将最大元素交换到末尾位置
        Swap(a + p, a + maxi);
        // 移动数组起始和末尾位置
        begin++;
        p--;
    }
}

/*
   函数名：Input
   函数功能：生成随机数塞进数组
   函数参数：数组，数组长度
   返回值：无
*/
// 堆排序
void AdjustDown(int *a, int n, int root) // 向下调整
{

    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
        {
            child++;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *a, int n)
{

    // 建堆
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(a, n, i);
    }

    // 交换
    for (int i = n - 1; i > 0; i--)
    {
        Swap(&a[i], &a[0]);
        AdjustDown(a, i, 0);
    }
}

/*
   函数名：Bubble_Sort
   函数功能：冒泡排序
   函数参数：数组，数组长度
   返回值：无
*/
void BubbleSort(int *a, int n)
{

    int i = 0;
    int flag = 0;

    // n-1趟排序
    for (i = 0; i < n - 1; i++)
    {
        int j = 0;

        // 一趟冒泡排序
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }

        // 若某一趟排序中没有元素交换则说明所有元素已经有序，不需要再排序
        if (flag == 0)
        {
            break;
        }
    }
}

/*
   函数名：Input
   函数功能：生成随机数塞进数组
   函数参数：数组，数组长度
   返回值：无
*/
// 快速排序hoare版本
int PartSort1(int *a, int left, int right)
{

    int key = right; // 选定基准值
    while (left < right)
    {
        // 选右边为基准值，左指针先走
        while (left < right && a[left] <= a[key])
        {
            left++;
        }

        // 右指针再走
        while (left < right && a[right] >= a[key])
        {
            right--;
        }

        Swap(&a[left], &a[right]);
    }
    Swap(&a[left], &a[key]);
    return left;
}

void QuickSort(int *a, int left, int right)
{

    if (left >= right)
    {
        return;
    }

    int keyi = PartSort1(a, left, right);
    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}

/*
   函数名：Input
   函数功能：生成随机数塞进数组
   函数参数：数组，数组长度
   返回值：无
*/
// 快速排序挖坑法
int PartSort2(int *a, int left, int right)
{
    int key = a[left]; // 取出基准值
    int hole = left;   // 保存坑的位置
    while (left < right)
    {
        while (left < right && a[right] >= key)
        {
            right--;
        }
        a[hole] = a[right];
        hole = right;

        while (left < right && a[left] <= key)
        {
            left++;
        }
        a[hole] = a[left];
        hole = left;
    }
    a[hole] = key;
    return hole;
}

/*
  函数名：Input
  函数功能：生成随机数塞进数组
  函数参数：数组，数组长度
  返回值：无
*/
// 快速排序前后指针法
int PartSort3(int *a, int left, int right)
{
    // 1.将基准值定在left
    int keyi = left;
    int prev = left;
    int cur = left + 1;
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    Swap(&a[prev], &a[keyi]);

    // 2.将基准值定在right
    /*int keyi = right;
    int prev = left - 1;
    int cur = prev + 1;
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[cur], &a[prev]);
        }
        cur++;
    }
    Swap(&a[keyi], &a[++prev]);
    return prev;*/
}

int main(){
    //这里是一函数调用,根据要求修改
    srand(time(0));
    const int N = 100000;
    int* a1 = (int*)malloc(sizeof(int) * N);
    int* a3 = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i)
    {
        a1[i] = rand();
        a3[i] = a1[i];
    }
    int begin3 = clock();
    Select_Sort(a3, N);
    int end3 = clock();
    printf("SelectSort:%d\n", end3 - begin3);
    free(a1);
    free(a3);
}
