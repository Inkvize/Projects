import java.util.Scanner;

public class Lab5 {
    public static void main(String[] args) {
        // ����� �� 1 �� 20
        final int from = 1;
        final int to = 20;
        // �������� ������ ��� �������
        Scanner scan = new Scanner(System.in);
        // ������� ������ ��� ������
        System.out.printf("������� ��� ������: ");
        Player player = new Player(scan.nextLine());
        // ������� ������ ��� �����
        System.out.printf("������� ��� �����: ");
        Enemy enemy = new Enemy(scan.nextLine());
        // ��������� �������������� ����?
        boolean avtomat = false;
        System.out.printf("��������� �������������� ���� yes/no?: ");
        if (scan.nextLine().equals("yes"))
            avtomat = true;
        int numPlayer = 0, numEnemy = 0;
        // ���� HP ������� ������ � 1 ������
        while (enemy.lives > 0 && player.lives > 0) {
            // ����� �����
            enemy.randNum = from + (int) (Math.random() * to);
            // ����� ������
            player.randNum = from + (int) (Math.random() * to);
            // ���� ����� �� ������ �����
            while (numPlayer != enemy.randNum && numEnemy != player.randNum) {
                // ���� ����������� �� ������ �������������� �����
                System.out.printf("������� ����� �� %d �� %d: ", from, to);
                if (avtomat == false)
                    // ����� ������ � ������
                    numPlayer = scan.nextInt();
                else { // ����� ����� ������ �������������� �����
                       // ������ ��� � ������
                    numPlayer = from + (int) (Math.random() * to);
                    System.out.println("\n" + numPlayer + " ");
                }
                // ���������� � ������ ����� � ��������� ��������� �����
                Enemy.checkRandom(numPlayer, player, enemy);
                // ���� ���������� �����
                numEnemy = from + (int) (Math.random() * to);
                // �������� � ������ ������������ ���������� ������ �����
                Player.checkRandom(numEnemy, enemy, player);
            }
        }
        scan.close();
        System.out.println("���� ��������.");
        if (enemy.lives == 0 && player.lives == 0)
            System.out.println("�������� ������");
        else if (enemy.lives == 0)
            System.out.printf("����� %s �������!", player.name);
        else if (player.lives == 0)
            System.out.printf("����� %s �������!", enemy.name);
    }
}