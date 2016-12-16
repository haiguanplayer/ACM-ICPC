/*
solution:
http://www.cnblogs.com/dirge/p/5966603.html
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N = 3005;
int a[N],b[N];
ll dp[N][N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            a[i] -= i;
            b[i] = a[i];
        }
        sort(b+1,b+1+n);
        int num = unique(b+1,b+1+n)-b;
        memset(dp,0x3f,sizeof(dp));
        for(int i = 0;i < num;i++)
            dp[0][i] = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j < num;j++)
            {
                dp[i][j] = abs(a[i]-b[j]) + dp[i-1][j];
                dp[i][j] = min(dp[i][j],dp[i][j-1]);
            }
        printf("%lld\n",dp[n][num-1]);
    }
    return 0;
}
