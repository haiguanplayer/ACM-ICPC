/*
dp[i][j] = p[i][j][1]*dp[i][j] + p[i][j][2]*dp[i][j+1] + p[i][j][3]*dp[i+1][j] + 2;
dp[i][j] = (p[i][j][2]*dp[i][j+1] + p[i][j][3]*dp[i+1][j] + 2) / (1 - p[i][j][1]);

*/
#include<cstdio>
using namespace std;

const int N = 1005;
double dp[N][N],p[N][N][4];
int main()
{
    int R,C;
    while(~scanf("%d%d",&R,&C))
    {
        for(int i = 1;i <= R;i++)
            for(int j = 1;j <= C;j++)
                for(int k = 1;k <= 3;k++)
                    scanf("%lf",&p[i][j][k]);
        dp[R][C] = 0;
        for(int i = R;i >= 1;i--)
        {
            for(int j = C;j >= 1;j--)
            {
                if(p[i][j][1] == 1 || (i == R && j == C))//不用决策的时候
                    continue;
                dp[i][j] = (p[i][j][2]*dp[i][j+1] + p[i][j][3]*dp[i+1][j] + 2) / (1 - p[i][j][1]);
            }
        }
        printf("%.3f\n",dp[1][1]);
    }
    return 0;
}
