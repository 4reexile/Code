#include <stdio.h>
#include <stdlib.h>
#define COURSE_MAXNUM 5

//我也不确定能不能用


//创建结构体
struct student
{
    long studentID;
    char studentName[20];
    char sex[4];
    struct{
        int year;
        int month;
        int day;
    }birthday;
    float score[COURSE_MAXNUM];
    float total;
    float average;
    int rank;
};
typedef struct student STUDENT;

//声明外部函数，函数在其它源文件中实现
extern void ReadStudInfo(const char *fileName, STUDENT stud[]);
extern void SaveResult(const char *fileName, STUDENT stud[],int n,int m);

//声明本文件中的其它函数
void Input(STUDENT *stud, int n,int m);
void Print(STUDENT *stud, int n,int m);
void TotalAndAverage(STUDENT *stud, int n,int m);
void RankByTotal(STUDENT *stud, int n,int m);
void SaveStudInfo(const char *fileName,STUDENT *stud,int n,int m);
void ReadResult(const char *fileName,STUDENT *stud);


int main()
{
    int n,m;         //n用于存放学生人数，m用于存放课程门数。
    STUDENT *stud;   //指向存放学生信息的存储块的首地址

    //freopen("Input.txt","r",stdin);
    scanf("%d%d",&n,&m); //输入学生总人数
  
    // 动态分配存储
    stud = (STUDENT *)malloc(n*sizeof(STUDENT));
    Input(stud,n,m);//输入学生信息
    //将测试输入信息写入二进制文件
    SaveStudInfo("student.dat",stud,n,m);
    free(stud);
  
    //打开文件student.dat,以二进制文件方式打开用于读
    //从文件中读取学生信息到数组stud中
    stud = (STUDENT *)malloc(n*sizeof(STUDENT));
    ReadStudInfo("student.dat",stud);//在fileBin.c中
  
    // 计算总分
    TotalAndAverage(stud,n,m);
    // 计算排名
    RankByTotal(stud,n,m);
    //Print(stud,n,m);
    //打开文件result.dat,以二进制文件方式打开用于写
    //将计算出了总分和平均分以及名次的学生信息写入文件
    SaveResult("result.dat",stud,n,m);//在fileBin.c中
    free(stud);

    //打开文件result.dat,以二进制文件方式打开用于读
    //从文件中读取学生信息到数组stud中,用于测试是否与预期输出一致
    stud = (STUDENT *)malloc(n*sizeof(STUDENT));
    ReadResult("result.dat",stud);
    //输出学生信息
    Print(stud,n,m);
    free(stud);
    return 0;
}
void Input(STUDENT *stud, int n,int m)
{
    int i;
    //freopen("Input.txt","r",stdin);
    //scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&stud[i].studentID);
        scanf("%s",stud[i].studentName);
        scanf("%s",stud[i].sex);
        scanf("%d-%d-%d",&stud[i].birthday.year,&stud[i].birthday.month,&stud[i].birthday.day);
        for(int j=0;j<m;j++)
            scanf("%f",&stud[i].score[j]);
        stud[i].total = 0;
        stud[i].average = 0;
        stud[i].rank = 0;
    }
}
void Print(STUDENT *stud, int n,int m)
{
    printf("%8s%12s%4s%12s%10s%10s%10s%10s%10s%10s%5s\n",
           "  NO.  ","Name","Sex"," Birthday ","Computer","English","Math","Music","Total","Average","Rank");
    for(int i=0;i<n;i++)
    {
        printf("%8ld",stud[i].studentID);
        printf("%15s",stud[i].studentName);
        printf("%5s",stud[i].sex);
        printf("%6d-%02d-%02d",stud[i].birthday.year,stud[i].birthday.month,stud[i].birthday.day);
        for(int j=0;j<m;j++)
        {
            printf("%10.0f",stud[i].score[j]);
        }
        printf("%10.0f",stud[i].total);
        printf("%10.0f",stud[i].average);
        printf("%5d\n",stud[i].rank);
    }
}

void TotalAndAverage(STUDENT *stud, int n,int m)
{
    for(int i=0;i<n;i++)
    {
        stud[i].total = 0;
        for(int j=0;j<m;j++)
            stud[i].total += stud[i].score[j];

        stud[i].average = stud[i].total/4;
    }
}

void RankByTotal(STUDENT *stud, int n,int m)
{

    for(int i=0;i<n-1; i++)
    {
        int k = i;
        for(int j=i+1;j<n;j++)
        {
            if(stud[j].total>stud[k].total)
            {
                k = j;
            }
        }
        if(k != i)
        {
            STUDENT temp = stud[i];
            stud[i] = stud[k];
            stud[k] = temp;
        }
        stud[i].rank = i+1;
        if(i>0 && stud[i].total == stud[i-1].total)
            stud[i].rank = stud[i-1].rank;
    }
    stud[n-1].rank = n;
    if(n-1>0 && stud[n-1].total == stud[n-2].total)
        stud[n-1].rank = stud[n-2].rank;
}

void SaveStudInfo(const char *fileName,STUDENT *stud,int n,int m)
{
    FILE *fp = fopen(fileName,"w");  //打开二进制文件student.dat用于写
    if(fp == NULL)
    {
        printf("Failure to open %s!\n",fileName);
        exit(0);
    }
    fwrite(&n,sizeof(n),1,fp);//将n写入文件
    fwrite(&m,sizeof(m),1,fp);//将m写入文件

    fwrite(stud,sizeof(STUDENT),n,fp);
    fclose(fp); //关闭文件
}

void ReadResult(const char *fileName,STUDENT *stud)
{
    FILE *fp = fopen(fileName,"r");  //打开二进制文件result.dat用于读
    if(fp == NULL)
    {
        printf("Failure to open %s!\n",fileName);
        exit(0);
    }
    int n,m;
    // 读一个整数（学生人数）
    fread(&n,sizeof(n),1,fp);
    // 课程数量
    fread(&m,sizeof(m),1,fp);

    fread(stud,sizeof(STUDENT),n,fp);

    fclose(fp);//关闭文件
}
//从文件fileName表示的二进制文件中读取学生基本信息，
//包括学号、姓名、性别、出生日期，若干门课程的成绩
//文件的第一行存储的信息包含了n和m，即学生的人数和课程门数
void ReadStudInfo(const char *fileName, STUDENT stud[])
{
/*************Begin***************/
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        printf("Failure to open %s!\n",fileName);
        exit(0);
    }
    int n,m;
    fread(&n,sizeof(n),1,fp);
    fread(&m,sizeof(m),1,fp);
    fread(stud,sizeof(STUDENT),n,fp);
    fclose(fp);
/*************End*****************/
}
//向文件fileName表示的二进制文件中写入学生基本信息，
//包括学号、姓名、性别、出生日期，若干门课程的成绩、总分、平均分、名次
//文件的第一行存储的信息应该包括n和m，即学生的人数和课程门数
void SaveResult(const char *fileName, STUDENT stud[],int n,int m)
{
    FILE *fp = fopen(fileName,"w");
    if(fp == NULL)
    {
        printf("Failure to open %s!\n",fileName);
        exit(0);
    }
    fwrite(&n,sizeof(n),1,fp);
    fwrite(&m,sizeof(m),1,fp);
    fwrite(stud,sizeof(STUDENT),n,fp);
    fclose(fp);
}
