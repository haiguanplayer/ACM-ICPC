#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;
struct node{
    ll num;
    int val;
    bool operator < (const node & p)const{
        return val > p.val;
    }
}a[N];
ll p[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%lld%d",&a[i].num,&a[i].val);
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 62;j >= 0;j--)
        {
            if(!(a[i].num >> j)) continue;
            if(!p[j]){
                p[j] = a[i].num;
                ans += a[i].val;
                break;
            }
            a[i].num ^= p[j];
        }
    }
    printf("%d\n",ans);
    return 0;
}
