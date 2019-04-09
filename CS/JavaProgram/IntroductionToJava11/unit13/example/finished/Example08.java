// SortComparableObjects.java

package unit13.example.out;

import java.math.*;

public class Example08 {
    public static void main(String[] args) {
        String[] cities = {"Beijing", "Jinan", "NewYork", "Tampa"};
        java.util.Arrays.sort(cities);
        for(String city: cities)
            System.out.print(city + " ");
        System.out.println();

        BigInteger[] hugeNumbers = {
            new BigInteger("123124123122354251241234"), 
            new BigInteger("123541283497123947019324701237443089"), 
            new BigInteger("918878612354713"), 
            new BigInteger("512345678912312413141099982409857012")};
        java.util.Arrays.sort(hugeNumbers);
        for(BigInteger number: hugeNumbers)
            System.out.print(number + " ");
        System.out.println();
    }
}

