#include<iostream>
using namespace std;

const long long MOD = 1e9+7;
long long dp[105][2][2];
int main()
{
    int n;
    cin >> n;
    dp[0][0][0] = 1;
    for(int i = 1;i <= n;i++)
    {
        dp[i][1][1] = (dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][0][1]) % MOD;
        dp[i][1][0] = (dp[i-1][1][0] + dp[i-1][1][1]) % MOD;
        dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1]) % MOD;
        dp[i][0][1] = dp[i-1][0][0];
    }
    cout << (dp[n][1][0] + dp[n][1][1]) % MOD << endl;
    return 0;
}

#include<iostream>
using namespace std;

const long long MOD = 1e9+7;
long long f[105],g[105],h[105];
long long pow_mod(long long a,long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    g[1] = h[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        f[i] = (f[i-1]*2 + g[i-1]) % MOD;
        g[i] = h[i-1];
        h[i] = (pow_mod(2,i)- f[i] - g[i]) % MOD;
    }
    cout << f[n] << endl;
    return 0;
}