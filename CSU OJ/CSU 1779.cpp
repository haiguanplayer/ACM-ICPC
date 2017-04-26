#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int a[N][N],row[N],col[N];

int main()
{
    int n,m,cnt = 0;
    while(~scanf("%d%d",&n,&m))
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                scanf("%d",&a[i][j]);
        printf("Case %d: ",++cnt);
        int mr = 1,mc = 1,maxr = 0,maxc = 0;
        int maxn = 0,m1 = 1,m2 = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                row[i] += a[i][j];
            }
            //printf("%d\n",row[i]);
            if(maxr < row[i])
            {
                maxr = row[i];
                mr = i;
            }
        }

        for(int j = 1;j <= m;j++)
        {
            for(int i = 1;i <= n;i++)
            {
                col[j] += a[i][j];
            }
            //printf("%d\n",col[j]);
            if(maxc < col[j])
            {
                maxc  = col[j];
                mc = j;
            }
        }



        //printf("\n%d %d\n",mr,mc);
         for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(maxn < row[i]+col[j]-a[i][j])
                {
                    maxn = row[i]+col[j]-a[i][j];
                    m1 = i;m2 = j;
                }
            }
        }
        //printf("%d %d\n",m1,m2);
        if(maxr + maxc - a[mr][mc] == maxn)//if(m1 == mr && m2 == mc)
            printf("Weak\n");
        else
            printf("Strong\n");
    }
}
