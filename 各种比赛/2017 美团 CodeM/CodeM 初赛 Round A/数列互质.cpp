#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define L 100
using namespace std;


const int N = 5*1e4+5;
int S,Sn;
int u,v,ul,vr;
int l,r;
int a[N],sum[N/L+5][N],ans[N],t[N];
int ql[N],qr[N],qk[N];
vector<int> V[N*2];
vector< pair<int,int> > Ins[L+5][N],Del[L+5][N];
vector<int> query[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    S = min((int)sqrt(n),100);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]),V[a[i]].push_back(i);

    for(int i = 1;i <= n;++i)
        if(V[i].size() >= S)
        {
            ++Sn;
            for(int j = 0;j < V[i].size();++j)
                ++sum[Sn][V[i][j]];
            for(int j = 1;j <= n;++j)
                sum[Sn][j] += sum[Sn][j-1];
        }
        else
        {
            for(int j = 0;j < V[i].size();++j)
            {
                u = V[i][j];
                if(j) ul = V[i][j-1] + 1;
                else ul = 1;
                for(int k = j,l = 1;k < V[i].size();++k,++l)
                {
                    v = V[i][k];
                    if(k < V[i].size()-1) vr = V[i][k+1]-1;
                    else vr = n;
                    Ins[l][ul].push_back(make_pair(v,vr));
                    Del[l][u].push_back(make_pair(v,vr));
                }
            }
        }

    for(int i = 1;i <= m;++i)
    {
        scanf("%d%d%d",&ql[i],&qr[i],&qk[i]);
        l = ql[i];r = qr[i];
        query[l].push_back(i);
        for(int j = 1;j <= Sn;++j)
            if(sum[j][r]-sum[j][l-1] > 0 && __gcd(sum[j][r]-sum[j][l-1],qk[i]) == 1)
                ans[i]++;
    }

    for(int i = 1;i < S;++i)
        for(int j = 1;j <= n;++j)
        {
            for(int k = Ins[i][j].size()-1;k >= 0;--k)
            {
                l = Ins[i][j][k].first;
                r = Ins[i][j][k].second;
                for(int w = l;w <= n;w += w&-w)
                    ++t[w];
                for(int w = r+1;w <= n;w += w&-w)
                    --t[w];
            }
            for(int k = query[j].size()-1;k >= 0;--k)
            {
                l = query[j][k];
                u = qr[l];v = qk[l];
                if(__gcd(v,i) != 1)continue;
                for(int w = u;w;w -= w&-w)
                ans[l]+=t[w];
            }
            for(int k = Del[i][j].size()-1;k >= 0;--k)
            {
                l = Del[i][j][k].first;
                r = Del[i][j][k].second;
                for(int w = l;w <= n;w+=w&-w)
                    --t[w];
                for(int w=r+1;w<=n;w+=w&-w)
                    ++t[w];
            }
        }
    for(int i = 1;i <= m;++i)
        printf("%d\n",ans[i]);
    return 0;
}


#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int n,m;
int block=250;
int a[maxn],id[maxn];
struct Query
{
	int l,r,k,id;
	Query(int l=0,int r=0,int k=0,int id=0):l(l),r(r),k(k),id(id){}
}q[maxn];
bool operator < (Query a,Query b)
{
	if(id[a.l]==id[b.l])
	{
		 return a.r>b.r;
	}
	return id[a.l]<id[b.l];
}
set<int> mp;
set<int>::iterator it;
int g[3005][3005];
int gcd(int a,int b)
{
	if(!b)return a;return gcd(b,a%b);
}
inline int Gcd(int a,int b)
{
	if(a<=1000&&b<=1000)return g[a][b];
	else return gcd(a,b);
}
int Ans[maxn];
int has[maxn];
inline void add(int x){has[x]++;if(has[x]==1)mp.insert(x);}
inline void del(int x){has[x]--;if(!has[x])mp.erase(x);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)id[i]=(i-1)/block+1;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k),q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1;i<=1000;++i)for(int j=1;j<=1000;++j)g[i][j]=gcd(i,j);
	int l=1,r=0;
	for(int i=1;i<=m;++i)
	{
		while(r<q[i].r)++r,add(a[r]);
        while(r>q[i].r)del(a[r]),--r;
        while(l>q[i].l)--l,add(a[l]);
        while(l<q[i].l)del(a[l]),++l;
        int k=q[i].k;
        for(it=mp.begin();it!=mp.end();++it)
        {
        	int j=*it;
        	if(Gcd(has[j],k)==1)++Ans[q[i].id];
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",Ans[i]);
	return 0;
}
