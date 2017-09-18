#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll p[205] = {1};
int main()
{
    for(int i = 1;i <= 62*2;i++)
        p[i] = p[i-1]*2%MOD;
    ll n;
    while(~scanf("%lld",&n))
    {
        ll ans = 1,sum = 1;
        for(int i = 1;i <= 62;i++)
        {
            sum <<= 1;
            if(sum >= n)
                break;
            ll tmp = p[(i-1)*2] + 1;//≤Ó÷µ
            ans = (ans + tmp) % MOD;
            if(sum + sum/2 < n)
                ans = (ans + tmp) % MOD;
            else
                continue;
            if(sum + sum/2 < n)
                ans = (ans + tmp*(((n-1-(sum+sum/2))/sum)%MOD)) % MOD;
        }
        printf("%lld\n",ans);
    }
}
