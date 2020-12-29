package core.blockFour;

import tasks.TaskFour;

import java.util.ArrayList;
import java.util.Scanner;

public class FourBlockMain {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите номер задачи");

        int task = in.nextInt();

        switch (task) {
            case 1: {
                System.out.println("Введите количество слов и размер строки:");
                int n = in.nextInt();
                int k = in.nextInt();
                ArrayList<String> strArr = new ArrayList<String>(n);
                System.out.println("Введите текст:");
                for (int i = 0; i < n; i++)
                {
                    strArr.add(in.next());
                }

                in.close();

                System.out.println(TaskFour.essay(k, strArr));
                break;
            }
            case 2: {
                System.out.println("Введите строку:");
                String str = in.next();

                in.close();

                System.out.println(TaskFour.split(str));
                break;
            }
            case 3: {
                System.out.println("Введите строку:");
                String str = in.next();

                in.close();

                if (str.indexOf('_') != -1)
                {
                    System.out.println(TaskFour.toCamelCase(str));
                }
                else
                {
                    System.out.println(TaskFour.toSnakeCase(str));
                }
                break;
            }
            case 4: {
                System.out.println("Введите 4 значения:");
                double start = in.nextDouble();
                double finish = in.nextDouble();
                double rate = in.nextDouble();
                double mult = in.nextDouble();

                in.close();

                System.out.println(TaskFour.overTime(start, finish, rate, mult));
                break;
            }
            case 5: {
                System.out.println("Введите рост:");
                double h = in.nextDouble();
                System.out.println("Введите вес:");
                double w = in.nextDouble();

                in.close();

                System.out.println(TaskFour.BMI(h, w));
                break;
            }
            case 6: {
                System.out.println("Введите число:");
                int n = in.nextInt();

                in.close();

                System.out.println(TaskFour.bugger(n));
                break;
            }
            case 7: {
                System.out.println("Введите строку:");
                String str = in.next();

                in.close();

                System.out.println(TaskFour.toStarShorthand(str));
                break;
            }
//            case 8: {
//                System.out.println("Введите две строки:");
//                String str1 = in.nextLine();
//                String str2 = in.nextLine();
//
//                in.close();
//
//                System.out.println(TaskFour.doesRhyme(str1, str2));
//            }
//            case 9: {
//                System.out.println("Введите два числа:");
//                int a = in.nextInt();
//                int b = in.nextInt();
//
//                in.close();
//
//                System.out.println(TaskFour.trouble(a, b));
//            }
            case 10: {
                System.out.println("Введите последовательность символов и символ, обозначающий начало/конец книги:");
                String str = in.next();
                String endChar = in.next();

                in.close();

                System.out.println(TaskFour.countUniqueBooks(str, endChar));
            }
            default:
                System.out.println("Неправильный формат ввода");
        }
    }
}
