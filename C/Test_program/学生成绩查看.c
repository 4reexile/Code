#include  <stdio.h>
#define STU 30
#define COURSE 3

extern void Input(long num[],int score[][COURSE],int n);
void Print(long num[],int score[][COURSE],int n);

int main(void)
{
    int n, score[STU][COURSE];
    long num[STU];
    printf("Please enter the total number of the students(n<=30):");
    scanf("%d", &n);                    //输入参加考试的学生人数
    printf("Enter No. and score as: MT  EN  PH\n");
    Input(num, score, n);                //输入学生成绩
    printf("There are %d students:\n",n);
    Print(num,score,n);                 //输出学生信息
    return 0;
}

/*
   函数名：Print
   函数功能：按格式输出输入的数据
   函数参数：学生编号,学生成绩二维数组,学生数目
   返回值：无
*/
void Print(long num[],int score[][COURSE],int n)
{
    int  i, j;
    printf("%8s\t|%6s%6s%6s\n","  NO    ","MT","EN","PH");
    printf("---------------------------------------------------\n");
    for (i=0; i<n; i++)
    {
        printf("%ld\t|", num[i]);
        for (j=0; j<COURSE; j++)
        {
                printf("%6d", score[i][j]);
        }
        printf("\n");
    }
}
//函数功能：输入某班 n 个学生期末考试三门课程成绩。参考教材p193的例6.7。
// 但要注意，main()函数已经输入获得了n，因此，此处的Input()不需要输入和返回 n。
void Input(long num[], int score[][COURSE], int n)
{
/***********Begin**********/

  int i,j;
    for(i=0;i<n;i++){
            scanf("%ld%d%d%d",&num[i],&score[i][0],&score[i][1],&score[i][2]);
    }   //num数组输入要ld！！
}
