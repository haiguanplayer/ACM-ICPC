#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
const int N = 1005;

int h[N],c[N];
long long dp[50005];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&h[i],&c[i]);
        int sum = 0;
        for(int i = 1;i <= n;i++)
            sum += c[i];

        for(int i = 1;i <= n;i++)
            for(int j = sum;j >= c[i];j--)
                dp[j] = max(dp[j],dp[j-c[i]]+h[i]);

        long long maxn = 0;
        for(int i = 1;i <= sum;i++)
            maxn = max(maxn,dp[i]*dp[i]-dp[i]*i-i*i);
        printf("%lld\n",maxn);
    }
    return 0;
}
