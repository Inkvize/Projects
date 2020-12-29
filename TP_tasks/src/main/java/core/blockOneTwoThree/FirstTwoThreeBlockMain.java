package core.blockOneTwoThree;

import tasks.TaskOne;
import tasks.TaskThree;
import tasks.TaskTwo;

public class FirstTwoThreeBlockMain {

    public static void main(String[] args) {
        System.out.println("1.1: " + TaskOne.remainder(3,4));
        System.out.println("1.2: " + TaskOne.triArea(7,4));
        System.out.println("1.3: " + TaskOne.animals(2,3,5));
        System.out.println("1.4: " + TaskOne.profitableGamble(0.2, 50, 9));
        System.out.println("1.5: " + TaskOne.operation(2,8,4));
        System.out.println("1.6: " + TaskOne.itoa('['));
        System.out.println("1.7: " + TaskOne.addUpTo(9));
        System.out.println("1.8: " + TaskOne.nextEdge(9,2));
        int[] nums = {3,4,5};
        System.out.println("1.9: " + TaskOne.sumOfCubes(nums));
        System.out.println("1.10: " + TaskOne.abcmath(42,5,10));
        System.out.println("1.10: " + TaskOne.abcmath(5,2,1));
        System.out.println("1.10: " + TaskOne.abcmath(1,2,3));
        System.out.println("2.1: " + TaskTwo.repeat("mice",5));
        int[] mas = {10, 4, 1, 4, -10, -50, 32, 21};
        System.out.println("2.2: " + TaskTwo.differenceMaxMin(mas));
        int[] mas1 = {1,5,6};
        System.out.println("2.3: " + TaskTwo.isAvgWhole(mas1));
        int[] mas2 = {1,2,3,5};
        System.out.println("2.4: " + TaskTwo.cumulativeSum(mas2));
        System.out.println("2.5: " + TaskTwo.getDecimalPlaces("43.20"));
        System.out.println("2.6: " + TaskTwo.fibonacci(7));
        System.out.println("2.7: " + TaskTwo.isValid("59001"));
        System.out.println("2.8: " + TaskTwo.isStrangePair("sparkling", "groups"));
        System.out.println("2.9(prefix): " + TaskTwo.isPrefix("automation", "auto"));
        System.out.println("2.9(suffix): " + TaskTwo.isSuffix("arochofobia", "fobia"));
        System.out.println("2.10: " + TaskTwo.boxSeq(1));
        System.out.println("3.1: " + TaskThree.solutions(1,0,-1));
        System.out.println("3.2: " + TaskThree.findZip("all zip files are zipped"));
        System.out.println("3.3: " + TaskThree.checkPerfect(28));
        System.out.println("3.4: " + TaskThree.flipEndChars("Cat, dog, and mouse."));
        System.out.println("3.5: " + TaskThree.isValidHexCode("#eaecee"));
        int[] same1 = {2};
        int[] same2 = {3,3,3,3,3,};
        System.out.println("3.6: " + TaskThree.same(same1, same2));
        System.out.println("3.7: " + TaskThree.isKaprekar(297));
        System.out.println("3.8: " + TaskThree.longestZero("01100001011000"));
        System.out.println("3.9: " + TaskThree.nextPrime(24));
        System.out.println("3.10: " + TaskThree.rightTriangle(145,105,100));
    }
}
