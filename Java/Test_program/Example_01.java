package Java.Test_program;

/*
设计一个汽车类Vehicle，包含的属性有车轮个数wheels和车重weight。
小汽车类Car是Vehicle类的子类，其中包含的属性有载人数loader。卡车类Truck是Car类的子类，
其中包含属性有载重量payload。每个类都有相关数据的输出方法。
*/

class Vehicle{
	int wheels; // 车轮数
	float weight; // 车重
	
	Vehicle(int wheels,float weight){
		this.wheels=wheels;
		this.weight=weight;
	}
	int getWheels(){
		return wheels;
	}
	float getWeight(){
		return weight;
	}
	void show(){
		System.out.println("车轮："+wheels);
		System.out.println("车重："+weight);
	}
} 

class Car extends Vehicle{
	int loader; // 载人数
	
	Car(int wheels,float weight,int loader){
		super(wheels,weight); // 调用父类的构造函数，对从父类继承而来的成员变量进行初始化
		this.loader=loader;
	}
	void show1(){
		System.out.println("车型：小车");
		super.show(); // 调用父类方法
		System.out.println("载人："+loader+"人");
	}
}

class Truck extends Car{
	float payload;
	
	Truck(int wheels,float weight,int loader,float payload){
		super(wheels,weight,loader); // 调用父类构造方法
		this.payload=payload;
	}
	void show2(){
		System.out.println("车型：卡车");
		super.show(); // 调用父类方法
		System.out.println("载人："+loader+"人");
		System.out.println("载重量："+payload);
	}
}


public class Example_01 {
    public static void main(String args[]){
		System.out.println("输出相关数据");
		Car car=new Car(4,1500,4); // 创建一个Car类对象
		car.show1();
		Truck truck=new Truck(8,7000,3,25000);
		truck.show2();
	}
}
