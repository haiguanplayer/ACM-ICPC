#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 20005;

ll a[N],sum[N], dp[2][305][235];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%lld",&a[i]),sum[i] = sum[i-1] + a[i];
        memset(dp,0,sizeof(dp));
        for(int i = n;i >= 1;i--)
        {
            for(int j = 1;j*j/2 <= i;j++)
            {
                if(i+j == n+1)
                {
                    dp[0][i&255][j] = sum[i+j-1]-sum[i-1];
                    dp[1][i&255][j] = -(sum[i+j-1]-sum[i-1]);
                    break;
                }
                dp[0][i&255][j] = max(dp[1][i+j&255][j],dp[1][i+j+1&255][j+1]+a[i+j]) +sum[i+j-1]-sum[i-1];
                dp[1][i&255][j] = min(dp[0][i+j&255][j],dp[0][i+j+1&255][j+1]-a[i+j]) -(sum[i+j-1]-sum[i-1]);
            }
        }
        printf("%lld\n",dp[0][1][1]);
    }
}
