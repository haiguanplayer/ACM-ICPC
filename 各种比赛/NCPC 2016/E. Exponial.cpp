#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll phi(ll n)
{
    ll res = n,a = n;
    for(int i = 2;i*i <= a;i++)
    {
        if(a % i == 0)
        {
            res -= res/i;
            while(a % i == 0)
                a /= i;
        }
    }
    if(a > 1)
        res -= res/a;
    return res;
}
ll pow_mod(ll a,ll b,ll mod)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b&1)
            ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
ll f(ll n,ll m)
{
    if(m == 1)
        return 0;
    if(n <= 5)
    {
        ll ans = 1;
        for(int i = 1;i <= n;i++)
            ans = pow_mod(i,ans,m);
        return ans;
    }
    else
    {
        ll x = phi(m);
        return pow_mod(n,x+f(n-1,x),m);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld\n",f(n,m));
    return 0;
}