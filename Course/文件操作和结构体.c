#include <stdio.h>
#include <stdlib.h>

//不想写使用手册,就看看语法就行了

typedef struct student
{
    int normal;
    int exam;
    float final;
}stu;

//从文件输入数据到结构体组
int readfile(stu *p,FILE *input){
    int i=0;
    if((input=fopen("data.txt","r"))==NULL){
        printf("open or new file error");
        exit(0);    //报错并且返回0
    }

    while(!feof(input)){    //文件数据流入
        fscanf(input,"%d %d",&p[i].normal,&p[i].exam);
        i++;
    }
    return i;
}

void outoffile(stu *p,FILE *output,int i){
    int j;
    if((output=fopen("T_data.txt","w"))==NULL){
        printf("open or new file error");
        exit(0);    //报错并且返回0
    }

    for(j=0;j<i;j++){
        p[j].final=p[j].normal*0.2+p[j].exam*0.8;
        printf("%lf\n",p[j].final);
        fprintf(output,"%.2lf\n",p[j].final);
    }
}


int main(){
    int n,i;
    stu* p;
    FILE *file;

    char path[1024];
    getcwd(path,1024);//得到文件路径位置
    strcat(path,"\\data.taxt");
    strcat(path,"\\T_data.taxt");

    printf("输入学生人数,n=10");
    n=10;
    p=(stu*)malloc(sizeof(stu)*n);//创建动态结构体数组

    i=readfile(p,file); //从文件读取数据

    outoffile(p,file,i);   //将得到的数据进行计算输出  

    free(p);//释放内存

    system("pause");
    return 0;
}


