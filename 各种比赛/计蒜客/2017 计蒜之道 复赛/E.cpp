#include<bits/stdc++.h>
using namespace std;

//typedef long long ll;
const int MOD = 1e9+7;
const int N = 20;
int a[N],dp[1<<N][N];
int gcd(int a,int b)
{
    return b == 0 ? a : gcd(b,a%b);
}
bool check(int x,int y)
{
    return x&(1<<y);
}
int main()
{
    ios_base::sync_with_stdio(0);//¹ØµôÍ¬²½
    int n,k;
    cin >> n >> k;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    dp[0][0] = 1;

    for(int i = 0;i < (1<<n);i++)
    {
        for(int l = 0;l < n;l++)
        {
            int tmp = i;
            if(check(i,l))
            {
                int tmp1 = a[l];
                for(int r = l;r < n;r++)
                {
                    if(check(i,r))
                    {
                        tmp ^= (1<<r);
                        tmp1 = gcd(tmp1,a[r]);
                        if(tmp1 < k) break;
                        for(int j = 1;j <= n;j++)
                        {
                            dp[i][j] = (dp[i][j] + dp[tmp][j-1])%MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1;i <= n;i++)
        ans = (ans + 1ll*i*dp[(1<<n)-1][i]%MOD)%MOD;

    cout<<ans<<endl;
    return 0;
}
