import java.util.*;
import java.math.*;

public class Main{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		long a = n/2,b = n/3,c = n/5,d = n/7;
		long ab = n/6,ac = n/10,ad = n/14,bc = n/15,bd = n/21,cd = n/35;
		long abc = n/30,abd = n/42,acd = n/70,bcd = n/105;
		long abcd = n/210;
		long res = a+b+c+d-(ab+ac+ad+bc+bd+cd)+(abc+abd+acd+bcd)-abcd;
		System.out.println(n-res);
	}
	//static void fun(int n){

	//}
}
