#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(a == 0 && b == 0)//没有最大公约数
        return - 1;
    if(b == 0)
    {
        x = 1;y = 0;
        return a;
    }
    ll d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
ll inv(ll a,ll n)
{
    ll x,y;
    ll d = exgcd(a,n,x,y);
    if(d == 1)
        return (x%n + n) % n;
    else
        return -1;
}
ll pow(int a,int b)
{
    ll base = a,ans = 1;
    while(b > 0)
    {
        if(b & 1)
            ans = ans*base%MOD;
        base = base*base%MOD;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int p,q,k;
        scanf("%d%d%d",&p,&q,&k);
        ll x = pow(p-2*q,k);
        ll y = pow(p,k);
        x = (x+y) % MOD;
        y = y * 2 % MOD;
        printf("%lld\n",(x*(inv(y,MOD))) % MOD);
    }
}
