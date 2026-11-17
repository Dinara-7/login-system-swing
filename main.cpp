import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LoginSystem extends JFrame implements ActionListener {

    private JLabel userLabel, passLabel;
    private JTextField userField;
    private JPasswordField passField;
    private JButton loginButton, resetButton;

    private static final String CORRECT_USERNAME = "WAINAINA";
    private static final String CORRECT_PASSWORD = "password123";

    public LoginSystem() {
        UIManager.put("OptionPane.messageFont", new Font("Arial", Font.BOLD, 12));
        UIManager.put("OptionPane.buttonFont", new Font("Arial", Font.BOLD, 12));

        setTitle("Login System");
        setSize(400, 300);
        setLayout(null);                       
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        Font boldFont = new Font("Arial", Font.BOLD, 12);

        userLabel = new JLabel("User Name");
        userLabel.setFont(boldFont);
        userLabel.setBounds(50, 50, 100, 25);

        passLabel = new JLabel("Password");
        passLabel.setFont(boldFont);
        passLabel.setBounds(50, 100, 100, 25);

        userField = new JTextField();
        userField.setBounds(150, 50, 150, 28);

        passField = new JPasswordField();
        passField.setBounds(150, 100, 150, 28);

        loginButton = new JButton("Login");
        loginButton.setBackground(Color.GREEN);
        loginButton.setFont(boldFont);
        loginButton.setBounds(50, 150, 100, 28);

        resetButton = new JButton("Reset");
        resetButton.setBackground(Color.CYAN);
        resetButton.setFont(boldFont);
        resetButton.setBounds(200, 150, 100, 28);

        add(userLabel);
        add(userField);
        add(passLabel);
        add(passField);
        add(loginButton);
        add(resetButton);

        loginButton.addActionListener(this);
        resetButton.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == loginButton) {
            String username = userField.getText().trim();
            String password = new String(passField.getPassword());

            if (username.equals(CORRECT_USERNAME) && password.equals(CORRECT_PASSWORD)) {
                JOptionPane.showMessageDialog(this, "Login Successful");
            } else {
                JOptionPane.showMessageDialog(this, "Incorrect username or password");
            }
        } else if (e.getSource() == resetButton) {
            userField.setText("");
            passField.setText("");
            userField.requestFocus();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new LoginSystem().setVisible(true));
    }
}
