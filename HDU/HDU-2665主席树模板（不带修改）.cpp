#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int L[N<<5],R[N<<5],sum[N<<5];
int a[N],T[N],Hash[N];
int tot;
void init()
{
    tot = 0;
}
int build(int l,int r)
{
    int rt = ++tot;
    sum[rt] = 0;
    if(l < r)
    {
        int mid = (l+r)>>1;
        L[rt] = build(l,mid);
        R[rt] = build(mid+1,r);
    }
    return rt;
}
int update(int pre, int l, int r, int x)
{
    int rt=(++tot);
    L[rt]=L[pre], R[rt]=R[pre], sum[rt]=sum[pre]+1;
    if(l<r)
    {
        int m=(l+r)>>1;
        if(x<=m)
            L[rt]=update(L[pre], l,m, x);
        else
            R[rt]=update(R[pre], m+1,r, x);
    }
    return rt;
}
int query(int u, int v, int l, int r, int k)
{
    if(l>=r)
        return l;
    int m=(l+r)>>1;
    int num=sum[L[v]]-sum[L[u]];
    if(num>=k)
        return query(L[u], L[v], l,m, k);
    else
        return query(R[u], R[v], m+1,r, k-num);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]),Hash[i] = a[i];
        sort(Hash+1,Hash+n+1);
        int d = unique(Hash+1,Hash+n+1)-Hash-1;
        T[0] = build(1,d);
        for(int i = 1;i <= n;i++)
        {
            int pos = lower_bound(Hash+1,Hash+d+1,a[i])-Hash;
            T[i] = update(T[i-1],1,d,pos);
        }
        while(q--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            int pos = query(T[l-1],T[r],1,d,k);
            printf("%d\n",Hash[pos]);
        }
    }
}
