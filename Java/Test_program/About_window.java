package Java.Test_program;

import java.awt.Frame;
import javax.swing.JFrame;

public class About_window {
    public static void main(String[] args) {
		Frame frame=new Frame(); //定义一个Frame容器对象frame
		frame.setSize(200,100);
		frame.setVisible(true); //注意Frame对象默认是不可见的，尝试注释掉此句，你会发现看
		 						//不到运行结果的窗口出现。
		
		
		JFrame jframe = new JFrame(); // 定义一个JFrame容器对象jframe
		jframe.setSize(200, 100);
		jframe.setVisible(true);// 注意JFrame对象默认是不可见的，若注释掉此句，你会发现看
								// 不到运行结果的窗口出现。
		jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// JFrame表面上可以关闭，
		// 实际上只是被隐藏为不显示。要真正可以关闭它，如上所示
		}
}
