/*
题意：给你国王死去的日期，and他的所有儿子的出生日期，让求成年的最小儿子编号
思路：计算所有儿子活的天数，找到成年的最小值位置即可
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 105;
int dd,mm,yy,n;
int d[N],m[N],y[N],day[N];
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);
    while(~scanf("%d%d%d",&dd,&mm,&yy))
    {
        scanf("%d",&n);
        int minn = 0x3f3f3f3f;
        int pos = -1;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&d[i],&m[i],&y[i]);
            if(yy-y[i] >= 17)
            {
                int sum = month[m[i]] - d[i] + 1;
                if(m[i] < 12)
                for(int j = m[i]+1;j <= 12;j++)
                    sum += month[j];
                sum += (yy-y[i]-1)*365;
                for(int j = 1;j <= mm-1;j++)
                    sum += month[j];
                sum += dd;
                day[i] = sum;
                if(day[i] < minn && day[i] > 18*365)
                {
                    minn = day[i];
                    pos = i;
                }
            }
        }
        printf("%d\n",pos);
    }
}
