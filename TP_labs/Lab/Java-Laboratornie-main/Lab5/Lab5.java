import java.util.Scanner;

public class Lab5 {
    public static void main(String[] args) {
        // Число от 1 до 20
        final int from = 1;
        final int to = 20;
        // Источник данных для сканера
        Scanner scan = new Scanner(System.in);
        // Просьба ввести имя игрока
        System.out.printf("Введите имя игрока: ");
        Player player = new Player(scan.nextLine());
        // Просьба ввести имя врага
        System.out.printf("Введите имя врага: ");
        Enemy enemy = new Enemy(scan.nextLine());
        // Настроить автоматическую игру?
        boolean avtomat = false;
        System.out.printf("Настроить автоматическую игру yes/no?: ");
        if (scan.nextLine().equals("yes"))
            avtomat = true;
        int numPlayer = 0, numEnemy = 0;
        // Пока HP имеется хотябы у 1 игрока
        while (enemy.lives > 0 && player.lives > 0) {
            // Число врага
            enemy.randNum = from + (int) (Math.random() * to);
            // Число игрока
            player.randNum = from + (int) (Math.random() * to);
            // Пока никто не угадал число
            while (numPlayer != enemy.randNum && numEnemy != player.randNum) {
                // Если ползователь не выбрал автоматический режим
                System.out.printf("Введите число от %d до %d: ", from, to);
                if (avtomat == false)
                    // Будет ввести в ручную
                    numPlayer = scan.nextInt();
                else { // Иначе игрок выбрал автоматический режим
                       // Рандом ему в помошь
                    numPlayer = from + (int) (Math.random() * to);
                    System.out.println("\n" + numPlayer + " ");
                }
                // Обращаемся к классу врага и проверяем введенное число
                Enemy.checkRandom(numPlayer, player, enemy);
                // Враг загадывает число
                numEnemy = from + (int) (Math.random() * to);
                // Проверям в классе пользователя загаданное врагам число
                Player.checkRandom(numEnemy, enemy, player);
            }
        }
        scan.close();
        System.out.println("Игра окончена.");
        if (enemy.lives == 0 && player.lives == 0)
            System.out.println("Победила дружба");
        else if (enemy.lives == 0)
            System.out.printf("Игрок %s победил»!", player.name);
        else if (player.lives == 0)
            System.out.printf("Игрок %s победил»!", enemy.name);
    }
}