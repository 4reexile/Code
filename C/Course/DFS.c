#include <stdio.h>
#include <stdlib.h>

#define MAXN 500
typedef struct // 邻接矩阵定义
{
    int Edge[MAXN][MAXN]; // 边信息
    int Visit[MAXN];      // 标记节点是否被访问过
    int Vnum;             // 顶点数
    int Enum;             // 边数

} GraphMatrix;

/*
   函数名：Create_Graph
   函数功能：图邻接矩阵的初始化
   函数参数：指向结构体的指针
   返回值：无
*/
void Create_Graph(GraphMatrix *G)
{
    int i, j;
    scanf("%d %d", &G->Vnum, &G->Enum);
    // G->Vnum=5

    for (i = 0; i < G->Vnum; i++) // 遍历初始化图，i指向顶点,j指向边
    {
        for (j = 0; j < G->Enum; j++)
        {
            G->Edge[i][j] = 0;
        }
    }
}

/*
   函数名：Input_file
   函数功能：输入信息
   函数参数：结构体指针
   返回值：无
*/
void Input_info(GraphMatrix *G)
{
    int i, vi, vj;

    for (i = 0; i < G->Enum; i++)
    {
        scanf("%d %d", &vi, &vj);    // 两个节点信息
        G->Edge[vi - 1][vj - 1] = 1; // 矩阵赋值
        G->Edge[vj - 1][vi - 1] = 1;
        // 无向图的话，因为矩阵对称只需要把vi和vj换换就行
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

    for (i = 0; i < G.Vnum; i++)
    {
        for (j = 0; j < G.Vnum; j++) // 循环输出数组内容
        {
            printf("%d\t", G.Edge[i][j]);
        }
        printf("\n");
    }
}

/*
   函数名：DFS
   函数功能：从u节点开始，寻找与其距离为1的节点对
   函数参数：结构体
   返回值：无
*/
void DFS(GraphMatrix G)
{
    
        
}

void main()
{

    GraphMatrix G;
    Create_Graph(&G);
    Input_info(&G);
    Out_Graph(G);
    DFS(G);

    return;
}
