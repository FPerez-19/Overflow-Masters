/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: java.math
 * Description: Arbitrary-precision integers, for when the answer does not fit
 * in a long long. Reference of the operations you actually need in contest.
 * Status: untested
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger big = new BigInteger("123456789012345678901234567890");
        BigInteger five = BigInteger.valueOf(5);
        BigInteger ten = BigInteger.TEN;
        BigInteger sum = big.add(ten);
        BigInteger prod = five.multiply(ten);
        BigInteger pow = five.pow(100);
        int cmp = big.compareTo(ten);          // -1, 0 or 1
        BigInteger a = scanner.nextBigInteger();

        scanner.close();
    }
}
