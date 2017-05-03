import java.util.*;
import java.math.*;
public class Main{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int ca = 1;ca <= t;ca++){
            int n = in.nextInt();
            System.out.printf("Case #%d: ",ca);
            System.out.println(BigInteger.valueOf(32).pow(n));
        }
    }
}
