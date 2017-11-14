#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define ms0(X) memset((X),0,sizeof((X)))
typedef long long ll;
const int N = 100005;
const int MOD = 4001;

struct node{
    int l,r,lc,rc,d;
    int L[2],R[2],s[2];
}t[10][2*N];

int tl,a[N][10];
int bit[15] = {1};
node push_up(int cnt,int tmp,node lc,node rc)
{
    int dl = lc.d,dr = rc.d;
    node x;
    if(tmp) x = t[cnt][tmp];
    x.d = lc.d ^ rc.d;
    x.L[0] = (lc.L[0] + rc.L[dl==0?0:1]) % MOD;
    x.L[1] = (lc.L[1] + rc.L[dl==0?1:0]) % MOD;
    x.R[0] = (rc.R[0] + lc.R[dr==0?0:1]) % MOD;
    x.R[1] = (rc.R[1] + lc.R[dr==0?1:0]) % MOD;
    x.s[0] = (lc.s[0] + rc.s[0] + (lc.R[0]*rc.L[0])%MOD + (lc.R[1]*rc.L[1])%MOD)%MOD;
    x.s[1] = (lc.s[1] + rc.s[1] + (lc.R[0]*rc.L[1])%MOD + (lc.R[1]*rc.L[0])%MOD)%MOD;
    return x;
}
int build(int cnt,int l,int r)
{
    int x = ++tl;
    t[cnt][x].l = l; t[cnt][x].r = r;
    t[cnt][x].lc = t[cnt][x].rc = 0;
    t[cnt][x].d = 0;
    ms0(t[cnt][x].L);ms0(t[cnt][x].R);ms0(t[cnt][x].s);
    if(l < r){
        int mid = (l+r)>>1;
        t[cnt][x].lc = build(cnt,l,mid);
        t[cnt][x].rc = build(cnt,mid+1,r);
        int lc = t[cnt][x].lc,rc = t[cnt][x].rc;
        t[cnt][x] = push_up(cnt,x,t[cnt][lc],t[cnt][rc]);
    }
    else{
        int d = a[l][cnt];
        t[cnt][x].d = d;
        t[cnt][x].L[d] = t[cnt][x].R[d] = t[cnt][x].s[d] = 1;
    }
    return x;
}
void change(int cnt,int x,int p,int val)
{
    if(t[cnt][x].l == t[cnt][x].r){
        t[cnt][x].d = val;
        t[cnt][x].L[val] = t[cnt][x].R[val] = t[cnt][x].s[val] = 1;
        t[cnt][x].L[val^1] = t[cnt][x].R[val^1] = t[cnt][x].s[val^1] = 0;
        return;
    }
    int lc = t[cnt][x].lc,rc = t[cnt][x].rc;
    int mid = (t[cnt][x].l + t[cnt][x].r) >> 1;
    if(p <= mid)
        change(cnt,lc,p,val);
    else
        change(cnt,rc,p,val);
    t[cnt][x] = push_up(cnt,x,t[cnt][lc],t[cnt][rc]);
}
node query(int cnt,int x,int l,int r)
{
    if(t[cnt][x].l == l && t[cnt][x].r == r)
        return t[cnt][x];
    int lc = t[cnt][x].lc,rc = t[cnt][x].rc;
    int mid = (t[cnt][x].l + t[cnt][x].r) >> 1;
    if(r <= mid)
        return query(cnt,lc,l,r);
    else if(l > mid)
        return query(cnt,rc,l,r);
    else{
        node x0 = query(cnt,lc,l,mid);
        node x1 = query(cnt,rc,mid+1,r);
        return push_up(0,0,x0,x1);
    }
}

int main()
{
    memset(a,0,sizeof(a));
    for(int i = 1;i <= 10;i++)
        bit[i] = bit[i-1]*2;

    int n,m;
    scanf("%d%d",&n,&m);
    int x,cnt,y,op;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&x);
        cnt = 0;
        while(x > 0){
            a[i][cnt++] = x%2;
            x /= 2;
        }
    }
    for(int i = 0;i < 10;i++){
        tl = 0;
        build(i,1,n);
    }
    while(m--)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(op == 1)
        {
            cnt = 0;
            while(y > 0){
                change(cnt++,1,x,y%2);
                y /= 2;
            }
            for(int i = cnt;i < 10;i++)
                change(i,1,x,0);
        }
        else
        {
            ll ans = 0;
            for(int i = 0;i < 10;i++)
            {
                node now = query(i,1,x,y);
                ans = (ans+bit[i]*now.s[1]%MOD)%MOD;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
