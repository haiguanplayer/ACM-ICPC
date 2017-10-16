#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MOD = 1e9+7;
typedef long long  LL;

LL n,m,p;
LL f[N];

LL gcd(LL a,LL b)  {return b ? gcd(b,a%b) : a;}
LL lcm(LL a,LL b)  {return a / gcd(a,b) * b;}
void Init(LL p)
{
    f[0] = 1;
    for(int i = 1;i < N;i++)
        f[i] = (f[i-1]*i) % p;
}

LL pow_mod(LL a,LL b,LL MOD)
{
    LL ans = 1;
    while(b)
    {
        if(b%2)
            ans = ans*a%MOD;
        a = a*a%MOD;
        b /= 2;
    }
    return ans;
}

LL Lucas(LL n,LL m,LL p)
{
    LL ans = 1;
    while(n && m)
    {
        LL a = n%p,b = m%p;
        if(a < b)
            return 0;
        ans = (ans*f[a]*pow_mod(f[b]*f[a-b]%p,p-2,p))%p;
        n /= p;m /= p;
    }
    return ans;
}

int main()
{
    LL n,t,w,x,c;
    while(~scanf("%lld%lld%lld",&n,&t,&w))
    {
        Init(MOD);
        LL ans = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lld%lld",&x,&c);
            LL l = x-t,r = x+t;
            LL cnt = w-l;
            if(l <= w && w <= r && cnt%2 == 0)
            {
                ans = (ans + Lucas(t,cnt/2,MOD)*c)%MOD;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
