package Java.Course;
import java.util.Scanner;

// Experi_1_02 
// 编写一个程序来表示长方体的长宽高等数据并有计算体积的函数可供调用

class Rectangle{	// 新的类
	protected double length;  // protected只允许子类和包内访问,public也行吧
    protected double width;
    
    Rectangle(double length, double width){	// 这是构造函数,用this赋值
    	this.length = length;
    	this.width = width;
    }
    public double area() {		// 函数
    	return length * width;					
    }
}

class Cuboid extends Rectangle{  // 新的类继承Rectangle
    private double height;
    
    Cuboid(double length, double width, double height) {  
        super(length, width);	// 当父类也有构造函数的时候,就要用到super,除非你需要添加新的东西
        this.height = height;
    }
    
    public double getVolume(){			//返回数据
    	return length * width * height;
    }
    public double getlength() {return length;}	// 这些是函数
    public double getwidth() {return width;}
    public double getheight() {return height;}
}


public class Cuboid_math {
    public static void main(String[] args) {	// main方法
        Scanner scanner = new Scanner(System.in);  
        System.out.println("Enter the length,width,height");  
        
        double length = scanner.nextDouble();  
        double width = scanner.nextDouble();  
        double height = scanner.nextDouble();  
        Cuboid cuboid = new Cuboid(length, width, height);  
        System.out.println("the length is " + cuboid.getlength() + ",the width is " + cuboid.getwidth() + ",the height is " + cuboid.getheight());  
        System.out.println("the volume is:" + cuboid.getVolume());  
        scanner.close();
    }
}
