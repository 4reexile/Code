package Java.Test_program;

// 接口

interface A1 {
	int aa = 100;
	float ab = 100.00f;
	void pntout(String ss);
}

class B1 implements A1 {
	public void pntout(String ss) {
		System.out.println(ss);
	}
}

public class Interface_01 {
    public static void main(String args[]) {
		B1 abc;
		abc = new B1();
		System.out.println(A1.aa);
		System.out.println(A1.ab);
		abc.pntout("I am a teacher.");
	}

}
