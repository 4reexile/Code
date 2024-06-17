#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // 最大顶点

typedef struct ArcNode // 定义边结点
{							
	int adjvex;				 // 邻接点域
	struct ArcNode *nextarc; // 指向下一邻接点的指针域
} ArcNode;

typedef struct VNode// 定义顶点结点
{					   
	char data;		   // 顶点域
	ArcNode *firstarc; // 指向第一条边结点
} VNode, AdjList[MAX];

typedef struct
{
	int Visited[MAX];	// 深度优先算法辅助数组
	AdjList vertices;	// 邻接表头结点数组
	int vnum, anum; // 顶点数，边数
} ALGraph;

void CreateUDC(ALGraph *h)
{
	int i, j, k, l;
	char ch1, ch2;
	ArcNode *p1, *p2;
	printf("请输入顶点数：");
	scanf("%d", &h->vnum);
	printf("请输入边数：");
	scanf("%d", &h->anum);
	for (i = 0; i < h->vnum; i++)
	{
		getchar();
		printf("请输入第%d顶点:", i + 1);
		scanf("%c", &h->vertices[i]);	// 读入顶点信息
		h->vertices[i].firstarc = NULL; // 点的边表头指针设为空
	}
	for (k = 0; k < h->anum; k++)
	{
		getchar();
		printf("建立第%d条边(格式A,B):", k + 1);
		scanf("%c,%c", &ch1, &ch2);
		for (l = 0; l < h->vnum; l++)
		{
			if (ch1 == h->vertices[l].data)
			{
				i = l;
			}
			if (ch2 == h->vertices[l].data)
			{
				j = l;
			}
		}
		p1 = (ArcNode *)malloc(sizeof(ArcNode)); // 生成一个新的边结点*p1
		p1->adjvex = j;							 // 邻接点序号为j
		p1->nextarc = h->vertices[i].firstarc;	 // 将新结点*p1插入顶点vi的边表头部
		h->vertices[i].firstarc = p1;
		p2 = (ArcNode *)malloc(sizeof(ArcNode)); // 生成另一个对称的新的边结点*p2
		p2->adjvex = i;							 // 邻接点序号为i
		p2->nextarc = h->vertices[j].firstarc;	 // 将新结点* p2插入顶点vj的边表头部
		h->vertices[j].firstarc = p2;
	}
}
void ScUDC(ALGraph *h)
{
	int i;
	ArcNode *P;
	printf("\n图的邻接表（无向）:\n");
	for (i = 0; i < h->vnum; i++)
	{
		printf("%C", h->vertices[i].data);
		P = h->vertices[i].firstarc;
		while (P != NULL)
		{
			printf("-->%d", P->adjvex);
			P = P->nextarc;
		}
		printf("\n");
	}
}

int main(){
	ALGraph H;
	CreateUDC(&H);
	ScUDC(&H);
	return 0;
}
