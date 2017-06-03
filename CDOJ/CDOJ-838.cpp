#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int n,m,C[N];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int val)
{
    while(x <= n)
    {
        C[x] += val;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += C[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    int x;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&x);
        add(i,x);
    }
    int s,l,r;
    while(m--)
    {
        scanf("%d%d%d",&s,&l,&r);
        if(s == 0)
            printf("%d\n",sum(r)-sum(l-1));
        else
            add(l,r);
    }
    return 0;
}
