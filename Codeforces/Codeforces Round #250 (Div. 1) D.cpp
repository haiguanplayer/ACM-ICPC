#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
struct node
{
    int l,r;
    ll maxn,sum;
}a[maxn*4];
int d[maxn];

void push_up(int x)
{
    a[x].maxn = max(a[x<<1].maxn,a[x<<1|1].maxn);
    a[x].sum = a[x<<1].sum + a[x<<1|1].sum;
}
void build(int x,int l,int r)
{
    a[x].l = l,a[x].r = r;
    if(l==r)
    {
        a[x].maxn = a[x].sum = d[l];
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
        a[x].maxn = a[x].sum = val;
        return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid)
        change(x<<1,pos,val);
    else
        change(x<<1|1,pos,val);
    push_up(x);
}
void mod(int x,int ql,int qr,ll val)
{
    int l = a[x].l,r = a[x].r;
    if(a[x].maxn < val)
        return;
    if(l == r)
    {
        a[x].sum %= val;
        a[x].maxn %= val;
        return;
    }
    int mid = (l+r)>>1;
    if(qr <= mid)
        mod(x<<1,ql,qr,val);
    else if(ql > mid)
        mod(x<<1|1,ql,qr,val);
    else
    {
        mod(x<<1,ql,mid,val);
        mod(x<<1|1,mid+1,qr,val);
    }
    push_up(x);
}
ll get(int x,int ql,int qr)
{
    int l = a[x].l,r = a[x].r;
    if(ql <= l && r <= qr)
        return a[x].sum;
    int mid = (l+r)>>1;
    ll sum1 = 0,sum2 = 0;
    if(qr <= mid)
        sum1 = get(x<<1,ql,qr);
    else if(ql > mid)
        sum2 = get(x<<1|1,ql,qr);
    else
    {
        sum1 = get(x<<1,ql,mid);
        sum2 = get(x<<1|1,mid+1,qr);
    }
    return sum1 + sum2;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++)
        scanf("%d",&d[i]);
    build(1,1,n);
    while(q--)
    {
        int op;
        scanf("%d",&op);
        int x,y,z;
        if(op == 1)
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",get(1,x,y));
        }
        else if(op == 2)
        {
            scanf("%d%d%d",&x,&y,&z);
            mod(1,x,y,z);
        }
        else
        {
            scanf("%d%d",&x,&y);
            change(1,x,y);
        }
    }
    return 0;
}
