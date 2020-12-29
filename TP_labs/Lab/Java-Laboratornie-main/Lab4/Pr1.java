import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Pr1 extends JFrame{
    
    private JButton button = new JButton("Нажмите");
    private JTextField input1 = new JTextField("", 0);
    private JTextField input2 = new JTextField("", 0);

    public Pr1() {
        super("Простая программа");
        this.setBounds(300, 400, 200, 200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container container = this.getContentPane();
        container.setLayout(new GridLayout(3, 2, 2, 2));
        container.add(input1);
        container.add(input2);
        button.addActionListener(new ButtonEventListener());
        container.add(button);
    }

    class ButtonEventListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
                input1.setText("Привет");
                input2.setText("Мир!");
        }
    }
    
}


