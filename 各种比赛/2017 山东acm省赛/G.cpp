#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

ll pow(int t,int m)
{
    ll ans = 1;
    for(int i = 0;i < m;i++)
        ans = ans*t*1ll%MOD;
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    ll sum = 0;
    for(int i = 1;i <= n;i++)
    {
        sum = (sum+pow(i,m))%MOD;
    }
    printf("%lld\n",sum);
    return 0;
}



import java.util.*;
import java.math.*;
public class Main{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext())
        {
            BigInteger n = in.nextBigInteger();
            BigInteger t = new BigInteger("3");
            BigInteger s = n.mod(t);
            if(s.compareTo(BigInteger.ZERO) == 0)

        }
    }
}
