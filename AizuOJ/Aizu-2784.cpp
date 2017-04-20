#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
typedef long long ll;
const int N = 1000005,p = 9901,MOD = 1e9+7;
vector<ll> G[N];
ll Hash[N];
map<ll,ll> m;
map<ll,ll>::iterator it;
void dfs(ll u)
{
    Hash[u] = 1;
    for(int i = 0;i < G[u].size();i++)
    {
        ll v = G[u][i];
        dfs(v);
        Hash[u] = (Hash[u]+Hash[v]*p)%MOD;
    }
    m[Hash[u]]++;
}
int main()
{
    int n,u,v;
    cin >> n;
    for(int i = 1;i <= n-1;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    dfs(1);
    ll ans = 0;
    for(it = m.begin();it != m.end();it++)
        ans += it->second*(it->second-1)/2;
    printf("%lld\n",ans);
    return 0;
}
