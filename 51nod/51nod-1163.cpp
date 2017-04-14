#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 50005;
struct node
{
    int E,W;
    bool operator < (const node & p)const
    {
            return E < p.E;
    }
}p[N];
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
        scanf("%d%d",&p[i].E,&p[i].W);
    sort(p,p+n);
    long long sum = 0;
    priority_queue<int ,vector<int >,greater<int> >pq;
    for(int i = 0;i < n;i++)
    {
        int k = p[i].W;
        if(p[i].E > pq.size())
        {
            sum += k;
            pq.push(k);
        }
        else
        {
            sum += k;
            pq.push(k);
            sum -= pq.top();
            pq.pop();
        }
    }
    printf("%lld\n",sum);
}
