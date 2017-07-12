#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

priority_queue<long long> pq;
int main()
{
    int n;
    long long x,ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        scanf("%lld",&x);
        x = (long long)1e9-x;
        pq.push(x);
        if(pq.top() > x)
        {
            ans += pq.top()-x;
            pq.pop();
            pq.push(x);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
