/*
给定n和s，要求将1~n与s+1~s+n,匹配使得i匹配j且有i整除j。
求是否能完全匹配。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;
const int N = 1005;
int n,s;
int G[N][N];
int vis[N],girl[N];
/*
bool is_prime(int x)
{
    if(x == 1 || x == 2)
        return false;
    for(int i = 2;i <= sqrt(x);i++)
        if(x % i == 0)
            return false;
    return true;
}*/

void Init()
{
    memset(G,0,sizeof(G));
    memset(girl,-1,sizeof(girl));
}

bool dfs(int x)
{
    for(int i = 0;i < n;i++)
    {
        if(G[x][i] && !vis[i])
        {
            vis[i] = true;
            if(girl[i] == -1 || dfs(girl[i]))
            {
                girl[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d",&n,&s);
        if(s < n)
            swap(s,n);
        printf("Case #%d: ",ca);
        /*
        int cnt = 0;
        for(int i = s+1;i <= s+n;i++)
        {
            if(is_prime(i))
                cnt++;
        }*/

        if(n > 500)
            printf("No\n");
        else
        {
            Init();
            for(int i = s+1;i <= s+n;i++)
                for(int j = 1;j <= n;j++)
                    if(i % j == 0)
                        G[j-1][i-s-1] = 1;

            int ans = 0;
            for(int i = 0;i < n;i++)
            {
                memset(vis,0,sizeof(vis));
                if(dfs(i))
                    ans++;
            }
            if(ans == n)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
