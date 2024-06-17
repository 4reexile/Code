#include  <stdio.h>  
#define STU 30  
#define COURSE 3  

void Input(long num[],int score[][COURSE],int n);  
void GetSumAver(int score[][COURSE],int n,int sum[],float aver[]);  
void Sort(long num[],int score[][COURSE],int n,int sum[],float aver[]);  
void Print(long num[],int score[][COURSE],int n,int sum[],float aver[]);  
int  Search(long num[], int n, long x);


int main(void)  
{  
    int n, score[STU][COURSE],sum[STU],pos;  
    long num[STU],x;  
    float aver[STU];  
    printf("Please enter the total number of the students(n<=30):");  
    scanf("%d", &n);                    //输入参加考试的学生人数  
    printf("Enter No. and score as: MT  EN  PH\n");  
    Input(num, score, n);                //输入学生成绩
    GetSumAver(score, n, sum, aver);    //计算总分和平均分  
    printf("Before sort:\n");  
    Print(num, score, n, sum, aver);  
    Sort(num, score, n, sum, aver);        //排名次  
    printf("After sort:\n");  
    Print(num, score, n, sum, aver);
    printf("Please enter searching number:\n");  
    scanf("%ld", &x);                    //以长整型格式输入待查找学生的学号  
    pos = Search(num,n,x);            //信息查询  

    if (pos != -1){  
        printf("position:   %8s\t|%6s%6s%6s%7s%8s\n","  NO    ","MT","EN","PH","SUM","AVER");  
        printf("%8d    %ld\t|%6d%6d%6d%7d%8.0f\n",  
                     pos+1,num[pos],    score[pos][0],score[pos][1],  
                     score[pos][2],    sum[pos],aver[pos]);  
    }else{  
        printf("Not found!\n");  
    }

    return 0;  
}  
// 函数功能：输入某班学生期末考试三门课程成绩  
void Input(long num[], int score[][COURSE], int n)  
{  
    /***********Begin************/
    int i,j;
    for(i=0;i<n;i++){
        scanf("%ld%d%d%d",&num[i],&score[i][0],&score[i][1],&score[i][2]);
    }
    /***********End************/ 
}
// 函数功能：计算每个学生的总分和平均分  
void GetSumAver(int score[][COURSE], int n, int sum[], float aver[])  
{  
    /***********Begin************/
    int i,m;
    for(i=0;i<n;i++){
        sum[i]=score[i][0]+score[i][1]+score[i][2];
        aver[i]=sum[i]/3.0;
    }


    /***********End************/ 
}  
// 函数功能：按总分成绩由高到低排出成绩的名次。注意，对应的学号、成绩、总分和平均分都需要保持一致
void Sort(long num[],int score[][COURSE], int n, int sum[], float aver[])  
{  
    /************Begin************/
    int change1,i, j, k, m;
    long change2;
    float change3;

    for(i=0; i<n-1; i++){
        k=i;

        for(j=i+1;j<n;j++){
            if(sum[j] > sum[k])
                k =j;
        }
        if(k!=i){
            change1 = sum[k]; sum[k] = sum[i]; sum[i] = change1;
            change2 = num[k]; num[k] = num[i]; num[i] = change2;
            change3 = aver[k]; aver[k] = aver[i]; aver[i] = change3;
            for(m=0; m<COURSE; m++){
                change1 = score[k][m];
                score[k][m] = score[i][m];
                score[i][m] = change1;
            }
        }
    }


    /***********End************/  
}  
// 函数功能：输出名次表，表格内包括学生编号、各科分数、总分和平均分  
void Print(long num[], int score[][COURSE], int n,  
            int sum[], float aver[])  
{  
    int  i, j;
    printf("%8s\t|%6s%6s%6s%7s%8s\n","  NO    ","MT","EN","PH","SUM","AVER");  
    printf("---------------------------------------------------\n");
    for (i=0; i<n; i++)  
    {  
        printf("%ld\t|", num[i]);  
        for (j=0; j<COURSE; j++)  
        {  
                printf("%6d", score[i][j]);  
        }  
        printf("%7d%8.0f\n", sum[i], aver[i]);  
    }  
}
// 函数功能：在学号数组中顺序查找学生的学号  
//           找到时，返回学生学号在学号数组中的下标位置，否则返回值-1  
/***********Begin************/
int  Search(long num[], int n, long x){
    int i;

    for(i=0;i<n;i++){
        if(num[i]==x)
            return i;
    }
    return -1;
}
/***********End************/
