package Java.Test_program;

public class fu {
    public static void main(String[] args) {
		ChildClass str = new ChildClass();
	} 
}

class ParentClass {  
    public ParentClass() {  
        System.out.println("ParentClass constructor called.");  
    }  
}  
  
class ChildClass extends ParentClass {  
    public ChildClass() {  
        super(); // 调用父类的构造函数  
        System.out.println("ChildClass constructor called.");  
    }  
}
