#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;


int a[10][10];
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&x,&y);
        a[x+3][y+3] = 1;
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x+3][y+3] = -1;
    }
    int sum = 0;
    for(int i = 0;i <= 6;i++)
    {
        if(i == 3)
        {
            if(a[i][0] + a[i][1] + a[i][2] == 3)
                sum++;
            if(a[i][4]+a[i][5]+a[i][6] == 3)
                sum++;
        }
        else
        {
            int cnt = 0;
            for(int j = 0;j <= 6;j++)
            {
                cnt += a[i][j];
            }
            if(cnt == 3)
                sum++;
        }
    }


    for(int i = 0;i <= 6;i++)
    {
        if(i == 3)
        {
            if(a[0][i]+a[1][i]+a[2][i] == 3)
                sum++;
            if(a[4][i]+a[5][i]+a[6][i] == 3)
                sum++;
        }
        else
        {
            int cnt = 0;
            for(int j = 0;j <= 6;j++)
            {
                cnt += a[j][i];
            }

                if(cnt == 3)
                    sum++;
        }
    }
    cout<<sum<<endl;
}
