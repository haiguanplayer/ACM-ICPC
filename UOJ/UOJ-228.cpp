#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;

int n,m,val[N];

struct node
{
    int l,r;
    ll minn,maxn,sum,add;
    void upd(ll x)
    {
        add += x,minn += x,maxn += x;
        sum += x*(r-l+1);
    }
}a[N<<2];

inline void push_up(int x)
{
    a[x].minn = min(a[x<<1].minn,a[x<<1|1].minn) + a[x].add;
    a[x].maxn = max(a[x<<1].maxn,a[x<<1|1].maxn) + a[x].add;
    a[x].sum = a[x<<1].sum + a[x<<1|1].sum + a[x].add*(a[x].r-a[x].l+1);
}
inline void build(int x,int l,int r)
{
    a[x].l = l,a[x].r = r;
    if(l == r)
    {
        a[x].minn = a[x].maxn = a[x].sum = val[l];
        return;
    }
    int mid = (l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    push_up(x);
}
inline void add(int x,int ql,int qr,ll tag)
{
    int l = a[x].l,r = a[x].r;
    if(ql <= l && r <= qr)
    {
        a[x].upd(tag);
        return;
    }
    int mid = (l+r)>>1;
    if(ql <= mid)
        add(x<<1,ql,qr,tag);
    if(qr > mid)
        add(x<<1|1,ql,qr,tag);
    push_up(x);
}
inline void Sqrt(int x,int ql,int qr,ll tag)
{
    int l = a[x].l,r = a[x].r;
    int mid  = (l+r)>>1;
    if(ql <= l && r <= qr)
    {
        if(a[x].minn == a[x].maxn || a[x].maxn-a[x].minn ==(ll)sqrt(a[x].maxn+tag)-(ll)sqrt(a[x].minn+tag))
        {
            ll ad = (ll)sqrt(a[x].minn+tag)-(a[x].minn+tag);
            a[x].upd(ad);
            //printf("22\n");
            return;
        }
        //printf("333\n");
        Sqrt(x<<1,ql,qr,tag+a[x].add);
        Sqrt(x<<1|1,ql,qr,tag+a[x].add);
        push_up(x);
        return;
    }
    //printf("***\n");
    if(ql <= mid)
        Sqrt(x<<1,ql,qr,tag+a[x].add);
    if(qr > mid)
        Sqrt(x<<1|1,ql,qr,tag+a[x].add);
    push_up(x);
}
inline ll query(int x,int ql,int qr,ll add)
{
    ll ans = 0;
    int l = a[x].l,r = a[x].r;
    int mid = (l+r)>>1;
    if(ql <= l && r <= qr)
        return a[x].sum+add*(r-l+1);
    if(ql <= mid)
        ans += query(x<<1,ql,qr,add+a[x].add);
    if(qr > mid)
        ans += query(x<<1|1,ql,qr,add+a[x].add);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%d",&val[i]);
    build(1,1,n);
    int op,x,y,z;
    while(m--)
    {
        scanf("%d",&op);
        if(op == 1)
        {
            scanf("%d%d%d",&x,&y,&z);
            add(1,x,y,z);
        }
        else if(op == 2)
        {
            scanf("%d%d",&x,&y);
            Sqrt(1,x,y,0);
        }
        else
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,x,y,0));
        }
    }
    return 0;
}
