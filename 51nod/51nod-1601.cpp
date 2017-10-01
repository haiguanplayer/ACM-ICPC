#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const int N = 1e5+5;
int trie[N*40][3],sum[N*40],val[N*40],to[N*40],cnt,weishu = 30-1;
ll ans,tot,ta,tt;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
ll pow_mod(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
inline void insert(int x)
{
    int now = 0;
    for(int i=weishu,bt;i>=0;i--){
        bt = 1-(0==(x&(1<<i)));
        if(!trie[now][bt]) trie[now][bt]=++cnt;
        now = trie[now][bt];
        sum[now]++;
    }
    val[now]=x;
}

inline int query(int x,int pre){
    int now = 0;
    for(int i=weishu,bt;i>=0;i--){
        bt = 1-(0==(x&(1<<i)));
        if(!trie[now][bt]) bt = 1-bt;
        if(now == pre) bt = 1-bt;
        now = trie[now][bt];
    }
    return now;
}

void dfs2(int x,int &pre){
    if(trie[x][0]) dfs2(trie[x][0],pre);
    if(trie[x][1]) dfs2(trie[x][1],pre);

    if(!trie[x][0]&&!trie[x][1]){
        int now = query(val[x],pre);
        if( ta==(val[now]^val[x])){
            tt =(tt+1ll*sum[now]*sum[x]%MOD)%MOD;
        }
        if( ta>(val[now]^val[x])){
            ta=(val[now]^val[x]);
            tt=(1ll*sum[now]*sum[x])%MOD;
        }
    }
}

void dfs(int x){
    if(trie[x][0]) dfs(trie[x][0]);
    if(trie[x][1]) dfs(trie[x][1]);

    if(trie[x][0]&&trie[x][1]){
        ta = INF,tt=0;

        if(to[trie[x][1]]<to[trie[x][0]])
            dfs2(trie[x][1],x);
        else      dfs2(trie[x][0],x);
        ans+=ta;
        tot=tot*tt%MOD;

    }
    else if(!trie[x][0]&&!trie[x][1]&&sum[x]>1)
        tot=tot*pow_mod(1ll*sum[x],1ll*sum[x]-2)%MOD;
}

int dfs1(int x){
    if(!trie[x][0]&&!trie[x][1])
        return to[x]=1;
    if(trie[x][0]) to[x]+=dfs1(trie[x][0]);
    if(trie[x][1]) to[x]+=dfs1(trie[x][1]);
    return to[x];
}

int main(){

    int n;
    while(~scanf("%d",&n)){

        cnt = 0;
        ans = 0ll,tot=1ll;

        for(int i=1,x;i<=n;i++){
            x=read();
            insert(x);
        }

        dfs1(0);
        dfs(0);
        printf("%lld\n%lld\n",ans,tot);
    }
    return 0;
}
