#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 50005;
struct node
{
    int s,e;
    bool operator < (const node & p)const
    {
        if(s != p.s)
             return s < p.s;
        else
            return e < p.e;
    }
}p[N];
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
        scanf("%d%d",&p[i].s,&p[i].e);
    sort(p,p+n);
    int temp = p[0].e,maxn = 0;
    for(int i = 1;i < n;i++)
    {
        if(temp <= p[i].e)//不被完全重叠
        {
            maxn = max(maxn,temp - p[i].s);
            temp = p[i].e;
        }
        else//被完全重叠
         maxn = max(maxn,p[i].e-p[i].s);

    }
    printf("%d\n",maxn);
    return 0;
}
