package Java.Course;

// Experi_2_01 
// 统计学生成绩的程序

// 第二个 通讯录程序 我没写

import java.util.Scanner;

public class Student_score {
    String name = "";
    double grade = 0.0;

    Student_score(String name, double grade) { //构造函数 赋值
        this.grade = grade;
        this.name = name;
    }
}

class Comparation {	
    static double max(Student_score[] students, int num) // 寻找最大值
    {
        double maxGrade = students[0].grade;
        for (int i = 1; i < num; i++) 
        {
            if (students[i].grade > maxGrade) 
            {
                maxGrade = students[i].grade;
            }
        }
        return maxGrade;
    }

    static double min(Student_score[] students, int num) // 寻找最小值
    {
        double minGrade = students[0].grade;
        for (int i = 1; i < num; i++) 
        {
            if (students[i].grade < minGrade) 
            {
                minGrade = students[i].grade;
            }
        }
        return minGrade;
    }

    public static void main(String[] args) //main
    {
        Student_score[] sg = new Student_score[10];	//将这个构造函数作为数组,新建一个数组
        
        Scanner input = new Scanner(System.in);
        System.out.println("请输入学生姓名和成绩");
        int count = 0;
        while (count < 10) 
        {
            System.out.print("姓名：");
            String name = input.nextLine();

            if (name.equals("end")) 
            {
                break;
            }

            System.out.print("分数：");
            double grade = input.nextDouble();
            input.nextLine();

            sg[count] = new Student_score(name, grade);
            count++;
        }

        if (count == 0) 
        {
            System.out.println("没有添加任何学生信息！");
            return;
        }

      
        System.out.print("请输入学生姓名进行查询：");
        String queryName = input.nextLine();
        boolean found = false;
        for (int i = 0; i < count; i++) 
        {
            if (sg[i].name.equals(queryName)) 
            {
                System.out.println("该学生的成绩为：" + sg[i].grade);
                found = true;
            }
        }
    }
}