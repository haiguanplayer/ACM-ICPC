#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int v[10][10],a[10];
char str[10][10];
int main()
{
    v[1][1] = v[1][4] = v[1][5] = v[1][6] = v[1][7] = 1;
    v[2][3] = v[2][6] = 1;
    v[3][5] = v[3][6] = 1;
    v[4][1] = v[4][4] = v[4][5] = 1;
    v[5][2] = v[5][5] = 1;
    v[6][2] = 1;
    v[7][4] = v[7][5] = v[7][6] = v[7][7] = 1;
    v[9][5] = 1;

    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d %s",&a[i],str[i]);

        map<int,int> m1,m2;
        m1.clear();m2.clear();

        for(int i = 0;i < 7;i++)//对每一列进行加和判断
        {
            int tmp1 = 0,tmp2 = 0;
            for(int j = 1;j <= n;j++)
            {
                tmp1 = tmp1*10 + v[a[j]][i+1];
                tmp2 = tmp2*10 + str[j][i] - '0';
            }
            m1[tmp1]++;
            m2[tmp2]++;
        }
        if(m1 == m2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
