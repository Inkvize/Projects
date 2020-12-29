package core.blockFive;

import java.util.ArrayList;
import java.util.Scanner;

public class Task4 {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);

        System.out.println("Введите последовательность чисел:");
        String[] strArr = in.nextLine().split(" ");

        in.close();

        ArrayList<Integer> mas = new ArrayList<Integer>(strArr.length);
        for (int i = 0; i < strArr.length; i++)
        {
            mas.add(Integer.parseInt(strArr[i]));
        }

        System.out.println(sumDigProd(mas));
    }

    public static int sumDigProd(ArrayList<Integer> mas)
    {
        int sum = 0;

        for (int val : mas)
        {
            sum += val;
        }

        while (sum > 9)
        {
            String sumStr = Integer.toString(sum);
            sum = 1;

            for (int i = 0; i < sumStr.length(); i++)
            {
                sum *= Integer.parseInt(String.valueOf(sumStr.charAt(i)));
            }
        }

        return sum;
    }
}
