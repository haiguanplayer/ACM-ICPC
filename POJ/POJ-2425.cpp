//SG function moban

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1005;
int n;
int map[N][N],SG[N];

int dfs(int m)
{
    if(SG[m] != -1)
        return SG[m];
    bool used[N];
    memset(used,0,sizeof(used));
    for(int i = 0;i < n;i++)
    {
        if(map[m][i] != -1)
            used[dfs(i)] = true;
    }
    int num = 0;
    while(used[num])
        num++;
    return SG[m] = num;
}
int main()
{
    int x,y;
    while(~scanf("%d",&n))
    {
        memset(map,255,sizeof(map));
        memset(SG,255,sizeof(SG));

        for(int i = 0;i < n;i++)
        {
            scanf("%d",&x);
            if(x == 0)
                SG[i] = 0;
            for(int j = 0;j < x;j++)
            {
                scanf("%d",&y);
                map[i][y] = 1;
            }
        }
        int t,f;
        while(~scanf("%d",&t) && t)
        {
            int ans = 0;
            for(int i = 0;i < t;i++)
            {
                scanf("%d",&f);
                ans = ans ^ dfs(f);
            }

            if(ans != 0)
                printf("WIN\n");
            else
                printf("LOSE\n");
        }
    }
    return 0;
}
