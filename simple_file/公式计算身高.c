#include <stdio.h>

int main()
{

    float faheight,moheight,height; //定义变量:父亲身高,母亲身高,性别,是否锻炼,良好饮食
    char sex,diet,sports;
    scanf ("%f %f %c %c %c",&faheight,&moheight,&sex,&sports,&diet);

    if(sex=='M')                            //判断性别套用公式
        height=(faheight+moheight)*0.54;
    else
        height=(faheight*0.923+moheight)/2;

    if (sports=='Y'&&diet=='Y')              //判断最后两个条件,可能switch更好一点?
        height=height*1.02+height*0.015;

    if (sports=='N'&&diet=='Y')
        height=height*1.015;

    if (sports=='Y'&&diet=='N')
        height=height*1.02;

    if (sports=='N'&&diet=='N')
        height=height;

    printf("%.2f",height);          //输出

    //system("pause");
    return 0;
}
