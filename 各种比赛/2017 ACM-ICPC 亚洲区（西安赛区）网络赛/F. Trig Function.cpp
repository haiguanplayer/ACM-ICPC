#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

ll pow_mod(ll a,ll b,ll mod)
{
    ll ans = 1;
    a %= mod;
    while(b)
    {
        if(b&1)
            ans = ans * a % mod;
        b >>= 1;
        a = a*a%mod;
    }
    return ans;
}
int main()
{
    ll p = 998244353,n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        if(m > n)
            printf("0\n");
        else if((n&1) ^ (m&1))//奇偶性不同
            printf("0\n");
        else
        {
            if(m == 0)
                printf("998244352\n");
            else
            {
                ll ans = n;
                for(int i = n-m+2;i <= n+m-2;i+=2)
                    ans = ans*i%MOD;
                ll k = 1;
                for(int i = 1;i <= m;i++)
                    k = k*i%MOD;
                ans = ans*pow_mod(k,MOD-2,MOD)%MOD;
                if(((n-m)/2) & 1)
                    ans = (MOD - ans) % MOD;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
