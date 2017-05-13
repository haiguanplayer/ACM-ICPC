import java.util.*;
import java.math.*;
public class Main{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            int n = in.nextInt();
            BigInteger sum = BigInteger.ONE;
            BigInteger p = BigInteger.ONE;
            for(int k = 1;k <= n/2;k++){
                p = p.multiply(BigInteger.valueOf((n - 2 * k + 1) * (n - 2 * k + 2))).divide(BigInteger.valueOf(k * (k + 1)));
                sum = sum.add(p);
            }
            System.out.println(sum.mod(BigInteger.TEN.pow(100)));
        }
    }
}
