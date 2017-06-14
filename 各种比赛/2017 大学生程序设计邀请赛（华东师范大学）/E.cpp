#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b == 0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    ll x,n;
    cin>>x>>n;
    for(ll i = 2;i <= n;i++)
    {
        ll tmp = lcm(i,x);
        printf("%lld\n",tmp/x);
    }
    return 0;
}
