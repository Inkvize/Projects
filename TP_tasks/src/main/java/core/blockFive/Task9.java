package core.blockFive;

import java.util.Scanner;

public class Task9 {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);

        System.out.println("Введите строку:");
        String str = in.nextLine();

        in.close();

        System.out.println(correctTitle(str));
    }

    public static String correctTitle(String str)
    {
        str = str.toLowerCase();
        String[] words = str.split(" ");
        String res = "";
        for (String word : words)
        {
            String[] subWords = word.split("-");
            String subRes = "";
            for (String subWord : subWords)
            {
                if (!subWord.equals("of") && !subWord.equals("and") && !subWord.equals("the") && !subWord.equals("in"))
                {
                    subRes += (char)(subWord.charAt(0)-32);
                    subRes += subWord.substring(1);
                    subRes += "-";
                }
                else
                {
                    subRes += subWord + "-";
                }
            }
            res += subRes.substring(0, subRes.length()-1);
            res += " ";
        }

        return res;
    }
}
