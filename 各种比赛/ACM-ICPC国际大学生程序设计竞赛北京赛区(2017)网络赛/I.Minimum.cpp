#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1<<18;
struct node
{
    int l,r;
    ll maxn,minn;
}a[N*4];
int d[N];

void push_up(int x)
{
    a[x].maxn = max(a[x<<1].maxn,a[x<<1|1].maxn);
    a[x].minn = min(a[x<<1].minn,a[x<<1|1].minn);
}
void build(int x,int l,int r)
{
    a[x].l = l,a[x].r = r;
    if(l==r)
    {
        a[x].maxn = a[x].minn = d[l];
        return;
    }
    int mid = (l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    push_up(x);
}
void change(int x,int pos,ll val)
{
    int l = a[x].l,r = a[x].r;
    if(l == r)
    {
        a[x].maxn = a[x].minn = val;
        return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid)
        change(x<<1,pos,val);
    else
        change(x<<1|1,pos,val);
    push_up(x);
}

ll getmin(int x,int ql,int qr)
{
    int l = a[x].l,r = a[x].r;
    if(l == ql && r == qr)
        return a[x].minn;
    int mid = (l+r)>>1;
    if(qr <= mid)
        return getmin(x<<1,ql,qr);
    else if(ql > mid)
        return getmin(x<<1|1,ql,qr);
    else
        return min(getmin(x<<1,ql,mid),getmin(x<<1|1,mid+1,qr));
}
ll getmax(int x,int ql,int qr)
{
    int l = a[x].l,r = a[x].r;
    if(l == ql && r == qr)
        return a[x].maxn;
    int mid = (l+r)>>1;
    if(qr <= mid)
        return getmax(x<<1,ql,qr);
    else if(ql > mid)
        return getmax(x<<1|1,ql,qr);
    else
        return max(getmax(x<<1,ql,mid),getmax(x<<1|1,mid+1,qr));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k,q;
        scanf("%d",&k);
        for(int i = 1;i <= 1<<k;i++)
            scanf("%d",&d[i]);
        build(1,1,1<<k);
        scanf("%d",&q);
        while(q--)
        {
            int op;
            scanf("%d",&op);
            int x,y;
            if(op == 1)
            {
                scanf("%d%d",&x,&y);
                ll u = getmin(1,x+1, y+1);
                ll v = getmax(1,x+1, y+1);
                //cout << u << " " << v <<"\n";
                printf("%lld\n",min(min(u*u,v*v),u*v));
            }
            else
            {
                scanf("%d%d",&x,&y);
                change(1, x+1, y);
            }
        }
    }
    return 0;
}
