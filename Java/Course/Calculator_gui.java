package Java.Course;

// Experi_4_01
// 这个是可以直接用的简易计算器成品

import javax.swing.*;  
import java.awt.*;  
import java.awt.event.ActionEvent;  
import java.awt.event.ActionListener;  

public class Calculator_gui {
    private JFrame frame;  
    private JTextField textField1;  
    private JTextField textField2;  
    private JLabel resultLabel;  
    private JButton addButton;  
    private JButton subtractButton;  
    private JButton clearButton;  
  
    public static void main(String[] args) {  
        EventQueue.invokeLater(new Runnable() {  
            public void run() {  
                try {  
                    Calculator_gui window = new Calculator_gui();  
                    window.frame.setVisible(true);  
                } catch (Exception e) {  
                    e.printStackTrace();  
                }  
            }  
        });  
    }  
  
    public Calculator_gui() {  
        initialize();  
    }  
  
    private void initialize() {  
        frame = new JFrame();  
        frame = new JFrame("简易计算器");
        frame.setBounds(100, 100, 300, 300);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        frame.getContentPane().setLayout(null);  
  
        textField1 = new JTextField();  
        textField1.setBounds(10, 10, 120, 25);  
        frame.getContentPane().add(textField1);  
        textField1.setColumns(10);  
  
        textField2 = new JTextField();  
        textField2.setBounds(10, 40, 120, 25);  
        frame.getContentPane().add(textField2);  
        textField2.setColumns(10);  
  
        resultLabel = new JLabel("运算结果");  
        resultLabel.setBounds(10, 70, 80, 25);  
        frame.getContentPane().add(resultLabel);  
  
        addButton = new JButton("相加");  
        addButton.addActionListener(new ActionListener() {  
            public void actionPerformed(ActionEvent arg0) {  
                int num1 = Integer.parseInt(textField1.getText());  
                int num2 = Integer.parseInt(textField2.getText());  
                int sum = num1 + num2;  
                resultLabel.setText("运算结果: " + sum);  
            }  
        });  
        addButton.setBounds(10, 100, 80, 25);  
        frame.getContentPane().add(addButton);  
  
        subtractButton = new JButton("相减");  
        subtractButton.addActionListener(new ActionListener() {  
            public void actionPerformed(ActionEvent arg0) {  
                int num1 = Integer.parseInt(textField1.getText());  
                int num2 = Integer.parseInt(textField2.getText());  
                int difference = num1 - num2;  
                resultLabel.setText("运算结果: " + difference);  
            }  
        });  
        subtractButton.setBounds(10, 130, 80, 25);  
        frame.getContentPane().add(subtractButton);  
  
        clearButton = new JButton("全部清零");  
        clearButton.addActionListener(new ActionListener() {  
            public void actionPerformed(ActionEvent arg0) {  
                textField1.setText("");  
                textField2.setText("");  
                resultLabel.setText("运算结果");  
            }  
        });  
        clearButton.setBounds(10, 160, 80, 25);  
        frame.getContentPane().add(clearButton);  
    }  
}
