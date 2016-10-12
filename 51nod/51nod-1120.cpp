/*
Lucas∂®¿Ì
C(m+n,m)%p

Exe.Time    733MS
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod = 10007;

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

void Exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    Exgcd(b, a%b, x1 ,y1);
    x = y1;
    y = x1 - (a/b)*y1;
}

int main()
{
    ll n,x,y;
    while(scanf("%lld",&n) != EOF)
    {
        Exgcd(n,Mod,x,y);
        x = (x%Mod + Mod) % Mod;
        x <<= 1ll;
        ll ans = Lucas(n*2-2,n-1,Mod);
        ans = ans * x % Mod;
        printf("%lld\n",ans);
    }
    return 0;
}
