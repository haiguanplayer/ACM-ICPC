package myjava;

import java.util.*;
import java.math.*;
public class Main {
	//´òËØÊı±í
	static int N = 1000005;
	static int [] p = new int [N];
	static boolean [] flag = new boolean [N];
	static int cnt = 0;
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		
		
		Prime();
		while(in.hasNext()){
			BigInteger K = in.nextBigInteger();
			int L = in.nextInt();
			if(K.equals(BigInteger.ZERO) && L == 0)
				break;
			int ans = 0;
			boolean sign = false;
			for(int i = 0;p[i] < L;i++){
				if(K.mod(BigInteger.valueOf(p[i])).equals(BigInteger.ZERO) ){
					ans = p[i];
					sign = true;
					break;
				}
			}
			
			if(sign)
				System.out.println("BAD "+ans);
			else
				System.out.println("GOOD");
		}
	}
	
	public static void Prime(){
		for(int i = 2;i < N;i++){
			if(flag[i])
				continue;
			p[cnt++] = i;
			for(int j = 2;i*j < N;j++)
				flag[i*j] = true;
		}
	}
}
