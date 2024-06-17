package Java.Test_program;

class Animal {  
    void move() {  
        System.out.println("Animals can move");  
    }  
}  
   
class Dog extends Animal {  
    // 重写父类的move()方法  
    @Override  
    void move() {  
        System.out.println("Dogs can walk and run");  
    }  
}  
   
class Cat extends Animal {  
    // 重写父类的move()方法  
    @Override  
    void move() {  
        System.out.println("Cats can jump and run");  
    }  
}  

public class Override_01 {
    public static void main(String args[]) {  
        Animal a1 = new Dog(); // 向上转型，变量a1可以调用Dog类中新增的方法，但不能调用新增的属性。  
        Animal a2 = new Cat(); // 向上转型，变量a2可以调用Cat类中新增的方法，但不能调用新增的属性。  
        a1.move(); // 执行的是Dog类中的move()方法  
        a2.move(); // 执行的是Cat类中的move()方法  
    } 
}
