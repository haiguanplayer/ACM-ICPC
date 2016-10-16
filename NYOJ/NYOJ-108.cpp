1.线段树


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1000005;
int a[N];
struct node
{
    int l,r,sum;
}tree[N<<2];

void build(int rt,int l,int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if(l == r)
    {
        tree[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt<<1,l,mid);
    build((rt<<1)+1,mid+1,r);
    tree[rt].sum = tree[rt<<1].sum + tree[(rt<<1)+1].sum;
}
int query(int rt,int l,int r)
{
    if(l == tree[rt].l && r == tree[rt].r)
        return tree[rt].sum;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(r <= mid)
        return query(rt<<1,l,r);
    if(l > mid)
        return query((rt<<1)+1,l,r);
    return query(rt<<1,l,mid) + query((rt<<1)+1,mid+1,r);
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    int x,y;
    while(m--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",query(1,x,y));
    }
    return 0;
}


2.树状数组

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1000005;
int c[N];
int lowbit(int x)
{
    return x&(-x);
}
void add(int t,int val)
{
    while(t <= N)
    {
        c[t] += val;
        t += lowbit(t);
    }
}
int sum(int t)
{
    int ans = 0;
    while(t > 0)
    {
        ans += c[t];
        t -= lowbit(t);
    }
    return ans;
}
int main()
{
    int n,m,x,y;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&x);
        add(i,x);
    }

    while(m--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",sum(y)-sum(x-1));
    }
    return 0;
}


3.最简单
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1000005;

int sum[N];
int main()
{
    int n,m,x,y;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&x);
        sum[i] = sum[i-1] + x;
    }
    while(m--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",sum[y]-sum[x-1]);
    }
    return 0;
}
