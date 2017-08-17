#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int t0,T,n;
int a[N],sum[N];
priority_queue< int,vector<int>,greater<int> > pq;
bool check(int k)
{
    while(!pq.empty())
        pq.pop();
    int ans = 0;
    int m = (n-1)%(k-1);
    if(m > 0)
    {
        ++m;
        ans += sum[m];
        pq.push(ans);
    }
    for(int i = m+1;i <= n;i++)
        pq.push(a[i]);
    int up = (n-1)/(k-1);
    for(int i = 0;i < up;i++)
    {
        int cnt = 0,tot = k;
        while(tot--)
        {
            cnt += pq.top();
            pq.pop();
        }
        ans += cnt;
        pq.push(cnt);
    }
    return ans <= T;
}
int main()
{
    scanf("%d",&t0);
    while(t0--)
    {
        scanf("%d %d",&n,&T);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i = 1;i <= n;i++)
            sum[i] = sum[i-1] + a[i];
        int l = 2,r = n;
        while(l < r)
        {
            int mid = (l+r)>>1;
            if(check(mid))
                r = mid;
            else
                l = mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
