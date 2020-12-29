package core.blockFive;

import java.util.Scanner;

public class Task10 {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);

        System.out.println("Введите число:");
        int n = in.nextInt();

        in.close();

        System.out.println(hexLattice(n));
    }

    public static String hexLattice(int n)
    {
        int mult = 0;
        int val = 1;
        int lines = -1;
        do
        {
            val += mult;
            mult += 6;
            lines += 2;
        } while (val < n);

        if (val != n)
        {
            return "Invalid";
        }

        int mid = lines/2 + 1;
        String res = "";
        for (int i = 1; i <= lines; i++)
        {
            if (i <= mid)
            {
                mult = i;
            }
            else
            {
                mult = lines - i + 1;
            }

            int start = mid - mult + 1;
            int end = lines*2 - start;
            char ch = 'o';
            for (int j = 1; j < lines*2; j++)
            {
                if (j >= start && j <= end)
                {
                    res += ch;
                    ch = ch == ' ' ? 'o' : ' ';
                }
                else
                {
                    res += ' ';
                }
            }
            res += '\n';
        }

        return res;
    }
}
