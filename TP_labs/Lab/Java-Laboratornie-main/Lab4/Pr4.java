import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Pr4 extends JFrame {
    private JButton button = new JButton("Отобразить");
    private JTextField input1 = new JTextField("", 0);

    public Pr4() {
        super("Диалоговое окно");
        this.setBounds(1000, 400, 300, 150);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container container = this.getContentPane();
        container.setLayout(new GridLayout(3, 2, 2, 2));
        container.add(input1);
        button.addActionListener(new ButtonEventListener());
        container.add(button);

    }

    class ButtonEventListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if (input1.getText().equals("") == false)
                JOptionPane.showMessageDialog(null, input1.getText(), "Информация", JOptionPane.PLAIN_MESSAGE);
        }

    }
}
