#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;;
ll a[N],sum[N];
int main()
{
    ll n,A,B;
    while(~scanf("%lld%lld%lld",&n,&A,&B))
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        ll pre = sum[n],now = 0;
        for(int i = n;i >= 1;i--)
        {
            now = pre-sum[i-1];
            pre = min(pre,max(sum[i-1],A+B-now+1));
        }
        printf("%s\n",now>A?"BOB":"ALICE");
    }
    return 0;
}
