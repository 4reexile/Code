#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//注意,这个程序只能将下面数组内的数字拿来进行创建Huffmman树

// 哈夫曼树结点结构
typedef struct
{
    int weight;              // 结点权重
    int parent, left, right; // 父结点、左孩子、右孩子在数组中的位置下标
} HTNode, *HuffmanTree;
// 动态二维数组，存储哈夫曼编码
typedef char **HuffmanCode;

/*
   函数名：Select
   函数功能：得到两个目前权值最小的数组
   函数参数：数组，数组尾，权重最小的节点位置
   返回值：无
*/
void Select(HuffmanTree HT, int end, int *s1, int *s2)
{
    int min1, min2;

    int i = 1; // 遍历数组初始下标为 1

    while (HT[i].parent != 0 && i <= end) // 找到还没构建树的结点1
    {
        i++;
    }
    min1 = HT[i].weight;
    *s1 = i;
    i++;
    while (HT[i].parent != 0 && i <= end) // 找到还没构建树的结点2
    {
        i++;
    }

    if (HT[i].weight < min1) // 对找到的两个结点比较大小，min2为大的，min1为小的
    {
        min2 = min1;
        *s2 = *s1;
        min1 = HT[i].weight;
        *s1 = i;
    }
    else
    {
        min2 = HT[i].weight;
        *s2 = i;
    }

    for (int j = i + 1; j <= end; j++) // 两个结点和后续的所有未构建成树的结点做比较
    {

        if (HT[j].parent != 0) // 如果有父结点，直接跳过，进行下一个
        {
            continue;
        }

        if (HT[j].weight < min1) // 如果比最小的还小，将min2=min1，min1赋值新的结点的下标
        {
            min2 = min1;
            min1 = HT[j].weight;
            *s2 = *s1;
            *s1 = j;
        }

        else if (HT[j].weight >= min1 && HT[j].weight < min2) // 如果介于两者之间，min2赋值为新的结点的位置下标
        {
            min2 = HT[j].weight;
            *s2 = j;
        }
    }
}

/*
   函数名：CreateHuffmanTree
   函数功能：创建哈弗曼树
   函数参数：数组，权重值数组，节点个数
   返回值：无
*/
void CreateHuffmanTree(HuffmanTree *HT, int *w, int n)
{
    if (n <= 1)
        return;                                          // 如果只有一个编码就相当于0
    int m = 2 * n - 1;                                   // 哈夫曼树总节点数，n就是叶子结点
    *HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); // 0号位置不用
    HuffmanTree p = *HT;

    for (int i = 1; i <= n; i++) // 初始化哈夫曼树中的所有结点
    {
        (p + i)->weight = *(w + i - 1);
        (p + i)->parent = 0;
        (p + i)->left = 0;
        (p + i)->right = 0;
    }

    for (int i = n + 1; i <= m; i++) // 从树组的下标 n+1 开始初始化哈夫曼树中除叶子结点外的结点
    {
        (p + i)->weight = 0;
        (p + i)->parent = 0;
        (p + i)->left = 0;
        (p + i)->right = 0;
    }

    for (int i = n + 1; i <= m; i++) // 构建哈夫曼树
    {
        int s1, s2;
        Select(*HT, i - 1, &s1, &s2);
        (*HT)[s1].parent = (*HT)[s2].parent = i;
        (*HT)[i].left = s1;
        (*HT)[i].right = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}

/*
   函数名：HuffmanCoding
   函数功能：进行哈弗曼编码
   函数参数：数组，储存哈弗曼编码的数组，节点个数
   返回值：无
*/
// HT为哈夫曼树，HC为存储结点哈夫曼编码的二维动态数组，n为结点的个数
void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n)
{
    *HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    int m = 2 * n - 1;
    int p = m;
    int cdlen = 0;
    char *cd = (char *)malloc(n * sizeof(char));
    // 将各个结点的权重用于记录访问结点的次数，首先初始化为0
    for (int i = 1; i <= m; i++)
    {
        HT[i].weight = 0;
    }
    // 一开始 p 初始化为 m，也就是从树根开始。一直到p为0
    while (p)
    {
        // 如果当前结点一次没有访问，进入这个if语句
        if (HT[p].weight == 0)
        {
            HT[p].weight = 1; // 重置访问次数为1
            // 如果有左孩子，则访问左孩子，并且存储走过的标记为0
            if (HT[p].left != 0)
            {
                p = HT[p].left;
                cd[cdlen++] = '0';
            }
            // 当前结点没有左孩子，也没有右孩子，说明为叶子结点，直接记录哈夫曼编码
            else if (HT[p].right == 0)
            {
                (*HC)[p] = (char *)malloc((cdlen + 1) * sizeof(char));
                cd[cdlen] = '\0';
                strcpy((*HC)[p], cd);
            }
        }
        // 如果weight为1，说明访问过一次，即是从其左孩子返回的
        else if (HT[p].weight == 1)
        {
            HT[p].weight = 2; // 设置访问次数为2
            // 如果有右孩子，遍历右孩子，记录标记值 1
            if (HT[p].right != 0)
            {
                p = HT[p].right;
                cd[cdlen++] = '1';
            }
        }
        // 如果访问次数为 2，说明左右孩子都遍历完了，返回父结点
        else
        {
            HT[p].weight = 0;
            p = HT[p].parent;
            --cdlen;
        }
    }
}

/*
   函数名：PrintHuffmanCode
   函数功能：打印哈弗曼编码
   函数参数：储存哈弗曼编码的数组，节点个数
   返回值：无
*/
void PrintHuffmanCode(HuffmanCode htable, int *w, int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d %s\n", w[i - 1], htable[i]);
}

int main(void)
{
    int w[5] = {2, 7, 4, 5, 19};
    int n = 5;
    HuffmanTree htree;
    HuffmanCode htable;
    CreateHuffmanTree(&htree, w, n);
    HuffmanCoding(htree, &htable, n);
    PrintHuffmanCode(htable, w, n);
    return 0;
}
