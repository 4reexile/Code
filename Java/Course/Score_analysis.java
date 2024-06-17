package Java.Course;	// 这个你自己改

// Experi_1_01 
// 接收用户输入一个学生的姓名以及 java 课的成绩，并输出对该学生成绩是否达到 60 分的及格分的判断

import java.util.Scanner;

public class  Score_analysis{
	public static void main(String[] args) {
		int i;
		Scanner input = new Scanner(System.in);
		String[] name = new String[100];
		double[] score = new double[100];
		
		System.out.println("Enter the name and score(end with N)");

		for(i = 0; i < name.length; i++) {
			System.out.println("Enter the name and score of the "+ (i+1) +"th student");
			
			name[i] = input.next();
			if(name[i].equals("N")) {		// 输入N终止程序
				System.out.println("END");	// 新的比较方式.equals
				break;
			}
			
			score[i] = input.nextDouble();	// 假如放在input后面,会导致输入N还要输入数字
	        if (score[i] >= 60) { 			// 判断是否及格
	        	System.out.println(name[i]+"的成绩为及格");
	        }else{
	        	System.out.println(name[i]+"的成绩为不及格");
	        }
		}
		input.close();
	}
	
}
