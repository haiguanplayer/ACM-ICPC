#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1000005;
typedef long long  LL;

LL n,m,p;
LL f[N];

LL gcd(LL a,LL b)  {return b ? gcd(b,a%b) : a;}
LL lcm(LL a,LL b)  {return a / gcd(a,b) * b;}
void Init(LL p)
{
    f[0] = 1;
    for(int i = 1;i <= p;i++)
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
	int t;
	cin >> t;
	LL n,m;
	Init(100070);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		if(m==0)
		{
			puts("1");
			continue;
		}
		printf("%lld\n",(Lucas(m+n,m,1e4+7)-Lucas(m+n,m-1,1e4+7)+LL(1e4+7))%LL(1e4+7));
	}
	return 0;
}
