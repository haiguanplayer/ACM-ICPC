#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int N = 2e5+10;
struct node
{
    int l,r,sum;
} T[N*20];
struct noder
{
    int w,v;
} a[N];
bool cmp(noder x,noder y)
{
    return x.w>y.w;
}
int mxv[N];
int mxvr[N];
int root[N];
int cnt,n;
void update(int l,int r,int &x,int y,int pos)
{
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if(l==r) return ;
    int mid=(r+l)>>1;
    if(mid>=pos)
        update(l,mid,T[x].l,T[y].l,pos);
    else
        update(mid+1,r,T[x].r,T[y].r,pos);
}
int query(int l,int r,int x,int y,int k)
{
    if(l==r) return l;
    int mid=(r+l)>>1;
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    if(sum>=k) return query(l,mid,T[x].l,T[y].l,k);
    else return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
void init()
{
    cnt=0;
    mxv[0]=0;
    mxvr[2*n+1]=0;
}
int main()
{
    scanf("%d",&n);
    init();
    for(int i=1; i<=2*n; i++) scanf("%d",&a[i].w);
    for(int i=1; i<=2*n; i++) scanf("%d",&a[i].v);
    sort(a+1,a+1+2*n,cmp);
    for(int i=1; i<=2*n; i++)
    {
        mxv[i]=max(mxv[i-1],a[i].v);
        update(1,2*n,root[i],root[i-1],a[i].v);
    }
    for(int i=2*n; i>=1; i--)
        mxvr[i] = max(mxvr[i+1],a[i].v);
    ll ans = INF;
    ans=min(ans,(ll)a[1].w*mxv[n]+(ll)a[n+1].w*mxvr[n+1]);
    for(int i=2; i<=n; i++)
    {
        ll x=query(1,2*n,root[i],root[2*n],n-1);
        ll y=query(1,2*n,root[i],root[2*n],n-i+1);
        ans=min(ans,(ll)a[1].w*max(mxv[i-1],mxvr[i+1])+(ll)max(x,(ll)a[i].v)*a[i].w);
        ans=min(ans,(ll)a[1].w*max((ll)mxv[i-1],y)+(ll)a[i].w*mxvr[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
