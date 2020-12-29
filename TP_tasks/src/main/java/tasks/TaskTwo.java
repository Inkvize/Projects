package tasks;

import java.util.ArrayList;
import java.util.ListIterator;

public class TaskTwo {

    public static String repeat(String text, int k) {
        StringBuilder result = new StringBuilder();
        for(int i = 0; i <text.length();i++) {
            for (int j = 1; j <= k; j++) {
                result.append(text.charAt(i));
            }
        }
        return result.toString();
    }

    public static Integer differenceMaxMin(int[] mas) {
        int max = mas[0];
        int min = mas[0];
        for (int i = 0; i < mas.length; i++) {
            if(max < mas[i]) max = mas[i];
            if(min > mas[i]) min = mas[i];
        }
        return max - min;
    }

    public static Boolean isAvgWhole(int[] mas) {
        boolean result = false;
        int sum = 0;
        for (int i : mas) {
            sum += i;
        };
        if(sum%mas.length == 0) result = true;
        return result;
    }

    public static ArrayList<Integer> cumulativeSum (int[] mas)
    {
        int sum = 0;
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        for (int ma : mas) {
            sum += ma;
            arrayList.add(sum);
        }
        return arrayList;
    }

    public static int getDecimalPlaces(String str)
    {
        if (str.contains("."))
        {
            return str.length() - 1 - str.indexOf('.');
        }
        else
        {
            return 0;
        }
    }

    public static int fibonacci(int n)
    {
        switch (n)
        {
            case 1:
                return 1;
            case 2:
                return 2;
            default:
                int a = 1;
                int b = 2;
                int res;
                for (int i = 3; i < n; i++)
                {
                    res = a + b;
                    a = b;
                    b = res;
                }
                return a + b;
        }
    }

    public static boolean isValid(String str)
    {
        if (str.length() != 5)
        {
            return false;
        }

        for (int i = 0; i < 5; i++)
        {
            if (str.codePointAt(i) < '0' || str.codePointAt(i) > '9')
            {
                return false;
            }
        }

        return true;
    }

    public static boolean isStrangePair(String str1, String str2)
    {
        if (str1.charAt(0) == str2.charAt(str2.length()-1) && str1.charAt(str1.length()-1) == str2.charAt(0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static boolean isSuffix(String word, String str)
    {
        str = str.substring(1);
        if (word.endsWith(str))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static boolean isPrefix(String word, String str)
    {
        str = str.substring(0, str.length()-1);
        if (word.startsWith(str))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static int boxSeq(int n)
    {
        if (n % 2 == 0)
        {
            return n;
        }
        else
        {
            return n+2;
        }
    }
}

