#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
ll a[N],b[N*2],dp[N][N*2];
ll n,k,p;

int main()
{
    cin >> n >> k >> p;
    for(int i = 1;i <= n;i++)
        scanf("%lld",&a[i]);
    for(int i = 1;i <= k;i++)
        scanf("%lld",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i = 0;i < N*2;i++)
        dp[0][i] = 0;
    for(int i = 1;i <= n;i++)
        for(int j = i;j <= k;j++)
            dp[i][j] = min(dp[i][j-1],max(dp[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-p)));
    cout << dp[n][k] << endl;
    return 0;
}
