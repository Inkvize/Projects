public class Player extends Person {
	String name;
	
	public Player(String name) {
		super(name);
		this.name = name;
	}

	// Проверка попадания врага по игроку
	public static void checkRandom(int num, Enemy enemy, Player player) {
		// Если попал
		if (player.randNum == num) {
			//Отнимаем 10 жизней
			Person.loseLives(player);
			System.out.printf("Враг попал в вас! У %s осталось %d жизней!\n", player.name, player.lives);
		} else
			System.out.println("Враг не угадал число");
	}
}