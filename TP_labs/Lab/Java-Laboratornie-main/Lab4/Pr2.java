  
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Pr2 extends JFrame {
    private JButton button = new JButton("Все готово");
    private JLabel label = new JLabel("Введите имя:");
    private JTextField input1 = new JTextField("", 0);
    private JCheckBox check = new JCheckBox("Согласны?", false);

    public Pr2() {
        super("Приложение с выбором");
        this.setBounds(500, 400, 300, 150);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container container = this.getContentPane();
        container.setLayout(new GridLayout(3, 2, 2, 2));
        container.add(label);
        container.add(input1);
        button.addActionListener(new ButtonEventListener());
        container.add(button);
        container.add(check);
    }

    class ButtonEventListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if (check.isSelected() == true && input1.getText().equals("") == false)

                JOptionPane.showMessageDialog(null, input1.getText() + " - Согласен\", \"Информация",
                        JOptionPane.PLAIN_MESSAGE);
            else if (input1.getText().equals("") == false)
                JOptionPane.showMessageDialog(null, input1.getText() + " - не согласен!", "Информация",
                        JOptionPane.PLAIN_MESSAGE);
        }

    }
}
