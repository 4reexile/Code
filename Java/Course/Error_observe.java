package Java.Course;

// Experi_3_01 
// 设计一个程序，在输入数的个数超过数组的实际大小时产生数组下标越界异常

import java.util.Scanner;

public class Error_observe {
    public static void main(String[] args) {  
        Scanner input = new Scanner(System.in);  
        int[] arr = new int[5];  
        System.out.println("input number until the end. Enter '-1'");  
  
        for (int j = 0; j < 100; j++) {  
            try {  
                int num = input.nextInt();  
                if (num == -1) {  
                    break;  
                }  
                arr[j] = num;  
            } catch (Exception e) {  //Exception是最广的错误类型
                System.out.println("Error: input error");  
                input.nextLine(); // clear the invalid input  
            }  
        }  
  
        System.out.println("the number your input is: ");  
        for (int i = 0; i < arr.length && arr[i] != 0; i++) {  
            System.out.println(arr[i]);  
        }  
        input.close();
    }  
}
