#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = (ll)0xffffffff+1;
const int val[16] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};
int a[20];
ll dp[20][1005];

ll deal(char *str)
{
    ll tmp = 0;
    for(int i = 0;i < 8;i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            tmp = tmp*16 + str[i]-'0';
        else
            tmp = tmp*16 + str[i]-'A'+10;
    }
    return tmp;
}
ll dfs(int pos,ll sum,bool flag)
{
    //printf("III\n");
    if(pos < 0)
        return sum;
    if(!flag && dp[pos][sum] != -1)
        return dp[pos][sum];
    int n = flag ? a[pos] : 15;
    ll ans = 0;
    for(int i = 0;i <= n;i++)
        ans += dfs(pos-1,sum+val[i],flag && (i == n));
    if(!flag)
        dp[pos][sum] = ans;
    return ans;
}
ll solve(ll x)
{
    if(x < 0)//0-1 = -1,so -1 should return 0
        return 0;
    int pos = 0;
    memset(a,0,sizeof(a));
    while(x > 0)
    {
        a[pos++] = x%16;
        x /= 16;
    }
    return dfs(7,0,1);//前导0也花费，都从第7位开始
}
int main()
{
    int t;
    ll n;
    char str[20];
    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--)
    {
        scanf("%lld %s",&n,str);
        n--;
        ll L = deal(str);
        ll R = (L+n)%MOD;
        if(L + n >= MOD)
            printf("%lld\n",solve(MOD-1) + (solve(R) - solve(L-1)));
        else
            printf("%lld\n",solve(R) - solve(L-1));
    }
    return 0;
}
