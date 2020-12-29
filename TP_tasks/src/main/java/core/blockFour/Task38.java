package core.blockFour;

import tasks.TaskFour;

import java.util.Scanner;

public class Task38 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите две строки:");
        String str1 = in.nextLine();
        String str2 = in.nextLine();

        in.close();

        System.out.println(TaskFour.doesRhyme(str1, str2));
    }
}
