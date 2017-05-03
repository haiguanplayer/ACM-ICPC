/*
题意
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int N = 55;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int high[N][N];
int main()
{
    int t,n,m;
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(high,0,sizeof(high));//qingkong a a
        int sum = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
            {
                scanf("%d",&high[i][j]);
                sum += high[i][j] != 0;
            }

        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                for(int k = 0;k < 4;k++)
                {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(high[x][y] < high[i][j])//防止越界
                        sum += (high[i][j] - high[x][y]);
                }
        printf("%d\n",sum);
    }
}
