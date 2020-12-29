public class Person {
    public int randNum;
    public int lives;
    String name;

    // ѕрисвоение имени и количества HP каждому персонажу
    public Person(String name) {
        this.name = name;
        this.lives = 100;
    }

    // ‘ункци€ вызывающ€€ дл€ отн€ти€ жизни персонажа при угадывании числа
    public static void loseLives(Person HP) {
        HP.lives -= 10;
    }
}