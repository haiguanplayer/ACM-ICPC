#include<bits/stdc++.h>
using namespace std;

template <class T1,class T2>inline void gmax(T1 &a,T2 b){if(b > a) a = b;}
template <class T1,class T2>inline void gmin(T1 &a,T2 b){if(b < a) a = b;}

const int INF = 0x3f3f3f3f;
const int N = 95;
int a[N],mx[N][N],mn[N][N];
int ST,LIM = 0 * CLOCKS_PER_SEC;
int n,ans;
void init()
{
    memset(mx,-0x3f,sizeof(mx));
    memset(mn,0x3f,sizeof(mn));
    for(int i = 1;i <= n;i++)
        mx[i][i-1] = mn[i][i-1] = 0;
    for(int l = n;l >= 1;l--)
        for(int r = l;r <= n;r++){
            int left = l,right = r;
            int sub;
            if(a[left] >= a[right])
                sub = a[left++];
            else
                sub = a[right--];
            gmax(mx[l][r], a[left]+mx[left+1][right]-sub);
            gmin(mn[l][r], a[left]+mn[left+1][right]-sub);
            gmax(mx[l][r], a[right]+mx[left][right-1]-sub);
            gmin(mn[l][r], a[right]+mn[left][right-1]-sub);
        }
}
void dfs(int l,int r,int dif)
{
    if(l > r)
    {
        gmax(ans,dif);
        return;
    }
    if(dif + mn[l][r] >= 0) return;
    if(dif + mx[l][r] <= ans) return;
    if(dif + mx[l][r] < 0)
    {
        gmax(ans,dif+mx[l][r]);
        return;
    }
    int sub;
    if(a[l] >= a[r])
        sub = a[l++];
    else
        sub = a[r--];

    if(clock() - ST > LIM) return;//...
    dfs(l+1,r,dif+a[l]-sub);
    dfs(l,r-1,dif+a[r]-sub);
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        init();
        ST = clock();
        ans = -INF;
        dfs(1,n,0);
        if(ans == -INF)
            puts("The child will be unhappy...");
        else
            printf("%d\n",-ans);
    }
}

