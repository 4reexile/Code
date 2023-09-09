#include <stdio.h>
#include <stdlib.h>

//这个代码肯定有点问题但是我肯定懒得改

typedef int AdjType;
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

/*
   函数名：add
   函数功能：计算最大值
   函数参数：指向结构体的指针,文件指针r
   返回值：无
*/

/*
   函数名：Create_Graph
   函数功能：图邻接矩阵的初始化
   函数参数：指向结构体的指针
   返回值：无
*/
void Create_Graph(GraphMatrix *G, FILE *pf)
{
    int i, j;
    // printf("输入顶点数和边数");
    fscanf(pf, "%d %d", &G->Enum, &G->Vnum); // 输入顶点数和边数
    // G->Vexs={1,2,3,4,5,6};
    for (i = 0; i < G->Vnum; i++) // 不能直接赋值，服了
    {
        G->Vexs[i] = i + 1;
    }

    for (i = 0; i < G->Vnum; i++) // 遍历初始化图，i指向顶点,j指向边
    {
        for (j = 0; j < G->Enum; j++)
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
   函数参数：结构体，文件指针w
   返回值：无
*/
void Out_Graph(GraphMatrix G, FILE *pf)
{
    int i, j;
    fprintf(pf, "\n邻接矩阵为:\n");
    fprintf(pf, "\t");

    for (i = 0; i < G.Vnum; i++)
        fprintf(pf, "%d\t", G.Vexs[i]); // 表的第一行1 2 3 4 5 6

    for (i = 0; i < G.Vnum; i++)
    {
        fprintf(pf, "\n%d\t", i + 1); // 表的第一列1 2 3 4 5 6
        for (j = 0; j < G.Vnum; j++)  // 循环输出数组内容
        {
            if (G.Edge[i][j] == UN) // 当值仍为9999输出∞（手写习惯）
                fprintf(pf, "%s\t", "∞");
            else
                fprintf(pf, "%d\t", G.Edge[i][j]);
        }
        fprintf(pf, "\n");
    }
}

/*
   函数名：Input_file
   函数功能：从文件中读取信息并且输入
   函数参数：结构体指针，文件指针r
   返回值：无
*/
void Input_info(GraphMatrix *G, FILE *pf)
{
    int n, e, vi, vj, w, i, j;

    for (i = 0; i < G->Enum; i++)
    {
        for (j = 0; j < G->Enum; j++)
        {
            fscanf(pf, "%d ", &G->Edge[i][j]);
        }
    }
    fscanf(pf, "%d", &G->Vbegin); // 赋值起点和终点
}

/*
   函数名：Dijkstra
   函数功能：使用Dijkstra算法来寻找最短路径长度
   函数参数：结构体指针，文件指针
   返回值：无
*/
void Dijkstra(GraphMatrix *G, FILE *pf)
{
    int i, j, k, min, u;  // 其中k为起始点到某个点最短路径的中转点
    int find[G->Vnum];    // 初始化find数组，判断是否被添加到新图中，0表示未被添加进新图中
    int distant[G->Vnum]; // 记录图中的的点到源点的距离，VMAX节点个数

    // 初始化distant数组：
    // 若G中Vbegin结点与Vmax结点之间有边，则相邻点距离为边权；
    // 否则，距离为无限大。
    for (i = 0; i < G->Vnum; i++)
    {
        distant[i] = G->Edge[G->Vbegin - 1][i];
        find[i] = 0;
    }
    find[G->Vbegin - 1] = 1; // 把开始节点添加到新图中

    for (i = 0; i < G->Vnum - 1; i++) // 循环Vnum-1次，因为第Vnum次会包含Vend节点，不需要更新了
    {
        min = UN;                     // min初始化为无限大
        for (j = 0; j < G->Vnum; j++) // 找到最小距离的点
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
    if (distant[G->Vend - 1] == UN) // 判断Vend是否和其他点相连
    {
        fprintf(pf, "从%d到%d没有路径\n", G->Vbegin, G->Vend);
    }
    else
    {
        fprintf(pf, "从%d到%d的最短距离为:%d\n", G->Vbegin, G->Vend, distant[G->Vend - 1]);
    }
}

/*
   函数名：main
   函数功能：主函数
   调用文件：text.txt,out.txt
*/
void main()
{
    /*
    请创建一个名为text.txt的文本文件，
    最前写入边数和顶点数，格式为“边数 顶点数”
    换行
    写入图，格式为“0 0 0 0 0 0”
    换行
    在文件末尾写入要寻找的最小路径的起点
    仅接受纯数字

    例子:
  9 6
  1 2 1
  1 3 12
  2 3 9
  2 4 3
  4 3 4
  4 5 13
  3 5 5
  4 6 15
  5 6 4
  1 6
    */
  
    // 打开文件
    FILE *pfr = fopen("text1.txt", "r"); // 只读文件
    FILE *pfw = fopen("output.txt", "w");
    if (pfr == NULL && pfw == NULL) // 打不开了，嘲讽一下
    {
        printf("404\n");
        exit(0);
    }
    // 函数调用
    GraphMatrix G;
    Create_Graph(&G, pfr);
    Input_info(&G, pfr);
    Out_Graph(G, pfw);
  
    // 要求输出1到所有路径的最小值，为了方便直接for循环,按照需求决定是否注释
    for (int i = 0; i < G.Vnum; i++)
    {
        G.Vend = i + 1;
        Dijkstra(&G, pfw);
    }
  
    // 释放
    fclose(pfr);
    fclose(pfw);
    pfr = NULL;
    pfw = NULL;
    printf("输出已完成,位于output.txt");
    return;
}
