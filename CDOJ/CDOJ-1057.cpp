#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N = 100005;
int a[N],n,m;

struct node
{
    int l,r;
    ll sum,lazy;
}tree[N<<4];

void push_up(int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}
void push_down(int rt,int m)
{
    if(tree[rt].lazy)
    {
        tree[rt<<1].lazy += tree[rt].lazy;
        tree[rt<<1|1].lazy += tree[rt].lazy;
        tree[rt<<1].sum += tree[rt].lazy * (m-(m>>1));
        tree[rt<<1|1].sum += tree[rt].lazy * (m>>1);
        tree[rt].lazy = 0;
    }
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].sum = tree[rt].lazy = 0;
    if(l == r)
        tree[rt].sum = a[l];
    else
    {
        int mid = (l+r)>>1;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        push_up(rt);
    }
}

void update(int val,int l,int r,int rt)
{
    if(tree[rt].l == l && tree[rt].r == r)
    {
        tree[rt].lazy += 1ll*val;
        tree[rt].sum += 1ll*val*(r-l+1);
        return;
    }
    if(tree[rt].l == tree[rt].r)
        return;

    push_down(rt,tree[rt].r-tree[rt].l+1);
    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(r <= mid)
        update(val,l,r,rt<<1);
    else if(l > mid)
        update(val,l,r,rt<<1|1);
    else
    {
        update(val,l,mid,rt<<1);
        update(val,mid+1,r,rt<<1|1);
    }
    push_up(rt);
}
ll query(int l,int r,int rt)
{
    if(tree[rt].l == l && tree[rt].r == r)
        return tree[rt].sum;
    push_down(rt,tree[rt].r-tree[rt].l+1);

    int mid = (tree[rt].l+tree[rt].r)>>1;
    ll ans = 0;
    if(r <= mid)
        ans += query(l,r,rt<<1);
    else if(l > mid)
        ans += query(l,r,rt<<1|1);
    else
    {
        ans += query(l,mid,rt<<1);
        ans += query(mid+1,r,rt<<1|1);
    }
    //printf("dsjilsdfgsd f\n");
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    scanf("%d",&m);
    while(m--)
    {
        int l,r,val;
        scanf("%d%d%d",&l,&r,&val);
        update(val,l,r,1);
        //printf("dsjils\n");
        printf("%lld\n",query(l,r,1));
    }
    return 0;
}
