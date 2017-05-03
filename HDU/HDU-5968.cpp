#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 105;
int num[N],sum[N],ans[N][N];
int main()
{
    int t,n,m,x;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&num[i]);
        for(int i = 1;i <= n;i++)
            sum[i] = sum[i-1]^num[i];
        for(int i = 1;i <= n;i++)
            for(int j = i;j <= n;j++)
                ans[i][j] = sum[j]^sum[i-1];
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&x);
            int minn = 0x3f3f3f3f,len;
            for(int i = 1;i <= n;i++)
                for(int j = i;j <= n;j++)
                {
                    if(minn > abs(ans[i][j]-x))
                    {
                        minn = abs(ans[i][j]-x);
                        len = j-i+1;
                    }
                    else if(minn == abs(ans[i][j]-x))
                        len = max(len,j-i+1);
                }
            printf("%d\n",len);
        }
        printf("\n");
    }
    return 0;
}
