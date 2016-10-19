#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double p[25];
bool vis[25];
int n;
double dfs(int r,int cur,int x)
{
    if(r == cur)
    {
        double temp = 1.0;
        for(int i =  0;i < n;i++)
            if(!vis[i])
                temp *= (1.0-p[i]);
        return temp;
    }

    double ans = 0;
    for(int i = x;i < n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            ans += dfs(r+1,cur,i+1)*p[i];
            vis[i] = 0;
        }
    }
    return ans;
}
int main()
{
    int r,ca = 0;;
    ios_base::sync_with_stdio(0);//¹ØµôÍ¬²½
    while(cin >> n >> r && (n || r))
    {
        for(int i = 0;i < n;i++)
            cin >> p[i];
        printf("Case %d:\n",++ca);
        memset(vis,false,sizeof(vis));

        double sum = dfs(0,r,0),temp;
        for(int i = 0;i < n;i++)
        {
            vis[i] = 1;
            temp = dfs(0,r-1,0)*p[i];
            printf("%.6f\n",temp/sum);
            vis[i] = 0;
        }
    }
    return 0;
}
