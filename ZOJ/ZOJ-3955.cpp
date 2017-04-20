#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
const int N = 1005;
int a[N][N],row[N][N],col[N][N];

ll pow_mod(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
            ans = ans*a%MOD;
        a = a*a%MOD;
        b /= 2;
    }
    return ans;
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
            {
                scanf("%d",&a[i][j]);
                row[i][j] = a[i][j];
                col[j][i] = a[i][j];
            }

        for(int i = 1;i <= n;i++)
            sort(row[i]+1,row[i]+1+m);
        for(int i = 1;i <= m;i++)
            sort(col[i]+1,col[i]+1+n);

        ll ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                ll t1 = m - (upper_bound(row[i]+1,row[i]+1+m,a[i][j]) - (row[i]+1));
                ll t2 = lower_bound(col[j]+1,col[j]+1+n,a[i][j]) - (col[j]+1);
                ans = (ans + pow_mod(2,t1)*pow_mod(2,t2)%MOD)%MOD;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
