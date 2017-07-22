#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    while((c=getchar()) != EOF)
    {
        int res = (c-'0')%3;
        while((c=getchar()) != '\n')
            res = (res+(c-'0'))%3;
        if(res == 2)
            res = 1;
        printf("%d\n",res);
    }
    return 0;
}
/*
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String [] args) {
       Scanner in = new Scanner(System.in);
        while(in.hasNext())
        {
            BigInteger n = in.nextBigInteger();
            BigInteger t = new BigInteger("3");
            BigInteger s = n.mod(t);
			BigInteger ZERO = BigInteger.ZERO;
			if(s.compareTo(ZERO) == 0)
				System.out.println("0");
			else
				System.out.println("1");
        }
    }
}

*/
