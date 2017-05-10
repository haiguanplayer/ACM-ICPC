#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 50005;
struct data
{
    int p,c;
}a[N];
priority_queue<int,vector<int>,greater<int> > pq;

bool cmpc(data a,data b)
{
    return a.c < b.c;
}
bool cmpp(data a,data b)
{
    return a.p < b.p;
}
int main()
{
    int n,k;
    ll m;
    while(cin >> n >> k >> m)
    {
        ll sum = 0;
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&a[i].p,&a[i].c);
        sort(a+1,a+n+1,cmpc);
        while(!pq.empty())
            pq.pop();
        bool flag = false;
        for(int i = 1;i <= k;i++)
        {
            sum += a[i].c;
            pq.push(a[i].p-a[i].c);
            if(sum > m){printf("%d\n",i-1);flag = true;break;}
            if(i == n){printf("%d\n",n);flag = true;break;}
        }
        if(flag)
            continue;
        //k < n
        sort(a+k+1,a+n+1,cmpp);
        int ans = k;
        for(int i = k+1;i <= n;i++)
        {
            int tmp = INF;
            if(!pq.empty())
                tmp = pq.top();
            if(tmp < a[i].p-a[i].c)
            {
                sum += tmp;
                pq.pop();
                pq.push(a[i].p-a[i].c);
                sum += a[i].c;
            }
            else
                sum += a[i].p;
            if(sum > m)
                break;
            else
                ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}
