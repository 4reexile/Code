#include <stdio.h>
#include <stdlib.h>

typedef int AdjType;
#define VMAX 6  // 最大顶点数
#define EMAX 9  // 最大边数
#define MAX 100 // 数组最大范围
#define UN 9999 // 数组初始化这个就是无限了，int塞不下char

typedef struct // 邻接矩阵定义
{
    AdjType Edge[MAX][MAX]; // 边信息
    AdjType Vexs[MAX];      // 点信息
    AdjType Vnum;           // 顶点数
    AdjType Enum;           // 边数
    AdjType Vbegin;         // 要寻找的起点
    AdjType Vend;           // 终点

} GraphMatrix;

typedef struct
{
    AdjType length; // 最短路径长度
    AdjType prevex; // 前驱顶点
} Path;

/*
   函数名：Create_Graph
   函数功能：图邻接矩阵的初始化
   函数参数：指向结构体的指针
   返回值：无
*/
void Create_Graph(GraphMatrix *G)
{
    int i, j;
    // printf("输入顶点数和边数");
    G->Enum = EMAX;
    G->Vnum = VMAX; // 题目已经限制了输入的顶点数
    // G->Vexs={1,2,3,4,5,6};
    for (i = 0; i < G->Vnum; i++) // 不能直接赋值，服了
    {
        G->Vexs[i] = i + 1;
    }

    for (i = 0; i < VMAX; i++) // 遍历初始化图，i指向顶点,j指向边
    {
        for (j = 0; j < EMAX; j++)
        {
            if (i == j) // 自己不会和自己有边，其他都赋值为无限
            {
                G->Edge[i][j] = 0;
            }
            else
            {
                G->Edge[i][j] = UN;
            }
        }
    }
}

/*
   函数名：Out_Graph
   函数功能：输出图邻接矩阵
   函数参数：结构体
   返回值：无
*/
void Out_Graph(GraphMatrix G)
{
    int i, j;

    printf("\n邻接矩阵为:\n");
    printf("      ");

    for (i = 0; i < G.Vnum; i++)
        printf("%5d ", G.Vexs[i]);

    for (i = 0; i < G.Vnum; i++)
    {
        printf("\n%5d ", i + 1);
        for (j = 0; j < G.Vnum; j++)
        {
            if (G.Edge[i][j] == UN)
                printf("%7s ", "∞");
            else
                printf("%5d ", G.Edge[i][j]);
        }
        printf("\n");
    }
}

/*
   函数名：Input_file
   函数功能：从文件中读取信息并且输入
   函数参数：结构体指针
   返回值：无
*/
void Input_info(GraphMatrix *G)
{
    int n, e, vi, vj, w, i, j;
    for (i = 0; i < G->Enum; i++)
    {
        printf("输入边的信息i j w:");
        scanf("%d%d%d", &vi, &vj, &w); // 两个节点信息，一个权值
        G->Edge[vi - 1][vj - 1] = w;   // 矩阵赋值
        // 无向图的话，因为矩阵对称只需要把vi和vj换换就行
    }
    printf("输入起点和终点a b\n");
    scanf("%d %d", &G->Vbegin, &G->Vend);
}

/*
   函数名：Dijkstra
   函数功能：使用Dijkstra算法来寻找最短路径长度
   函数参数：结构体指针
   返回值：无
*/
void Dijkstra(GraphMatrix *G)
{
    int find[VMAX] = {0}; // 初始化find数组，0表示未被添加进新图中
    int distant[VMAX];
    int i, j, k, min, u; // 其中k为起始点到某个点最短路径的中转点

    // 初始化distant数组：
    // 若G中Vbegin结点与Vmax结点之间有边，则相邻点距离为边权；
    // 否则，距离为无限大。
    for (i = 0; i < G->Vnum; i++)
    {
        distant[i] = G->Edge[G->Vbegin - 1][i];
    }
    find[G->Vbegin - 1] = 1; // 把开始节点添加到新图中

    for (i = 0; i < G->Vnum - 1; i++) // 循环Vnum-1次，因为第Vnum次会包含Vend节点，不需要更新了
    {
        min = UN; // min初始化为无限大
        for (j = 0; j < G->Vnum; j++)// 找到最小距离的点
        {
            if (!find[j] && distant[j] < min) // 如果j未被添加且j的距离更小
            {
                min = distant[j];
                u = j;
            }
        }

        find[u] = 1; // 添加结点u到新图中，并标记已添加

        for (k = 0; k < G->Vnum; k++) // 更新distant数组
        {
            if (!find[k] && G->Edge[u][k] != UN && min + G->Edge[u][k] < distant[k]) // 如果k未被添加进新图中，存在边，且当前路径更短
            {
                distant[k] = min + G->Edge[u][k];
            }
        }
    }

    if (distant[G->Vend - 1] == UN) // 如果Vend没有和其他点相连
    {
        printf("从%d到%d没有路径\n", G->Vbegin, G->Vend);
    }
    else
    {
        printf("从%d到%d的最短距离为:%d\n", G->Vbegin, G->Vend, distant[G->Vend - 1]);
    }
}

/*
   函数名：main
   函数功能：主函数
   函数参数：无
   返回值：无
*/
void main()
{
    GraphMatrix G;
    Create_Graph(&G);
    Input_info(&G);
    Out_Graph(G);
    printf("\n");
    Dijkstra(&G);
    return ;
}
