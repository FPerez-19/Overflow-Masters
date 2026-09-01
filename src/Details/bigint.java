import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger numeroGigante = new BigInteger("123456789012345678901234567890");
        BigInteger cinco = BigInteger.valueOf(5);
        BigInteger diez = BigInteger.TEN; 
        BigInteger suma = numeroGigante.add(diez);
        BigInteger multiplicacion = cinco.multiply(diez);
        BigInteger potencia = cinco.pow(100);
        int resultadoComparacion = numeroGigante.compareTo(diez);
        BigInteger a = scanner.nextBigInteger();
        
        scanner.close();
    }
}