#include<bits/stdc++.h>
using namespace std;

int dp[2005],vis[105][2005],a[2005];
struct node
{
    int t,d,p,id;
    bool operator < (const node & p)const
    {
        return d < p.d;
    }
}p[105];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> p[i].t >> p[i].d >> p[i].p,p[i].id = i;
    sort(p+1,p+n+1);
    int time;
    for(int i = 1;i <= n;i++)
    {
        time = p[i].t;
        for(int j = p[i].d-1;j >= time;j--)
        {
            if(dp[j] < dp[j-time] + p[i].p)
            {
                dp[j] = dp[j-time] + p[i].p;
                vis[i][j] = 1;
            }
        }
    }
    int pos = 0;
    for(int i = 1;i < p[n].d;i++)
        if(dp[i] > dp[pos])
            pos = i;
    cout<<dp[pos]<<"\n";
    int cnt = 0;
    for(int i = n;i >= 1;i--)
        if(vis[i][pos])
            a[cnt++] = p[i].id,pos -= p[i].t;
    cout<<cnt<<"\n";
    if(cnt) cout<<a[cnt-1];
    for(int i = cnt-2;i >= 0;i--)
        cout<<" "<<a[i];
    cout<<"\n";
    return 0;
}
