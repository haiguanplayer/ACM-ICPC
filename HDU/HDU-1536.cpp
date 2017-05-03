#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10005;
int SG[N];
int s[105],h,k;

int dfs(int m)
{
    if(SG[m] != -1)
        return SG[m];
    bool used[N];
    memset(used,0,sizeof(used));
    for(int i = 0;i < k;i++)
    {
        if(m >= s[i])
        {
            dfs(m-s[i]);
            used[SG[m-s[i]]] = true;
        }
    }
    int num = 0;
    while(used[num])
        num++;
    return SG[m] = num;
}
int main()
{
    int m,L;
    while(scanf("%d",&k) != EOF && k)
    {
        memset(SG,-1,sizeof(SG));
        for(int i = 0;i < k;i++)
            scanf("%d",&s[i]);
        sort(s,s+k);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&L);
            int ans = 0;
            while(L--)
            {
                scanf("%d",&h);
                ans ^= dfs(h);
            }

            if(ans == 0)
                printf("L");
            else
                printf("W");
        }
        printf("\n");
    }
    return 0;
}
