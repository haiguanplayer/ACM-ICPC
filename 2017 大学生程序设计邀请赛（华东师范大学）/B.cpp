#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 300005;
const int M = 5005;

int n,t,ch[N][26],p[M],vis[M];
double m,g[N],dp[M];
char str[M],a[35];
int main()
{
    while(~scanf("%d",&n))
    {
        memset(ch[0],0,sizeof(ch[0]));
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%s%lf",a,&m);
            int k = 0;
            int len = strlen(a);
            for(int j = len-1;j >= 0;j--)
            {
                int x;
                if(a[j] >= 'a' && a[j] <= 'z')
                    x = a[j]-'a';
                else
                    x = a[j]-'A';
                if(!ch[k][x])
                {
                    ch[k][x] = ++cnt;
                    memset(ch[cnt],0,sizeof(ch[cnt]));
                    g[cnt] = 0;
                }
                k = ch[k][x];
            }
            g[k] = max(g[k],m);
        }
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s",str+1);
            int len = strlen(str+1);
            for(int i = 0;i <= len;i++)
                dp[i] = 0;
            memset(p,-1,sizeof(p));
            for(int i = 1,j;i <= len;i++)
            {
                int k = 0;
                for(j = i;j >= 1;j--)
                {
                    int x;
                    if(str[j] >= 'a' && str[j] <= 'z')
                        x = str[j]-'a';
                    else
                        x = str[j]-'A';
                    if(ch[k][x])
                    {
                        k = ch[k][x];
                        double tmp = g[k]?log(g[k]):0;
                        if(dp[i] < dp[j-1] + (i-j+1)*(i-j+1)*tmp)
                            dp[i] = dp[j-1] + (i-j+1)*(i-j+1)*tmp,p[i] = j-1;
                    }
                    else
                        break;
                }
                while(j >= 1)
                {
                    if(dp[i] < dp[j-1])
                        dp[i] = dp[j-1],p[i] = j-1;
                    j--;
                }
            }
            printf("%.6f\n",dp[len]);
            memset(vis,0,sizeof(vis));
            int k = len;
            while(k != -1)
            {
                vis[k] = 1;
                k = p[k];
            }
            for(int i = 1;i <= len;i++)
            {
                if(vis[i] && i != len)
                    printf("%c ",str[i]);
                else
                    printf("%c",str[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
