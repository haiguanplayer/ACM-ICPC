import java.util.*;
import java.math.*;

public class Main{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		int x,n = in.nextInt();
		int cnt0 = 0,cnt5 = 0;
		for(int i = 1;i <= n;i++){
			x = in.nextInt();
			if(x == 0)
				cnt0++;
			else
				cnt5++;
		}
		if(cnt0 == 0)
			System.out.println(-1);
		else{
			if(cnt5 < 9)
				System.out.println(0);
			else{
				for(int i = 1;i <= 9*(cnt5/9);i++)
					System.out.print(5);
				for(int i = 1;i <= cnt0;i++)
					System.out.print(0);

			}
		}
		System.out.println();
	}
	//static void fun(int n){

	//}
}
