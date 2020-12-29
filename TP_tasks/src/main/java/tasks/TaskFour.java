package tasks;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;

public class TaskFour {

    public static String essay(int k, ArrayList<String> strArr)
    {
        String res = "";
        int count = k;
        Iterator<String> it = strArr.iterator();

        String val = it.next();
        res += val + " ";
        count -= val.length();
        while (it.hasNext())
        {
            val = it.next();
            if (count < val.length())
            {
                res += '\n';
                count = k;
            }
            res += val + " ";
            count -= val.length();
        }

        return res;
    }

    public static String split(String str)
    {
        String res = "";
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            res += ch;

            if (ch == '(')
            {
                count++;
            }
            else
            {
                count--;
            }

            if (count == 0)
            {
                res += ' ';
            }
        }

        return res;
    }

    public static String toCamelCase(String str)
    {
        String res = "";
        boolean newWord = false;

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            if (ch == '_')
            {
                newWord = true;
            }
            else if (newWord)
            {
                newWord = false;
                res += (char)(ch-32);
            }
            else
            {
                res += ch;
            }
        }

        return res;
    }

    public static String toSnakeCase(String str)
    {
        String res = "";

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            if (ch >= 'A' && ch <= 'Z')
            {
                res += '_';
                res += (char)(ch+32);
            }
            else
            {
                res += ch;
            }
        }

        return res;
    }

    public static String overTime(double start, double finish, double rate, double mult)
    {
        double reg = 0;
        double over = 0;

        if (start < 9 && finish < 9)
        {
            over = finish - start;
        }
        else if (start < 9 && finish >= 9 && finish <= 17)
        {
            over = 9 - start;
            reg = finish - 9;
        }
        else if (start < 9 && finish > 17)
        {
            over = 9 - start + finish - 9;
            reg = 9 + 17;
        }
        else if (start >= 9 && start <= 17 && finish >= 9 && finish <= 17)
        {
            reg = finish - start;
        }
        else if (start >= 9 && start <= 17 && finish > 17)
        {
            reg = 17 - start;
            over = finish - 17;
        }
        else
        {
            over = finish - start;
        }

        return "$" + String.format("%.2f", reg*rate + over*rate*mult);
    }

    public static String BMI(double w, double h)
    {
        double val = w / (h*h);
        String res = String.format("%.1f", val);
        if (val < 18.5)
        {
            res += " Underweight";
        }
        else if (val >= 18.5 && val < 25)
        {
            res += " Normal weight";
        }
        else
        {
            res += " Overweight";
        }

        return res;
    }

    public static int bugger(int n)
    {
        int count = 0;
        String str = Integer.toString(n);

        while (str.length() > 1)
        {
            count++;

            int val = 1;
            for (int i = 0; i < str.length(); i++)
            {
                val *= Integer.parseInt((str.substring(i, i+1)));
            }

            str = Integer.toString(val);
        }

        return count;
    }

    public static String toStarShorthand(String str)
    {
        String res = "";
        int count = 1;
        char ch = '\0';

        for (int i = 0; i < str.length(); i++)
        {
            char newCh = str.charAt(i);

            if (newCh == ch)
            {
                count++;
            }
            else
            {
                if (count != 1)
                {
                    res += '*';
                    res += Integer.toString(count);
                    count = 1;
                }
                res += newCh;
                ch = newCh;
            }
        }
        if (count != 1)
        {
            res += '*';
            res += Integer.toString(count);
        }

        return res;
    }

    public static boolean doesRhyme(String str1, String str2)
    {
        int index;

        index = str1.lastIndexOf(' ');
        if (index == -1)
        {
            index = 0;
        }
        String word1 = str1.substring(index+1).toUpperCase();

        index = str2.lastIndexOf(' ');
        if (index == -1)
        {
            index = 0;
        }
        String word2 = str2.substring(index+1).toUpperCase();

        String check = "";
        for (int i = 0; i < word1.length(); i++)
        {
            char ch = word1.charAt(i);
            if (ch == 'E' || ch == 'Y' || ch == 'U' || ch == 'O' || ch == 'A' || ch == 'I')
            {
                check += ch;
            }
        }

        int count = 0;
        for (int i = 0; i < word2.length(); i++)
        {
            char ch = word2.charAt(i);
            if (ch == 'E' || ch == 'Y' || ch == 'U' || ch == 'O' || ch == 'A' || ch == 'I')
            {
                if (count >= check.length())
                {
                    return false;
                }
                else if (ch != check.charAt(count))
                {
                    return false;
                }
                count++;
            }
        }

        return true;
    }

    public static boolean trouble(int a, int b)
    {
        String str1 = Integer.toString(a);
        String str2 = Integer.toString(b);
        char number = '\0';
        int count = 0;

        for (int i = 0; i < str1.length(); i++)
        {
            char ch = str1.charAt(i);
            if (ch == number)
            {
                count++;
            }
            else
            {
                number = ch;
                count = 0;
            }
            if (count == 2)
            {
                if (str2.contains(String.copyValueOf(new char[]{number, number})))
                {
                    return true;
                }
                else
                {
                    count = 0;
                }
            }
        }

        return false;
    }

    public static int countUniqueBooks(String str, String endChar)
    {
        int count = 0;
        boolean open = false;
        HashSet<Character> set = new HashSet<Character>();

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            if (!open && ch == endChar.charAt(0))
            {
                open = true;
            }
            else if (open)
            {
                if (ch != endChar.charAt(0))
                {
                    if (!set.contains(ch))
                    {
                        set.add(ch);
                        count++;
                    }
                }
                else
                {
                    open = false;
                    set.clear();
                }
            }
        }

        return count;
    }
}
