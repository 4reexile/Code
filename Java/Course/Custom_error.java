package Java.Course;

// Experi_3_02
// 自定义异常

import java.util.Scanner;

//定义自定义异常类 NumberOutRange继承自Exception
class NumberOutRange extends Exception {
    public NumberOutRange(String msg) {
        super(msg);
    }  
} 

//readANumber函数将抛出NumberOutRange异常。try-catch语句捕获并处理这个异常。
public class Custom_error {
    //定义 readANumber 函数并声明 NumberOutRange 异常  
	public static int readANumber() throws NumberOutRange {  //throws-可能有超出异常
        Scanner scanner = new Scanner(System.in);  
        System.out.println("enter a number between 0 and 100: ");  
        int number = scanner.nextInt();  
        
        if (number < 0 || number > 100) {
            throw new NumberOutRange("The number entered is not within the range of 0-100");  
        }  
        return number;  
    }  
	
	public static void main(String[] args) {  
        try {  
            int number = readANumber();  //调用
            System.out.println("the number your entered: " + number);  
        } catch (NumberOutRange e) {  
            System.out.println("error: " + e.getMessage());  
        }  
    }  
}
