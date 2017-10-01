#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
    return b == 0?a:gcd(b,a%b);
}
int main()
{
    ll n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        --n;--m;
        ll g = gcd(n,m);
        n /= g;m /= g;

        ll res = (g-1)*n*m +(n+m);
        printf("%lld\n",res);
    }
    return 0;
}
