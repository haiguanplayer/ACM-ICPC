#include<bits/stdc++.h>
using namespace std;

const int N = 30005;
int a[N][6],id[N][6];
bitset<N> dp[N][6],ans;//dp[i][j]表示第j门课比第i名同学名次高的同学

int main()
{
    int n,x;
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= 5;j++)
                scanf("%d",&x),a[i][j] = x,id[x][j] = i;//第j门课第x名是i同学
        for(int i = 2;i <= n;i++)
        {
            for(int j = 1;j <= 5;j++)
            {
                dp[i][j] = dp[i-1][j];//先将比第i-1名同学高的放入集合
                dp[i][j].set(id[i-1][j]);//再将第i-1名放入
            }
        }

        for(int i = 1;i <= n;i++)
        {
            ans.set();
            for(int j = 1;j <= 5;j++)
                ans &= dp[a[i][j]][j];
            printf("%d\n",ans.count());
        }
    }
    return 0;
}
