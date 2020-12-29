package core.blockFour;

import tasks.TaskFour;

import java.util.Scanner;

public class Task39 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите два числа:");
        int a = in.nextInt();
        int b = in.nextInt();

        in.close();

        System.out.println(TaskFour.trouble(a, b));
    }
}
