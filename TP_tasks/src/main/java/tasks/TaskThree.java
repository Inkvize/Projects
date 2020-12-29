package tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class TaskThree {

    public static int solutions(int a, int b, int c)
    {
        double d = b*b - 4*a*c;
        if (d < 0)
        {
            return 0;
        }
        else if (d == 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    public static int findZip(String str)
    {
        return str.indexOf("zip", str.indexOf("zip")+3);
    }

    public static boolean checkPerfect(int num)
    {
        int sum = 1;
        int n = (int)Math.ceil(Math.sqrt(num));

        for (int i = 2; i < n; i++)
        {
            if (num % i == 0)
            {
                n = num / i;
                sum += i;
                sum += n;

                if (sum > num)
                {
                    return false;
                }
            }
        }

        if (sum != num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    public static String flipEndChars(String str)
    {
        if (str.length() < 2)
        {
            return "Несовместимо";
        }

        char cBegin = str.charAt(0);
        char cEnd = str.charAt(str.length()-1);
        if (cBegin == cEnd)
        {
            return "Два-это пара";
        }

        return cEnd + str.substring(1, str.length()-1) + cBegin;
    }

    public static boolean isValidHexCode(String str)
    {
        if (str.length() != 7 || str.charAt(0) != '#')
        {
            return false;
        }

        for (int i = 1; i < str.length(); i++)
        {
            char ch = str.charAt(i);

            if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'F') && (ch < 'a' || ch > 'f'))
            {
                return false;
            }
        }

        return true;
    }

    public static boolean same(int[] mas1, int[] mas2) {
        return sameHelper(mas1) == sameHelper(mas2);
    }

    private static int sameHelper(int[] mas){
        int k = 0;
        HashSet<Integer> hashSet = new HashSet<Integer>();
        for (int ma : mas) {
            if (!hashSet.contains(ma)) k++;
            hashSet.add(ma);
        }
        return k;
    }

    public static boolean isKaprekar(int number) {
        String str = String.valueOf(number * number);
        String left;
        String right;

        if(str.length() == 1)
        {
            right = str;
            left = "0";
        }
        else
        {
            left = str.substring(0, str.length() / 2);
            right = str.substring(str.length() / 2, str.length());
        }

        int letftToNumber = Integer.parseInt(left);
        int rightToNumber = Integer.parseInt(right);

        return (letftToNumber + rightToNumber) == number;
    }

    public static String longestZero(String str) {
        int maxZero = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str.charAt(i) == '0')
            {
                int countOfZero = 1;
                while((i + 1) < str.length() && str.charAt(i + 1) == '0' )
                {
                    countOfZero++;
                    i++;
                }
                if(countOfZero > maxZero)
                    maxZero = countOfZero;
            }
        }

        String result = "";
        for(int i = 0; i < maxZero; i++) {
            result += "0";
        }
        return result;
    }

    public static int nextPrime(int num) {
        if(num < 2)
            num = 2;

        while(true) {
            boolean bool = false;
            for(int i = 2; i < num; i++) {
                if(num % i == 0)
                {
                    bool = true;
                    break;
                }
            }
            if(!bool)
                return num;
            else
                num++;
        }
    }

    public static boolean rightTriangle(int a, int b, int c) {
        int[] array = {a, b ,c};
        Arrays.sort(array);
        return Math.pow(array[0], 2) + Math.pow(array[1], 2) == Math.pow(array[2], 2);
    }
}
