#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N],cnt[N],nxt[N],endd[N];
int n,m,blo;
void update(int i,int j)
{
    if(j > n)
    {
        nxt[i] = n+1;
        cnt[i] = 1;//¿éºÅ
        endd[i] = i;
    }
    else
    {
        if(i/blo == j/blo)
        {
            cnt[i] = cnt[j]+1;
            endd[i] = endd[j];
            nxt[i] = nxt[j];
        }
        else
        {
            cnt[i] = 1;
            endd[i] = i;
            nxt[i] = j;
        }
    }
}
void solve(int x)
{
    int c = cnt[x],e = endd[x];
    while(true)
    {
        x = nxt[x];
        if(x > n)
            break;
        c += cnt[x];
        e = endd[x];
    }
    printf("%d %d\n",e,c);
}
int main()
{
    scanf("%d%d",&n,&m);
    blo = sqrt(n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    for(int i = n;i >= 1;i--)
        update(i,i+a[i]);
    int op,x,y;
    while(m--)
    {
        scanf("%d",&op);
        if(op == 0)
        {
            scanf("%d%d",&x,&y);
            update(x,x+y);
            for(int i = x-1;i >= x/blo*blo;i--)
                update(i,i+a[i]);
            a[x] = y;
        }
        else
        {
            scanf("%d",&x);
            solve(x);
        }
    }
}
