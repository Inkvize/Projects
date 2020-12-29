package core.blockFive;

import java.util.Scanner;
import java.util.Stack;

public class Task7 {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);

        System.out.println("Введите число:");
        int n = in.nextInt();

        in.close();

        System.out.println(numToEng(n));
    }

    public static String numToEng(int n)
    {
        if (n == 0)
        {
            return "zero\nноль";
        }

        Stack<String> stackEn = new Stack<String>();
        Stack<String> stackRu = new Stack<String>();

        if (n % 100 / 10 != 1)
        {
            switch (n % 10)
            {
                case 1:
                    stackEn.push("one");
                    stackRu.push("один");
                    break;
                case 2:
                    stackEn.push("two");
                    stackRu.push("два");
                    break;
                case 3:
                    stackEn.push("three");
                    stackRu.push("три");
                    break;
                case 4:
                    stackEn.push("four");
                    stackRu.push("четыре");
                    break;
                case 5:
                    stackEn.push("five");
                    stackRu.push("пять");
                    break;
                case 6:
                    stackEn.push("six");
                    stackRu.push("шесть");
                    break;
                case 7:
                    stackEn.push("seven");
                    stackRu.push("семь");
                    break;
                case 8:
                    stackEn.push("eight");
                    stackRu.push("восемь");
                    break;
                case 9:
                    stackEn.push("nine");
                    stackRu.push("девять");
                    break;
            }
        }

        if (n > 9)
        {
            switch (n % 100 / 10)
            {
                case 1:
                    switch (n % 10)
                    {
                        case 0:
                            stackEn.push("ten");
                            stackRu.push("десять");
                            break;
                        case 1:
                            stackEn.push("eleven");
                            stackRu.push("одиннадцать");
                            break;
                        case 2:
                            stackEn.push("twelve");
                            stackRu.push("двенадцать");
                            break;
                        case 3:
                            stackEn.push("thirteen");
                            stackRu.push("тринадцать");
                            break;
                        case 4:
                            stackEn.push("fourteen");
                            stackRu.push("четырнадцать");
                            break;
                        case 5:
                            stackEn.push("fifteen");
                            stackRu.push("пятнадцать");
                            break;
                        case 6:
                            stackEn.push("sixteen");
                            stackRu.push("шестнадцать");
                            break;
                        case 7:
                            stackEn.push("seventeen");
                            stackRu.push("семнадцать");
                            break;
                        case 8:
                            stackEn.push("eighteen");
                            stackRu.push("восемнадцать");
                            break;
                        case 9:
                            stackEn.push("nineteen");
                            stackRu.push("девятнадцать");
                            break;
                    }
                    break;
                case 2:
                    stackEn.push("twenty");
                    stackRu.push("двадцать");
                    break;
                case 3:
                    stackEn.push("thirty");
                    stackRu.push("тридцать");
                    break;
                case 4:
                    stackEn.push("forty");
                    stackRu.push("сорок");
                    break;
                case 5:
                    stackEn.push("fifty");
                    stackRu.push("пятьдесят");
                    break;
                case 6:
                    stackEn.push("sixty");
                    stackRu.push("шестьдесят");
                    break;
                case 7:
                    stackEn.push("seventy");
                    stackRu.push("семьдесят");
                    break;
                case 8:
                    stackEn.push("eighty");
                    stackRu.push("восемьдесят");
                    break;
                case 9:
                    stackEn.push("ninety");
                    stackRu.push("девяносто");
                    break;
            }
        }

        if (n > 99)
        {
            switch (n / 100)
            {
                case 1:
                    stackEn.push("one hundred");
                    stackRu.push("сто");
                    break;
                case 2:
                    stackEn.push("two hundred");
                    stackRu.push("двести");
                    break;
                case 3:
                    stackEn.push("three hundred");
                    stackRu.push("триста");
                    break;
                case 4:
                    stackEn.push("four hundred");
                    stackRu.push("четыреста");
                    break;
                case 5:
                    stackEn.push("five hundred");
                    stackRu.push("пятьсот");
                    break;
                case 6:
                    stackEn.push("six hundred");
                    stackRu.push("шестьсот");
                    break;
                case 7:
                    stackEn.push("seven hundred");
                    stackRu.push("семсот");
                    break;
                case 8:
                    stackEn.push("eight hundred");
                    stackRu.push("восемсот ");
                    break;
                case 9:
                    stackEn.push("nine hundred");
                    stackRu.push("девятьсот");
                    break;
            }
        }

        String res = "";
        int end = stackEn.size();
        for (int i = 0; i < end; i++)
        {
            res += stackEn.pop();
            res += ' ';
        }
        res += '\n';

        end = stackRu.size();
        for (int i = 0; i < end; i++)
        {
            res += stackRu.pop();
            res += ' ';
        }

        return res;
    }
}
