#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

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

ll GetC(ll n,ll m,ll mod)
{
    if(m > n)
        return 0;
    if(m > n - m)
        m = n - m;
    ll a = 1,b = 1;
    while(m)
    {
        a = a*n%mod;
        b = b*m%mod;
        m--;
        n--;
    }
    return a * pow_mod(b,mod-2,mod)%mod;
}

ll Lucas(ll n,ll k,ll mod)
{
    if(k == 0)
        return 1;
    return GetC(n%mod,k%mod,mod)*Lucas(n/mod,k/mod,mod)%mod;
}
int main()
{
    int t;
    ll n,m,q;
    cin >> t;
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        ll u = max(n,m);
        ll v = min(n,m);
        printf("%lld\n",Lucas(u,v,MOD));
    }
    return 0;
}
