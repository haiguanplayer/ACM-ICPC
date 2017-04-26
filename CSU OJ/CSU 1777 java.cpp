import java.util.*;
import java.math.*;
public class Main {
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		BigDecimal a,b;
		int cnt = 0;
		while(in.hasNext()){
			a = in.nextBigDecimal();
			b = in.nextBigDecimal();
			System.out.printf("Case "+(++cnt)+": ");
			if(a.compareTo(b) > 0)
				System.out.println("Bigger");
			else if(a.compareTo(b) < 0)
				System.out.println("Smaller");
			else
				System.out.println("Same");
		}
	}
}
