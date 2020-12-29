package core.blockFive;

import java.util.HashSet;
import java.util.Scanner;

public class Task5 {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);

        System.out.println("Введите последовательность слов:");
        String str = in.nextLine();

        in.close();

        System.out.println(sameVowelGroup(str));
    }

    public static String sameVowelGroup(String str)
    {
        String[] strArr = str.split(" ");

        HashSet<Character> pattern = new HashSet<Character>();
        for (int i = 0; i < strArr[0].length(); i++)
        {
            char ch = strArr[0].charAt(i);
            if (ch == 'e' || ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'a')
            {
                if (!pattern.contains(ch))
                {
                    pattern.add(ch);
                }
            }
        }

        String res = strArr[0];
        for (int i = 1; i < strArr.length; i++)
        {
            for (int j = 0; j < strArr[i].length(); j++)
            {
                char ch = strArr[i].charAt(j);
                if (!pattern.contains(ch) &&
                        (ch == 'e' || ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'a'))
                {
                    break;
                }

                if (j == strArr[i].length()-1)
                {
                    res += ' ';
                    res += strArr[i];
                }
            }
        }

        return res;
    }
}
