#include<bits/stdc++.h>
using namespace std;

const int N = 255;
int a[N][N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y,u,v;
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d%d%d",&x,&y,&u,&v);
        a[x][y] = a[u][v] = i+1;
        double k = (y-v*1.0)/(x-u*1.0);
        int l = min(x,u);int r = max(x,u);
        while(l <= r)
        {
            double yy = (l-u*1.0)*(y-v*1.0)/(x-u*1.0)+v;
            if(yy == (long long)yy)
                a[l][(long long)yy] = i+1;
            l++;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",a[x][y]);
    }
    return 0;
}
