#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int N = 2*1e5+5;
int maxsum[N][20],minsum[N][20];
void RMQ(int n) //预处理->O(nlogn)
{
    for(int j = 1;j < 20;j++)
        for(int i = 1;i <= n;i++)
            if(i + (1 << j) - 1 <= n)
            {
                maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << (j - 1))][j - 1]);
                minsum[i][j] = min(minsum[i][j - 1], minsum[i + (1 << (j - 1))][j - 1]);
            }
}
int Diff(int l,int r)
{
    int k = (int)(log(r - l + 1.0) / log(2.0));
    int maxres = max(maxsum[l][k], maxsum[r - (1 << k) + 1][k]);
    int minres = min(minsum[l][k], minsum[r - (1 << k) + 1][k]);
    return maxres-minres;
}
int main()
{
    int n,k;
        scanf("%d%d",&n,&k);
        for(int i = 1; i <= n; ++i)//输入信息处理
        {
            scanf("%d", &maxsum[i][0]);
            minsum[i][0] = maxsum[i][0];
        }
        RMQ(n);
        long long ans = 0;
        int l,r,mid;
        for(int i = 1;i <= n;i++)
        {
            l = i,r = n;
            while(l+1 < r)
            {
                mid = (l+r)>>1;
                if(Diff(i,mid) <= k)
                     l = mid;
                else
                    r = mid-1;
            }
            if(Diff(i,r) <= k)
                ans += 1ll*(r-i+1);
            else
                ans += 1ll*(l-i+1);
        }
        printf("%lld\n",ans);
    return 0;
}
