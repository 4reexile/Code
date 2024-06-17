package Java.Course;

// Experi_4_01_error
// 这个会出现不同结果重叠的问题, 要成品直接用另一个

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Calculator_gui_test {
    JFrame frame;  
    JLabel label1,label2,label3;  
    JTextField textField1, textField2;  
    JButton button1, button2;  
    String result;  
  
    public static void main(String[] args) {  
    	Calculator_gui_test window = new Calculator_gui_test();           
    }  
    
  
    public Calculator_gui_test() {  
        frame = new JFrame("简易计算器");  
        frame.setBounds(100, 100, 300, 160);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        frame.getContentPane().setLayout(null);  
        
        textField1 = new JTextField();  
        textField1.setBounds(40, 30, 30, 25);  
        frame.getContentPane().add(textField1);
  
        label1 = new JLabel("+");  
        label1.setBounds(90, 30, 80, 25);  		// 设置从容器的 (20,30) 位置开始，宽度为 80，高度为 25,原点在左上角
        frame.getContentPane().add(label1);  	// 添加到容器
        
        textField2 = new JTextField();  
        textField2.setBounds(120, 30, 30, 25);  
        frame.getContentPane().add(textField2);
  
        label2 = new JLabel("=");  
        label2.setBounds(170, 30, 80, 25);  
        frame.getContentPane().add(label2);  
        
        /*
        label3 = new JLabel("result");
        label3.setBounds(200, 30, 80, 25);  
        frame.getContentPane().add(label3);
        */
        
        
        button1 = new JButton("ok");     
        button1.setBounds(40, 70, 70, 25);   
        
        button1.addActionListener(new ButtonClickListener());
        
        frame.getContentPane().add(button1);
        
        
        button2 = new JButton("exit");	// exit事件监听和处理
        button2.addActionListener(new Exit());
        button2.setBounds(190, 70, 70, 25);   
        frame.getContentPane().add(button2);
        
        frame.setVisible(true);  
    }
    
    class Exit implements ActionListener { // exit事件监听和处理
    	public void actionPerformed(ActionEvent e) { 
    		System.exit(0);
    	}
    }
    
    class ButtonClickListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {  
            String num1 = textField1.getText();  
            String num2 = textField2.getText();  
      
            if (!num1.equals("") && !num2.equals("")) {  
                int a = Integer.parseInt(num1);  
                int b = Integer.parseInt(num2);  
                int sum = a + b;  
                result = Integer.toString(sum);  
      
                textField1.setText("");  
                textField2.setText("");  
            } else {  
                JOptionPane.showMessageDialog(null, "请输入运算数");  
            }  
        
            JLabel resultLabel = new JLabel(""+result);  
            resultLabel.setBounds(200, 30, 80, 25);  
            // 在创建新的resultLabel之前，先移除已经存在的resultLabel 但是,上次的结果依然存在这个地方,所以是失败的  
            frame.remove(resultLabel);  
            frame.add(resultLabel);  
            frame.repaint();  
        }  
    }
}
