#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
struct node
{
    int val,cnt;
    bool operator < (const node & p)const
    {
        return val < p.val;
    }
}p[N];
int b[N*N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        scanf("%d",&p[i].val);
    for(int i = 1;i <= n;i++)
        scanf("%d",&p[i].cnt);
    sort(p+1,p+1+n);
    int num = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= p[i].cnt;j++)
            b[num++] = p[i].val;
    long long sum = 0,ans = 0,maxn = 0;
    for(int i = num-1;i >= 0;i--)
    {
        sum += 1ll*b[i];
        ans += sum;
        maxn = max(maxn,ans);
    }
    printf("%lld\n",maxn);
    return 0;
}
