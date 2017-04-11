#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int N = 1e5+5;
int a[N],b[N];
long long solve(int n)
{
    long long res = 0,s = 0;
    for(int i = 1;i < n;i++)
    {
        s += b[i];
        res = max(res,s);
        if(s < 0)
            s = 0;
    }
    return res;
}
int main()
{
    int n,num = 0;
    cin>>n;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    for(int i = 1;i < n;i++)
    {
        b[i] = abs(a[i]-a[i+1]);
        if(i % 2 == 0)
            b[i] = -b[i];
    }
    long long res = solve(n);
    for(int i = 1;i < n;i++)
        b[i] = -b[i];

    res = max(res,solve(n));
    cout<<res<<endl;
    return 0;
}
