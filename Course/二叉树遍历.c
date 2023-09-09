#include <stdio.h>
#include <string.h>
#include <malloc.h>


typedef char DataType;

// 二叉树结点定义
typedef struct node
{
    DataType data; // 存放结点数据
    struct node *lchild, *rchild;
} *ptree, BiTree; // 二叉树

/*// 函数可直接使用，功能：输出结点数据
void print(DataType d)
{
    cout << d << " ";
}
*/

ptree Create_Bitree() // 创建二叉树(根节点)
{
    ptree p = (ptree)malloc(sizeof(BiTree));
    p->lchild = p->rchild = NULL;
    return p;
}

/*
函数名：createBiTree
函数功能：创建二叉树，要求输入二叉树的先根序序列(具体输入方式请看左侧说明)，并创建对应二叉树，并返回二叉树的根结点指针
参数：头结点
返回值：无
*/
void createBiTree(ptree *T) // 初始化二叉树 
{
    char ch;
    ch = getchar();
    if (ch == '#')
        *T = NULL;
    else
    {
        (*T) = (ptree)malloc(sizeof(BiTree));
        (*T)->data = ch;
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));
    }
}

/*
函数名：preOrder
函数功能：先根遍历二叉树
参数：二叉树根结点指针
返回值：无
*/
void preOrder(ptree T) // 递归先序遍历
{
    if (T)
    {
        printf("%c ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

/*
函数名： inOrder
函数功能：中根遍历二叉树
参数：二叉树根结点指针
返回值：无
*/
void inOrder(ptree T) // 中序递归
{

    if (T)
    {
        inOrder(T->lchild);
        printf("%c ", T->data);
        inOrder(T->rchild);
    }
}

/*
函数名：postOrder
函数功能：后根遍历二叉树
参数：二叉树根结点指针
返回值：无
*/
void postOrder(ptree T) // 后序递归遍历
{
    if (T)
    {
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c ", T->data);
    }
}

/*
函数名：nodeCount
函数功能：输出所构造的二叉树的叶子个数
参数：二叉树根结点指针
返回值：叶子个数
*/
int nodeCount(ptree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        if ((nodeCount(T->lchild) == NULL) && (nodeCount(T->rchild) == NULL))
        {
            return 1;
        }
        else
        {
            return nodeCount(T->lchild) + nodeCount(T->rchild);
        }
    }
}

/*
函数名：nodeCount
函数功能：交换左右二叉树
参数：二叉树根结点指针
返回值：无
*/
void Exchange(ptree T)
{
    if (T->lchild == NULL && T->rchild == NULL);
    else // 三种情况，1.都不为空，2.左为空，3.右为空；
    {
        // 交换左右子树；
        ptree *p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
    }

    // 如果交换后的这个结点左子树不为空，则继续向下寻找可以交换的结点；
    if (T->lchild)
        Exchange(T->lchild);
    if (T->rchild)
        Exchange(T->rchild);
}

int main(void)
{
    ptree T;
    T = Create_Bitree(); // 调用创建二叉树功能，得到二叉树的根结点指针
    createBiTree(&T);
    //Exchange(T);    //将左右子树互换
    
    printf("先根遍历顺序");
    preOrder(T); // //调用先根遍历二叉树，按先根遍历顺序输出二叉树结点功能
    printf("\n");
    
    printf("中根遍历顺序");
    postOrder(T); // 调用中根遍历二叉树，按中根遍历顺序输出二叉树结点功能
    printf("\n");
  
    printf("后根遍历顺序");
    inOrder(T); // 调用后根遍历二叉树，按后根遍历顺序输出二叉树结点功能
    printf("\n");
  
    //printf("\n%d", nodeCount(T));   //调用计算叶子数个数的函数,不需要注释即可
    printf("\n");
    
    // AB#DG###CE##FH###
    return 0;
}
