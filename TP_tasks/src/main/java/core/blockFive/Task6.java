package core.blockFive;

import java.util.Scanner;

public class Task6 {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);

        System.out.println("Введите номер карты:");
        String str = in.nextLine();

        in.close();

        System.out.println(validateCard(str));
    }

    public static boolean validateCard(String str)
    {
        if (str.length() < 14 || str.length() > 19)
        {
            return false;
        }

        char checksum = str.charAt(str.length()-1);
        str = str.substring(0, str.length()-1);

        str = new StringBuilder(str).reverse().toString();

        String doubleStr = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (i % 2 == 0)
            {
                int val = Integer.parseInt(String.valueOf(str.charAt(i)))*2;
                if (val > 9)
                {
                    val = val/10 + val%10;
                }
                doubleStr += Integer.toString(val);
            }
            else
            {
                doubleStr += str.charAt(i);
            }
        }

        int sum = 0;
        for (int i = 0; i < doubleStr.length(); i++)
        {
            sum += Integer.parseInt(String.valueOf(doubleStr.charAt(i)));
        }

        sum = 10 - sum % 10;
        if (checksum == Integer.toString(sum).charAt(0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
