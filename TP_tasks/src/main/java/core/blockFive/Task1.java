package core.blockFive;

import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
    Scanner in  = new Scanner(System.in);

		System.out.println("Введите сообщение:");
    String str = in.nextLine();

		in.close();

		if (str.charAt(0) >= '0' && str.charAt(0) <= '9')
    {
        System.out.println(decrypt(str));
    }
		else
    {
        System.out.println(encrypt(str));
    }
}

    public static String encrypt(String str)
    {
        String res = "";
        char oldCh = str.charAt(0);
        res += (int)oldCh;
        res += " ";

        for (int i = 1; i < str.length(); i++)
        {
            char newCh = str.charAt(i);
            res += newCh - oldCh;
            res += " ";
            oldCh = newCh;
        }

        return res;
    }

    public static String decrypt(String str)
    {
        String res = "";
        String[] code = str.split(" ");
        int symbol = Integer.parseInt(code[0]);
        res += (char)symbol;

        for (int i = 1; i < code.length; i++)
        {
            symbol += Integer.parseInt(code[i]);
            res += (char)(symbol);
        }

        return res;
    }
}
